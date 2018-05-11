#include<iostream>
#include<vector>
using namespace std;
struct node
{
	int data;
	int visited;
	node *up;
	node *right;
	node *left;
	node *down;
};
int search(node *a)
{
	if (a==NULL||a->visited==1||a->data==0)
	{
		return 0;
	}
	else
	{
		a->visited=1;
		return 1+search(a->up)+search(a->right)+search(a->left)+search(a->down);
	}
}
int main()
{
	int rows=0,cols=0;
	cin>>rows>>cols;
	vector<node*> graph;
	int M=rows*cols;
	cin.get();
	for (int i=0;i<rows;i++)
	{
		for (int j=0;j<cols;j++)
		{
			node *m=new node;
			char temp=cin.get();
			m->data=temp-'0';
			graph.push_back(m);
		}
		cin.get();
	}
	for (int i=0;i<M;i++)
	{
		graph[i]->up=NULL;
		graph[i]->down=NULL;
		graph[i]->right=NULL;
		graph[i]->left=NULL;
		if ((i+1)%cols!=0)
		{
			if (graph[i+1]->data==1)
			{
				graph[i]->right=graph[i+1];
			}
		}
		if (i%cols!=0)
		{
			if (graph[i-1]->data==1)
			{
				graph[i]->left=graph[i-1];
			}
		}
		if (i<M-cols)
		{
			if (graph[i+cols]->data==1)
			{
				graph[i]->down=graph[i+cols];
			}
		}
		if (i>=cols)
		{
			if (graph[i-cols]->data==1)
			{
				graph[i]->up=graph[i-cols];
			}
		}
	}
	int max=0;
	for (int i=0;i<M;i++)
	{
		int temp1=search(graph[i]);
		if (max<temp1)
		{
			max=temp1;
		}
	}
	cout<<max<<endl;
	return 0;
}




	

		

