#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 14000
unsigned int hash(int input){
		unsigned int hv;
		hv=input%size;
		return hv;
}
int bucket[size];
struct CollisionNode{			//用來存放collision的資料的Linked List,不用array是因為我根本不知道會collision幾筆
		int data;
		struct CollisionNode *link;
};
int col=0;
void collision(struct CollisionNode *p){	//collision的所有資料用這個function找空格放
		int x=0;
		struct CollisionNode *q;
		while(x<size&&p!=NULL)
		{
				if(bucket[x]==-1)
				{
						bucket[x]=p->data;
						q=p;
						p=p->link;
						free(q);
				}
				else
						col++;
				x++;
		}
}
int main()
{
		FILE *fp;
		char file[20];
		int buf,value,i;
		float score;
		struct CollisionNode *node=NULL;
		struct CollisionNode *p,*q;
		for(i=0;i<=size;i++){			//initialize
				bucket[i]=-1;
		}
		printf("please input the file's name:");
		scanf("%s",file);
		fp=fopen(file,"r");
		while(fscanf(fp,"%d",&buf)!=EOF)
		{
				value=hash(buf);
				if(bucket[value]==-1)		//代表空的,放入
						bucket[value]=buf;
				else{						//collision了,先存起來
						p=(struct CollisionNode*)malloc(sizeof(struct CollisionNode));
						p->data=buf;
						p->link=NULL;
						if(node==NULL){
								node=p;
								q=p;
						}
						else{
								q->link=p;
								q=p;
						}
						col++;
				}
		}
		collision(node);
		score=(10000.0/size)/(col+1);
		printf("in bucket:10000\ntable size:%d\ncollision times:%d\nperformance scores:%.6f\n",size,col,score);



		return 0;
}
