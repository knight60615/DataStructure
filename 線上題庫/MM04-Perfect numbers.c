#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
		int n,i=0;
		long long int p,j,sum=0;
		scanf("%d",&n);
		while(i<n){
			scanf("%lld",&p);
		if(p>0&&p<pow(10,15))
			for(j=1;j<=sqrt(p);j++){
				if(p%j==0){
	if(j*j==p||j==1) 
					sum=sum+j;
	else if(j*j!=p&&j!=1) 
					sum=sum+j+p/j;
}
}
		if(sum==p)
		printf("perfect\n");
		else if(sum!=p)
		printf("nonperfect\n");
		sum=0;
		i++;
}

	return 0;
}

