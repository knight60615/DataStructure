#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MaxName 30
#define MaxPeople 100
struct D {
		int NO,Ms,Cs;//student number,Math score,Chinese score.
		char Name[MaxName];
}Dtab[MaxPeople];
int NOcmp(const void *a,const void *b)//4�إΨ�qsort���ƨ禡
{//�t�dnumber
		struct D *f=(struct D *)a;
		struct D *r=(struct D *)b;
		return ((f->NO)-(r->NO));
}
int Cscmp(const void *a,const void *b)
{//�t�dChinese score
		struct D *f=(struct D *)a;
		struct D *r=(struct D *)b;
		return ((f->Cs)-(r->Cs));
}
int Mscmp(const void *a,const void *b)
{//�t�dMath score
		struct D *f=(struct D *)a;
		struct D *r=(struct D *)b;
		return ((f->Ms)-(r->Ms));
}
int Namecmp(const void *a,const void *b)
{//�t�dName
		struct D *f=(struct D *)a;
		struct D *r=(struct D *)b;
		return strcmp(f->Name,r->Name);
}
int main(int argc,char *argv[])
{
		int tNO,tMs,tCs;//�Ȧs�Ϊ��ܼ�,�Ψӱ�Ū�ɮɧ�쪺��
		char t[MaxName];//t�Ψӱ��W�r
		int ptr=0,total=0,c;//ptr�O�Ψӷ�index,total�O���`�@���h�ֲ�,c�O��switch�Ϊ�
		FILE *fp=fopen(argv[1],"r");//Ū�ɨåB�קK�}�ɥ���
		if(!fp) {printf("Malloc Failed or The File Not Found\n");return 0;}
		while(fscanf(fp,"%d %s %d %d",&tNO,t,&tMs,&tCs)!=EOF)//��Ū�쪺�F���istruct array��
		{
				total++;
				Dtab[ptr].NO=tNO;
				Dtab[ptr].Ms=tMs;
				Dtab[ptr].Cs=tCs;
				strcpy(Dtab[ptr].Name,t);
				ptr++;
		}
		while(1)//��while(1)�����i�H�@������Ū�����O����ܸ��
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
						case 5:return 0;//�����i�H���X�j��õ���
				}
		}
}
