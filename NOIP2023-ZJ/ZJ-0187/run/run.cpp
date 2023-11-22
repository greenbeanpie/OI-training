#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back 
#define mp make_pair
const int maxn = 1e5 + 10;
int c, t;
ll n, m, k, d;
struct node {
	int l, r, val;
}a[maxn];
ll dp[maxn][2];
ll f[1010][1010], p[1010];
vector <pair<int, int> > v[1010];
void solve1() {
	memset(f, 0xcf, sizeof(f));f[0][0] = 0; 
	for (int i = 1; i <= n; i++) {
		v[i].clear();
	}
	for (int i = 1; i <= m; i++) {
		v[a[i].r].pb(mp(a[i].l, a[i].val));
	}
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end()); reverse(v[i].begin(), v[i].end());
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= min(i-1, (int)k); j++) f[i][0] = max(f[i][0], f[i-1][j]);
		//cout << i << " " << f[i][0] << " dubug" << endl;
		 ll val = 0; int id = 0;
		for (int j = 1; j <= min(i, (int)k); j++) {
			while (id < v[i].size() && v[i][id].first >= i - j + 1) val += v[i][id].second, id++;
			f[i][j] = f[i-1][j-1] + val - d;
		}
	}
	ll ans = 0;
	for (int i = 0; i <= k; i++) {
		//cout << f[n][i] << " dubug" << endl;
		ans = max(ans, f[n][i]);
	}
	cout << ans << endl;
}
bool cmp(node x, node y) {
	if (x.r != y.r) return x.r < y.r;
	else return x.l > y.l;
}
priority_queue <pair<int, int> > q;
void solve2() {
	sort(a + 1, a + m + 1, cmp);
	memset(f, 0xcf, sizeof(f));
	memset(p, 0xcf, sizeof(p)); 
	 p[0] = 0;
	for (int i = 1; i <= m; i++) {
		while (q.size()) q.pop();
		for (int j = 1; j <= i; j++) q.push(mp(a[j].l, a[j].val)); 
		ll val = 0; int id = i; f[i][0] = p[i-1];
		for (int j = i; j >= 1; j--) {
			int pos = q.top().first; val = val + q.top().second; q.pop();
			//cout << pos << " " << val << " " << i << endl;
			if (a[i].r-pos+1 > k) break;
			while (id > 0 && a[id].r >= pos) id--;
			f[i][i-j+1] = p[id] + val - (ll)(a[i].r-pos+1) * (ll)d;
		//	if (val - (ll)(a[i].r-pos+1) * (ll)d > 0) cout << 
		//	cout << i << " " << i - j + 1 << " " <<	f[i][i-j+1] << endl;
		}
		for (int j = 0; j <= i; j++) p[i] = max(f[i][j], p[i]);
	//	cout << f[i][1] << endl;
	}
	cout << p[m] << endl;
}
void solve3() {
	
}
void solve4() {
	ll ans = 0;
	for (int i = 1; i <= m; i++) {
		ll cost = (ll)(a[i].r-a[i].l + 1) * (ll) d;
		ans = max(ans, ans - cost + a[i].val);
	}
	cout << ans << endl;
}
void solve5() {
	
}
int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> m >> k >> d;
		
		for (int i = 1; i <= m; i++) {
			int x, y, val; scanf("%d%d%d", &x, &y,&val);
			a[i].l = x-y+1, a[i].r = x, a[i].val = val;
		}
	//	cout << n << " " << m << " " << k << " " << d << endl;
		//solve4();
		if (n <= 1000) {
			solve1(); continue;
		}
		if (m <= 1000) {
			solve2(); continue;
		}
		if (15 <= c && c <= 16) {
			solve3(); continue;
		}
		if (17 <= c && c <= 18) {
			solve4(); continue;
		}
		solve5();
	}
	return 0;
}