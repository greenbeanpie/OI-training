#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int a, tot;
};
bool cmp1(node a, node b)
{
	return a.a < b.a;
}

vector<node> l1, l;
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P1248.in", "r", stdin);
	freopen("P1248.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int a[n], b[n];
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++)
	{
		l.push_back({min(a[i], b[i]), i});
	}
	stable_sort(l.begin(), l.end(), cmp1);
	int pos1=0,pos2=n-1;
	for(int i=0;i<n;i++){
		if(l[i].a==a[l[i].tot]){
			ans[pos1++]=l[i].tot;
		}
		else{
			ans[pos2--]=l[i].tot;
		}                      
	}
	int t1=0,t2=0;
	for(int i=0;i<n;i++ )
	return 0;
}