#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
		int N,i,j,a,b;
		char A[9],B[9];
		scanf(" %d",&N);
		for(i=0;i<N;i++){
			a=b=0;
			scanf("%s %s",A,B);
			for(j=0;j<8;j++){
				a=a+(A[j]-'0')*pow(2,7-j);
				b=b+(B[j]-'0')*pow(2,7-j);
}
		printf("%d\n",a+b);
}


	return 0;
}

