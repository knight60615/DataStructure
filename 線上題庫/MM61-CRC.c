#include<stdio.h>
#include<stdlib.h>
int main()
{
		int x,y,z,amount,leg,tail;
		scanf("%d %d %d",&amount,&leg,&tail);
		z=amount-tail;
		y=(leg-2*tail-8*z)/2;
		x=tail-y;
		if(x>=0&&y>=0&&z>=0&&amount>=0&&leg>=0&&tail>=0&&(leg-2*tail-8*z)%2==0)
			printf("%d %d %d\n",x,y,z);
		else
			printf("No solution\n");	

return 0;
}

