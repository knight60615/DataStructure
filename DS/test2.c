#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxword 10
#define maxtab 13000
typedef struct CollisionNode {			//�ŧi�@�ӷǳƥΨӦs��collision����ƪ�Linked List
		char word[maxword];
		struct CollisionNode *next;
}node;
node *head=NULL;						//head�Bhere���O�ΨӨ�U�s��pointer
node *here;
char *bucket[maxtab];
int ColTimes=0;							//�b�B�zcollision���禡���]�|�Ψ�ҥH�ŧi�������ܼ�
unsigned int hash(char *key)			//��Ū�i�Ӫ��r���H33�A�֥[
{
		int tmp=0;
		while(*key++)
				tmp=(tmp<<5)+tmp+*key;
		return tmp;
}
void Collision(node *ptr)				//�M��Ū�bucket�M���list�W���F��v����i�h�A�M��������Ϊ��O����Ŷ�
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
					ColTimes++;				//��즳�F�誺bucket�ɡAcollision����+1
				idx++;
		}
}
int main(int argc,char *argv[])
{
		node *ptr=NULL;						//ptr�O��U��F���iLinked List������
		FILE *f=fopen(argv[1],"r");
		int idx;							//�ŧi�n�Ϊ�idx�٦��ȦsŪ�i�Ӫ��r�ꪺ�ܼ�
		double per;							//�Ψӭp��performance
		char tmp[maxword];
		if(!f) {printf("File Open Failed.\n");return 0;}//�קK�}�ɥ���
		//printf("Data:");
		while(fgets(tmp,maxword,f))			//�u�n��Ū��F��j��N�|�~��i��
		{
				tmp[strlen(tmp)-1]='\0';	//��r�����\n\0�令\0�H�K�L�ۤv���U�@��
				//printf("\t%s",tmp);
				idx=hash(tmp)%maxtab;
				if(bucket[idx]==NULL)
				{
						bucket[idx]=(char *)malloc(strlen(tmp)*sizeof(char));	//bucket�O�Ū��N��F���i�h
						strcpy(bucket[idx],tmp);
				}
				else
				{
						ptr=(node *)malloc(sizeof(node));						//�p�G���O�Ū��N��ilist
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
		Collision(head);						//�I�s�禡��list�̪��F���ibucket
		printf("in Bucket : 10000\nTable Size : %d\n",maxtab);	
		printf("Collision Time(s) = %d\n",ColTimes);
		per=(10000.0/maxtab)/(ColTimes+1);
		printf("%f\n",per);
		return 0;
}
