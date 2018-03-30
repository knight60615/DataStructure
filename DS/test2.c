#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxword 10
#define maxtab 13000
typedef struct CollisionNode {			//宣告一個準備用來存放collision的資料的Linked List
		char word[maxword];
		struct CollisionNode *next;
}node;
node *head=NULL;						//head、here都是用來協助存放的pointer
node *here;
char *bucket[maxtab];
int ColTimes=0;							//在處理collision的函式中也會用到所以宣告成全域變數
unsigned int hash(char *key)			//把讀進來的字乘以33再累加
{
		int tmp=0;
		while(*key++)
				tmp=(tmp<<5)+tmp+*key;
		return tmp;
}
void Collision(node *ptr)				//尋找空的bucket然後把list上的東西逐次放進去，然後釋放佔用的記憶體空間
{
		int idx=0;
		while(idx<maxtab&&ptr)
		{
				if(bucket[idx]==NULL)
				{
						bucket[idx]=(char *)malloc(strlen(ptr->word)*sizeof(char));
						strcpy(bucket[idx],ptr->word);
						here=ptr;
						ptr=ptr->next;
						free(here);
				}
				else
					ColTimes++;				//找到有東西的bucket時，collision次數+1
				idx++;
		}
}
int main(int argc,char *argv[])
{
		node *ptr=NULL;						//ptr是協助把東西放進Linked List的指標
		FILE *f=fopen(argv[1],"r");
		int idx;							//宣告要用的idx還有暫存讀進來的字串的變數
		double per;							//用來計算performance
		char tmp[maxword];
		if(!f) {printf("File Open Failed.\n");return 0;}//避免開檔失敗
		//printf("Data:");
		while(fgets(tmp,maxword,f))			//只要有讀到東西迴圈就會繼續進行
		{
				tmp[strlen(tmp)-1]='\0';	//把字串尾端\n\0改成\0以免他自己跳下一行
				//printf("\t%s",tmp);
				idx=hash(tmp)%maxtab;
				if(bucket[idx]==NULL)
				{
						bucket[idx]=(char *)malloc(strlen(tmp)*sizeof(char));	//bucket是空的就把東西放進去
						strcpy(bucket[idx],tmp);
				}
				else
				{
						ptr=(node *)malloc(sizeof(node));						//如果不是空的就放進list
						if(!ptr) {printf("Malloc Failed.\n");return 0;}
						strcpy(ptr->word,tmp);
						ptr->next=NULL;
						if(head==NULL)
						{
								head=ptr;
								here=ptr;
						}
						else
						{
							here->next=ptr;
							here=ptr;
						}
						ColTimes++;
				}
		}
		//printf("\n");
		Collision(head);						//呼叫函式把list裡的東西放進bucket
		printf("in Bucket : 10000\nTable Size : %d\n",maxtab);	
		printf("Collision Time(s) = %d\n",ColTimes);
		per=(10000.0/maxtab)/(ColTimes+1);
		printf("%f\n",per);
		return 0;
}
