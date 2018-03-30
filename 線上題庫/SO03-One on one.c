#include <stdio.h>  
#include <stdlib.h>  
int myintcmp(const void*a,const void*b)
{
		return *((int*)a)-*((int*)b);
}
  
int main()  
{  
    int size,i,j,enemy[10000],solder[10000],win;  
  
    while(1)  
    {  
        scanf("%d", &size);  
        if (size==0)  
            return 0;  

        win=0;  
        for (i=0;i<size;i++)  
            scanf("%d",&enemy[i]);  
        for (i=0;i<size;i++)  
            scanf("%d",&solder[i]);  
        qsort(enemy,size,sizeof(int),myintcmp);  
        qsort(solder,size,sizeof(int),myintcmp);  
  
        for (i=size-1, j=size-1;j>=0;)  
        {  
                if(solder[i]>enemy[j])  
                {  
                    win++;  
                    i--;  
                    j--;  
                }  
                else   
                    j--;   
        }  
  
        printf("%d\n",win);  
    }  
  return 0;
}
