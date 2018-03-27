#include<iostream>
#include<vector>
using namespace std;
void bubblesort(vector<int>*L)
{
	int i,j;
	int temp;
	bool flag  = false;
	
	for(i=0;i!=(*L).size()&&(!flag);i++)
	{
		flag = true;
		for(j=(*L).size();j!=i;j--)
		{
			if((*L)[j]<(*L)[j-1])
			{
				temp = (*L)[j-1];
				(*L)[j-1] = (*L)[j];
				(*L)[j] = temp;
				flag = false;
			}
		}
	}
}

void selectsort(vector<int> *L)
{
	int i,j;
	int min;
	int temp;
	for(i=0;i!=(*L).size();i++)
	{
		min = i;
		for(j=i+1;j<(*L).size();j++)
		{
			if((*L)[min]>(*L)[j])
			{
				min = j;
			}
		}
		if(i!=min)
		{
			temp = (*L)[i];
			(*L)[i]=(*L)[min];
			(*L)[min]=temp;
		}
	}
}

void Insertsort(vector<int> *L)
{
	int i,j;
	for(i=1;i<(*L).size();i++)
	{
		if((*L)[i]<(*L)[i-1])
		{
			int temp = (*L)[i];
			for(j=i-1;(*L)[j]>temp;j--)
			{
				(*L)[j+1]=(*L)[j];
			}
			(*L)[j+1]=temp;
		}
	}
}

void Shellsort(vector<int> *L)
{
	int i,j,temp;
	int increment = (*L).size();
	do
	{
		increment = increment / 3 + 1;
		for(i=increment;i<(*L).size();i++)
		{
			if((*L)[i]<(*L)[i-increment])
			{
				temp = (*L)[i];
				for(j = i-increment;j>-1&&temp<(*L)[j];j-=increment)
				{
					(*L)[j+increment]=(*L)[j];
				}
				(*L)[j+increment] = temp;
	
			}
		}
	}while(increment>1);
}

int main()
{
	vector<int> T {11,3,14,123,2,55,13,56,2,45,77,7,15,6,1,28,9};
	vector<int>*P = &T;
	//bubblesort(P);
	//selectsort(P);
	//Insertsort(P);
	Shellsort(P);
	auto i = (*P).begin();
	while(i!=(*P).end())
	{
		cout<<*i<<" ";
		i++;
	}
	cout<<endl;
	return 1;
}
