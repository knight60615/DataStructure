#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000
int myintcmp(const void*a,const void*b)
{
		return *((int*)a)-*((int*)b);
}
int main()
{
	char input[MAX],temp[MAX];
	int A[MAX],i,j,k,B[MAX],m,n;
	while(gets(input)!=NULL){
		i=j=0;
while(input[i]!='\0'){
	k=0;
		while(input[i]!=' '){
			
			temp[k++]=input[i];
			i++;
}
temp[k++]='\0';
A[j++]=atoi(temp);
i++;
}
qsort(A,j,sizeof(int),myintcmp);
m=0;
for(i=0;i<MAX;i++)
B[i]=0; 
for(i=1;i<j;i++){
		if(i==1){
			for(k=2;k<=A[0];k++)
				if(A[i]%k==0)
					B[m++]=k;
}
		else{
			n=0;
			for(k=0;k<m;k++)
				if(A[i]%B[k]==0)
					B[n++]=B[k];
			m=n;
}
}
printf("Common factor in ascending order:");
for(i=0;i<m;i++)
printf("%d ",B[i]);
printf("\n");

}
	return 0;
}

