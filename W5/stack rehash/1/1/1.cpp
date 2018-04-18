#include<iostream>
#include<stack>
using namespace std;
bool judge(int *a,int k)
{
	stack<int> s;
	int i=1;
	for (int m=1;m<=k;m++)
	{
		while(s.empty()||*(a+m)!=s.top())
		{
			if (i>k)
			{
				return false;
			}
			else
			{
				s.push(i++);
			}
		}
		s.pop();
	}
	return true;
}
int main()
{
	int n=0,k=0;
	cin>>n>>k;
	int a[1000]={0};
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=k;j++)
		{
			cin>>a[j];
		}
		if (judge(a,k))
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
	return 0;
}