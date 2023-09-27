#include <iostream>
#include <ctime>
// using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#pragma GCC optimize("Ofast")
#define int long long
#define endl "\n"
#define problemname "divide"
#define const constexpr
const __float128 eps = 1e-16;
#pragma GCC optimize("Ofast")

void read(__float128 &_x)
{
	__float128 integer = 0, floating = 0, now = 1;
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

void write(__float128 _x)
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
__float128 fabs(__float128 _x)
{
	return _x >= 0 ? _x : -_x;
}

namespace Main
{

	int main()
	{
		double st = clock();
		__float128 num;
		read(num);
		if (num >= 1)
		{
			cout << "1 1";
			return 0;
		}
		int start = 1;
		for (int a = start; a <= 1e9; a++)
		{
			int b = a / num + 0.5;
			if (fabs((__float128)a / b - num) <= eps)
			{
				cout << a << " " << b;
				return 0;
			}
		}

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