#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
int count=0,cost[MAX][MAX],parent[MAX];
int collapsingFind(int i){
		int root,trail,lead;
		/*把指到i那一項的其他成員全部指到root*/
		for(root=i;parent[root]>=0;root=parent[root])
				;
		for(trail=i;trail!=root;trail=lead){
				lead=parent[trail];
				parent[trail]=root;
		}
		return root;
}
int weightedUnion(int i,int j){
		/*找到起點的根*/
		i=collapsingFind(i);
		j=collapsingFind(j);
		int temp=parent[i]+parent[j];
		if(parent[i]==-1&&parent[j]==-1){	//第一次操作,整個圖形的根parent會變成-2
				parent[j]=i;
				parent[i]=temp;
				return 1;
		}
		if(parent[i]==-2&&parent[j]==-2){	//兩條單獨的邊
				parent[j]=i;
				return 1;
		}
		else if(parent[i]>parent[j]){
				parent[i]=j;
				parent[j]=temp;
				return 1;
		}
		else if(parent[i]<parent[j]){
				parent[j]=i;
				parent[i]=temp;
				return 1;
		}
		else if(parent[i]==parent[j])	//會形成迴路,不能做事
				return 0;
		return 0;		//根本不會用到 隨便return就好
}
int kruskal(int n){
		int i,j,minc,minp,from,sum=0,check;
		while(count<n-1){
				minc=-1;
				for(i=0;i<n;i++){
						for(j=0;j<n;j++){
								if(cost[i][j]!=0&&minc==-1){
										minc=cost[i][j];
										minp=j;
										from=i;
								}
								else if(minc>cost[i][j]&&cost[i][j]!=0){
										minc=cost[i][j];
										minp=j;
										from=i;
								}
						}
				}
				if(minc==-1)
						return sum;		//代表沒邊了
				else{
						check=weightedUnion(from,minp);
						if(check==1){
								sum=sum+minc;
								count++;
								cost[from][minp]=cost[minp][from]=0;		//用完就蓋掉
								printf("Edge %d:<%d %d> cost:%d\n",count,from+1,minp+1,minc);
						}
						else if(check==0){		//形成迴路,所以這條邊不能用也要蓋掉
								cost[from][minp]=cost[minp][from]=0;
								}
				}
		}
		return sum;

}
int main()
{
		int n,i,j,sum;
		printf("Enter number of vertices:\n");
		scanf("%d",&n);
		printf("Enter the adjacency matrix:\n");
		for(i=0;i<n;i++){
				for(j=0;j<n;j++)
						scanf("%d",&cost[i][j]);
		}
		for(i=0;i<n;i++)
				parent[i]=-1;
		printf("The edges of Minimum Cost Spanning Tree are\n");
		sum=kruskal(n);
		printf("Minimun cost = %d\n",sum);

		return 0;
}

