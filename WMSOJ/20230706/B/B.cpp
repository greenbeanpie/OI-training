#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct node
{
	int v, w;
};
vector<node> wtm;
bool cmp(node a, node b)
{
	return a.v > b.v;
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("watermelon.in", "r", stdin);
	freopen("watermelon.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int k, n, p, sum = 0;
	cin >> k >> n >> p;
	set<int> s;
	node water[k + 1];
	for (int i = 1; i <= k; i++)
	{
		cin >> water[i].w >> water[i].v;
	}
	int t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		s.insert(t);
	}
	sort(water + 1, water + 1 + k, cmp);
	for (int i = 1; i <= k; i++)
	{
		if (s.size() && s.lower_bound(water[i].w) != s.end())
		{
			s.erase(s.lower_bound(water[i].w));
			sum += water[i].v;
		}
		else if (p)
		{
			p--;
			sum += water[i].v;
		}
		if (s.empty() && !p)
		{
			break;
		}
	}
	cout << sum;
	return 0;
}