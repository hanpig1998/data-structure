#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
int main()
{
	int N=0,M=0;
	scanf("%d %d",&N,&M);
	struct node *first=new node;
	struct node *A=first;
	first->data=1;
	for (int i=2;i<=N;i++)
	{
	    struct node *B=new node;
		A->next=B;
		B->data=i;
		A=B;
	}
	A->next=first;
	A=first;
	for (int i=1;i<N;i++)
	{
		for (int j=1;j<M-1;j++)
		{
			A=A->next;
		}
		A->next=A->next->next;
		A=A->next;
	};
	printf("%d",A->data);
}