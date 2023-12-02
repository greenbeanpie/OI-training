#include <bits/stdc++.h>

#define i64 long long
#define all(x) x.begin(), x.end()
#define seg(a, l, r) a + l, a + r + 1
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

const int N = 1e5 + 5;

int n, m;
int siz[N], dat[N], val[N], rev[N], fa[N];
int son[N][2];

#define ls(u) son[u][0]
#define rs(u) son[u][1]

void pushUp(int u)
{
	siz[u] = siz[ls(u)] + siz[rs(u)] + 1;
	dat[u] = dat[ls(u)] ^ dat[rs(u)] ^ val[u];
}

void reverse(int u)
{
	swap(ls(u), rs(u));
	rev[u] ^= 1;
}

void pushDown(int u)
{
	if (rev[u])
	{

		if (ls(u))
			reverse(ls(u));
		if (rs(u))
			reverse(rs(u));

		rev[u] = 0;
	}
}

int get(int x)
{
	return rs(fa[x]) == x;
}

bool isRoot(int x)
{
	return ls(fa[x]) != x && rs(fa[x]) != x;
}

void update(int x)
{
	if (!isRoot(x))
		update(fa[x]);
	pushDown(x);
}

void rotate(int x)
{
	int y = fa[x], z = fa[y];
	int fx = get(x), fy = get(y);

	if (!isRoot(y))
		son[z][fy] = x;
	fa[x] = z;

	son[y][fx] = son[x][fx ^ 1];
	fa[son[x][fx ^ 1]] = y;
	// assert(son[x][fx ^ 1] != 0);

	son[x][fx ^ 1] = y;
	fa[y] = x;

	pushUp(y);
	pushUp(x);
}

void splay(int x)
{
	update(x);

	for (int y = fa[x]; !isRoot(x); rotate(x))
	{
		y = fa[x];

		if (!isRoot(y))
		{
			if (get(x) == get(y))
				rotate(y);
			else
				rotate(x);
		}
	}
}

int access(int x)
{
	int last = 0;
	for (last = 0; x; x = fa[x])
	{
		splay(x);

		rs(x) = last;
		last = x;

		pushUp(x);
	}

	return last;
}

void makeRoot(int x)
{
	access(x);
	splay(x);
	reverse(x);
}

void split(int x, int y)
{
	makeRoot(x);
	access(y);
	splay(y);
}

int findRoot(int x)
{
	access(x);
	splay(x);
	while (ls(x))
	{
		pushDown(x);
		x = ls(x);
	}

	splay(x);

	return x;
}

void link(int x, int y)
{
	makeRoot(x);

	if (findRoot(y) == x)
		return;

	fa[x] = y;
}

void cut(int x, int y)
{
	split(x, y);
	if (ls(y) == x && !rs(y))
		ls(y) = fa[x] = 0;
}

void FileIO(string s)
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
#ifndef ONLINE_JUDGE
	FileIO("P3690");
#endif

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	rep(i, 1, n)
	{
		cin >> val[i];
		dat[i] = val[i];
	}

	while (m--)
	{
		int op, x, y;
		cin >> op >> x >> y;

		if (op == 0)
		{
			split(x, y);
			cout << dat[y] << "\n";
		}

		if (op == 1)
			link(x, y);
		if (op == 2)
			cut(x, y);
		if (op == 3)
		{
			splay(x);
			val[x] = y;
		}
	}

	return 0;
}