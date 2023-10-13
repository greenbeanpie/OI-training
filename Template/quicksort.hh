#include <bits/stdc++.h>
using namespace std;


void quicksort(int l,int r,int *num)
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
	
	quicksort(l,j,num);
	quicksort(i,r,num);
}
