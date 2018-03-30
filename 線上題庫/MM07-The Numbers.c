#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
		int N,M,count,i;
		char n[2],m[7];
		count=0;
		scanf("%d %d",&N,&M);
		if(N>=10&&N<=99&&M>=1000000&&M<=9999999){
			sprintf(n,"%d",N);		//itoa	
			sprintf(m,"%d",M);
			for(i=0;i<6;i++){		//逐一比對 每次比對2位 
				if(n[0]==m[i]&&n[1]==m[i+1])
				count++;
			}
		printf("%d\n",count);
		}
		else
		printf("error\n");	
		
	
	
	return 0;
}
