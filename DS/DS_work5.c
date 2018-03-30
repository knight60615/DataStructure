#include<stdio.h>
#include<stdlib.h>
#define MAX 127
struct tnode{
		int num;
		struct tnode *lc;
		struct tnode *rc;
};
int front,rear;
int heap[MAX];
struct tnode queue[MAX];
void addq(struct tnode *item)
{
		rear=(rear+1)%MAX;
		if(front==rear)
				printf("queue is full\n");
		else
				queue[rear]=*item;
}
struct tnode *deleteq(){
		if(front==rear){
				return 0;
		}
		else{
				front=(front+1)%MAX;
				return &queue[front];
		}
}
struct tnode *insert(struct tnode *tp,int data){
		struct tnode *temp;
		temp=(struct tnode*)malloc(sizeof(struct tnode));
		if(tp==NULL){
				temp->num=data;
				temp->lc=NULL;
				temp->rc=NULL;		//initialize temp
				return temp;
		}
		if (tp->num>data)
				tp->lc=insert(tp->lc,data);
		else if(tp->num<data)
				tp->rc=insert(tp->rc,data);
		return tp;
}
struct tnode *find(struct tnode *tp,int data){
		if(tp==NULL)
				return NULL;
		else if (tp->num==data)
				return tp;
		else if (tp->num>data)
				return find(tp->lc,data);
		else
				return find(tp->rc,data);
}
struct tnode *delete(struct tnode *root,int data) {
		struct tnode *temp;
		if (root==NULL) {
				printf("%d  does not exist in this binary tree\n",data);
				return NULL;
		} else if (root->num>data)
				root->lc=delete(root->lc,data);
		else if (root->num<data)
				root->rc=delete(root->rc,data);
		else {
				if (root->lc && root->rc) { //two children
						temp=root->rc;
						while(temp->lc!=NULL){     //���^��|��X�k��̤p���`�I
								temp=temp->lc;
						}

						root->num=temp->num;
						root->lc=delete(root->lc,root->num);
				}else{ // one child or no child
						if (root->lc==NULL)
								root=root->rc;
						else if (root->rc==NULL)
								root=root->lc;
				}}
		return root;	

}
void infixorder(struct tnode *tp){
		if(tp){
				infixorder(tp->lc);		
				printf("%d ",tp->num);	
				infixorder(tp->rc);
		}
}
void levelorder(struct tnode *ptr){
		front=rear=0;
		if(!ptr)
				return; /*�Ū���*/
		addq(ptr);
		while(1){
				ptr=deleteq();
				if(ptr){
						printf("%d ",ptr->num);
						if(ptr->lc)
								addq(ptr->lc);
						if(ptr->rc)
								addq(ptr->rc);
				}
				else
						break;
		}

}
int push(int item,int n){		//�ⶵ�إ[��ثe�j�p�On��max heap
		int i;
		if(n==MAX){
				printf("full\n");
				return n;
		}
		i=++n;
		while((i!=1)&&(item>heap[i/2])){	//�q�̫�}�l��,��parent�j�N��parent���U��
				heap[i]=heap[i/2];
				i/=2;
		}
		heap[i]=item;
		return n;		//�^�Ǥj�p
}
int pop(int n){		//�qmax heap���R���̤j������
		int parent,child;
		int temp;
		if(n==0){
				printf("the queue is empty.\n");
				return n;
		}
		temp=heap[n--];	//�γ̫�@�Өӽվ���n,���s�X��
		parent=1;
		child=2;
		while(child<=n){
				if((child<n)&&heap[child]<heap[child+1])	//�q�ثe�����`�I��̤j�l�`�I
						child++;
				if(temp>heap[child])	//�N��temp(�̥���)�O�ѤU�̤j��
						break;
				/*�i��U���q,���쪺�l�`�I���W��*/
				heap[parent]=heap[child];
				parent=child;		//�~�򩹤U,�@�����U�h
				child*=2;
		}
		heap[parent]=temp;	//�@��������̥����^��
		return n;
}
int main()
{
		int input,size=0,i;
		char c;
		struct tnode *tree=NULL;
		struct tnode *p;
		while(1){
				printf("BST\n<I>nsert a number.\n<D>elete a number.\n<S>earch a number.\n<P>rint in infix&level order.\n");
				scanf(" %c",&c);
				switch(c){
						case'I':scanf(" %d",&input);
								tree=insert(tree,input);
								break;
						case'D':scanf(" %d",&input);
								delete(tree,input);
								break;
						case'S':printf("input the number you want to search:\n");
								scanf(" %d",&input);
								p=find(tree,input);
								if(!p)
										printf("not found.\n");
								else
										printf("found.\n");
								break;
						case'P':printf("The tree in infix order:");
								infixorder(tree);
								printf("\nThe tree in level order:");
								levelorder(tree);
								printf("\n");
								break;
						default:c='Q';
								break;
				}
				if(c=='Q')
						break;
		}

		while(1){
				printf("heap\n<I>nsert a number.\n<D>elete a max number.\n<P>rint the heap queue.\n");
				scanf(" %c",&c);
				switch(c){
						case'I':scanf(" %d",&input);
								size=push(input,size);
								break;
						case'D':size=pop(size);
								break;
						case'P':printf("The data in the heap queue:");
								for(i=1;i<=size;i++){
										printf("%d ",heap[i]);
								}
								printf("\n");
								break;
						default:c='Q';
								break;
				}
				if(c=='Q')
						break;

		}

		return 0;
}
