#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>  
  
int main()  
{  
    double h,t;  
    double bai;  
  
    while(scanf("%lf %lf", &h, &t)!=EOF)  
    {  
        bai=h/pow(t,1.5)-18;  
        if (bai>=40)  
            printf("morbidly obese\n");  
        else if (bai>=30&&bai<40)  
            printf("obese\n");  
        else if (bai>=25&&bai<30)  
            printf("overweight\n");  
        else if (bai>=18.5&&bai<25)  
            printf("healthy\n");  
        else  
            printf("underweight\n");  
  
  
    }  
  
  
    return 0;  
}
