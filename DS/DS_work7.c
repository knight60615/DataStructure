#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
void swap(int *a,int *b){
		int temp;
		temp=*a;
		*a=*b;
		*b=temp;
}
void adjust(int num[],int root,int n){
		int child,temp;
		temp=num[root];
		child=2*root;		//���l��
		while(child<=n){
				if(child<n&&num[child]<num[child+1])
						child++;
				if(num[root]>num[child])	//�����کM�̤j�l��
						break;
				else{
						num[child/2]=num[child];	//���ʦ����`�I
						child*=2;
				}
		}
		num[child/2]=temp;
}
void quicksort(int num[],int left,int right){
		int pivot,i,j;
		if(left<right){
				i=left;
				j=right+1;
				pivot=num[left];
				do{	/*��X����>pivot�M�k��<pivot����m,�p�G�����m�C��k��N�洫*/
						do i++;	while(num[i]<pivot);
						do j--;	while(num[j]>pivot);
						if(i<j)	swap(&num[i],&num[j]);
				}while(i<j);
						swap(&num[left],&num[j]);
						quicksort(num,left,j-1);
						quicksort(num,j+1,right);
		}
}
void heapSort(int num[],int n){
		int i;
		for(i=n/2;i>0;i--)		//�����nmax heap
				adjust(num,i,n);
		for(i=n-1;i>0;i--){		//���ƥH�U�ʧ@
				swap(&num[1],&num[i+1]);	//��̤j�ȸ�̫�@�Ӹ`�I�洫
				adjust(num,1,i);		//�ѤU���@max heap
		}
}
void radixSort(int num[],int n){	//�H10�����
		int temp[10][n],order[10];	//order����10�Ӯe��,�ȥN��e���̪��Ӽ�
		int d=1,i,j,k,lsd;
		for(i=0;i<10;i++)
				order[i]=0;
		while(d<=1000){
				for(i=0;i<n;i++){		//�Ƨ�
						lsd=(num[i]/d)%10;
						temp[lsd][order[lsd]]=num[i];
						order[lsd]++;
				}
				k=0;
				for(i=0;i<10;i++){		//���s�ƦC
						if(order[i]!=0)
								for(j=0;j<order[i];j++)
										num[k++]=temp[i][j];
						order[i]=0;
				}
				d*=10;		//�U�@��,���e�@��
		}
}
int main()
{
		int n,i,inputr[MAX],inputq[MAX],inputh[MAX];
		char input[MAX],*p;
		scanf("%d ",&n);
keyin:	gets(input);
		/*for(i=0;i<n;i++){
				scanf("%d",&inputr[i]);
				inputq[i]=inputh[i+1]=inputr[i];
		}*/
		for(i=0;i<strlen(input);i++){		//�p�G���O�Ʀr�ΪŮ�N���J�X�k
				if(input[i]-'0'>=0&&input[i]-'0'<=9)
				{}
				else if(input[i]==' ')
				{}
				else
						break;
		}
		if(i!=strlen(input))	//�p�G��J�X�ki�|����strlen(input)
				goto keyin;
		i=0;
		p=strtok(input," ");
		while(p!=NULL){
			inputq[i]=inputh[i+1]=inputr[i]=atoi(p);
			p=strtok(NULL," ");
			i++;
		}
		quicksort(inputq,0,n-1);
		heapSort(inputh,n);
		radixSort(inputr,n);
		printf("quicksort:");
		for(i=0;i<n;i++)
				printf("%d ",inputq[i]);
		printf("\n");
		printf("heapsort:");
		for(i=1;i<n+1;i++)
				printf("%d ",inputh[i]);
		printf("\n");
		printf("radixsort:");
		for(i=0;i<n;i++)
				printf("%d ",inputr[i]);
		printf("\n");

		return 0;
}

