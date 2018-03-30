#include<stdio.h>
#include<stdlib.h>
int main()
{
		int a,b,c,max,mid,min;
		scanf("%d %d %d",&a,&b,&c);
		if(a>=b&&a>=c)
			max=a;
		else if(b>=a&&b>=c)
			max=b;
		else if(c>=a&&c>=b)
			max=c;
		if(max==a&&b>=c){
			mid=b;
			min=c;
}
		else if(max==a&&c>=b){
			mid=c;
			min=b;
}
		else if(max==b&&a>=c){
			mid=a;
			min=c;
}
		else if(max==b&&c>=a){
			mid=c;
			min=a;
}
		else if(max==c&&b>=a){
			mid=b;
			min=a;
}
		else if(max==c&&a>=b){
			mid=a;
			min=b;
}
		if(mid+min>max){
			if(min*min+mid*mid==max*max)
				printf("right\n");
			else if(min*min+mid*mid>max*max)
				printf("acute\n");
			else if(min*min+mid*mid<max*max)
				printf("obtuse\n");
}	
		else
		printf("invalid\n");

	return 0;
}

