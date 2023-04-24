#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const double ff = 1e-4;

double su[100005];
int n, s, t, m;

struct ab
{
	int l;
	double v;
} que[100005];

bool chk(double k)
{
	for (int i = 1; i <= n; ++i)
	{
		su[i] -= i * k;
	}
	su[0] = 0;

	bool fl = false;
	int hd = 1, tl = 1;
	for (int i = 0; i < m; ++i)
	{
		while (tl > hd && que[tl - 1].v >= su[i])
		{
			--tl;
		}
		que[tl].l = i;
		que[tl++].v = su[i];
		if (su[i + s] - que[hd].v >= 0)
		{
			fl = true;
			break;
		}
	}
	
	if (!fl)
	{
		for (int i = m; i <= n - s; ++i)
		{
			while (hd < tl && que[hd].l + m <= i)
			{
				++hd;
			}
			while (tl > hd && que[tl - 1].v >= su[i])
			{
				--tl;
			}
			que[tl].l = i;
			que[tl++].v = su[i];
			if (su[i + s] - que[hd].v >= 0)
			{
				fl = true;
				break;
			}
		}
	}
	
	for (int i = 1; i <= n; ++i)
	{
		su[i] += i * k;
	}
	return fl;
}

int main()
{
	scanf("%d", &n);
	scanf("%d%d", &s, &t);
	m = t - s + 1;
	su[0] = 0;
	double ll = 0, rr = 0;
	for (int i = 1; i <= n; ++i)
	{
		double xx;
		scanf("%lf", &xx);
		su[i] = su[i - 1] + xx;
		ll = min(ll, xx);
		rr = max(rr, xx);
	}
	while (ll + ff * 5 <= rr)
	{
		double mid = (ll + rr) / 2;
		if (chk(mid))
		{
			ll = mid;
		}
		else
		{
			rr = mid;
		}
	}
	while (chk(ll))
	{
		ll += ff;
	}
	printf("%.3f", ll - ff);
	return 0;
}
