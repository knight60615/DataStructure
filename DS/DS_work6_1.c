#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
int visit[MAX]={0},A[MAX][MAX];
void dfs(int v,int n){
		int i,j;
		visit[v]=1;			//�N��w���X
		for(j=0;j<n;j++){
				if(A[v][j]==1&&visit[j]==0){	//�۳s�B�S���X�L
						printf("%d->%d\n",v+1,j+1);
						dfs(j,n);		//�q��F���I�}�l��
				}
		}
}
int main()
{
		int n,i,j,state=1;
		printf("Enter number of vertices:\n");
		scanf("%d",&n);
		printf("Enter the adjacency matrix:\n");
		for(i=0;i<n;i++){
				for(j=0;j<n;j++)
						scanf("%d",&A[i][j]);
		}
		printf("The output is\n");
		dfs(0,n);
		for(i=0;i<n;i++){
				if(visit[i]==0){
						state=0;
						break;
				}
		}
		if(state==1)
				printf("Graph is connected\n");
		else
				printf("Graph is not connected\n");

		return 0;
}
