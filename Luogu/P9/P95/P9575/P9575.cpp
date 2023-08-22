#include <bits/stdc++.h>
#define int long long
const int N = 100010;
using namespace std;
int n,num1,num2;
int a[N],ans[N];
bool flag=1;
#define problemname "P9575"
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)	cin>>a[i];
	if(n%2==0)
	{
		cout<<1<<"\n";
		for(int i = 1;i<=n/2;i++) cout<<0;
		for(int i = 1;i<=n/2;i++) cout<<1;
		return 0;
	}
	for(int i = 1;i<=n;i++)	
	{
		if(a[i]%2) num1++;
		else num2++;
	}
	if(num1%2)
	{
		cout<<-1;
		return 0;
	}
	int x=2;
	num1=num2=0;
	while(flag)
	{
		for(int i = 1;i<=n;i++) 
			if(a[i]%2)
			{ 
				flag=0;
				break;
			}
		if(!flag) break;
		for(int i = 1;i<=n;i++)	a[i]/=2;
		x*=2;
	}
	for(int i = 1;i<=n;i++)	
	{
		if(a[i]%2) num1++;
		else num2++;
	}
	if(num1%2)
	{
		cout<<-1;
		return 0;
	}
	cout<<x<<"\n";
	int sum=(num1+num2*2)/2;
	if(sum<=num1)
	{
		for(int i = 1;i<=n;i++)
		{
			if(sum&&a[i]%2) sum--,cout<<0;
			else cout<<1;
		}
	}
	else
	{
		int num=(sum-num1)/2;
		for(int i = 1;i<=n;i++)
		{
			if(num&&a[i]%2==0) num--,cout<<0;
			else if(a[i]%2) cout<<0;
			else if(num<=0&&a[i]%2==0) cout<<1;
		}
	}
	return 0;
}
