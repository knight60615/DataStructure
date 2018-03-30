#include<stdio.h>
#include<stdlib.h>
int myintcmp(const void*a,const void*b)
{
		return *((int*)a)-*((int*)b);
}
int main()
{
		int Q1,Q2,R1,R2,D=0,i,j,A[100],B[100],m=0,n=0;
		scanf("%d %d %d %d",&Q1,&R1,&Q2,&R2);
		Q1=Q1-R1;
		Q2=Q2-R2;
		for(i=1;i<=Q1;i++){
			if(Q1%i==0)
				A[m++]=i;	
}
		for(i=1;i<=Q2;i++){
			if(Q2%i==0)
				B[n++]=i;	
}
		qsort(A,m,sizeof(int),myintcmp);
		qsort(B,n,sizeof(int),myintcmp);
		if(A[m-1]>B[n-1]){
			for(i=m-1;i>=0;i--){
				for(j=0;j<=n-1;j++)	{
				if(A[i]==B[j]){
					D=A[i];
					break;
}}
				if(D!=0)
					break;
}
}
		else if(A[m-1]<B[n-1]){
	for(i=n-1;i>=0;i--){
				for(j=0;j<=m-1;j++)	{
				if(B[i]==A[j]){
					D=B[i];
					break;
}}
				if(D!=0)
					break;
}
}
		for(i=1;i<D;i++)
			if(D%i==0)
				printf("%d ",i);
		printf("%d\n",D);

	return 0;
}

