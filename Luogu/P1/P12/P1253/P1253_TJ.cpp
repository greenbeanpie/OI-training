#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>

typedef long long int ll;

const int maxn = 1000006;

ll nul = 1e18;

int n, q;
int a[maxn];

struct Node
{
	int l, r;
	ll w, t1, t2;
	Node *ls, *rs;

	void make_tag1(ll x)
	{
		w = t1 = x;
		t2 = 0;
	}

	void make_tag2(ll x)
	{
		w += x;
		if (t1 != nul)
			t1 += x;
		else
			t2 += x;
	}

	void pushdown()
	{
		if (t1 != nul)
		{
			ls->make_tag1(t1);
			rs->make_tag1(t1);
			t1 = nul;
		}
		else if (t2)
		{
			ls->make_tag2(t2);
			rs->make_tag2(t2);
			t2 = 0;
		}
	}

	void pushup() { w = std::max(ls->w, rs->w); }

	bool InRange(int L, int R) { return (L <= l) && (r <= R); }
	bool OutofRange(int L, int R) { return (l > R) || (r < L); }

	void upd(int L, int R, int x, int op)
	{
		if (InRange(L, R))
		{
			if (op == 1)
				make_tag1(x);
			else
				make_tag2(x);
		}
		else if (!OutofRange(L, R))
		{
			pushdown();
			ls->upd(L, R, x, op);
			rs->upd(L, R, x, op);
			pushup();
		}
	}

	ll qry(int L, int R)
	{
		if (InRange(L, R))
			return w;
		else if (!OutofRange(L, R))
		{
			pushdown();
			return std::max(ls->qry(L, R), rs->qry(L, R));
		}
		else
			return -nul;
	}
};

Node Mem[maxn << 1], *pool = Mem;

Node *New(int L, int R)
{
	auto u = pool++;
	u->l = L;
	u->r = R;
	u->t1 = nul;
	u->t2 = 0;
	if (L != R)
	{
		int M = (L + R) >> 1;
		u->ls = New(L, M);
		u->rs = New(M + 1, R);
		u->pushup();
	}
	else
	{
		u->w = a[L];
	}
	return u;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("P1253_6.in", "r", stdin);
	freopen("P1253_TJ.out", "w", stdout);
#endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> n >> q;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> a[i];
	}
	auto rot = New(1, n);
	for (int op, l, r, x; q; --q)
	{
		std::cin >> op >> l >> r;
		if (op != 3)
		{
			std::cin >> x;
			rot->upd(l, r, x, op);
		}
		else
		{
			std::cout << rot->qry(l, r) << '\n';
		}
	}
	return 0;
}