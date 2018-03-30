#include <stdio.h>
#include <stdlib.h>
//total 總共在find中往上幾次
int total=0;
int Union(int *parent, int a, int b);
int Find(int *parent, int a);

int main()
{
		int i, k, parent[100], num, instru_n, a, b;
		char instru;

		for(i=0; i<100; i++) {
				parent[i] = -1;
		}

		scanf("%d", &num);
		scanf("%d", &instru_n);

		for(i=0; i<instru_n; i++) {
				scanf("%c");
				scanf("%c", &instru);
				//U把2個集合聯集   F找出root
				switch(instru) {
						case 'U':
								scanf("%d", &a);
								scanf("%d", &b);
								k = Union(parent, a, b);

								printf("Root: %d, %d members\n", k, parent[k]*-1);
								break;
						case 'F':
								scanf("%d", &a);
								k = Find(parent, a);

								printf("Representor: %d\n", k);
								break;
				}
		}
		printf("Total go-up: %d\n", total);
		return 0;
}
//傳入集合陣列和要聯集的兩個成員  回傳root
//大的集合的root為最後的root
int Union(int *parent, int a, int b)
{
		a = Find(parent, a);
		b = Find(parent, b);
		if(parent[a]<=parent[b]) {
				parent[a] = parent[a]+parent[b];
				parent[b] = a;
				return a;
		}
		else {
				parent[b] = parent[a]+parent[b];
				parent[a] = b;
				return b;
		}

}
//傳入要找的集合陣列和要找的成員 回傳root
int Find(int *parent, int a)
{
		int root, trail, lead;
		//找出root
		for(root = a; parent[root]>=0; root = parent[root]);
		//把把成員那一項往上找的其他成員全部指到root 加快下次find時間
		for(trail = a; trail != root; trail = lead) {
				lead = parent[trail];
				parent[trail] = root;
				total++;
		}
		return root;
}
