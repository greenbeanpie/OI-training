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
constexpr int N = 1e5 + 5;
int c, T, n, m, k, d, sum[N];

struct orzflexibledog {
	int x, y, v;
} a[N];

inline bool check(int S) {
	for(int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + (S >> (i - 1) & 1);
	}
	for(int x = 1; x <= n - k; x++) {
		if(sum[x + k] - sum[x - 1] == k + 1) {
			return 0;
		}
	}
	return 1;	
}

inline void solve() {
	read(n, m, k, d);
	for(int i = 1; i <= m; i++) read(a[i].x, a[i].y, a[i].v);
	if(c == 1 || c == 2) {
		int ans = 0;
		for(int S = 0; S < (1 << n); S++) {
			if(!check(S)) continue;
			int res = -__builtin_popcount(S) * d;
			for(int i = 1; i <= m; i++) {
				if(sum[a[i].x] - sum[a[i].x - a[i].y] == a[i].y) {
					res += a[i].v;
				}
			}
			ans = std::max(ans, res);
		}
		printf("%d\n", ans);
	} else {
		
	}
}

signed main() {
	FileIO("run");
	for(read(c, T); T--; ) solve();
	return 0;
}
/*
10:26 8pts
*/
