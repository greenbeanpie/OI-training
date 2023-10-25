#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
typedef pair<long long, long long> PII;
mt19937 rnd(time(0));
long long t, n, a[N], ans, hsh[N], sta[N], top, hsh2[N];
map<PII, long long> mp;
inline void sol()
{
	top = ans = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n + 5; ++i)
		hsh[i] = rnd(), hsh2[i] = rnd();
	long long now = 0, n2 = 0;
	mp.clear();
	mp[{0, 0}] = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (top && sta[top] == a[i])
			--top, now ^= (hsh[top + 1] * a[i]), n2 += (hsh[top + 1] ^ a[i]);
		else
			sta[++top] = a[i], now ^= (hsh[top] * a[i]), n2 -= (hsh[top] ^ a[i]);
		ans += mp[{now, n2}];
		mp[{now, n2}]++;
	}
	cout << ans << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--)
		sol();
	return 0;
}