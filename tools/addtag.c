#include <stdio.h>
#define X_NUM 29
#define Y_NUM 19
#define TAG "MJ GET bokunimowakaru.github.io/MJ/bk01/"
main(){
	FILE *fp,*fw;
	char c;
	char file[]="123456.txt";
	int i,j,k=1;
	fp = fopen("in.txt", "r");
	if(fp==NULL){
		fprintf(stderr,"sorry, hard coded in.txt -> nnn.txt\n");
		return -1;
	}
    while( feof(fp) == 0 ){
		sprintf(file,"%d.txt",k);
		fw=fopen(file, "w");
		fprintf(fw,"cls:?\"page %d \";\n",k);
		if(fw==NULL) return -1;
		for(j=0;j<Y_NUM;j++){
			fprintf(fw,"' ");
			for(i=0;i<X_NUM;i++){
				if(!feof(fp)) c=fgetc(fp);
				else{
					i=X_NUM;
					break;
				}
		        switch(c){
					case '\r':
						break;
					case '\n':
						i=X_NUM;
						break;
					case (char)0x81:	// ルビの削除
						c=fgetc(fp);
						if(c==0x73){
							while(c!=0x74 && !feof(fp)) c=fgetc(fp);
						}
						break;
					default:
						fprintf(fw,"%c",c);
						break;
				}
			}
			fprintf(fw,"\n");
		}
		fprintf(fw,"'\ninputA:A=A+!A*%d:?\"",k+1);
		fprintf(fw,TAG);
		fprintf(fw,"\";A;\".txt\"\n");
		fclose(fw);
		k++;
    }
    fclose(fp);
    return 0;
}

