#include<stdio.h>
#include<stdlib.h>
int main()
{
		int m,n,b,i,j,k;
		scanf(" %d",&m);
		for(i=0;i<m;i++){
				scanf("%d %d",&n,&b);
				int A[1000];
				j=0;
				while(n>=b){
						A[j++]=(n%b);
						n/=b;
}
				A[j]=n;
				for(k=j;k>=0;k--){
				if(A[k]>=0&&A[k]<10)
					printf("%d",A[k]);
				else if(A[k]==10)
					printf("A");
				else if(A[k]==11)
					printf("B");
				else if(A[k]==12)
					printf("C");
				else if(A[k]==13)
					printf("D");
				else if(A[k]==14)
					printf("E");
				else if(A[k]==15)
					printf("F");
}
				printf("\n");
}

	return 0;
}

