#include <bits/stdc++.h>

#define int long long 
#define x first
#define y second
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define ls u << 1
#define rs u << 1 |1


using namespace std;

const int N = 1e5 + 10;

int dp[N];
vector<pair<int, int>> tz[N];
struct tree
{
	int l, r;
	int maxx;
	int add;
}tr[N << 2];
int n, m, k, d;

void eval(int u, int add)
{
	tr[u].maxx += add;
	tr[u].add += add;
}

void pushdown(int u)
{
	if(tr[u].add)
	{
		eval(ls, tr[u].add);
		eval(rs, tr[u].add);
		tr[u].add = 0;
	}
}

void pushup(int u)
{
	tr[u].maxx = max(tr[ls].maxx, tr[rs].maxx);
}

void modify(int u, int l, int r, int v)
{
	if(tr[u].l >= l && tr[u].r <= r) 
	{
		eval(u, v);
		return ;
	}
	pushdown(u);
	int mid = (tr[u].l + tr[u].r) >> 1;
	if(l <= mid) modify(ls, l, r, v);
	if(r > mid) modify(rs, l, r, v);
	pushup(u);
}

int query(int u, int l, int r)
{
	if(tr[u].l >= l && tr[u].r <= r) return tr[u].maxx;
	pushdown(u);
	int mid = (tr[u].l + tr[u].r) >> 1;
	int ans = -1e18;
	if(l <= mid) ans = max(ans, query(ls, l, r));
	if(r > mid) ans = max(ans, query(rs, l, r));
	return ans;
}

void insert(int u, int x, int v)
{
	if(tr[u].l == tr[u].r)
	{
		tr[u].maxx = v;
		return ;
	}
	int mid = (tr[u].l + tr[u].r) >> 1;
	if(x <= mid) insert(ls, x, v);
	else insert(rs, x, v);
	pushup(u);
}

void build(int u, int l, int r)
{
	tr[u] = {l, r};
	if(l == r)
	{
		tr[u].maxx = -1e18;
		return ;
	}
	int mid = (tr[u].l + tr[u].r) >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	pushup(u);
}

signed main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int c, t;
	cin >> c >> t;
	while(t--)
	{
		
		cin >> n >> m >> k >> d;
		
		rep(i, 0, n + 1) dp[i] = -1e18;
		
		rep(i, 1, m)
		{
			int x, y, v;
			cin >> x >> y >> v;
			tz[x].push_back({x - y + 1, v});
		}
		

		dp[0] = 0; dp[1] = 0;
		build(1, 0, n + 1);
		insert(1, 0, 0);
		insert(1, 1, 0);

		rep(i, 2, n + 1)
		{
			modify(1, 0, i - 2, -d);
			for(auto j : tz[i - 1]) modify(1, 0, j.x - 1, j.y);
			dp[i] = query(1, max(0ll, i - k - 1), i - 1);
			insert(1, i, dp[i]);
		}

		int ans = 0;
		rep(i, 1, n + 1) ans = max(ans, dp[i]);
		cout << ans << '\n';
		
		rep(i, 1, n) tz[i].clear();
	}
	
}