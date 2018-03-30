#include<stdio.h>
#include<stdlib.h>
#include<string.h>
unsigned int hash(char *key){
		unsigned int hv=0;
		for(hv=0;*key;key++) // string polynomial 
				hv=hv+*key;
		hv=hv%10;
		return hv;
}
struct table{
		char slot[5];
};
int main()
{
		struct table bucket[10];
		char /*bucket[10][5],*/buf[5],file[20];
		int collision,value,i;
		for(i=0;i<=9;i++)		//initialize
				strcpy(bucket[i].slot,"\0");
		collision=0;
		FILE *fp;
		printf("please input the file's name:");
		scanf("%s",file);
		fp=fopen(file,"r");
		printf("data:");
		while(fscanf(fp,"%s",buf)!=EOF)
				printf("%s ",buf);
		printf("\n");
		fp=fopen(file,"r");
		while(fscanf(fp,"%s",buf)!=EOF)
		{
				value=hash(buf);
				if(strcmp(bucket[value].slot,"\0")==0){		//空的,放入
						strcpy(bucket[value].slot,buf);
				}
				else				//collision
				{
						while(strcmp(bucket[value].slot,"\0")!=0){	//放到下一個空的slot
								value=(value+1)%10;
								collision++;
						}
						strcpy(bucket[value].slot,buf);
				}
		}
		for(i=0;i<=9;i++)
				printf("bucket[%d]:%s\n",i,bucket[i].slot);
		printf("collision times:%d\n",collision);




		return 0;
}
