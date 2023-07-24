#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define endl "\n"

struct node
{
	int l, r, k, lblock, rblock;
};
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> discrete;
int ori[100005], val[100005], num[1000005], cnt[100005], ans[100005], block_size,
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
	++cnt[val[pos]];
	maxinum = max(cnt[val[pos]] * num[val[pos]], maxinum);
}

void sub(int pos)
{
	--cnt[val[pos]];
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("AT_joisc2014_c.in", "r", stdin);
	freopen("AT_joisc2014_c.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	block_size = ceil(sqrt(n));
	for (int i = 1; i <= n; i++)
	{
		cin >> ori[i];
		discrete.insert(ori[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		val[i] = discrete.order_of_key(ori[i]) + 1;
		num[i] = *discrete.find_by_order(i - 1);
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> prob[i].l >> prob[i].r;
		prob[i].k = i;
		prob[i].lblock = (prob[i].l - 1) / block_size + 1;
		prob[i].rblock = (prob[i].r - 1) / block_size + 1;
	}
	sort(prob + 1, prob + 1 + q, cmp);
	int lastblock =-1;
	l=1;
	//r = (prob[1].rblock - 1) * block_size + 1, l = nowl = r + 1, maxnum = -1;
	for (int i = 1; i <= q; i++)
	{
		if (prob[i].rblock== prob[i].lblock)
		{
			int c[100005]={0};
			int maxinum = 0;
			for (int j = prob[i].l; j <= prob[i].r; j++)
			{
				++c[val[j]];
				maxinum=max(maxinum,c[val[j]]*num[val[j]]);
			}
			ans[prob[i].k] = maxinum;
			continue;
		}
		if (prob[i].lblock ^ lastblock)
		{
			lastblock = prob[i].lblock;
			while (l <= r)
			{
				sub(l++);
			}
			r = (prob[i].rblock-1)  * block_size + 1, l = nowl = r + 1;
			maxnum = 0;
		}
		while (r < prob[i].r)
		{
			add(++r, maxnum);
		}
		tempans = maxnum;
		while (l > prob[i].l)
		{
			add(--l, maxnum);
		}
		ans[prob[i].k] = maxnum;
		while (l < nowl)
		{
			sub(l++);
		}
		maxnum = tempans;
	}
	for (int i = 1; i <= q; i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}