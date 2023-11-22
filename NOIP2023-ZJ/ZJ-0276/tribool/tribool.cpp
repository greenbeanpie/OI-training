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
template <> inline void read(char& x) {
	for(x = gc(); !std::isgraph(x); x = gc());
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
int c, T, n, m, a[N], b[N], ans = 1e9;
std::vector<int> vec[N];

inline void addEdge(int u, int v) {
	vec[u].emplace_back(v);
}

struct Opt {
	char opt;
	int i, j;
} q[N];

inline int calc(char opt) {
	if(opt == 'F') return 1;
	if(opt == 'U') return 0;
	return -1;
}

// T/U/F = 1/0/-1
void dfs(int u, int cnt) {
	if(cnt > ans) return ;
	if(u == n + 1) {
		memcpy(b, a, sizeof(int) * (n + 1));
		for(int i = 1; i <= m; i++) {
			if(q[i].opt == '+') {
				b[q[i].i] = b[q[i].j];
			} else if(q[i].opt == '-') {
				b[q[i].i] = -b[q[i].j];
			} else {
				b[q[i].i] = calc(q[i].opt);
			}
		}
		for(int i = 1; i <= n; i++) if(a[i] != b[i]) return ;
		ans = std::min(ans, cnt);
		return ;
	}
	a[u] = 1; dfs(u + 1, cnt);
	a[u] = -1; dfs(u + 1, cnt);
	a[u] = 0; dfs(u + 1, cnt + 1);
}

inline void solve() {
	read(n, m);
	for(int i = 1; i <= m; i++) {
		read(q[i].opt);
		if(q[i].opt == '+') {
			read(q[i].i, q[i].j);
		} else if(q[i].opt == '-') {
			read(q[i].i, q[i].j);
		} else read(q[i].i);
	}
	if(c == 1 || c == 2) {
		ans = 1e9;
		dfs(1, 0);
		printf("%d\n", ans);
	} else if(c == 3 || c == 4) {
		ans = 0;
		for(int i = 1; i <= n; i++) a[i] = 114514;
		for(int i = 1; i <= m; i++) a[q[i].i] = calc(q[i].opt);
		for(int i = 1; i <= n; i++) ans += a[i] == 0;
		printf("%d\n", ans);
	} else if(c == 5 || c == 6) {
		ans = 0;
		for(int i = 1; i <= n; i++) a[i] = 114514;
		int t = 2e7 / m;
		while(t--) {
			for(int i = 1; i <= m; i++) {
				if(q[i].opt == '+') {
					a[q[i].i] = a[q[i].j];
				} else {
					a[q[i].i] = 0;
				}
			}
		}
		for(int i = 1; i <= n; i++) ans += a[i] == 0;
		printf("%d\n", ans);
	} else puts("0");
}

signed main() {
	FileIO("tribool");
	for(read(c, T); T--; ) solve();
	return 0;
}
/*
10:26 40-60pts
*/
