#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
		char input[100];
		int l,i,sum=0;
		while(scanf("%s",input)!=EOF){
			l=strlen(input);
			for(i=0;i<l;i++){
					sum=sum+(input[i]-64)*pow(26,(l-i-1));
}
		printf("%d\n",sum);
		sum=0;

}

	return 0;
}

