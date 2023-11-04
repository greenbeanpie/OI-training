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

__int128_t ask[N];

int n, m;

signed main(signed argc, char *argv[])
{
#ifdef CODESPACE
	char *temp[] = {"checker", "permutation.in", "permutation.out", "permutation.ans"};
	registerTestlibCmd(4, temp);
#endif
#ifndef CODESPACE
	registerTestlibCmd(argc, argv);
#endif
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
	for (int i = 1; i <= m; i++)
	{
		// ouf.readEoln();
		ouf.nextLine();
		for (int j = 1; j <= n; j++)
		{
			int ch = ouf.readChar() - '0';
			if (ch)
				ask[j] |= ((__int128_t)1 << (i - 1));
		}
	}
	ouf.close();

	set<__int128_t> s;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (s.count(ask[i] | ask[j]))
			{
				quitf(_wa, "Your asks can't get proper positions. Do you play Genshin Impact?");
			}

			s.insert(ask[i] | ask[j]);
		}
	}
	if (pts == 100)
	{
		quitf(_ok, "You code has accepted. Let's play Genshin Impact!");
	}
	else
	{
		quitf((TResult)(16 + pts), "You asked too many times so you only get %lld points this time. Play less Genshin Impact next time!", pts);
	}
	return 0;
}
