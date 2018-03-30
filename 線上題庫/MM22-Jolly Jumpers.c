#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int myintcmp(const void*a,const void*b)
{
		return *((int*)a)-*((int*)b);
}
int main()
{
		int n,i,A[3000],B[3000],C[3000],state;
		while(scanf("%d",&n)!=EOF){
			for(i=0;i<n;i++)
				scanf(" %d",&A[i]);
			for(i=0;i<n-1;i++){
				B[i]=i+1;
				C[i]=abs(A[i]-A[i+1]);
}
			qsort(C,n-1,sizeof(int),myintcmp);
			state=1;
			for(i=0;i<n-1;i++){
				if(B[i]!=C[i]){
					state=0;
					break;
}}
			if(state==0)
				printf("Not jolly\n");
			else if(state==1)
				printf("Jolly\n");
}

	return 0;
}

