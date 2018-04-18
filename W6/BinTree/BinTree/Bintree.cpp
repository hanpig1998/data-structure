#include<iostream>
#include<malloc.h>
using namespace std;
struct node
{
	int value;
	struct node *lchild;
	struct node *rchild;
};
node *create_tree(int *pre,int *mid,int size)
{
	if (size<=0)
	{
		return NULL;
	}
	int i=0;
	for (i=0;i<size;i++)
		if (*(mid+i)==*pre)
			break;
	node *a=(node *)malloc(sizeof(node));
	a->value=*(mid+i);
	a->lchild=create_tree(pre+1,mid,i);
	a->rchild=create_tree(pre+i+1,mid+i+1,size-i-1);
	return a;
}
void back(node *a)
{
	if (a!=NULL)
	{
		back(a->lchild);
		back(a->rchild);
		cout<<a->value<<' ';
	}
}
int main()
{
	int number=0;
	cin>>number;
	for (int i=1;i<=number;i++)
	{
		int size=0;
		cin>>size;
		int pre[30000]={0};
		int mid[30000]={0};
		for (int j=0;j<size;j++)
		{
			cin>>pre[j];
		}
		for (int j=0;j<size;j++)
		{
			cin>>mid[j];
		}
		node *ans=create_tree(pre,mid,size);
		back(ans);
		cout<<endl;
	}
	return 0;
}


