#include<iostream>
#include"sortalgo.h"

using namespace std;
sort_item::sort_item(vector<int> P)
{
	L = P;
}
void meg(vector<int>*P2,vector<int>*P,int i,int t,int m)
{
	int j,k,l;
	for(j = i,k = t+1,l=i;j<=t&&k<=m;l++)
	{
		if((*P2)[j]<(*P2)[k])
		{
			(*P)[l] =(*P2)[j];
			j++;
		}
		else 
		{
			(*P)[l] = (*P2)[k];
			k++;
		}
	}
	if(j<=t)
		for(;j<=t;j++,l++)
			(*P)[l] = (*P2)[j];
	if(k<=m)
		for(;k<=m;k++,l++)
			(*P)[l] = (*P2)[k];
	return ;
}
void msort(vector<int> L,vector<int>*P,int i,int m)
{
	int a = L.size();
	vector<int> P2(a);
	if(i == m)
		(*P)[i] = L[m];
	else
	{
		int t = (i+m)/2;
		msort(L,&P2,i,t);
		msort(L,&P2,t+1,m);
		meg(&P2,P,i,t,m);
	}
	
}
void sort_item::Mergesort()
{
	vector<int> P(L.size());
	msort(L,&P,0,L.size()-1);
	for(int i = 0;i<L.size();i++)
		L[i]=P[i];
}
void swap(int i,int j,vector<int> *P)
{
	int temp;
	temp =	(*P)[i];
	(*P)[i]= (*P)[j];
	(*P)[j] = temp;
}
int part(int low,int high,vector<int> *P)
{
	int midkey = (*P)[low];
	while(low <high)
	{
		while(low<high&& midkey<=(*P)[high])
			high--;
		swap(low,high,P);
		while(low<high&&(*P)[low]<=midkey)
			low++;
		swap(low,high,P);
	}
	return low;
}
void qsort(int low,int high,vector<int> *P)
{
	int mid;
	if(low<high)
	{
		mid = part(low,high,P);
		qsort(low,mid-1,P);
		qsort(mid+1,high,P);
	}
}
void sort_item::quicksort()
{
	qsort(0,L.size()-1,&L);
}

void HeapAdjust(vector<int> *p,int i,int len)
{
	int j,k;
	int temp = (*p)[i];
	for(j=2*i+1;j<len-1;j=j*2+1)
	{
		if(j<len&&(*p)[j]<(*p)[j+1])
			j++;
		if((*p)[j]<=temp)
			break;
		(*p)[i]=(*p)[j];
		i=j;	
	}
	(*p)[i]=temp;
}
void sort_item::heapsort()
{
	int i;
	int temp;
	for(i=L.size()/2;i>-1;i--)
		HeapAdjust(&L,i,L.size());
	
	for(i=L.size();i>0;i--)
	{
		temp = L[i-1];
		L[i-1]=L[0];
		L[0] = temp;
		HeapAdjust(&L,0,i-1);
	}
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
	vector<int> T{11,3,14,123,2,55,13,56,2,45,77,7,15,6,1,28,9};
	sort_item S(T);
	//S.Shellsort();
	//S.heapsort();
	S.Mergesort();
	S.print();
	return 1;
}

