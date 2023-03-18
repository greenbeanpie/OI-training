#include <bits/stdc++.h>
using namespace std;

int num[1000000];

void quicksort(int l,int r)
{
	if(l>r)
	{
		return;
	}
	int mid=num[(l+r)/2];
	int i=l;
	int j=r;
	while(i<=j)
	{
		while(num[j]>mid)
		{
			j--;
		}
		while(num[i]<mid)
		{
			i++;
		}
		if(i<=j)
		{
			swap(num[i],num[j]);
			i++;
			j--;
		}
	}
	
	quicksort(l,j);
	quicksort(i,r);
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	quicksort(0,n-1);
	for(int i=0;i<n;i++)
	{
		printf("%d ",num[i]);
	}
	return 0;
}