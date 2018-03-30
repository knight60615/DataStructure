#include<stdio.h>
#include<stdlib.h>
int main()
{
		int N,i,j,height,width,depth,surface,volume,a,b;
float min=125001;
	scanf("%d",&N);
for(i=0;i<N;i++){
		scanf("%d %d %d",&height,&width,&depth);
surface=2*(height*width+height*depth+width*depth);
volume=height*width*depth;
if(surface>=volume){
			for(j=1;j<=volume;j++){
		if(surface%j==0&&volume%j==0)
			{surface=surface/j;
			 volume=volume/j;
			 j=1;}	}
}
else if(surface<volume){
			for(j=1;j<=surface;j++){
		if(surface%j==0&&volume%j==0)
			{surface=surface/j;
			 volume=volume/j;
			 j=1;}	}
}
if((float)surface/(float)volume<min){
a=surface;
b=volume;
min=(float)a/(float)b;
}

}

printf("%d/%d\n",a,b);
	return 0;
}

