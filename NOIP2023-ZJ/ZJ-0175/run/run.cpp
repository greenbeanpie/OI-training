#include<bits/stdc++.h>
#define rep(i, l, r) for(int i(l), i##end(r); i <= i##end; ++ i)
#define per(i, r, l) for(int i(r), i##end(l); i >= i##end; -- i)
#define ci const int
#define mem(a, var) memset(a, var, sizeof(a))
#define mp make_pair
#define eb emplace_back
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

namespace SkyMaths {

template <class node> void rd(node &x) {
    x = 0; bool f = 0; char ch = getchar();
    while(ch < '0' || ch > '9') f ^= ch == '-', ch = getchar();
    while(ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
    if(f) x = -x;
}

template <class Tx, class ...Ty> void rd(Tx &x, Ty &... y) {
    rd(x);
    rd(y...);
}

template <class node> void cmax(node &a, node b) {
	if(a < b) a = b;
}

bool _st;

ci N = 1e5 + 9;
ci Mx = 1e3 + 9;

int C, T, n, m, k, d;
ll f[Mx][Mx];
ll sum[Mx];

vector< pii > a[Mx];

struct cl {int x, y, v;} c[N];

bool _ed;

bool in(int L, int p, int R) {
	return L <= p && p <= R;
}

void solveB() {
	rd(n, m, k, d);
	ll ans = 0;
	rep(i, 1, m) {
		rd(c[i].x, c[i].y, c[i].v);
		if(c[i].y <= k && c[i].x - c[i].y + 1 > 0 && c[i].v > 1LL * d * c[i].y) {
			ans = ans + c[i].v - 1LL * d * c[i].y;
		}
	}
	printf("%lld\n", ans);
}

//void solve10() {
//	rd(n, m, k, d);
//	rep(i, 1, n + 1) a[i].clear();
//	rep(i, 1, m) rd(c[i].x, c[i].y, c[i].v);
//}

int solve() {
//	cerr << (&_st - &_ed) /1048576.0 << "MB" << endl;
	rd(C, T);
	while(T --) {
		if(in(17, C, 18)) {
			solveB();
			continue;
		}
		rd(n, m, k, d);
		rep(i, 1, n + 1) a[i].clear();
		rep(i, 1, m) rd(c[i].x, c[i].y, c[i].v);
		mem(f, -0x3f);
		rep(i, 1, m) a[c[i].x].eb(mp(c[i].y, c[i].v));
		f[0][0] = 0;
		rep(i, 1, n + 1) {
			rep(j, 0, k) cmax(f[i][0], f[i - 1][j]);
			rep(j, 1, k) f[i][j] = f[i - 1][j - 1] - d;
			mem(sum, 0);
			for(pii cur : a[i]) {
				sum[cur.fi] += cur.se;
			}
			rep(j, 1, k) sum[j] += sum[j - 1];
			rep(j, 1, k) f[i][j] += sum[j];
		}
		printf("%lld\n", f[n + 1][0]);
	}
	return 0;
}

}

int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
    SkyMaths :: solve();
    return 0;
}
