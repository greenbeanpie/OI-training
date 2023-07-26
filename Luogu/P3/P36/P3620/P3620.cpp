#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define endl "\n"

struct node
{
	int l, r, val;
};
bool operator<(node a, node b)
{
	return a.val < b.val;
}
bool operator>(node a, node b)
{
	return a.val > b.val;
}
int myhash(int l, int r)
{
	return l * 10005 + r;
}
int num[100005];
int chafen[100005];
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P3620.in", "r", stdin);
	freopen("P3620.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	std::priority_queue<node, vector<node>, greater<node>> pq;
	cc_hash_table<int, bool> vis;
	int n, k;
	cin >> n >> k;
	cin >> num[1];
	chafen[1] = num[1];
	for (int i = 2; i <= n; i++)
	{
		cin >> num[i];
		chafen[i] = num[i] - num[i - 1];
		pq.push({i - 1, i, chafen[i]});
	}
	int sum = 0;
	for (int i = 1, tot = 0; tot < k; i++)
	{
		auto now = pq.top();
		pq.pop();
		if (vis.find(myhash(now.l,now.r))==vis.end()||!vis[myhash(now.l, now.r)])
		{
			vis[myhash(now.l - 1, now.l)] = true;
			vis[myhash(now.r, now.r + 1)] = true;
			vis[myhash(now.l, now.r)] = true;
			sum += now.val;
			tot++;
			if (now.l > 1 && now.r < n)
			{
				pq.push({now.l - 1, now.r + 1, chafen[now.l - 1] + chafen[now.r + 1]});
			}
		}
	}
	cout << sum << endl;
	return 0;
}