#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
const int B = 350;
template <class T>
void read(T &x)
{
	char c;
	bool op = 0;
	while (c = getchar(), c < '0' || c > '9')
		if (c == '-')
			op = 1;
	x = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')
		x = x * 10 + c - '0';
	if (op)
		x = -x;
}
int qu[N];
int qv[N];
int rk[N];
int val[N];
int n;
int m;
int cntb[N / B + 3];
int pl[N / B + 3];
int pr[N / B + 3];
int ve[N];
int nx[N];
int al[N];
int ans[N];
int ctt;
inline void add(int u, int V)
{
	ve[++ctt] = V;
	nx[ctt] = al[u];
	al[u] = ctt;
}
namespace lsh // 离散化
{
	inline bool cmp(const int &x, const int &y) { return val[x] < val[y]; }
	inline void pre()
	{
		for (int i = 1; i <= n; i++)
			ans[i] = i;
		sort(ans + 1, ans + n + 1, cmp);
		for (int i = 1; i <= n; i++)
			rk[ans[i]] = i;
		for (int i = 1; i <= n; i++)
			ans[rk[i]] = val[i];
		for (int i = 1; i <= n; i++)
			val[i] = ans[i];
		val[n + 1] = -1;
		for (int i = 1; i <= n; i++)
			pr[(i - 1) / B + 1] = i;
		for (int i = n; i >= 1; i--)
			pl[(i - 1) / B + 1] = i;
	}
}
struct bcj // 并查集
{
	int fa[N];
	int tot[N];
	int x[20 * N];
	int v[20 * N];
	int ct;
	int al[N];
	inline void add(int u, int V)
	{
		v[++ct] = V;
		x[ct] = al[u];
		al[u] = ct;
	}
	inline void mglist(int p, int q) // 归并两个有序链表，注意不要新开多余的节点
	{
		int t;
		int i = al[p];
		int j = al[q];
		int k1 = v[i] & 32767;
		int k2 = v[j] & 32767;
		if (k1 == k2)
			v[i] = (((v[i] >> 15) + (v[j] >> 15)) << 15) | k1, t = i, i = x[i], j = x[j];
		else if (k1 < k2)
			t = i, i = x[i];
		else
			v[++ct] = v[j], al[p] = ct, t = ct, j = x[j];
		while (i && j)
		{
			int k1 = v[i] & 32767;
			int k2 = v[j] & 32767;
			if (k1 == k2)
				v[i] = (((v[i] >> 15) + (v[j] >> 15)) << 15) | k1, x[t] = i, t = i, i = x[i], j = x[j];
			else if (k1 < k2)
				x[t] = i, t = i, i = x[i];
			else
				v[++ct] = v[j], x[t] = ct, t = ct, j = x[j];
		}
		while (i)
			x[t] = i, t = i, i = x[i];
		while (j)
			v[++ct] = v[j], x[t] = ct, t = ct, j = x[j];
		x[t] = 0;
	}
	inline void splist(int p, int q, int ti) // 分裂两个有序链表
	{
		for (int i = al[q]; i; i = x[i])
			cntb[v[i] & 32767] += (v[i] >> 15);
		while (al[p] > ti)
			al[p] = x[al[p]];
		int t = al[p];
		v[t] = (((v[t] >> 15) - (cntb[v[t] & 32767])) << 15) | (v[t] & 32767);
		for (int i = x[al[p]]; i; i = x[i])
			if (i <= ti)
			{
				int k = v[i] & 32767;
				v[i] = (((v[i] >> 15) - cntb[k]) << 15) | k, x[t] = i, t = i;
			}
		ct = ti;
		for (int i = al[q]; i; i = x[i])
			cntb[v[i] & 32767] = 0;
		x[t] = 0;
	}
	inline void f(int &x)
	{
		for (; x != fa[x]; x = fa[x])
			;
	}
	inline int ck(int x)
	{
		for (; x != fa[x]; x = fa[x])
			;
		return x;
	}
	inline void ih()
	{
		for (int i = 1; i <= n; i++)
			fa[i] = i;
		for (int i = 1; i <= n; i++)
			tot[i] = 1;
		for (int i = 1; i <= n; i++)
			add(i, (1 << 15) | ((i - 1) / B + 1));
	}
	inline void lk(int &u, int &V) // 连边
	{
		f(u);
		f(V);
		if (u == V)
			return;
		if (tot[u] < tot[V])
			swap(u, V);
		tot[u] += tot[V];
		fa[V] = u;
		mglist(u, V);
	}
	inline void del(int u, int V, int ti)
	{
		fa[V] = V;
		tot[u] -= tot[V];
		splist(u, V, ti);
	}											   // 删除边
	inline int brukth(int id, int l, int r, int k) // 暴力查询kth
	{
		for (int i = l; i <= r; i++)
		{
			k -= (id == ck(i));
			if (!k)
				return i;
		}
	}
	inline int kth(int u, int k)
	{
		f(u);
		if (k > tot[u])
			return n + 1;
		for (int i = al[u]; i; i = x[i])
			if (k > (v[i] >> 15))
				k -= (v[i] >> 15);
			else
				return brukth(u, pl[v[i] & 32767], pr[v[i] & 32767], k);
	}
} bcj;
inline void dfs(int u) // 在操作树上dfs
{
	if (u < 0)
	{
		ans[-u] = bcj.kth(qu[-u], qv[-u]);
		return;
	}
	int curt;
	if (u != 1)
		curt = bcj.ct, bcj.lk(qu[u], qv[u]);
	for (int i = al[u]; i; i = nx[i])
		dfs(ve[i]);
	if (u != 1 && qu[u] != qv[u])
		bcj.del(qu[u], qv[u], curt);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("P5064.in", "r", stdin);
	freopen("P5064_TJ.out", "w", stdout);
#endif
	read(n);
	read(m);
	for (int i = 1; i <= n; i++)
		read(val[i]);
	lsh::pre();
	bcj.ih();
	ans[1] = 1;
	for (int i = 2, typ, x, fa = 1; i <= m + 1; i++)
	{
		read(typ);
		switch (typ)
		{
		case 1:
		{
			read(qu[i]);
			read(qv[i]);
			qu[i] = rk[qu[i]];
			qv[i] = rk[qv[i]];
			ans[i] = i;
			add(fa, i);
			fa = i;
			break;
		}
		case 2:
		{
			read(x);
			x++;
			fa = ans[x];
			ans[i] = fa;
			break;
		}
		case 3:
		{
			read(qu[i]);
			read(qv[i]);
			qu[i] = rk[qu[i]];
			add(fa, -i);
			ans[i] = ans[i - 1];
			break;
		}
		}
	}
	for (int i = 2; i <= m + 1; i++)
		ans[i] = -2;
	dfs(1);
	for (int i = 2; i <= m + 1; i++)
		if (ans[i] != -2)
			printf("%d\n", val[ans[i]]);
	return 0; // 拜拜程序~
}
