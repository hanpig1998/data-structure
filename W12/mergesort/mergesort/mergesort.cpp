#include<iostream>
using namespace std;
long long int answer=0;
void merge_2(double data_x[],double data_y[],int first,int mid,int last,double sorted_x[],double unsorted_y[])
{
	int i=first,j=mid;
	int k=0;
	while (i<mid&&j<last)
	{
		if (data_x[i]<data_x[j])
		{
			sorted_x[k]=data_x[i];
			unsorted_y[k]=data_y[i];
			i++;
			k++;
		}
		else
		{
			sorted_x[k]=data_x[j];
			unsorted_y[k]=data_y[j];
			j++;
			k++;
		}
	}
	while (i<mid)
	{
		sorted_x[k]=data_x[i];
		unsorted_y[k]=data_y[i];
		k++;
		i++;
	}
	while (j<last)
	{
		sorted_x[k]=data_x[j];
		unsorted_y[k]=data_y[j];
		k++;
		j++;
	}
	for (int v=0;v<k;v++)
	{
		data_x[first+v]=sorted_x[v];
		data_y[first+v]=unsorted_y[v];
	}
}
void mergesort_2(double data_x[],double data_y[],int first,int last,double sorted_x[],double unsorted_y[])
{
	if (first+1<last)
	{
		int mid=(first+last)/2;
		mergesort_2(data_x,data_y,first,mid,sorted_x,unsorted_y);
		mergesort_2(data_x,data_y,mid,last,sorted_x,unsorted_y);
		merge_2(data_x,data_y,first,mid,last,sorted_x,unsorted_y);
	}
}
void merge_1(double data[],int first,int mid,int last,double sorted[])
{
	int i=first,j=mid;
	int k=0;
	while (i<mid&&j<last)
	{
		if (data[i]<data[j])
		{
			sorted[k]=data[i];
			i++;
			k++;
			if (i-1<j)
			{
				answer+=last-j;
			}
		}
		else
		{
			sorted[k]=data[j];
			j++;
			k++;
		}
	}
	while (i<mid)
	{
		sorted[k]=data[i];
		k++;
		i++;
	}
	while (j<last)
	{
		sorted[k]=data[j];
		k++;
		j++;
	}
	for (int v=0;v<k;v++)
	{
		data[first+v]=sorted[v];
	}
}
void mergesort_1(double data[],int first,int last,double sorted[])
{
	if (first+1<last)
	{
		int mid=(first+last)/2;
		mergesort_1(data,first,mid,sorted);
		mergesort_1(data,mid,last,sorted);
		merge_1(data,first,mid,last,sorted);
	}
}
int main()
{
	int N=0;
	cin>>N;
	double *data_x=new double[N];
	double *data_y=new double[N];
	double *sorted_x=new double[N];
	double *sorted_y=new double[N];
	for (int i=0;i<N;i++)
	{
		cin>>data_x[i]>>data_y[i];
	};
	mergesort_2(data_x,data_y,0,N,sorted_x,sorted_y);
	mergesort_1(data_y,0,N,sorted_y);
	cout<<answer<<endl;
	return 0;
}


