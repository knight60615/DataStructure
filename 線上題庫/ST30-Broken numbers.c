#include <stdio.h>    
#include <stdlib.h>    
#include <string.h>    
int main()    
{    
    char input[81],num[81];    
    int i,j;     
    while(gets(input)!=NULL){    
        j=0;    
        for (i=0;i<strlen(input);i++)    
        {    
            if (input[i]>='0'&&input[i]<='9')    
                num[j++]=input[i];    
        }    
        num[j]='\0';     
        if (j==0)    
            printf("-1\n");    
        else    
            printf("%d\n",atoi(num));    
    
    }    
    
    
        
    return 0;    
}
