#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct PolynomialNode *listpointer;
struct PolynomialNode{ 
		float coef; 
		int exponent; 
		struct PolynomialNode *link; 
};
void Attach(listpointer *first,char *file){
		struct PolynomialNode *p,*q;
		float buf1;
		int buf2;
		FILE *fp;
		fp=fopen(file,"r");
		while(fscanf(fp,"%f %d",&buf1,&buf2)!=EOF){	
				if(*first){			//first不是空的
						q=(struct PolynomialNode*)malloc(sizeof(struct PolynomialNode));
						q->coef=buf1;
						q->exponent=buf2;
						q->link=p->link;
						p->link=q;
						p=q;
				}
				else{				//first是空的(第一筆)
						p=(struct PolynomialNode*)malloc(sizeof(struct PolynomialNode));
						p->coef=buf1;
						p->exponent=buf2;
						p->link=NULL;
						(*first)=p;
				}

		}
}
struct PolynomialNode **PolyAdd(listpointer A,listpointer B,listpointer *first){
		listpointer p,q;
		while(A!=NULL&&B!=NULL){	//AB其中一個或同時用完前
				if(*first){			//first不是空的
						q=(struct PolynomialNode*)malloc(sizeof(struct PolynomialNode));
						if(A->exponent>B->exponent)
						{
								q->coef=A->coef;
								q->exponent=A->exponent;
								A=A->link;
								q->link=p->link;
								p->link=q;
								p=q;
						}
						else if(A->exponent<B->exponent)
						{
								q->coef=B->coef;
								q->exponent=B->exponent;
								B=B->link;
								q->link=p->link;
								p->link=q;
								p=q;
						}
						else
						{
								q->coef=(A->coef+B->coef);
								q->exponent=A->exponent;
								A=A->link;
								B=B->link;
								q->link=p->link;
								p->link=q;
								p=q;
						}
				}
				else{			//first是空的(第一筆)
						p=(struct PolynomialNode*)malloc(sizeof(struct PolynomialNode));
						if(A->exponent>B->exponent)
						{
								p->coef=A->coef;
								p->exponent=A->exponent;
								A=A->link;
								p->link=NULL;
								(*first)=p;
						}
						else if(A->exponent<B->exponent)
						{
								p->coef=B->coef;
								p->exponent=B->exponent;
								B=B->link;
								p->link=NULL;
								(*first)=p;
						}
						else
						{
								p->coef=(A->coef+B->coef);
								p->exponent=A->exponent;
								A=A->link;
								B=B->link;
								p->link=NULL;
								(*first)=p;
						}
				}

		}
		while(B!=NULL)		//A用完
		{
				q=(struct PolynomialNode*)malloc(sizeof(struct PolynomialNode));
				q->coef=B->coef;
				q->exponent=B->exponent;
				B=B->link;
				q->link=p->link;
				p->link=q;
				p=q;
		}
		while(A!=NULL)		//B用完
		{
				q=(struct PolynomialNode*)malloc(sizeof(struct PolynomialNode));
				q->coef=A->coef;
				q->exponent=A->exponent;
				A=A->link;
				q->link=p->link;
				p->link=q;
				p=q;
		}
		return first;
}
void printPoly(struct PolynomialNode *A){
		struct PolynomialNode *p;
		for(p=A;p->link!=NULL;p=p->link)
				printf("%.1fx^%d+",p->coef,p->exponent);
		if(p->exponent==0)
				printf("%.1f\n",p->coef);
		else
				printf("%.1fx^%d\n",p->coef,p->exponent);
}
void CircularListPolyAttach(listpointer *first,char *file){
		struct PolynomialNode *p,*q;
		float buf1;
		int buf2;
		FILE *fp;
		fp=fopen(file,"r");
		/*製作一個標頭節點，值是亂設的因為不重要*/
		p=(struct PolynomialNode*)malloc(sizeof(struct PolynomialNode));
		p->exponent=-1;
		p->link=p;
		(*first)=p;
		while(fscanf(fp,"%f %d",&buf1,&buf2)!=EOF){	
				q=(struct PolynomialNode*)malloc(sizeof(struct PolynomialNode));
				q->coef=buf1;
				q->exponent=buf2;
				q->link=p->link;
				p->link=q;
				p=q;
		}
}
void CircularListprintPoly(struct PolynomialNode *A){
		struct PolynomialNode *p;
		for(p=A->link;p->link!=A;p=p->link)		//因為有標頭節點所以從第二個節點開始印
				printf("%.1fx^%d+",p->coef,p->exponent);
		if(p->exponent==0)
				printf("%.1f\n",p->coef);
		else
				printf("%.1fx^%d\n",p->coef,p->exponent);
}
struct PolynomialNode **CircularListPolyAdd(listpointer A,listpointer B,listpointer *first){
		listpointer p,q,x,y;
		/*製作一個標頭節點，值是亂設的因為不重要*/
		p=(struct PolynomialNode*)malloc(sizeof(struct PolynomialNode));
		p->exponent=-1;
		p->link=p;
		(*first)=p;
		x=A;	//記錄AB起點
		y=B;
		A=A->link;		//跳過標頭節點
		B=B->link;
		while(A!=x&&B!=y){
				q=(struct PolynomialNode*)malloc(sizeof(struct PolynomialNode));
				if(A->exponent>B->exponent)
				{
						q->coef=A->coef;
						q->exponent=A->exponent;
						A=A->link;
						q->link=p->link;
						p->link=q;
						p=q;
				}
				else if(A->exponent<B->exponent)
				{
						q->coef=B->coef;
						q->exponent=B->exponent;
						B=B->link;
						q->link=p->link;
						p->link=q;
						p=q;

				}
				else
				{
						q->coef=(A->coef+B->coef);
						q->exponent=A->exponent;
						A=A->link;
						B=B->link;
						q->link=p->link;
						p->link=q;
						p=q;

				}
		}


		while(B!=y)
		{
				q=(struct PolynomialNode*)malloc(sizeof(struct PolynomialNode));
				q->coef=B->coef;
				q->exponent=B->exponent;
				B=B->link;
				q->link=p->link;
				p->link=q;
				p=q;
		}
		while(A!=x)
		{
				q=(struct PolynomialNode*)malloc(sizeof(struct PolynomialNode));
				q->coef=A->coef;
				q->exponent=A->exponent;
				A=A->link;
				q->link=p->link;
				p->link=q;
				p=q;
		}
		return first;
}
int main()
{
		listpointer *node1,*node2,*node3,*node4,*node5,*node6;
		node1=node2=node3=node4=node5=node6=NULL;
		node1=(listpointer*)malloc(sizeof(listpointer));
		node2=(listpointer*)malloc(sizeof(listpointer));
		node3=(listpointer*)malloc(sizeof(listpointer));
		node4=(listpointer*)malloc(sizeof(listpointer));
		node5=(listpointer*)malloc(sizeof(listpointer));
		node6=(listpointer*)malloc(sizeof(listpointer));
		Attach(node1,"1.txt");
		Attach(node2,"2.txt");
		printf("A(x)=");
		printPoly(*node1);
		printf("B(x)=");
		printPoly(*node2);
		node3=PolyAdd(*node1,*node2,node3);
		printf("C(x)=");
		printPoly(*node3);
		CircularListPolyAttach(node4,"3.txt");
		printf("D(x)=");
		CircularListprintPoly(*node4);
		CircularListPolyAttach(node5,"4.txt");
		printf("E(x)=");
		CircularListprintPoly(*node5);
		node6=CircularListPolyAdd(*node4,*node5,node6);
		printf("F(x)=");
		CircularListprintPoly(*node6);

		return 0;
}
