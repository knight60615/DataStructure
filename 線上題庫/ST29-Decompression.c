#include <stdio.h>    
#include <stdlib.h>    
#include <string.h>    
int main()    
{    
    char input[100],letter[100];    
    int num,i,j,k,state;     
    while(gets(input)!=NULL){ 
        j=0;  
		state=0;  
        for (i=0;i<strlen(input);i++)    
        {    
            if (input[i]>='0'&&input[i]<='9'&&state==0){
                num=input[i]-'0';    
				state=1;
}			
			else if(input[i]>='0'&&input[i]<='9'&&state==1){
				letter[j]='\0';
				for(k=0;k<num;k++)
						printf("%s",letter);
				j=0;
				letter[j]='\0';
				num=input[i]-'0';
}
			else if(state==1)
				letter[j++]=input[i];
			
        }    
            printf("\n");    
        
    }    
    
    
        
    return 0;    
}
