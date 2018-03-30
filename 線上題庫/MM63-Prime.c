#include<stdio.h>
#include<stdlib.h>
#define MAX 100 
int main()
{
		int N,i,j=0,a[MAX],b[MAX];
		scanf("%d",&N);
		for(i=0;i<MAX;i++)
			a[i]=b[i]=0;
		for(i=2;i<=N;i++){
				if(N%i==0){
					a[j]=i;
					b[j]++;
					N=N/i;
					i--;
}
				else if(b[j]!=0)
					j++;
}
		for(i=0;i<j;i++)
			printf("%d^%d x ",a[i],b[i]);
		printf("%d^%d\n",a[i],b[i]);
	return 0;
}

