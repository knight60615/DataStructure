#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
int myintcmp(const void*a,const void*b)
{
		return *((int*)a)-*((int*)b);
}
int main()
{
	int n,A[MAX],i=0;
	while(scanf("%d",&n)!=EOF){
			A[i++]=n;
}
	qsort(A,i,sizeof(int),myintcmp);
	printf("Median="); 
	if(i%2==1)
		printf("%d\n",A[i/2]);
	else{
		if((A[i/2-1]+A[i/2])%2!=0)
		printf("%.1f\n",(float)(A[i/2-1]+A[i/2])/2.0);
		else
		printf("%d\n",(A[i/2-1]+A[i/2])/2);

}
	return 0;
}

