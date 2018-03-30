#include <stdio.h>
#include <stdlib.h>
//total �`�@�bfind�����W�X��
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
				//U��2�Ӷ��X�p��   F��Xroot
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
//�ǤJ���X�}�C�M�n�p������Ӧ���  �^��root
//�j�����X��root���̫᪺root
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
//�ǤJ�n�䪺���X�}�C�M�n�䪺���� �^��root
int Find(int *parent, int a)
{
		int root, trail, lead;
		//��Xroot
		for(root = a; parent[root]>=0; root = parent[root]);
		//��⦨�����@�����W�䪺��L������������root �[�֤U��find�ɶ�
		for(trail = a; trail != root; trail = lead) {
				lead = parent[trail];
				parent[trail] = root;
				total++;
		}
		return root;
}
