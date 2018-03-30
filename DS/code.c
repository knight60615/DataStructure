#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 15					//統一定義maze尺寸
typedef struct Node {				//stack的型態定義
		int X;
		int Y;
		struct Node *next;
}Node;
Node *topA=NULL;					//topA是給ratA用的stack,topB是給ratB用的
Node *topB=NULL;
Node *ptr=NULL;						//協助操作的pointer
int MAZE[maxsize+2][maxsize+2];		//存放maze本體的二維陣列
int markA[maxsize+2][maxsize+2];	//markA跟B都是用來記錄走過的點
int markB[maxsize+2][maxsize+2];
int rowA=1,colA=1;					//2組數字用來表示座標
int rowB=15,colB=15;
void push(Node **top,int A,int B)	//將新座標放進stack的push函式
{
		ptr=malloc(sizeof(Node));
		ptr->Y=A;
		ptr->X=B;
		ptr->next=*top;
		*top=ptr;
}
int DirA(int A,int B)				//ratA的方向判斷副函式
{
		if(MAZE[A][B+1]==0)			//先判斷這個方向能不能走
		{
				if((A!=topA->Y||(B+1)!=topA->X)&&markA[A][B+1]!=1)	//再判斷這個方向走出去的那一步是否已走過
						return 1;									//或者這個方向是回頭路的話也不走
		}															//如果4個方向都走過就回到stack頂端的那一步
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
int DirB(int A,int B)			//ratB的方向判斷副函式,幾乎都跟ratA的一樣
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
void moveA(int dir)			//ratA的移動副函式
{
		switch(dir)			//藉由回傳的數字來決定是往哪個方向走
		{
				case 1:
						push(&topA,rowA,colA);		//走之前先將現在的位置放進stack
						colA+=1;					//座標變成移動過後的座標
						markA[rowA][colA]=1;		//將移動過後的這一個位置作上記號
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
						rowA=topA->Y;				//如果方向判斷函式回傳0,即4個方向都不能走
						colA=topA->X;				//就回到stack的頂端那一步
						topA=topA->next;
						markA[rowA][colA]=1;
		}
}
void moveB(int dir)			//ratB的移動副函式
{
		switch(dir)			//也是都跟ratA的一樣
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
		char tmp[20];										//用來協助存放maze的陣列
		FILE *fp=fopen(argv[1],"r");						//開檔以及開檔失敗的應變措施
		if(!fp) {printf("File Opening Failed.\n");return 0;}
		while(fgets(tmp,20,fp))								//開檔後,逐行讀入
		{
				tmp[strlen(tmp)]='\0';						//將尾端的\n或是\0改成\0
				for(colA=1;colA<=maxsize;colA++)
				{
						MAZE[rowA][colA]=tmp[colA-1]-'0';	//將char型態的值減去'0'即可得到int型態的值
						markA[rowA][colA]=MAZE[rowA][colA];	//把maze複製進markA跟B中
						markB[rowA][colA]=MAZE[rowA][colA];
				}
				rowA++;
		}
		for(rowA=0;rowA<maxsize+2;rowA++)					//在maze週圍蓋牆(1)
		{													//如此方向判斷副函式可以省去很多判斷上的問題
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
		ptr=(Node*)malloc(sizeof(Node));		//建立stack,並給予起點的位置
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
		while(1)								//在迴圈裡不停的進行
		{
				moveA(DirA(rowA,colA));			//每走一步就print出他的位置
				printf("ratA(%d,%d)\n",rowA-1,colA-1);
				if(rowA==rowB&&colA==colB)		//用ratA的位置來判斷是否遇見ratB,以達成終止條件跳出迴圈
				{
						printf("RatA and RatB meet at (%d,%d).\n",rowB-1,colB-1);
						break;
				}
				else if((rowA==15&&colA==15)||(rowB==1&&colB==1))	//判斷是否有哪一隻rat走到出口
				{
						printf("Rats didn't find each other in this maze.\n");
						break;
				}
				moveB(DirB(rowB,colB));
				printf("ratB(%d,%d)\n",rowB-1,colB-1);
		}
		return 0;
}
