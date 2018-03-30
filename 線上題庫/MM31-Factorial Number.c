#include<stdio.h>
#include<stdlib.h>
int main()
{
		int M,n,i,j,sum;
		scanf("%d",&M);
		for(i=0;i<M;i++){
				scanf("%d",&n);
				sum=1;
				for(j=1;j<=n;j++)
					sum*=j;
				printf("%d\n",sum);
}

	return 0;
}

