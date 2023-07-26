#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define endl "\n"

int num[100005];

void mysort(int *Begin, int *End, bool op)
{
	unordered_map<int, int> cnt;
	for (auto i = Begin; i != End; i++)
	{
		cnt[*i]++;
	}
	if (op)
	{
		auto now = End;
		for (auto i : cnt)
		{
			for (int j = 1; j <= i.second; j++)
			{
				*--now = i.first;
			}
		}
	}
	else
	{
		auto now = Begin;
		for (auto i : cnt)
		{
			for (int j = 1; j <= i.second; j++)
			{
				*now++ = i.first;
			}
		}
	}
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P2824.in", "r", stdin);
	freopen("P2824.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
	}
	int op, l, r;
/	for (int i = 1; i <= m; i++)
	{
		cin >> op >> l >> r;
		mysort(num + l, num + 1 + r, op);
	}
	int pos;
	cin >> pos;
	cout << num[pos];
	return 0;
}