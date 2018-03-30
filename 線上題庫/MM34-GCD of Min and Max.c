#include<stdio.h>
#include<stdlib.h>
int myintcmp(const void*a,const void*b)
{
		return *((int*)a)-*((int*)b);
}
int main()
{
		int M,N,i,j,A[1001],x,div;
		scanf("%d",&N);
	for(i=0;i<N;i++)
{
		scanf(" %d",&M);
		x=0;
	for(j=0;j<M;j++)
		scanf(" %d",&A[x++]);
	qsort(A,x,sizeof(int),myintcmp);
	for(j=1;j<=A[x-1];j++)
		if(A[0]%j==0&&A[x-1]%j==0)
			div=j;
		printf("%d\n",div);
}

	return 0;
}

