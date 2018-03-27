#include<iostream>
#include"sortalgo.h"

using namespace std;
sort_item::sort_item(vector<int> P)
{
	L = P;
}

void sort_item::bubblesort()
{
	int i,j;
	int temp;
	bool flag  = false;
	
	for(i=0;i!=L.size()&&(!flag);i++)
	{
		flag = true;
		for(j=L.size();j!=i;j--)
		{
			if(L[j]<L[j-1])
			{
				temp = L[j-1];
				L[j-1] = L[j];
				L[j] = temp;
				flag = false;
			}
		}
	}
}

void sort_item::selectsort()
{
	int i,j;
	int min;
	int temp;
	for(i=0;i!=L.size();i++)
	{
		min = i;
		for(j=i+1;j<L.size();j++)
		{
			if(L[min]>L[j])
			{
				min = j;
			}
		}
		if(i!=min)
		{
			temp = L[i];
			L[i]=L[min];
			L[min]=temp;
		}
	}
}

void sort_item::Insertsort()
{
	int i,j;
	for(i=1;i<L.size();i++)
	{
		if(L[i]<L[i-1])
		{
			int temp = L[i];
			for(j=i-1;L[j]>temp;j--)
			{
				L[j+1]=L[j];
			}
			L[j+1]=temp;
		}
	}
}

void sort_item::Shellsort()
{
	int i,j,temp;
	int increment = L.size();
	do
	{
		increment = increment / 3 + 1;
		for(i=increment;i<L.size();i++)
		{
			if(L[i]<L[i-increment])
			{
				temp = L[i];
				for(j = i-increment;j>-1&&temp<L[j];j-=increment)
				{
					L[j+increment]=L[j];
				}
				L[j+increment] = temp;
	
			}
		}
	}while(increment>1);
}

void sort_item::print()
{
	auto i = L.begin();
	while(i!=L.end())
	{
		cout<<*i<<" ";
		i++;
	}
	cout<<endl;
}

int main()
{
	vector<int> T {11,3,14,123,2,55,13,56,2,45,77,7,15,6,1,28,9};
	sort_item S(T);
	S.Shellsort();
	S.print();
	return 1;
}
