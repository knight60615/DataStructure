#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
int count=0,cost[MAX][MAX];
int prim(int n){
		int i,j,v,minc,minp,from,sum=0,TV[MAX]={0};	//TV是到的位置,從0開始且沒有邊
		while(count<n-1){
				minc=-1;		//initialize,值隨便訂的
				for(j=0;j<=count;j++){
						v=TV[j];
						for(i=0;i<n;i++){
								if(cost[v][i]!=0&&minc==-1){	//第一個相連的
										minc=cost[v][i];
										minp=i;
										from=v;
								}
								else if(minc>cost[v][i]&&cost[v][i]!=0){	//有更小就換掉
										minc=cost[v][i];
										minp=i;
										from=v;
								}
						}
				}
				if(minc==-1)
						return sum;		//代表沒邊了
				else {
						sum=sum+minc;
						count++;
						TV[count]=minp;
						cost[from][minp]=cost[minp][from]=0;
						printf("Edge %d:<%d %d> cost:%d\n",count,from+1,minp+1,minc);

				}
		}
		return sum;

}
int main()
{
		int n,i,j,sum;
		printf("Enter number of nodes:");
		scanf("%d",&n);
		printf("Enter the adjacency matrix:\n");
		for(i=0;i<n;i++){
				for(j=0;j<n;j++)
						scanf("%d",&cost[i][j]);
		}
		printf("The output is\n");
		sum=prim(n);
		printf("Minimun cost=%d\n",sum);

		return 0;
}

