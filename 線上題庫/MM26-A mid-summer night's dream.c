#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000 
int myintcmp(const void*a,const void*b)
{
		return *((int*)a)-*((int*)b);
}
int main()
{
		int n,check=0,i,count1,count2,*x,a;
	while(scanf("%d",&n)!=EOF){
	count1=count2=0;
	x=(int*)malloc(sizeof(int)*n); 
	for(i=0;i<n;i++)
		scanf(" %d",&x[i]);
	qsort(x,n,sizeof(int),myintcmp);
if(n%2==1){
	a=x[n/2];
	count2=1;
for(i=0;i<n;i++)
	if(x[i]==a)
		count1++;
}
else{
	a=x[n/2-1];
	count2=x[n/2]-x[n/2-1]+1;
for(i=0;i<n;i++)
	if(x[i]==a)
		count1++;
if(x[n/2-1]!=x[n/2])
	for(i=0;i<n;i++)
		if(x[i]==x[n/2])
		count1++;
}
/*for(i=0;i<n;i++)
	if(x[i]==a)
		count1++;*/

printf("%d %d %d\n",a,count1,count2);
}
	return 0;
}

