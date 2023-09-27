#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const double eps = 1e-15;
#define problemname "P1298"
int n, m;
double x;

int sgn(double x) { return (x > eps) - (x < -eps); }
int main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname "_TJ.out", "w", stdout);
#endif
	scanf("%d%d", &m, &n);
	scanf("%lf", &x);
	int lm = 0, ln = 1, rm = 1, rn = 0;
	for (int mm = 1, nn = 1; mm <= m && nn <= n; mm = lm + rm, nn = ln + rn)
	{
		switch (sgn(x * nn - mm))
		{
		case 0:
		{
			printf("%d/%d\n", mm, nn);
			return 0;
		}
		case 1:
			lm = mm, ln = nn;
			break;
		case -1:
			rm = mm, rn = nn;
			break;
		}
	}
	if (rn == 0)
	{
		printf("%d/%d\n", lm, ln);
		return 0;
	}
	switch (sgn((x - 1. * lm / ln) - (1. * rm / rn - x)))
	{
	case 1:
		printf("%d/%d\n", rm, rn);
		break;
	case 0:
		puts("TOO MANY");
		break;
	case -1:
		printf("%d/%d\n", lm, ln);
	}
}