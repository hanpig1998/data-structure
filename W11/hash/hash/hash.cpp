#include<iostream>
#include<string.h>
#include<math.h>
#define M 119997
using namespace std;
struct point
{
	int x;
	int y;
	int dx;
	int dy;
	point():x(0),y(0),dx(0),dy(0){}
};
void hashsearch(int &num, point *temp, int k,int *hash) 
{
    int key=((temp[k].x)*1000+(temp[k].y))%M;
    if (key<0)
	{
		key+=M;
	}
    while (hash[key]>-1)
	{
        int i=hash[key];
        if ((temp[i].x==temp[k].x)&&(temp[i].y==temp[k].y)&&(temp[i].dx*temp[k].dy!=temp[i].dy*temp[k].dx)) 
			{
				num++;
			}
        key=(key+1)%M;
    }
    hash[key]=k;
}
int main()
{
	int hash[M]={0};
    int n=0,m=0;
    int total=0;
    cin>>n;
    while (n--)
	{
        total=0;
        memset(hash,-1,sizeof(hash));
        cin>>m;
		int cross=m*(m-1)/2;
        point *p=new point[m];
        point* mid = new point[cross];
        for (int i=0;i<m;i++) 
		{
            cin>>p[i].x>>p[i].y;
        }
		int k=0;
        for (int i=0;i<m-1;i++)
		{
            for (int j=i+1;j<m;j++) 
			{
				mid[k].x=p[i].x+p[j].x;
                mid[k].y=p[i].y+p[j].y;
                mid[k].dx=p[i].x-p[j].x;
                mid[k].dy=p[i].y-p[j].y;
                hashsearch(total,mid,k,hash);
                k++;
            }
        }
        cout<<total<<endl;
    }
    return 0;
}