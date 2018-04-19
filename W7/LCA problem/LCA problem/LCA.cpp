#include<iostream>
using namespace std;
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
	for (int i=1;i<=N;i++)
	{
		int x=0;
		cin>>x;
		insert(x,root);
	}
}
int LCA(int a,int b,BSTNode *&root)
{
	if (((root->data)-a)*((root->data)-b)<=0)
	{
		return root->data;
	}
	else if (((root->data)>a)&&((root->data)>b))
	{
		return LCA(a,b,root->left);
	}
	else
	{
		return LCA(a,b,root->right);
	}
}
int main()
{
	int N=0,M=0;
	cin>>N>>M;
	BSTNode *root=NULL;
	Construct(root,N);
	for (int i=1;i<=M;i++)
	{
		int a=0,b=0;
		cin>>a>>b;
		cout<<LCA(a,b,root)<<endl;
	}
	return 0;
}

