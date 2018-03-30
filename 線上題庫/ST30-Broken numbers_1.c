#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
		int l,state=0;
		char input[1000],*ptr;
		//scanf("%d ",&N);
		//for(i=0;i<N;i++){
		while(gets(input)!=NULL){
			state=0;
			//gets(input);
			l=strlen(input);
			ptr=input;
			while(*ptr!='\0'){
				if(*ptr>='0'&&*ptr<='9'){
						printf("%d",*ptr-'0');
						state=1;
}
				ptr++;
}
			if(state==0&&input[0]!='\0')
				printf("-1\n");
			else
				printf("\n");
			input[0]='\0';
			
}

	return 0;
}

