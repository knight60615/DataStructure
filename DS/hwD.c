#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
struct move {  int vert;
               int horiz;
            };
struct position {  int row;
                   int col;
                   int direction;
                }A_stack[200],B_stack[200];

int A_top=0,B_top=0;

void A_push(struct position x)
{ if(A_top>=49) return;
  A_stack[++A_top]=x;
}

void B_push(struct position x)
{ if(B_top>=49) return;
  B_stack[++B_top]=x;
}

struct position A_pop(void)
{ if(A_top==-1) return;
  return A_stack[A_top--];
}

struct position B_pop(void)
{ if(B_top==-1) return;
  return B_stack[B_top--];
}

main()
{ FILE *fp;
  struct position temp;
  struct move A_move[4],B_move[4];
  char maze[15][17],buf[20];
  short int A_mark[15][15]={0},B_mark[15][15]={0};
  int i,nextrow,nextcol,A_row,A_col,A_direction,A_arrival=FALSE;
  int B_row,B_col,B_direction,B_arrival=FALSE;
  
  fp=fopen("maze.txt","r");
  for(i=0;i<15;i++) { fgets(buf,20,fp);
                      strcpy(maze[i],buf);
                     // printf("%s",maze[i]);
                    }

  A_mark[0][0]=1; B_mark[14][14]=1;
  A_stack[0].row=0; A_stack[0].col=0; A_stack[0].direction=0; 
  B_stack[0].row=14; B_stack[0].col=14;  B_stack[0].direction=0;
  
  A_move[0].vert=0; A_move[0].horiz=1;  
  A_move[1].vert=1; A_move[1].horiz=0;
  A_move[2].vert=-1; A_move[2].horiz=0;
  A_move[3].vert=0; A_move[3].horiz=-1;

  B_move[0].vert=0; B_move[0].horiz=-1;
  B_move[1].vert=-1; B_move[1].horiz=0;
  B_move[2].vert=1; B_move[2].horiz=0;
  B_move[3].vert=0; B_move[3].horiz=1;

  while((A_top>-1)&&(A_arrival==FALSE))
  { temp=A_pop();
    A_row=temp.row; 
    A_col=temp.col; 
    A_direction=temp.direction;
    while((A_direction<4)&&(A_arrival==FALSE))
    { nextrow=A_row+A_move[A_direction].vert; 
      nextcol=A_col+A_move[A_direction].horiz;
      if(nextrow==14&&nextcol==14) A_arrival=TRUE;
      else if(nextrow>=0&&nextrow<=14&&nextcol>=0&&nextcol<=14)
      { if(maze[nextrow][nextcol]=='0')
        { A_mark[A_row][A_col]=1;
          temp.row=A_row;
          temp.col=A_col;
          temp.direction=++A_direction;
          A_push(temp);
          A_row=nextrow;
          A_col=nextcol;
          A_direction=0;
          if(A_mark[nextrow][nextcol]==1)
          { for(i=A_top;i>=0;i--) if(A_stack[i].row==nextrow&&A_stack[i].col==nextcol) { A_direction=A_stack[i].direction; break;}
          }
        }
        else if(maze[nextrow][nextcol]=='1') ++A_direction;
      } 
      else ++A_direction;
    }
  }

  while((B_top>-1)&&(B_arrival==FALSE))
  { temp=B_pop();
    B_row=temp.row; 
    B_col=temp.col; 
    B_direction=temp.direction;
    while((B_direction<4)&&(B_arrival==FALSE))
    { nextrow=B_row+B_move[B_direction].vert;
  	  nextcol=B_col+B_move[B_direction].horiz;
      if(nextrow==14&&nextcol==14) B_arrival=TRUE;
  	  else if(nextrow>=0&&nextrow<=14&&nextcol>=0&&nextcol<=14)
  	  { if(maze[nextrow][nextcol]=='0')
  	    { B_mark[B_row][B_col]=1;  	      
  	      temp.row=B_row;
  	      temp.col=B_col;
  	      temp.direction=++B_direction;
  	      B_push(temp);
  	      B_row=nextrow;
  	      B_col=nextcol;
  	      B_direction=0;
  	      if(B_mark[nextrow][nextcol]==1)
          { for(i=B_top;i>=0;i--) if(B_stack[i].row==nextrow&&B_stack[i].col==nextcol) { B_direction=B_stack[i].direction; break;}
          }
  	    }
        else if(maze[nextrow][nextcol]=='1') ++B_direction;
  	  }
  	  else  ++B_direction;  
  	}
  }		

   if(A_arrival==TRUE)
   { for(i=0;i<=A_top;i++) printf("ratA(%d,%d)\n",A_stack[i].row,A_stack[i].col);
     printf("ratA(%d,%d)\n",A_row,A_col);
     printf("ratA(14,14)\n");
   }
  










}
  











