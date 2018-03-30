#include<stdio.h>
#include<stdlib.h>
int recursive(int n){
if(n==1)
	return 1;
else if(n==2)
	return 2;
else
	return (recursive(n-2)+recursive(n-1));
}
int main()
{
	int tile,combination;
	scanf("%d",&tile);
	combination=recursive(tile);
	printf("%d\n",combination);

	return 0;
}

