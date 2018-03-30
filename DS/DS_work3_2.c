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
struct CollisionNode{			//�ΨӦs��collision����ƪ�Linked List,����array�O�]���ڮڥ������D�|collision�X��
		int data;
		struct CollisionNode *link;
};
int col=0;
void collision(struct CollisionNode *p){	//collision���Ҧ���ƥγo��function��Ů��
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
				if(bucket[value]==-1)		//�N��Ū�,��J
						bucket[value]=buf;
				else{						//collision�F,���s�_��
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
