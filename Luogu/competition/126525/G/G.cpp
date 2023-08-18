#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "G"
#define const constexpr
const int N = 1e5 + 10;

struct node
{
	int val, cnt;
};
bool operator<(node a, node b)
{
	return a.val < b.val;
}

int numa[N], numb[N], val[N];
std::priority_queue<node> side[N];

template <typename T>
void clear(std::priority_queue<T> &q)
{
	std::priority_queue<T> q1;
	swap(q, q1);
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		numa[0] = numb[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			clear(side[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> val[i];
			numa[i] = val[i] - i;
			numb[i] = numa[i];
		}
		sort(numb + 1, numb + 1 + n);
		int bend = unique(numb + 1, numb + 1 + n) - numb;
		for (int i = 1; i <= n; i++)
		{
			numa[i] = lower_bound(numb + 1, numb + 1 + bend, numa[i]) - numb;
		}

		for (int i = 1; i <= n; i++)
		{
			side[numa[i]].push({val[i], i});
		}
		int sum = 0;
		for (int i = 1; i <= n && side[i].size(); i++)
		{
			int cnt = 0;
			while (side[i].size() > 1)
			{
				int a, b;
				a = side[i].top().val;
				side[i].pop();
				b = side[i].top().val;
				side[i].pop();
				if (a + b > 0)
				{
					sum += a + b;
				}
				else
				{
					break;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}