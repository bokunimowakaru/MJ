/*
64x128 2値(1ビット) 画像のBMPファイルからフォントを作成するためのBASICコマンドを出力する
BMPのヘッダはバイト数で除去（BMPファイルによっては動作しないかも）
異常処理は基本的に行っていない（セグフォがあるかも）

総画素数	64画素×128画素×1bit = 8192画素 1024バイト
キャラクタ	16行　／　8桁

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PIX_SIZE_BYTE	1024
#define PIX_X			64
#define PIX_Y			128
unsigned int JAM_ADR=	0x700;
unsigned char PIX_WHITE=0x01;
unsigned char FILE_DIV=0x01;

void err(char *s){
	fprintf(stderr,"Usage : %s [-1 or -0] filename.bmp\n",s);
	fprintf(stderr,"入力ファイル名は、3文字以上、アルファベット小文字\n\n");
	fprintf(stderr,"Options\n");
	fprintf(stderr,"  -0          白黒反転します\n");
	fprintf(stderr,"  -1          反転無し(デフォルト)\n");
	fprintf(stderr,"  -Hhhh       IchigoJam用の開始アドレスを指定(hhhは16進数)\n");
	fprintf(stderr,"  -c          ファイル結合(非分割出力)\n");
	exit(1);
}

int main(int argc,char **argv){
	FILE *fp;
	int i,x,y;
	unsigned char data[PIX_SIZE_BYTE+1];
	unsigned char out[PIX_SIZE_BYTE+1];
	unsigned char c;
	char s[65];
//	          0123456789012345678901
//	char s[]="mkdir XXX &> /dev/null";
//	char s[]="XXX/n.txt";

	printf("開始(%s)\n",argv[0]);
	while( argc>2 && argv[1][0] == '-'){
		if(argv[1][1] == 'H'){
			JAM_ADR = strtol(&argv[1][2],NULL,16);;
		}else if(argv[1][1] == 'c'){
			FILE_DIV=0x00;
			JAM_ADR=0xC00;
		}else{
			PIX_WHITE=(unsigned char)atoi( &argv[1][1] );
			printf("PIX_WHITE = %02x\n",PIX_WHITE);
		}
		argv++;
		argc--;
	}
	
	printf("ARG数確認(%d)\n",argc);
	if(argc<2)err(argv[0]);
	if(argc>2)err(argv[0]);
	
	printf("ARG文字確認(%s)\n",argv[1]);
	for(i=0;i<3;i++){
		if(argv[1][i]<'a'||argv[1][i]>'z')err(argv[0]);
	}
	
	printf("入力ファイル確認(%s)\n",argv[1]);
	fp=fopen(argv[1],"r");
	if(fp==0)err(argv[0]);
	fseek(fp,0x0000003E,SEEK_SET);
	for(i=0;i<PIX_SIZE_BYTE;i++){
		data[i]=fgetc(fp);
		if(feof(fp)){
			fprintf(stderr,"サイズエラー\n");
			return -1;
		}
	}
	fclose(fp);
	for(i=0;i<64;i++) printf("-"); printf("\n");
	
	memset(out,0x00,PIX_SIZE_BYTE);
	for(y=0;y<PIX_Y;y++){
		for(x=0;x<PIX_X/8;x++){
			out[x+y*8]=data[x+PIX_SIZE_BYTE-y*8-8];
			printf("%02x ",out[x+y*8]);
		//	printf("%04x ",x+PIX_SIZE_BYTE-y*8-8);
		}
		printf("\n");
	}
	for(i=0;i<64;i++) printf("-"); printf("\n");
	
	/* 入力データの表示 */
/*	for(y=0;y<PIX_Y;y++){
		for(x=0;x<PIX_X;x++){
			c=data[x/8+y*8];
			c=( ( ( c>>(7-(x%8)) ) & 0x01 ) == PIX_WHITE );
			if( c ){
				printf("#");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	for(i=0;i<64;i++) printf("-"); printf("\n");
*/	
	/* 文字回転処理 */
/*	memcpy(data,out,PIX_SIZE_BYTE);
	memset(out,0x00,PIX_SIZE_BYTE);
	for(y=0;y<PIX_Y;y++){
		for(x=0;x<PIX_X;x++){
			c=data[x/8+y*8];
			c=( ( ( c>>(7-(x%8)) ) & 0x01 ) == PIX_WHITE );
			if( c ){
				out[x/8+(y/8)*64+(x%8)*8] |= ( 0x01<<(y%8));
			}
		}
		printf("\n");
	}
	for(i=0;i<64;i++) printf("-"); printf("\n");
*/	
	
	/* 先頭のデータが0xFFだとIchigoJam側でファイルとして扱われない */
	c=out[(PIX_X/8)-1];
	if(!PIX_WHITE) c = ~c;
	if(c==0xFF) c=0xEF;
	if(!PIX_WHITE) c = ~c;
	out[(PIX_X/8)-1]=c;

	/* 出力用のデータ表示 */
	for(y=0;y<PIX_Y;y++){
		for(x=0;x<PIX_X;x++){
			c=out[x/8+y*8];
			if( (( c>>(7-(x%8)) ) & 0x01) == PIX_WHITE ){
				printf("#");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	for(i=0;i<64;i++) printf("-"); printf("\n");
	
	strcpy(s,"mkdir XXX 2> /dev/null");
	memcpy(&s[6],argv[1],3);
	printf("ディレクトリ作成(%s)\n",s);
	system(s);
	argv[1][3]='\0';
	for(x=(PIX_X/8)-1;x>=0;x--){
		if(x==(PIX_X/8)-1 || FILE_DIV ){
			strncpy(s,argv[1],16);	// 23バイト、22文字まで
			if(!FILE_DIV) sprintf(s,"%s/c.txt",s);
			else sprintf(s,"%s/%1d.txt",s,7-x);
			printf("ファイル出力(%s)\n",s);
			fp=fopen(s,"w");
		}
		if(fp==0){
			fprintf(stderr,"ファイルの書き込みに失敗しました\n");
			return -1;
		}
		for(y=0;y<(PIX_Y/8);y++){
		//	printf("poke#%3X,",JAM_ADR+8*(y+(7-x)*8));
			printf("poke#%3X,",JAM_ADR+8*y);
			fprintf(fp,"poke#%3X,",JAM_ADR+8*y);
			for(i=0;i<8;i++){
				if(PIX_WHITE) c = out[x+y*64+i*8]; else c = ~out[x+y*64+i*8];
				if(c<100){
					printf("%d",c);
					fprintf(fp,"%d",c);
				}
				else{
					printf("#%X",c);
					fprintf(fp,"#%X",c);
				}
				if(i<7){
					printf(",");
					fprintf(fp,",");
				}
			}
			printf("\n");
			fprintf(fp,"\n");
		}
		/*
		strncpy(s,argv[1],16);	// 23バイト、22文字まで
		sprintf(s,"%s/%1d.txt",s,7-x+1);
		fprintf(fp,"MJ GET bokunimowakaru.github.io/MJ/pg05/bmp/%s\n",s);
		*/
		if(x==0 || FILE_DIV ){
			fprintf(fp,"goto200\n");
			fclose(fp);
		}
		if( !FILE_DIV ) JAM_ADR += PIX_Y;
		for(i=0;i<64;i++) printf("-"); printf("\n");
	}
	return 0;
}
