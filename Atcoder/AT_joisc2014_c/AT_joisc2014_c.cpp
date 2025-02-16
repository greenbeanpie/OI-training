#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"
int read()
{
	int x = 0, f = 1;
	char c = getchar();
	while (!isdigit(c))
	{
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (isdigit(c))
		x = x * 10 + c - '0', c = getchar();
	return x * f;
}
struct node
{
	int l, r, k, lblock, rblock;
};
int a[100005], b[100005], cnt[100005], ans[100005], block_size,
	l, r, maxnum, n, q, tempans, nowl;
node prob[100005];
bool cmp(node a, node b)
{
	if (a.lblock == b.lblock)
	{
		return a.r < b.r;
	}
	return a.lblock < b.lblock;
}

void add(int pos, int &maxinum)
{
	++cnt[a[pos]];
	maxinum = max(cnt[a[pos]] * b[a[pos]], maxinum);
}

void sub(int pos)
{
	--cnt[a[pos]];
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("AT_joisc2014_c.in", "r", stdin);
	freopen("AT_joisc2014_c.out", "w", stdout);
#endif
	n = read(), q = read();
	block_size = sqrt(n);
	for (int i = 1; i <= n; i++)
	{
		a[i] = b[i] = read();
	}
	sort(b + 1, b + 1 + n);
	int len = unique(b + 1, b + 1 + n) - b - 1;
	for (int i = 1; i <= n; ++i)
	{
		a[i] = lower_bound(b + 1, b + 1 + len, a[i]) - b;
	}
	// for (int i = 1; i <= n; i++)
	for (int i = 1; i <= q; i++)
	{
		prob[i].l = read(), prob[i].r = read();
		prob[i].k = i;
		prob[i].lblock = (prob[i].l - 1) / block_size + 1;
		prob[i].rblock = (prob[i].r - 1) / block_size + 1;
	}
	sort(prob + 1, prob + 1 + q, cmp);
	int lastblock = -1;
	l = 1;
	// r = (prob[1].rblock - 1) * block_size + 1, l = nowl = r + 1, maxnum = -1;
	int now = 1;
	for (int i = 1; i <= ceil(1.0*n/block_size); i++)
	{
		memset(cnt,0,sizeof(cnt));
		r = i * block_size + 1, l = nowl = r + 1;
		maxnum = -1;
		while (prob[now].lblock == i)
		{
			if (prob[now].rblock == prob[now].lblock)
			{
				static int cnt[100005];
				tempans=maxnum;
				for (int j = prob[now].l; j <= prob[now].r; j++)
				{
					++cnt[a[j]];
					maxnum = max(maxnum, cnt[a[j]] * b[a[j]]);
				}
				ans[prob[now].k] = maxnum;
				for (int j = prob[now].l; j <= prob[now].r; j++)
				{
					--cnt[a[j]];
				}
				maxnum=tempans;
				now++;
				continue;
			}
			while (r < prob[now].r)
			{
				add(++r, maxnum);
			}
			tempans = maxnum;
			while (l > prob[now].l)
			{
				add(--l, maxnum);
			}
			ans[prob[now].k] = maxnum;
			while (l < nowl)
			{
				sub(l++);
			}
			maxnum = tempans;
			now++;
		}
	}
	for (int i = 1; i <= q; i++)
	{
		printf("%lld\n", ans[i]);
	}
	return 0;
}