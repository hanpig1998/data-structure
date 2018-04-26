#include<iostream>
using namespace std;
int node[100]={0};
int i=0;
int m=0;
struct BSTNode
{
	int data;
	BSTNode *left;
	BSTNode *right;
};
void insert(int x,BSTNode *&p)
{
	if (p==NULL)
	{
		p=new BSTNode;
		p->data=x;
		p->left=NULL;
		p->right=NULL;
	}
	else if (x<p->data)
	{
		insert(x,p->left);
	}
	else 
	{
		insert(x,p->right);
	}
}
void Construct(BSTNode *&root,int N)
{
	for (int j=1;j<=N;j++)
	{
		int x=0;
		cin>>x;
		insert(x,root);
	}
}
void judge(BSTNode *a)
{
	if (a!=NULL)
	{
		judge(a->left);
		judge(a->right);
		if (a->data==node[i])
		{
			i++;
		}
		else
		{
			i++;
			m=1;
		}
	}
}
void store(BSTNode *a)
{
	if (a!=NULL)
	{
		store(a->left);
		store(a->right);
		node[i++]=a->data;
	}
}
int main()
{
	int L=0,N=0;
	cin>>L>>N;
	BSTNode *root=NULL;
	Construct(root,L);
	store(root);
	i=0;
	for (int j=1;j<=N;j++)
	{
		BSTNode *root1=NULL;
		Construct(root1,L);
		judge(root1);
		if (m==0)
		{
			i=0;
			cout<<"YES"<<endl;
		}
		else
		{
			i=0;
			m=0;
			cout<<"No"<<endl;
		}
	}
	return 0;
}
