#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 15					//�Τ@�w�qmaze�ؤo
typedef struct Node {				//stack�����A�w�q
		int X;
		int Y;
		struct Node *next;
}Node;
Node *topA=NULL;					//topA�O��ratA�Ϊ�stack,topB�O��ratB�Ϊ�
Node *topB=NULL;
Node *ptr=NULL;						//��U�ާ@��pointer
int MAZE[maxsize+2][maxsize+2];		//�s��maze���骺�G���}�C
int markA[maxsize+2][maxsize+2];	//markA��B���O�ΨӰO�����L���I
int markB[maxsize+2][maxsize+2];
int rowA=1,colA=1;					//2�ռƦr�ΨӪ�ܮy��
int rowB=15,colB=15;
void push(Node **top,int A,int B)	//�N�s�y�Щ�istack��push�禡
{
		ptr=malloc(sizeof(Node));
		ptr->Y=A;
		ptr->X=B;
		ptr->next=*top;
		*top=ptr;
}
int DirA(int A,int B)				//ratA����V�P�_�ƨ禡
{
		if(MAZE[A][B+1]==0)			//���P�_�o�Ӥ�V�ण�ਫ
		{
				if((A!=topA->Y||(B+1)!=topA->X)&&markA[A][B+1]!=1)	//�A�P�_�o�Ӥ�V���X�h�����@�B�O�_�w���L
						return 1;									//�Ϊ̳o�Ӥ�V�O�^�Y�����ܤ]����
		}															//�p�G4�Ӥ�V�����L�N�^��stack���ݪ����@�B
		if(MAZE[A+1][B]==0)
		{
				if(((A+1)!=topA->Y||B!=topA->X)&&markA[A+1][B]!=1)
						return 2;
		}
		if(MAZE[A-1][B]==0)
		{
				if(((A-1)!=topA->Y||B!=topA->X)&&markA[A-1][B]!=1)
						return 3;
		}
		if(MAZE[A][B-1]==0)
		{
				if((A!=topA->Y||(B-1)!=topA->X)&&markA[A][B-1]!=1)
						return 4;
		}
		return 0;
}
int DirB(int A,int B)			//ratB����V�P�_�ƨ禡,�X�G����ratA���@��
{
		if(MAZE[A][B-1]==0)
		{
				if((A!=topB->Y||(B-1)!=topB->X)&&markB[A][B-1]!=1)
						return 1;
		}
		if(MAZE[A-1][B]==0)
		{
				if(((A-1)!=topB->Y||B!=topB->X)&&markB[A-1][B]!=1)
						return 2;
		}
		if(MAZE[A+1][B]==0)
		{
				if(((A+1)!=topB->Y||B!=topB->X)&&markB[A+1][B]!=1)
						return 3;
		}
		if(MAZE[A][B+1]==0)
		{
				if((A!=topB->Y||(B+1)!=topB->X)&&markB[A][B+1]!=1)
						return 4;
		}
		return 0;
}
void moveA(int dir)			//ratA�����ʰƨ禡
{
		switch(dir)			//�ǥѦ^�Ǫ��Ʀr�ӨM�w�O�����Ӥ�V��
		{
				case 1:
						push(&topA,rowA,colA);		//�����e���N�{�b����m��istack
						colA+=1;					//�y���ܦ����ʹL�᪺�y��
						markA[rowA][colA]=1;		//�N���ʹL�᪺�o�@�Ӧ�m�@�W�O��
						break;
				case 2:
						push(&topA,rowA,colA);
						rowA+=1;
						markA[rowA][colA]=1;
						break;
				case 3:
						push(&topA,rowA,colA);
						rowA-=1;
						markA[rowA][colA]=1;
						break;
				case 4:
						push(&topA,rowA,colA);
						colA-=1;
						markA[rowA][colA]=1;
						break;
				case 0:
						rowA=topA->Y;				//�p�G��V�P�_�禡�^��0,�Y4�Ӥ�V�����ਫ
						colA=topA->X;				//�N�^��stack�����ݨ��@�B
						topA=topA->next;
						markA[rowA][colA]=1;
		}
}
void moveB(int dir)			//ratB�����ʰƨ禡
{
		switch(dir)			//�]�O����ratA���@��
		{
				case 1:
						push(&topB,rowB,colB);
						colB-=1;
						markB[rowB][colB]=1;
						break;
				case 2:
						push(&topB,rowB,colB);
						rowB-=1;
						markB[rowB][colB]=1;
						break;
				case 3:
						push(&topB,rowB,colB);
						rowB+=1;
						markB[rowB][colB]=1;
						break;
				case 4:
						push(&topB,rowB,colB);
						colB+=1;
						markB[rowB][colB]=1;
						break;
				case 0:
						rowB=topB->Y;
						colB=topB->X;
						topB=topB->next;
						markB[rowB][colB]=1;
		}
}
int main(int argc,char *argv[])
{
		char tmp[20];										//�ΨӨ�U�s��maze���}�C
		FILE *fp=fopen(argv[1],"r");						//�}�ɥH�ζ}�ɥ��Ѫ����ܱ��I
		if(!fp) {printf("File Opening Failed.\n");return 0;}
		while(fgets(tmp,20,fp))								//�}�ɫ�,�v��Ū�J
		{
				tmp[strlen(tmp)]='\0';						//�N���ݪ�\n�άO\0�令\0
				for(colA=1;colA<=maxsize;colA++)
				{
						MAZE[rowA][colA]=tmp[colA-1]-'0';	//�Nchar���A���ȴ�h'0'�Y�i�o��int���A����
						markA[rowA][colA]=MAZE[rowA][colA];	//��maze�ƻs�imarkA��B��
						markB[rowA][colA]=MAZE[rowA][colA];
				}
				rowA++;
		}
		for(rowA=0;rowA<maxsize+2;rowA++)					//�bmaze�g��\��(1)
		{													//�p����V�P�_�ƨ禡�i�H�٥h�ܦh�P�_�W�����D
				for(colA=0;colA<maxsize+2;colA++)
				{
						if(colA==0||colA==maxsize+1||rowA==0||rowA==maxsize+1)
						{
								MAZE[rowA][colA]=1;
								markA[rowA][colA]=1;
								markA[rowA][colA]=1;
						}
				}
		}
		ptr=(Node*)malloc(sizeof(Node));		//�إ�stack,�õ����_�I����m
		ptr->X=1;
		ptr->Y=1;
		ptr->next=NULL;
		topA=ptr;
		ptr=(Node*)malloc(sizeof(Node));
		ptr->X=15;
		ptr->Y=15;
		ptr->next=NULL;
		topB=ptr;
		rowA=1;
		colA=1;
		printf("ratA(%d,%d)\nratB(%d,%d)\n",rowA-1,colA-1,rowB-1,colB-1);
		while(1)								//�b�j��̤������i��
		{
				moveA(DirA(rowA,colA));			//�C���@�B�Nprint�X�L����m
				printf("ratA(%d,%d)\n",rowA-1,colA-1);
				if(rowA==rowB&&colA==colB)		//��ratA����m�ӧP�_�O�_�J��ratB,�H�F���פ������X�j��
				{
						printf("RatA and RatB meet at (%d,%d).\n",rowB-1,colB-1);
						break;
				}
				else if((rowA==15&&colA==15)||(rowB==1&&colB==1))	//�P�_�O�_�����@��rat����X�f
				{
						printf("Rats didn't find each other in this maze.\n");
						break;
				}
				moveB(DirB(rowB,colB));
				printf("ratB(%d,%d)\n",rowB-1,colB-1);
		}
		return 0;
}
