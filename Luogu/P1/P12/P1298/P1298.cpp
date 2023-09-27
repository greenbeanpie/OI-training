#include <iostream>
#include <ctime>
// using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
// #pragma GCC optimize("Ofast")
#define int long long
#define double long double
#define endl "\n"
#define problemname "P1298"
#define const constexpr
const double eps = 1e-16;
// #pragma GCC optimize("Ofast")

void read(double &_x)
{
	double integer = 0, floating = 0, now = 1;
	char c = getchar();
	while (c != '.')
	{
		integer = integer * 10 + (c - '0');
		c = getchar();
	}
	for (int i = 1; i <= 19; i++)
	{
		now /= 10;
		c = getchar();
		floating += (c - '0') * now;
	}
	_x = integer + floating;
}

void write(double _x)
{
	cout << (int)_x << ".";
	_x -= (int)_x;
	while (_x)
	{
		_x *= 10;
		cout << (int)_x;
		_x -= (int)_x;
	}
}
double fabs(double _x)
{
	return _x >= 0 ? _x : -_x;
}

namespace Main
{

	int main()
	{
		int m, n;
		cin >> m >> n;
		double st = clock();
		double num;
		cin >> num;
		double ans = 10000000;
		int ansa, ansb,cnt=0;
		for (int a = 1; a <= m; a++)
		{
			int b = (double)a / num + 0.5;
			if (b == 0)
				continue;
			if (b > n)
			{
				break;
			}
			if (fabs((double)a / b - num) < ans)
			{
				cnt = 1;
				ans = fabs((double)a / b - num);
				ansa = a, ansb = b;
			}
			else if (fabs((double)a / b - num) == ans){
				++cnt;
			}
		}

		cout << ansa << "/" << ansb;
		
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