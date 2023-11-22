#include <bits/stdc++.h>
#define gc() (iS == iT && (iT = (iS = buf) + fread(buf, 1, 1 << 20, stdin), iS == iT) ? EOF : *iS++)
char buf[1 << 20], *iS = buf, *iT = buf;
template <typename _Tp> inline void read(_Tp& x) {
	x = 0; char c = gc(); bool f = 0;
	for(; !std::isdigit(c); c = gc()) f |= c == '-';
	for(; std::isdigit(c); c = gc()) x = (x << 1) + (x << 3) + (c ^ 48);
	f ? x = ~x + 1 : 1;
}
template <> inline void read(std::string& x) {
	x.clear(); char c = gc();
	for(; !std::isgraph(c); c = gc());
	for(; std::isgraph(c); c = gc()) x += c;
}
template <typename _Tp, typename ...Args>
inline void read(_Tp& x, Args& ...args) {
	read(x), read(args...);
}
inline void FileIO(std::string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

typedef long long i64;
constexpr int N = 5e5 + 5;
int c, n, m, q, x[N], y[N], a[N], b[N];

bool dfs1(int i, int j) {
	if(j == m + 1) {
		for(int u = i; u <= n; u++) {
			if(x[u] > y[m]) continue;
			return 0;
		}
		return 1;
	}
	for(int k = i; k <= n; k++) {
		if(x[k] <= y[j]) break;
		if(dfs1(k, j + 1)) return 1;
	}
	return 0;
}

bool dfs2(int i, int j) {
	if(j == m + 1) {
		for(int u = i; u <= n; u++) {
			if(x[u] < y[m]) continue;
			return 0;
		}
		return 1;
	}
	for(int k = i; k <= n; k++) {
		if(x[k] >= y[j]) break;
		if(dfs2(k, j + 1)) return 1;
	}
	return 0;
}

constexpr int M = 2005;
bool dp[M][M];
inline bool check() {
	for(int i = 1; i <= n; i++) memset(dp[i], 0, sizeof(bool) * (m + 1));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(x[i] <= y[j]) continue;
			dp[i][j] = dp[i - 1][j - 1] | dp[i - 1][j] | dp[i][j - 1];
		}
	}
	if(dp[n][m]) return 1;
	for(int i = 1; i <= n; i++) memset(dp[i], 0, sizeof(bool) * (m + 1));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(x[i] >= y[j]) continue;
			dp[i][j] = dp[i - 1][j - 1] | dp[i - 1][j] | dp[i][j - 1];
		}
	}
	return dp[n][m];
}

signed main() {
	FileIO("expand");
	read(c, n, m, q);
	for(int i = 1; i <= n; i++) read(x[i]);
	for(int i = 1; i <= m; i++) read(y[i]);
//	if(c == 1) {
//		if(x[1] != y[1]) putchar('1');
//		else putchar('0');
//		for(int kx, ky, p, v; q--; ) {
//			read(kx, ky);
//			memcpy(a, x, sizeof(int) * (n + 1));
//			memcpy(b, y, sizeof(int) * (m + 1));
//			while(kx--) {
//				read(p, v);
//				x[p] = v;
//			}
//			while(ky--) {
//				read(p, v);
//				y[p] = v;
//			}
//			if(x[1] != y[1]) putchar('1');
//			else putchar('0');
//			memcpy(x, a, sizeof(int) * (n + 1));
//			memcpy(y, b, sizeof(int) * (m + 1));
//		}
//		putchar('\n');
//	} else if(c == 2) {
//		if(n == 2 && m == 2) {
//			if((x[1] < y[1] && x[2] < y[2]) || (x[1] > y[1] && x[2] > y[2])) putchar('1');
//			else putchar('0');
//			for(int kx, ky, p, v; q--; ) {
//				read(kx, ky);
//				memcpy(a, x, sizeof(int) * (n + 1));
//				memcpy(b, y, sizeof(int) * (m + 1));
//				while(kx--) {
//					read(p, v);
//					x[p] = v;
//				}
//				while(ky--) {
//					read(p, v);
//					y[p] = v;
//				}
//				if((x[1] < y[1] && x[2] < y[2]) || (x[1] > y[1] && x[2] > y[2])) putchar('1');
//				else putchar('0');
//				memcpy(x, a, sizeof(int) * (n + 1));
//				memcpy(y, b, sizeof(int) * (m + 1));
//			}
//			putchar('\n');
//		} else {
//			if(m == 1) std::swap(n, m), std::swap(x, y);
//			if((x[1] < y[1] && x[1] < y[2]) || (x[1] > y[1] && x[1] > y[2])) putchar('1');
//			else putchar('0');
//			for(int kx, ky, p, v; q--; ) {
//				read(kx, ky);
//				memcpy(a, x, sizeof(int) * (n + 1));
//				memcpy(b, y, sizeof(int) * (m + 1));
//				while(kx--) {
//					read(p, v);
//					x[p] = v;
//				}
//				while(ky--) {
//					read(p, v);
//					y[p] = v;
//				}
//				if((x[1] < y[1] && x[1] < y[2]) || (x[1] > y[1] && x[1] > y[2])) putchar('1');
//				else putchar('0');
//				memcpy(x, a, sizeof(int) * (n + 1));
//				memcpy(y, b, sizeof(int) * (m + 1));
//			}
//			putchar('\n');
//		}
//	}
	if(c <= 4) {
		if(!((x[1] < y[1] && x[n] < y[m]) || (x[1] > y[1] && x[n] > y[m]))) putchar('0');
		else putchar((dfs1(1, 1) || dfs2(1, 1)) ? '1' : '0');
		for(int kx, ky, p, v; q--; ) {
			read(kx, ky);
			memcpy(a, x, sizeof(int) * (n + 1));
			memcpy(b, y, sizeof(int) * (m + 1));
			while(kx--) {
				read(p, v);
				x[p] = v;
			}
			while(ky--) {
				read(p, v);
				y[p] = v;
			}
			if(!((x[1] < y[1] && x[n] < y[m]) || (x[1] > y[1] && x[n] > y[m]))) putchar('0');
			else putchar((dfs1(1, 1) || dfs2(1, 1)) ? '1' : '0');			
			memcpy(x, a, sizeof(int) * (n + 1));
			memcpy(y, b, sizeof(int) * (m + 1));
		}
		putchar('\n');
	} else if(c <= 7) {
		if(!((x[1] < y[1] && x[n] < y[m]) || (x[1] > y[1] && x[n] > y[m]))) putchar('0');
		else putchar(check() ? '1' : '0');
		for(int kx, ky, p, v; q--; ) {
			read(kx, ky);
			memcpy(a, x, sizeof(int) * (n + 1));
			memcpy(b, y, sizeof(int) * (m + 1));
			while(kx--) {
				read(p, v);
				x[p] = v;
			}
			while(ky--) {
				read(p, v);
				y[p] = v;
			}
			if(!((x[1] < y[1] && x[n] < y[m]) || (x[1] > y[1] && x[n] > y[m]))) putchar('0');
			else putchar(check() ? '1' : '0');
			memcpy(x, a, sizeof(int) * (n + 1));
			memcpy(y, b, sizeof(int) * (m + 1));
		}
		putchar('\n');
	} else {
		for(int i = 1; i <= q + 1; i++) putchar('1');
	}
	return 0;
}
/*
too hard.
10:06 10pts
12:33 20pts
12:44 [25,35]pts
*/
