#include <stdio.h>    
#include <stdlib.h>    
#include <string.h>    
int main()
{
		char target[100],temp[1000];
		int n,i,j,k;
		scanf("%s %d",target,&n);
		for(i=0;i<n;i++){
		int check=0;
		temp[0]='/0';
		scanf("%s",temp);
		for(j=0;j<strlen(target);j++)
			for(k=0;k<strlen(temp);k++){
			if(temp[k]>=65&&temp[k]<=90){
				if(temp[k]==target[j]||temp[k]+32==target[j]){
					check++;
					break;
}
}
			else if(temp[k]>=97&&temp[k]<=122){
					if(temp[k]==target[j]||temp[k]-32==target[j]){
					check++;
					break;
}
}
}
		if(check==strlen(target))	
			printf("%s\n",temp);

}

	return 0;
}

