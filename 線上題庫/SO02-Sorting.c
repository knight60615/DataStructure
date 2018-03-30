#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>   
int set;  
int cmp(int *a, int *b)  
{  
    if (set==1)  
        return ( *(int*)a - *(int*)b );  
    else  
        return ( *(int*)b - *(int*)a );  
}  
  
  
int main()  
{  
    char temp[1000],*ptr;  
    int num[1000]; 
    int i=0,j,size;  
  
  
    gets(temp);  
  
    ptr=strtok(temp," \n"); 
    num[i++]=atoi(ptr);  
  
    while(1)  
    {  
        ptr=strtok(NULL," \n");  
        if (strcmp(ptr,"-a")==0)  
        {  
            set=1;  
            break;  
        }  
        else if(strcmp(ptr,"-d")==0)  
        {  
            set=2;  
            break;  
        }  
        num[i++]=atoi(ptr);  
    }  
    qsort(num,i,sizeof(int),cmp);  
    printf("Array =");  
    for (j=0;j<i;j++)  
        printf("% d", num[j]);  
    printf("\n");  
  
    while(scanf("%d", &size)!=EOF)  
    {  
        printf("N = %d, Array =", size);  
        for (j=0;j<i/size;j++)  
            printf(" %d", num[j]);  
    printf("\n");  
    }  
  
    return 0;  
}
