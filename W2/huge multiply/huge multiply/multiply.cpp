#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char a[100]={0},b[100]={0};
	int N=0;
	scanf("%d",&N);
	for (int t=0;t<N;t++)
	{
		scanf("%s %s",a,b);
		int c[200]={0};
		int n=strlen(a);
		int m=strlen(b);
		int multiply[100][200]={0};
		int temp1=0,temp2=0;
		int exchange1=0,exchange2=0;
		for (int i=m-1;i>=0;i--)
		{
			for (int j=n;j>=0;j--)
			{
				if (j>=1)
				{
					exchange1=a[j-1]-'0';
					exchange2=b[i]-'0';
					temp2=exchange1*exchange2+temp1;
					multiply[i][j+i]=temp2%10;
					temp1=temp2/10;
				}
				else
				{
					temp2=0;
					multiply[i][j+i]=temp1;
					temp1=0;
				}
			}
		}
		int temp3=0,temp4=0;
		for (int k=m+n;k>=1;k--)
		{
			for (int i=0;i<=m-1;i++)
			{
				temp4+=multiply[i][k-1];
			}
			temp4+=temp3;
			c[k]=temp4%10;
			temp3=temp4/10;
			temp4=0;
		}
		c[0]=temp3;
		int time=0;
		for (time=0;time<=(m+n);time++)
		{
			if (c[time]!=0)
			{
				break;
			}
		}
		if (time>m+n)
		{
			printf("0");
		}
		else
		{
			while(time<=(m+n))
			{
				printf("%d",c[time]);
				time++;
			}
		}
		printf("\n");
	}
	return 0;
}
		

	