#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
		int n,i,j,sum=0;
		scanf("%d",&n);
		for(i=1;i<n;i++){
			for(j=1;j<=sqrt(i);j++){
				if(i%j==0){
	if(j*j==i||j==1) 
					sum=sum+j;
	else if(j*j!=i&&j!=1) 
					sum=sum+j+i/j;
}
}
		if(sum==i&&i!=1)
		printf("%d\n",i);
		sum=0;
}
	return 0;
}

