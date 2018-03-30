#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 500
struct key{
		int num;
		char *name;
		int math;
		int chinese;
};
void swap(struct key *a,struct key *b){
		struct key *temp;
		*temp=*a;
		*a=*b;
		*b=*temp;
}
int main(int argc, char *argv[])
{
		FILE *fp;
		if (argc>0)
				fp=fopen(argv[1],"r");

		if(fp==NULL){				
				printf("fopen failed\n");
				return 0;
		}
		struct key grade[Max];		//structure array
		struct key *p;
		char bufName[Max],s;
		int bufNum,bufMath,bufChinese;
		int i=0,x,y;
		/*依照測資原本的順序輸入資料*/
		while(fscanf(fp,"%d %s %d %d",&bufNum,bufName,&bufMath,&bufChinese)!=EOF)
		{
				grade[i].name=(char *)malloc(sizeof(char)*(strlen(bufName)+1));
				bufName[strlen(bufName)]='\0';
				grade[i].num=bufNum;
				grade[i].math=bufMath;
				grade[i].chinese=bufChinese;
				strcpy(grade[i].name,bufName);
				i++;
		}
		for(p=grade;p<grade+i;p++)
				printf("%d\t%s\t%d\t%d\n",p->num,p->name,p->math,p->chinese);
		while(1){			//action menu 沒規定是否重複執行所以讓他重複了
				printf("請選擇欲執行之動作:\n1. sort by student No.\n2. sort by Chinese score.\n3. sort by Math score.\n4. sort by name.\n");
				scanf(" %c",&s);
				switch(s){
						case'1':for(x=0;x<i-1;x++){
										for(y=0;y<i-x-1;y++){
												if(grade[y].num>grade[y+1].num){
														/*swap(grade+y,grade+y+1);*/
														swap(&grade[y],&grade[y+1]);
												}							//Bubble sort

										}
								}
								for(x=0;x<i;x++)
										printf("%d\t%s\t%d\t%d\n",grade[x].num,grade[x].name,grade[x].math,grade[x].chinese);
								break;
						case'2':for(x=0;x<i-1;x++){
										for(y=0;y<i-x-1;y++)
												if(grade[y].chinese>grade[y+1].chinese){
														/*swap(grade+y,grade+y+1);*/
														swap(&grade[y],&grade[y+1]);
												}							//Bubble sort

								}

								for(x=0;x<i;x++)
										printf("%d\t%s\t%d\t%d\n",grade[x].num,grade[x].name,grade[x].math,grade[x].chinese);
								break;

						case'3':for(x=0;x<i-1;x++){
										for(y=0;y<i-x-1;y++){
												if(grade[y].math>grade[y+1].math){
														/*swap(grade+y,grade+y+1);*/
														swap(&grade[y],&grade[y+1]);
												}							//Bubble sort

										}
								}
								for(x=0;x<i;x++)
										printf("%d\t%s\t%d\t%d\n",grade[x].num,grade[x].name,grade[x].math,grade[x].chinese);
								break;

						case'4':for(x=0;x<i-1;x++){
										for(y=0;y<i-x-1;y++){
												if(strcmp(grade[y].name,grade[y+1].name)>0)
														/*swap(grade+y,grade+y+1);*/
														swap(&grade[y],&grade[y+1]);
										}							//Bubble sort

								}

								for(x=0;x<i;x++)
										printf("%d\t%s\t%d\t%d\n",grade[x].num,grade[x].name,grade[x].math,grade[x].chinese);
								break;
				}
		}
		return 0;
}
