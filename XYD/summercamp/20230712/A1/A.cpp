#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
ll n, p, c, a[1000], tot, ans;
vector<ll> s;
vector<pair<ll, ll>> t;
ll m_pow(ll a, ll b) // 快速幂，求逆元
{
	ll ans = 1;
	while (b)
	{
		if (b & 1)
			ans = (ans * a) % p;
		b >>= 1;
		a = (a * a) % p;
	}
	return ans;
}
void dfs1(ll x, ll l, ll r, ll sum) // 用dfs求出每一个乘积
{
	if (x == r + 1)
	{
		ll ne;
		ne = (m_pow(sum, p - 2) * c) % p; // 将每一乘积需要的答案压入数组
		s.push_back(ne);
		return;
	}
	dfs1(x + 1, l, r, sum);
	dfs1(x + 1, l, r, (sum * a[x]) % p);
}
void dfs2(ll x, ll l, ll r, ll sum)
{
	if (x == r + 1)
	{
		vector<pair<ll, ll>>::iterator it;
		it = lower_bound(t.begin(), t.end(), make_pair(sum, (ll)0)); // 进行匹配
		if ((*it).first == sum)
			ans = (ans + (*it).second) % mod;
		return;
	}
	dfs2(x + 1, l, r, sum);
	dfs2(x + 1, l, r, (sum * a[x]) % p);
}
int main()
{
	scanf("%lld%lld%lld", &n, &p, &c);
	for (ll i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	if (c >= p)
	{
		printf("0\n");
		return 0;
	}
	for (ll i = 1; i <= n; i++)
		a[i] %= p;
	dfs1(1, 1, n / 2, 1);
	sort(s.begin(), s.end());
	ll kind = s[0], w = 1;
	for (ll i = 1; i < (ll)s.size(); i++)
	{
		if (s[i] == kind)
			w++;
		else
		{
			t.push_back(make_pair(kind, w));
			w = 1;
			kind = s[i];
		}
	}
	t.push_back(make_pair(kind, w));
	tot = 0;
	dfs2(n / 2 + 1, n / 2 + 1, n, 1);
	if (c == 1)
		ans = (ans - 1) % mod;
	printf("%lld\n", ans % mod);
}