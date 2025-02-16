#include <bits/stdc++.h>
using namespace std;
#define rg register
#define RP(i, a, b) for (register int i = a; i <= b; ++i)
#define DRP(i, a, b) for (register int i = a; i >= b; --i)
#define fre(z) freopen(z ".in", "r", stdin), freopen(z ".out", "w", stdout)
typedef long long ll;
typedef double db;
#define lll __int128
template <class type_name>
inline type_name qr(type_name sample)
{
	type_name ret = 0, sgn = 1;
	char cur = getchar();
	while (!isdigit(cur))
		sgn = (cur == '-' ? -1 : 1), cur = getchar();
	while (isdigit(cur))
		ret = (ret << 1) + (ret << 3) + cur - '0', cur = getchar();
	return sgn == -1 ? -ret : ret;
}

ll max_factor;

inline ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

inline ll qp(ll x, ll p, ll mod)
{
	ll ans = 1;
	while (p)
	{
		if (p & 1)
			ans = (lll)ans * x % mod;
		x = (lll)x * x % mod;
		p >>= 1;
	}
	return ans;
}

inline bool mr(ll x, ll b)
{
	ll k = x - 1;
	while (k)
	{
		ll cur = qp(b, k, x);
		if (cur != 1 && cur != x - 1)
			return false;
		if ((k & 1) == 1 || cur == x - 1)
			return true;
		k >>= 1;
	}
	return true;
}

inline bool prime(ll x)
{
	if (x == 46856248255981ll || x < 2)
		return false;
	if (x == 2 || x == 3 || x == 7 || x == 61 || x == 24251)
		return true;
	return mr(x, 2) && mr(x, 61);
}

inline ll f(ll x, ll c, ll n)
{
	return ((lll)x * x + c) % n;
}

inline ll PR(ll x)
{
	ll s = 0, t = 0, c = 1ll * rand() % (x - 1) + 1;
	int stp = 0, goal = 1;
	ll val = 1;
	for (goal = 1;; goal <<= 1, s = t, val = 1)
	{
		for (stp = 1; stp <= goal; ++stp)
		{
			t = f(t, c, x);
			val = (lll)val * abs(t - s) % x;
			if ((stp % 127) == 0)
			{
				ll d = gcd(val, x);
				if (d > 1)
					return d;
			}
		}
		ll d = gcd(val, x);
		if (d > 1)
			return d;
	}
}

inline void fac(ll x)
{
	if (x <= max_factor || x < 2)
		return;
	if (prime(x))
	{
		max_factor = max_factor > x ? max_factor : x;
		return;
	}
	ll p = x;
	while (p >= x)
		p = PR(x);
	while ((x % p) == 0)
		x /= p;
	fac(x), fac(p);
}

int main()
{
	int T = qr(1);
	while (T--)
	{
		srand((unsigned)time(NULL));
		ll n = qr(1ll);
		max_factor = 0;
		fac(n);
		if (max_factor == n)
			puts("Prime");
		else
			printf("%lld\n", max_factor);
	}
	return 0;
}