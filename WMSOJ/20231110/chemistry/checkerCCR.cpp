#include "testlib_for_CCR.h"
#include <iostream>
#include <cstdio>
#include <set>
#include <cmath>
#include <map>
using namespace std;
char is[4000010];
int pt[4000010];
set<int> had[4000010];
int got[4000010], n, m, k, k1, k2, k3, k4;
int get(int x)
{
	return (pt[x] == x) ? x : (pt[x] = get(pt[x]));
}
int main(int argc, char *argv[])
{
	registerTestlibCmd(argc, argv);
	n = ouf.readInt(), m = ans.readInt();
	if (n != m)
		quitf(_wa, "0\nYou check it wrongly!");
	if (n == 0)
		quitf(_ok, "1\nYou make it!");
	m = ouf.readInt();
	for (int i = 1; i <= n; i++)
	{
		while (is[i] != 'C' && is[i] != 'N' && is[i] != 'O' && is[i] != 'H')
			is[i] = ouf.readChar();
		if (is[i] == 'C')
			k1++;
		else if (is[i] == 'H')
			k2++;
		else if (is[i] == 'O')
			k3++;
		else if (is[i] == 'N')
			k4++;
	}
	k = ans.readInt();
	if (k1 != k)
		quitf(_wa, "0\nWrong number!");
	k = ans.readInt();
	if (k2 != k)
		quitf(_wa, "0\nWrong number!");
	k = ans.readInt();
	if (k3 != k)
		quitf(_wa, "0\nWrong number!");
	k = ans.readInt();
	if (k4 != k)
		quitf(_wa, "0\nWrong number!");
	for (int i = 1; i <= n; i++)
		pt[i] = i;
	for (int i = 1, a, b, c; i <= m; i++)
	{
		a = ouf.readInt(), b = ouf.readInt(), c = ouf.readInt();
		pt[get(a)] = get(b);
		if (had[a].find(b) != had[a].end())
			quitf(_wa, "0\nYou repeat it!");
		else
			had[a].insert(b), had[b].insert(a), got[a] += c, got[b] += c;
	}
	k = get(1);
	for (int i = 2; i <= n; i++)
		if (get(i) != k)
			quitf(_wa, "0\nYou don't link all atom!");
	for (int i = 1; i <= n; i++)
	{
		if (is[i] == 'C')
		{
			if (got[i] != 4)
				quitf(_wa, "0\nWrong value!");
		}
		else if (is[i] == 'H')
		{
			if (got[i] != 1)
				quitf(_wa, "0\nWrong value!");
		}
		else if (is[i] == 'O')
		{
			if (got[i] != 2)
				quitf(_wa, "0\nWrong value!");
		}
		else if (is[i] == 'N')
		{
			if (got[i] != 3)
				quitf(_wa, "0\nWrong value!");
		}
	}
	quitf(_ok, "1\nYou make it!");
}
