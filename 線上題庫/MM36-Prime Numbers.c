#include<stdio.h>
#include<stdlib.h>
int main()
{	
		int a,i,j,set,count;
while(1){
	scanf(" %d",&a);
	count=0;
	if(a==0)
		break;	
	for(i=1;i<a;i++){
	set=0;
		if(i==1) {}
		else {
			for(j=2;j<=i;j++){
				if(i%j==0)
					set++;
				if(set>1)
					break;
}
}
	if(set==1)
		count++;
}
printf("%d\n",count);
}


	return 0;
}

