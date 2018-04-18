#include<stdio.h>
#include<stdlib.h>
struct student
{
	int x1;
	int x2;
};
int compare(const void *p1,const void *p2)
{
	struct student *a1=(student*)p1;
    struct student *a2=(student*)p2;
	if (a1->x1>a2->x1)
	{
		return 1;
	}
	else if (a1->x1<a2->x1)
	{
		return -1;
	}
	else
	{
		if (a1->x2>a2->x2)
		{
			return 1;
		}
		else if (a1->x2<a2->x2)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
}
int main()
{
	student a[25000]={0};
	int N;
	scanf("%d",&N);
	for (int i=0;i<N;i++)
	{
		scanf("%d %d",&a[i].x1,&a[i].x2);
	}
	qsort(a,N,sizeof(a[0]),compare);
	printf("%d %d\n",a[0].x1,a[0].x2);
	for (int i=1;i<N;i++)
	{
		if ((a[i].x1!=a[i-1].x1)||(a[i].x2!=a[i-1].x2))
		{
			printf("%d %d\n",a[i].x1,a[i].x2);
		}
	}
	return 0;
}

