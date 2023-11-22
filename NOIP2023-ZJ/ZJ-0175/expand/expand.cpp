#include<bits/stdc++.h>
#define rep(i, l, r) for(int i(l), i##end(r); i <= i##end; ++ i)
#define per(i, r, l) for(int i(r), i##end(l); i >= i##end; -- i)
#define ci const int
#define mem(a, var) memset(a, var, sizeof(a))
using namespace std;

bool _st;

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

template <class node> void cmin(node &x, node y) {
	if(x > y) x = y;
}

template <class node> void cmax(node &x, node y) {
	if(x < y) x = y;
}


ci N = 5e5 + 9;
ci L = 2009;

int c, n, m, q, kx, ky;
int x[N], y[N];
int px[N], vx[N];
int py[N], vy[N];

void reverse() {
	rep(i, 1, n) x[i] = -x[i];
	rep(i, 1, m) y[i] = -y[i];
}

int stx[N], xn, sty[N], yn;

bool f[L][L];
bool dp[2][N];

bool guess_check() {
	xn = yn = 0;
	rep(i, 1, n) {
		while(yn && stx[xn] <= x[i]) -- xn;
		stx[++ xn] = x[i];
	}
	rep(i, 1, m) {
		while(yn && sty[yn] >= y[i]) -- yn;
		sty[++ yn] = y[i];
	}
	
	mem(dp, 0);
	dp[0][0] = 1;
	int pre = 0, now = 1;
	rep(i, 1, xn) {
		mem(dp[now], 0);
		rep(j, 1, yn) {
			if(stx[i] < sty[j]) {
				dp[now][j] = dp[pre][j] | dp[now][j - 1] | dp[pre][j - 1];
			}
		}
		swap(now, pre);
	}
	return dp[pre][yn];
}

//set<int> st;
//int tmp[N], o[N];

//bool cmp(int a, int b) {
//	return y[a] < y[b];
//}

//bool guess_check(int rev = 0) {
//	if(rev) reverse();
//	
//	bool fl = 0;
//	rep(i, 1, m) o[i] = i;
//	sort(o + 1, o + m + 1, cmp);
//	
//	rep(i, 1, n) {
//		if(x[i] <= y[o[1]]) return 0;
//		int L = 1, R = m;
//		while(L < R) {
//			int mid = (L + R + 1) >> 1;
//			if(y[o[mid]] >= x[i]) R = mid - 1;
//			else L = mid;
//		}
//		tmp[i] = L;
//	}
//	per(i, n - 1, 1) {
//		cmin(tmp[i], tmp[i - 1]);
//	}
//	int L = 0;
//	rep(i, 1, n) {
//		rep(j, tmp[i - 1] + 1, tmp[i]) {
//			st.insert(o[j]);
//		}
//		if(st.lower_bound(L) != st.end()) {
//			L = *st.lower_bound(L);
//		}
//	}
//	
//	if(rev) reverse();
//	
//	return fl;
//}

bool check(int rev = 0) {
	if(c > 7) {
		return guess_check();
	}
	if(rev) reverse();

	mem(f, 0);
	f[0][0] = 1;
	rep(i, 1, n) {
		rep(j, 1, m) {
			if(x[i] > y[j]) {
				f[i][j] = f[i - 1][j] | f[i][j - 1] | f[i - 1][j - 1];
			}
		}
	}
	
	if(rev) reverse();
	
	return f[n][m];
}

void solve() {
	rd(c);
	rd(n, m, q);
	rep(i, 1, n) {
		rd(x[i]);
	}
	rep(i, 1, m) {
		rd(y[i]);
	}
	printf("%d", (check() || check(1)));
	while(q --) {
		rd(kx, ky);
		rep(i, 1, kx) rd(px[i], vx[i]), swap(x[px[i]], vx[i]);
		rep(i, 1, ky) rd(py[i], vy[i]), swap(y[py[i]], vy[i]);
		
		printf("%d", (check() || check(1)));
		rep(i, 1, kx) swap(x[px[i]], vx[i]);
		rep(i, 1, ky) swap(y[py[i]], vy[i]);
	}
	printf("\n");
}

}

bool _ed;

int main() {
//	cerr << (&_st - &_ed) / 1048576.0 << endl;
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
    SkyMaths :: solve();
    return 0;
}
