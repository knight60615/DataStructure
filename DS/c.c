#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MaxName 30
#define MaxPeople 100
struct D {
		int NO,Ms,Cs;//student number,Math score,Chinese score.
		char Name[MaxName];
}Dtab[MaxPeople];
int NOcmp(const void *a,const void *b)//4種用來qsort的副函式
{//負責number
		struct D *f=(struct D *)a;
		struct D *r=(struct D *)b;
		return ((f->NO)-(r->NO));
}
int Cscmp(const void *a,const void *b)
{//負責Chinese score
		struct D *f=(struct D *)a;
		struct D *r=(struct D *)b;
		return ((f->Cs)-(r->Cs));
}
int Mscmp(const void *a,const void *b)
{//負責Math score
		struct D *f=(struct D *)a;
		struct D *r=(struct D *)b;
		return ((f->Ms)-(r->Ms));
}
int Namecmp(const void *a,const void *b)
{//負責Name
		struct D *f=(struct D *)a;
		struct D *r=(struct D *)b;
		return strcmp(f->Name,r->Name);
}
int main(int argc,char *argv[])
{
		int tNO,tMs,tCs;//暫存用的變數,用來接讀檔時抓到的值
		char t[MaxName];//t用來接名字
		int ptr=0,total=0,c;//ptr是用來當index,total記錄總共有多少組,c是給switch用的
		FILE *fp=fopen(argv[1],"r");//讀檔並且避免開檔失敗
		if(!fp) {printf("Malloc Failed or The File Not Found\n");return 0;}
		while(fscanf(fp,"%d %s %d %d",&tNO,t,&tMs,&tCs)!=EOF)//把讀到的東西放進struct array裡
		{
				total++;
				Dtab[ptr].NO=tNO;
				Dtab[ptr].Ms=tMs;
				Dtab[ptr].Cs=tCs;
				strcpy(Dtab[ptr].Name,t);
				ptr++;
		}
		while(1)//用while(1)讓它可以一直重複讀取指令來顯示資料
		{
				printf("\nSort by\n1.Student NO.\n2.Chinese score.\n3.Math score.\n4.Name.\n5.EXIT.\n");
				scanf("%d",&c);
				switch(c)
				{
						case 1://sort by number
								qsort(Dtab,total,sizeof(struct D),NOcmp);
								for(ptr=0;ptr<total;ptr++)
								{
										printf("%d\t%s\t%d\t%d\n",Dtab[ptr].NO,Dtab[ptr].Name,Dtab[ptr].Ms,Dtab[ptr].Cs);
								}
								break;
						case 2://sort by Chinese score
								qsort(Dtab,total,sizeof(struct D),Cscmp);
								for(ptr=0;ptr<total;ptr++)
								{
										printf("%d\t%s\t%d\t%d\n",Dtab[ptr].NO,Dtab[ptr].Name,Dtab[ptr].Ms,Dtab[ptr].Cs);
								}
								break;
						case 3://sort by Math score
								qsort(Dtab,total,sizeof(struct D),Mscmp);
								for(ptr=0;ptr<total;ptr++)
								{
										printf("%d\t%s\t%d\t%d\n",Dtab[ptr].NO,Dtab[ptr].Name,Dtab[ptr].Ms,Dtab[ptr].Cs);
								}
								break;
						case 4://sort by name
								qsort(Dtab,total,sizeof(struct D),Namecmp);
								for(ptr=0;ptr<total;ptr++)
								{
										printf("%d\t%s\t%d\t%d\n",Dtab[ptr].NO,Dtab[ptr].Name,Dtab[ptr].Ms,Dtab[ptr].Cs);
								}
								break;
						case 5:return 0;//讓它可以跳出迴圈並結束
				}
		}
}
