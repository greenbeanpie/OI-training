#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"

/*struct frac
{
	double up, down;
	double operator&()
	{
		return (double)up / (double)down;
	}
	frac(int a, int b)
	{
		up = a, down = b;
	}
};
bool operator<(frac a, frac b)
{
	return a.up / a.down < b.up / b.down;
}
bool operator<(frac a, double b)
{
	return a.up / a.down < b;
}
bool operator>(frac a, double b)
{
	return a.up / a.down > b;
}*/
void solve(int a, int b, int c, int d, int &p, int &q)
{
	/*frac num1(a, b), num2(c, d);
	if (num1 < (double)1 && num2 > (double)1)
	{
		p = q = 1;
		return;
	}*/
	if (a < b && c > d)
	{
		p = q = 1;
		return;
	}
	// int x = a / b;
	int x = d / c;
	solve(d - x * c, c, b - x * a, a, q, p);
	q += x * p;
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P5179.in", "r", stdin);
	freopen("P5179.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int a, b, c, d;
	while (cin >> a >> b >> c >> d)
	{
		int p, q;
		solve(a, b, c, d, p, q);
		cout << p << "/" << q << endl;
	}
	return 0;
}