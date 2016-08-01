#include <stdio.h>
#define TAG "MJ GET bokunimowakaru.github.io/MJ/n/"
// ニュース用

main(){
	FILE *fp,*fw;
	char c;
	char file[]="123456.txt";
	int i,j,k=1;
    for(k=1;k<99;k++){
		fp = fopen("tmp.txt", "r");
		if(fp==NULL){
			fprintf(stderr,"sorry, hard coded tmp.txt -> nnn.txt\n");
			return -1;
		}
		sprintf(file,"%d.txt",k);
		fw=fopen(file, "w");
		fprintf(fw,"\ncls:?\"page %d \";\n",k);
		if(fw==NULL) return -1;
		while(!feof(fp)){
			c=fgetc(fp);
			if(c != -1) fprintf(fw,"%c",c);
		}
		fprintf(fw,"inputA:A=A+!A*%d:?\"",k-1);
		fprintf(fw,TAG);
		fprintf(fw,"\";A;\".txt\"\n");
		fclose(fw);
    	fclose(fp);
    }
    return 0;
}

