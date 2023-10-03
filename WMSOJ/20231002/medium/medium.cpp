#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC optimize(2)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "medium"
#define const constexpr

namespace Main
{
	random_device rd;
	mt19937 myrand(rd());
	const int N = 2e5 + 5;
	int num[N];
	int dp[N][2];
	int tot = 0;
	int n, maxinum = 1;
	int maxans=0;
	vector<int> v;
	tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> dp0, dp1;
	void dfs(int now, bool last)
	{
		if (now > n)
		{
			sort(v.begin(),v.end());
			maxans=max(maxans,v[v.size()/2]);
			return;
		}
		if (!last)
		{
			v.push_back(num[now]);
			dfs(now + 1, 1);
			v.pop_back();
			return;
		}
		dfs(now + 1, 0);
		v.push_back(num[now]);
		dfs(now + 1, 1);
		v.pop_back();
	}
	int main()
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> num[i];
			maxinum = max(maxinum, num[i]);
		}
		if(n<=20){
			dfs(1,1);
			cout << maxans;
			return 0;
		}
		if(maxinum<=1){
			int cnt0=0,cnt1=0;
			for(int i=1;i<=n;i++){
				cnt0+=!num[i],cnt1+=num[i];
			}
			for(int i=1;i<=n;i++){
				if(!num[i]){
					--cnt0;
					i++;
				}
			}
			if(cnt0<=n/2){
				cout << 1;
			}
			else{
				cout << 0;
			}
			return 0;
		}
		dp[1][0] = 0;
		dp[1][1] = num[1];
		dp1.insert({num[1], ++tot});
		for (int now = 2; now <= n; now++)
		{
			dp[now][0] = dp[now - 1][1];
			swap(dp0, dp1);
			dp1.insert({num[now], ++tot});
			dp0.insert({num[now], ++tot});
			int medium1 = dp1.find_by_order(dp1.size() / 2)->first, medium0 = dp0.find_by_order(dp0.size() / 2)->first;
			if (medium1 > medium0)
			{
				dp[now][1] = medium1;
			}
			else
			{
				dp[now][1] = medium0;
				dp1 = dp0;
			}
			dp0.erase(dp0.lower_bound({num[now], -1}));
		}
		// dfs(n);
		cout << max(dp[n][1], dp[n][0]);
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main::main();
	return 0;
}
