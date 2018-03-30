#include<stdio.h>
#include<stdlib.h>
struct key{
	int num;
	int count;
	struct key *next;
};
struct key *search(struct key *A,int data){
		struct key *ptr=A;
		while(ptr!=NULL) {
				if(ptr->num==data)//找到
						return ptr;
				else 						//沒找到
						ptr=ptr->next;
		} return NULL;			//全部找完都沒找到
}
struct key *insert(struct key *A,int data){
		struct key *ptr=(struct key*)malloc(sizeof(struct key));
		ptr->num=data;
		ptr->count=1;
		ptr->next=A;
		A=ptr;
		return A;
}
int main()
{
		int n,i=0,maxn=0,maxc=0;
		struct key *input=NULL,*p;
		while(scanf("%d",&n)!=EOF){
			i++;
			if((p=search(input,n))==NULL)
				input=insert(input,n);
			else 
				p->count++;
}
	for(p=input;p!=NULL;p=p->next){
			if(p->count>maxc){
				maxn=p->num;
				maxc=p->count;
} 
}
int same=0;
	for(p=input;p!=NULL;p=p->next){ 
			if(p->count==maxc)
				same++;
} 
		/*if(i%2==0)
			i=i/2;
		else
			i=i/2+1;
		if(maxc>=i&&same==1)
			printf("Majority is %d\n",maxn);
		else
			printf("No Majority\n");*/
		if(maxc<(i/2)||same>1)
			 printf("No Majority\n");
		else
			printf("Majority is %d\n",maxn);
	return 0;
}

