#include<bits/stdc++.h>
#define rep(i, l, r) for(int i(l), i##end(r); i <= i##end; ++ i)
#define per(i, r, l) for(int i(r), i##end(l); i >= i##end; -- i)
#define ci const int
#define mem(a, var) memset(a, var, sizeof(a))
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

bool _st;

ci N = 1e5 + 9;

int c, T, cnt, n, m, ans;
int pa[N * 4], now[N][2], ord[N][2], sz[N * 4];

void build(int i) {
	now[i][0] = ++ cnt;
	now[i][1] = ++ cnt;
}

int find(int i) {
	return pa[i] == i ? i : pa[i] = find(pa[i]);
}

void merge(int x, int y) {
	if((x = find(x)) == (y = find(y))) return;
	if(sz[x] < sz[y]) swap(x, y);
	sz[x] += sz[y];
	pa[y] = x;
}

void calc() {
	cnt = ans = 0;
	rd(n, m);
	cnt = 3;
	rep(i, 1, n) {
		ord[i][0] = ++ cnt;
		ord[i][1] = ++ cnt;
		now[i][0] = ord[i][0];
		now[i][1] = ord[i][1];
	}
	sz[0] = 0;
	rep(i, 1, N * 4 - 1) {
		pa[i] = i;
		sz[i] = 1;
	}
	rep(t, 1, m) {
		char opt;
		scanf(" %c", &opt);
		if(opt == 'T') {
			int i; rd(i); build(i);
			merge(now[i][1], 3);
			merge(now[i][0], 2);
		}
		if(opt == 'F') {
			int i; rd(i); build(i);
			merge(now[i][1], 2);
			merge(now[i][0], 3);
		}
		if(opt == 'U') {
			int i; rd(i); build(i);
			merge(now[i][1], 1);
			merge(now[i][0], 1);
		}
		if(opt == '+') {
			int i, j; rd(i, j);
			int x = now[j][0];
			int y = now[j][1];
			build(i);
			merge(now[i][0], x);
			merge(now[i][1], y);
		}
		if(opt == '-') {
			int i, j; rd(i, j);
			int x = now[j][0];
			int y = now[j][1];
			build(i);
			merge(now[i][0], y);
			merge(now[i][1], x);
		}
	}
	ans = 0;
	rep(i, 1, n) {
		merge(now[i][0], ord[i][0]);
		merge(now[i][1], ord[i][1]);
	}
	rep(i, 1, n) {
		if(find(ord[i][0]) == find(ord[i][1])) {
			++ ans;
		}
	}
	printf("%d\n", ans);
}

int solve() {
	rd(c, T);
	while(T --) {
		calc();
	}
	return 0;
}

bool _ed;

}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
    SkyMaths :: solve();
    return 0;
}
