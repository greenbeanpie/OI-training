#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	cin >> n;
	long long list1[n];
	for (int i = 0; i < n; i++)
	{
		cin >> list1[i];
	}
	cin >> m;
	long long list2[m];
	for (int i = 0; i < m; i++)
	{
		cin >> list2[i];
	}
	int list1n[n], list2n[m];
	for (int i = 0; i < n; i++)
	{
		list1n[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (list1[i] > list1[j])
			{
				list1n[i] = list1n[j] + 1;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		list2n[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (list2[i] > list2[j])
			{
				list2n[i] = list2n[j] + 1;
			}
		}
	}
	int public1n[n], public2n[m],n1,m1;
	memset(public1n,0,sizeof(public1n));
	memset(public2n,0,sizeof(public2n));
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (list1[i] == list2[j])
			{
				public1n[i] = 1;
				public2n[j] = 1;
				
				
				for (int a = i-1; a >=n1; a--)
				{
					for (int b = j-1; b >=m1; b--)
					{
						if (list1[a] == list2[b])
						{
							t = public1n[a];
							break;
						}
					}
				}
				public1n[i] = t + 1;
				public2n[j] = t + 1;
				n1=i;
				m1=j;
				break;
			}
			
		}
	}
	cout << t << endl;
	
	return 0;
}