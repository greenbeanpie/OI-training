#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct node
{
	int u, v;
};
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("shopping.in", "r", stdin);
	freopen("shopping.out", "w", stdout);
#endif
	int T;
	cin >> T;
	while (T--)
	{
		int n, s;
		cin >> n >> s;
		node t[n];
		int a=0;
		for (int i = 0; i < n; i++)
		{
			cin >> t[i].u;
			a+=t[i].u;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> t[i].v;
		}
		int maxinum=0;
		for(int i=1;i<=min(a,s);i++){
			int sum=0,val=0;
			for(int j=0;j<n;j++){
				if(sum+t[j].u<=i){
					sum+=t[j].u;
					val+=t[j].v;
				}
			}
			maxinum=max(maxinum,val);
		}
		cout << maxinum << endl;
	}
	return 0;
}