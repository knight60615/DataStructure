#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{	
		//long long int m,n;
		char *m,*n;
		int p,M;
		m=(char *)malloc(sizeof(char)*102);
		n=(char *)malloc(sizeof(char)*102);
		while(1){
		scanf("%s %s",m,n);
		M=m[strlen(m)-1]-'0';
		if(M==0&&n[0]=='0')
break;
		else {
		M=M%10;
		if(n[0]=='0')
				printf("1\n");
		else if(M==0||M==1||M==5||M==6)
			printf("%d\n",M);
		else if(M==2||M==3||M==7||M==8){
			if(strlen(n)<2)
				p=n[0]-'0';
			else 
			p=(n[strlen(n)-2]-'0')*10+(n[strlen(n)-1]-'0');
		p=p%4;
		if(p==0)
		p=4;
		printf("%d\n",(int)pow(M,p)%10);	

}
		else if(M==4||M==9){
		if(n[0]=='0')
				printf("1\n");
		else{
		p=(n[strlen(n)-1]-'0')%2;
		if(p==0)
		p=2;
		printf("%d\n",(int)pow(M,p)%10);	
}
}

}
}
	return 0;
}
