#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
		char input[100],*ptr;
		int count,i,l;
		scanf("%s",input);
	//	l=strlen(input);
		for(i=0;i<26;i++){
			count=0;

				ptr=strchr(input,'A'+i);
						while(ptr!=NULL){			
							count++;
							ptr=strchr(ptr+1,'A'+i);
}
				ptr=strchr(input,'A'+i+32);
						while(ptr!=NULL){			
							count++;
							ptr=strchr(ptr+1,'A'+i+32);
}
		printf("%d\n",count);
}
	return 0;
}

