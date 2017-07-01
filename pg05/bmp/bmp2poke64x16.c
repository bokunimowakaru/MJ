/*
64x16 2値(1ビット) 画像のBMPファイルからフォントを作成するためのBASICコマンドを出力する
BMPのヘッダはバイト数で除去（BMPファイルによっては動作しないかも）
異常処理は基本的に行っていない（セグフォがあるかも）

総画素数	64画素×16画素×1bit = 1024画素 128バイト
キャラクタ	8桁×2行

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PIX_SIZE_BYTE	128
#define PIX_X			64
#define JAM_ADR			0x700
unsigned char PIX_WHITE=0x01;

int main(int argc,char **argv){
	FILE *fp;
	int i,x,y;
	unsigned char data[PIX_SIZE_BYTE+1];
	unsigned char out[PIX_SIZE_BYTE/PIX_X*8][8];
	unsigned char c;
	
	if( argc>2 && argv[1][0] == '-'){
		PIX_WHITE=(unsigned char)atoi( &argv[1][1] );
		printf("PIX_WHITE = %02x\n",PIX_WHITE);
		argv++;
	}
	fp=fopen(argv[1],"r");
	if(fp==0){
		fprintf(stderr,"Usage : %s [-1 or -0] filename.bmp\n",argv[0]);
		fprintf(stderr,"オプション -0 で白黒反転します\n");
		return -1;
	}
	fseek(fp,0x0000003E,SEEK_SET);
	fgets((char *)data,PIX_SIZE_BYTE+1,fp);
	fclose(fp);
	for(y=0;y<PIX_SIZE_BYTE/PIX_X*8;y++){
		for(x=0;x<PIX_X/8;x++){
			printf("%02x ",data[x+(PIX_SIZE_BYTE-8)-y*(PIX_X/8)]);
		}
		printf("\n");
	}
	memset(out,0x00,PIX_SIZE_BYTE/PIX_X*8*8);
	for(y=0;y<PIX_SIZE_BYTE/PIX_X*8;y++){
		for(x=0;x<PIX_X;x++){
			c=data[x/8+(PIX_SIZE_BYTE-8)-y*(PIX_X/8)];
			if(x%8==0){
				out[x/8+(y/8)*8][y%8]=c;
			}
			if( (( c>>(7-(x%8)) ) & 0x01) == PIX_WHITE ){
				printf("#");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	for(i=0;i<PIX_SIZE_BYTE/PIX_X*8;i++){
		printf("poke#%3X,",JAM_ADR+i*8);
		for(y=0;y<8;y++){
			if(PIX_WHITE) c = out[i][y]; else c = ~out[i][y];
			if(c<100) printf("%d",c);
			else printf("#%X",c);
			if(y<7)printf(",");
		}
		printf("\n");
	}
	return 0;
}
