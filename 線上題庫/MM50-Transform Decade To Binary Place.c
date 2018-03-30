#include<stdio.h>
#include<stdlib.h>
int main()
{	
	int input,output[32],k,n=0;
	scanf("%d",&input);
		for(k=31;k>=0;k--)
			output[n++]=((input>>k) &1);
		n=0;
while(output[n]==0)
n++;
		for(k=n;k<=31;k++)
			printf("%d",output[k]);
printf("\n");
	return 0;
}

