#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define ssz(x) (int((x).size()))

auto chmin = [](auto& x, auto y) { if (x > y) x = y; };
auto chmax = [](auto& x, auto y) { if (x < y) x = y; };

using ll = long long;
const int max_n = 2e5, max_m = 1e5, max_lgn = 18, max_s = 2 << max_lgn;

ll tr[max_s], tag[max_s];

inline int ls(int x) { return x * 2; }
inline int rs(int x) { return x * 2 + 1; }

void updata(int id, ll v) {
	tr[id] += v, tag[id] += v;
}
void pushdown(int id)
{
	if (tag[id])
	{
		updata(ls(id), tag[id]);
		updata(rs(id), tag[id]);
		tag[id] = 0;
	}
}

void build(int l, int r, int id)
{
	tr[id] = tag[id] = 0;
	if (l < r)
	{
		int mid = (l + r) >> 1;
		build(l, mid, ls(id));
		build(mid + 1, r, rs(id));
	}
}

void modify(int L, int R, int l, int r, int id, ll val)
{
	if (L <= l && r <= R)
		return updata(id, val);
	int mid = (l + r) >> 1;
	pushdown(id);
	if (L <= mid)
		modify(L, R, l, mid, ls(id), val);
	if (mid < R)
		modify(L, R, mid + 1, r, rs(id), val);
	tr[id] = max(tr[ls(id)], tr[rs(id)]);
}

void setv(int n, int p, ll v)
{
	int l = 0, r = n - 1, id = 1;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		pushdown(id);
		if (p <= mid)
			r = mid, id = ls(id);
		else
			l = mid + 1, id = rs(id);
	}
	tr[id] = v;
	while (id >>= 1)
		tr[id] = max(tr[ls(id)], tr[rs(id)]);
}

ll query(int L, int R, int l, int r, int id)
{
	if (L <= l && r <= R)
		return tr[id];
	int mid = (l + r) >> 1; ll ret = 0;
	pushdown(id);
	if (L <= mid)
		chmax(ret, query(L, R, l, mid, ls(id)));
	if (mid < R)
		chmax(ret, query(L, R, mid + 1, r, rs(id)));
	return ret;
}

int l[max_m], r[max_m], v[max_m];
vector<int> b;
vector<pair<int, int>> cp[max_n];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);  
	
	int cid, cas, n, m, k, d;
	
	cin >> cid >> cas;
	while (cas--)
	{
		cin >> n >> m >> k >> d;
		b.clear(), b.reserve(m * 2);
		
		for (int i = 0, x, y; i < m; i++)
		{
			cin >> x >> y >> v[i];
			l[i] = x - y + 1, r[i] = x;
			if (l[i] - 1 >= 0)
				b.push_back(l[i] - 1), b.push_back(r[i] + 1);
		}
		sort(all(b));
		b.erase(unique(all(b)), b.end());
		
		int sz = ssz(b);
		for (int i = 0; i < sz; i++)
			cp[i].clear();
		
		auto s = [&](int x) {
			return lower_bound(all(b), x) - b.begin();
		};
		for (int i = 0; i < m; i++)
			if (l[i] - 1 >= 0)
				cp[s(r[i] + 1)].emplace_back(s(l[i] - 1), v[i]);
		
		build(0, sz - 1, 1);
		
		ll mx = 0;
		setv(sz, 0, d);
		for (int i = 1; i < sz; i++)
		{
			modify(0, i - 1, 0, sz - 1, 1, -1ll * d * (b[i] - b[i - 1]));
			for (auto [l, v] : cp[i])
				modify(0, l, 0, sz - 1, 1, v);
			int cp = s(b[i] - k - 1);
			if (cp <= i - 1)
				chmax(mx, query(cp, i - 1, 0, sz - 1, 1));
			setv(sz, i, mx + d);
			// cerr << i << " " << mx << endl;
		}
		cout << mx << endl;
	}
	
	return 0;
}