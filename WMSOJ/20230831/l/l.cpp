#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "l"
#define const constexpr

namespace Main
{

	vector<int> e[41];
	struct prob
	{
		int s, t, l, r, id;
	} p[1005];
	bool cmp(prob a, prob b)
	{
		return a.s < b.s;
	}
	int n, m, q, a, b, s, t, l, r;
	// void bfs(int u){
	// 	bitset<41> vis;
	// 	queue<int> q;
	// 	q.push(u);
	// 	vis[u] = 1;
	// 	while (q.size())
	// 	{
	// 		auto now=q.front();
	// 		q.pop();
	// 		for(auto i:e[now]){
	// 			if (!min_dis[u][i])
	// 			{
	// 				vis[i] = 1;
	// 				q.push(i);
	// 				min_dis[u][i] = min_dis[u][now] + 1;
	// 				++cnt[u][i];
	// 			}
	// 			else if(min_dis[u][i]==min_dis[u][now]+1){
	// 				++cnt[u][i];
	// 			}
	// 		}
	// 	}
	// }
	int ans = 0;
	void dfs(int now, int t, int l, int r, int stp)
	{
		if (stp > r)
		{
			return;
		}
		if (stp == r)
		{
			if (now == t)
			{
				++ans;
			}
			return;
		}
		if (stp >= l)
		{
			++ans;
		}
		for (int i : e[now])
		{
			dfs(i, t, l, r, stp + 1);
		}
	}
	int main()
	{
		cin >> n >> m;
		for (int i = 1; i <= m; i++)
		{
			cin >> a >> b;
			e[a].push_back(b);
			e[b].push_back(a);
		}
		cin >> q;
		for (int i = 1; i <= q; i++)
		{
			cin >> p[i].s >> p[i].t >> p[i].l >> p[i].r;
		}
		for (int i = 1; i <= q; i++)
		{
			dfs(p[i].s, p[i].t, p[i].l, p[i].r, 0);
			cout << ans << endl;
			ans = 0;
		}
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