#include "testlib.h"
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define int long long

const int N = 1005;

string c[80];

bitset<N> vis1, vis2;

bitset<N> ask[N];

int n, m;

bool check(int l, int r)
{

	vis1.set(), vis2.set();
	bool flag1 = 0, flag2 = 0;
	for (int i = 1; i <= m; i++)
	{
		if (ask[i][l])
		{
			flag1 = 1;
			vis1 &= ask[i];
		}
		if (ask[i][r])
		{
			flag2 = 1;
			vis2 &= ask[i];
		}
	}
	if (!flag1 || !flag2)
	{
		return 0;
	}
	if (((vis1.count() == 2 && vis1[r]) || vis1.count() == 1) && ((vis2.count() == 2 && vis2[l]) || vis2.count() == 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

signed main(signed argc, char *argv[])
{
	registerTestlibCmd(argc, argv);

	n = inf.readLong(), m = ouf.readLong();
	int pts;
	if (m > 75)
	{
		quitf(_wa, "You asked %lld times, do you play Genshin Impact?", m);
	}
	else if (m > 40)
	{
		pts = 95 - m;
	}
	else if (m > 35)
	{
		pts = 135 - 2 * m;
	}
	else if (m > 30)
	{
		pts = 170 - 3 * m;
	}
	else if (m > 26)
	{
		pts = 230 - 5 * m;
	}
	else
	{
		pts = 100;
	}
	// ouf.readEoln();
	for (int i = 1; i <= m; i++)
	{
		// ouf.readEoln();
		ouf.nextLine();
		for (int j = 1; j <= n; j++)
		{
			ask[i][j] = ouf.readChar() - '0';
		}
	}
	ouf.close();
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = i; j <= n; j++)
		{
			if (!check(i, j))
			{
				++cnt;
			}
		}
		if (cnt > 1)
		{
			quitf(_wa, "Your asks can't get proper positions. Do you play Genshin Impact?");
			return 0;
		}
	}
	if (pts == 100)
	{
		quitf(_ok, "You get an accepted result in this case. Let's play Genshin Impact!");
	}
	else
	{
		quitf((TResult)(16 + pts), "You asked too many times so you only get %lld points this time. Play less Genshin Impact next time!", pts);
	}
	return 0;
}
