#include<iostream>
using namespace std;
int min(int i,int j)
{
	if (i<j)
	{
		return i;
	}
	else
	{
		return j;
	}
}
int main()
{
	int N=0,M=0;
	cin>>N>>M;
	int graph[100][100]={0};
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
		{
			cin>>graph[i][j];
		}
	}
	for (int k=0;k<N;k++)
	{
		for (int i=0;i<N;i++)
		{
			for (int j=0;j<N;j++)
			{
				if ((graph[i][j]<min(graph[i][k],graph[k][j]))&&i!=j)
				{
					graph[i][j]=min(graph[i][k],graph[k][j]);
				}
			}
		}
	}
	int dest1=0,dest2=0;
	for (int i=1;i<=M;i++)
	{
		cin>>dest1>>dest2;
		if (dest1==dest2)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			cout<<graph[dest1][dest2]<<endl;
		}
	}
	return 0;
}
