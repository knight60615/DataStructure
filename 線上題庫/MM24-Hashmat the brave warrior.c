#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
		int A,B;
double limit;
limit=pow(2,32);
while(scanf("%d %d",&A,&B)!=EOF){
	//scanf("%d %d",&A,&B);
	if(A<B&&A<=limit&&B<=limit)
		printf("%d\n",B-A);
	else if(A>=B&&A<=limit&&B<=limit)
		printf("%d\n",A-B);
}
	 
	return 0;
}
