#include <bits/stdc++.h>
using namespace std;
#define int __int128
#define ll long long
#define ull unsigned long long
#define endl "\n"

pair<int, int> exgcd(int a, int b, int &abgcd)
{ // ax+by=gcd(a,b)
	if (!b)
	{
		abgcd = a;
		return {1, 0};
	}
	auto ans = exgcd(b, a % b, abgcd);
	return {ans.second, ans.first - a / b * ans.second};
}
int excrt(pair<ll, ll>* num,int n)
{
	int m1 = num[0].second, a1 = num[0].first;
	int x, y;
	for (int i = 1; i < n; i++)
	{
		int m2 = num[i].second, a2 = num[i].first;
		// m_1 * x - m_2 * y = a2 - a1;
		int abgcd;
		pair<int,int> xy = exgcd(m1, m2, abgcd);
		int c = (a2 - a1 % m2 + m2) % m2, mod = m2 / abgcd;
		x = xy.first, y = xy.second;
		x = x * c / abgcd % mod;
		a1 += m1 * x ;
		m1 = lcm((ull)m2, (ull)m1);
		a1 = (a1 % m1 + m1) % m1;
	}
	return (a1 % m1 + m1) % m1;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P4777.in", "r", stdin);
	freopen("P4777.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	long long n;
	cin >> n;
	pair<ll, ll> num[n];
	for (int i = 0; i < n; i++)
	{
		cin >> num[i].second >> num[i].first;
	}
	
	cout << (long long)excrt(num,n);
	return 0;
}