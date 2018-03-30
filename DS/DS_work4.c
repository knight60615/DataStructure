#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
struct stack{		//存放老鼠路徑
		int row;
		int col;
		int dir;
}pathA[225],pathB[225],positionA[225],positionB[225];
int topA=0,topB=0,topAA=-1,topBB=-1;
struct move{
		int vert;
		int horiz;
};
void pushA(struct stack x)
{ if(topA>=224) return;
		pathA[++topA]=x;
}

void pushB(struct stack x)
{ if(topB>=224) return;
		pathB[++topB]=x;
}

void pushAA(struct stack x)		//真路徑
{ if(topAA>=224) return;
		positionA[++topAA]=x;
}

void pushBB(struct stack x)		//真路徑
{ if(topBB>=224) return;
		positionB[++topBB]=x;
}

struct stack popA(void)
{ if(topA==-1) return;
		return pathA[topA--];
}

struct stack popB(void)
{ if(topB==-1) return;
		return pathB[topB--];
}
int main()
{
		char maze[18][18];
		int mark[18][18];
		char buf[20];
		struct move moveA[4],moveB[4];
		int i,j,rowA,colA,dirA,rowB,colB,dirB,nextrow,nextcol,found;
		FILE *fp;
		struct stack temp;
		i=0;
		fp=fopen("maze.txt","r");
		while(fgets(buf,20,fp)) {
				strcpy(maze[i],buf);
				i++;
		}
		pathA[0].row=pathA[0].col=pathA[0].dir=pathB[0].dir=rowA=colA=dirA=dirB=0;
		pathB[0].row=pathB[0].col=rowB=colB=14;
		for(i=0;i<18;i++){
				for(j=0;j<18;j++)
						mark[i][j]=0;
		}

		moveA[0].vert=0;	moveA[0].horiz=1;
		moveA[1].vert=1;	moveA[1].horiz=0;
		moveA[2].vert=-1;	moveA[2].horiz=0;
		moveA[3].vert=0;	moveA[3].horiz=-1;

		moveB[0].vert=0;	moveB[0].horiz=-1;
		moveB[1].vert=-1;	moveB[1].horiz=0;
		moveB[2].vert=1;	moveB[2].horiz=0;
		moveB[3].vert=0;	moveB[3].horiz=1;


		/*A老鼠走迷宮*/
		found=FALSE;
		mark[0][0]=1;
		while(topA>-1&&!found){
				temp=popA();
				rowA=temp.row;
				colA=temp.col;
				dirA=temp.dir;
				pushAA(temp);		//為了在真路徑存起點和遇到死路回頭的所有點
				while(dirA<4&&!found){		//依照方向修先順序嘗試
						nextrow=rowA+moveA[dirA].vert;
						nextcol=colA+moveA[dirA].horiz;
						if(nextrow==14&&nextcol==14){
								found=TRUE;
								temp.row=nextrow;
								temp.col=nextcol;
								pushAA(temp);		//真路徑之最後一步
						}
						else if(maze[nextrow][nextcol]=='0'&&mark[nextrow][nextcol]!=1){
								mark[nextrow][nextcol]=1;
								temp.row=rowA;
								temp.col=colA;
								temp.dir=++dirA;
								pushA(temp);		//走之前先將現在的位置放進stack
								rowA=nextrow;
								colA=nextcol;
								temp.row=rowA;
								temp.col=colA;
								pushAA(temp);		//走完存到真路徑
								dirA=0;
						}
						else
								++dirA;
						}		//假如都不通代表遇死路,跳出迴圈pop掉stack頂端位置繼續嘗試


				}


				/*B老鼠走迷宮*/
				for(i=0;i<18;i++){
						for(j=0;j<18;j++)
								mark[i][j]=0;
				}
				found=FALSE;
				mark[14][14]=1;
				while(topB>-1&&!found){
						temp=popB();
						rowB=temp.row;
						colB=temp.col;
						dirB=temp.dir;
						pushBB(temp);
						while(dirB<4&&!found){
								nextrow=rowB+moveB[dirB].vert;
								nextcol=colB+moveB[dirB].horiz;
								if(nextrow==0&&nextcol==0){
										found=TRUE;
										temp.row=nextrow;
										temp.col=nextcol;
										pushBB(temp);
								}
								else if(maze[nextrow][nextcol]=='0'&&mark[nextrow][nextcol]!=1){
										mark[nextrow][nextcol]=1;
										temp.row=rowB;
										temp.col=colB;
										temp.dir=++dirB;
										pushB(temp);
										rowB=nextrow;
										colB=nextcol;
										temp.row=rowB;
										temp.col=colB;
										pushBB(temp);
										dirB=0;
								}
								else
										++dirB;
						}


				}
				/*for(i=0;i<=topAA;i++){
				  printf("A(%d,%d)\n",positionA[i].row,positionA[i].col);
				  }
				  for(i=0;i<=topBB;i++){
				  printf("B(%d,%d)\n",positionB[i].row,positionB[i].col);
				  }*/
				i=j=0;
				while(i<=topAA&&j<=topBB){		//印出老鼠路徑,順便在此判斷相遇與否,若相遇就中斷列印
						printf("ratA(%d,%d)\n",positionA[i].row,positionA[i].col);
						printf("ratB(%d,%d)\n",positionB[j].row,positionB[j].col);
						i++;
						if(i==topAA||(positionA[i].row==positionB[j].row&&positionA[i].col==positionB[j].col)){
								printf("ratA(%d,%d)\n",positionA[i].row,positionA[i].col);
								printf("ratB(%d,%d)\n",positionB[j].row,positionB[j].col);
								break;
						}
						j++;
						if((positionA[i].row==positionB[j].row&&positionA[i].col==positionB[j].col)){
								printf("ratA(%d,%d)\n",positionA[i].row,positionA[i].col);
								printf("ratB(%d,%d)\n",positionB[j].row,positionB[j].col);
								break;
						}
				}
				if(positionA[i].row==positionB[j].row&&positionA[i].col==positionB[j].col)
						printf("rats ecounter each other in(%d,%d)\n",positionA[i].row,positionA[i].col);

				else
						printf("Rats didn't find each other in this maze.\n");






				return 0;
		}
