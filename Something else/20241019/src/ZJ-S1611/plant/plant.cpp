#include <bits/stdc++.h> 
#define gc() (iS == iT && (iT = (iS = buf) + fread(buf, 1, 1 << 20, stdin), iS == iT) ? EOF : *iS++)
char buf[1 << 20], *iS = buf, *iT = buf;
template <typename _Tp> inline void read(_Tp& x) {
	char c = gc(); x = 0; bool f = 0;
	for(; !std::isdigit(c); c = gc()) f |= c == '-';
	for(; std::isdigit(c); c = gc()) x = x * 10 + (c ^ '0');
	f ? x = ~x + 1 : 1;
}
template <typename _Tp, typename ...Args>
inline void read(_Tp& x, Args& ...args) {
	read(x), read(args...);
}
typedef long long i64;
constexpr int N = 1e5 + 5;
int n;
i64 a[N], b[N], c[N], k;

inline i64 getrank(i64 mid) {
	i64 rk = 1;
	for(int i = 1; i <= n; i++) {
		if(a[i] + b[i] * c[1] >= mid) continue;
		else if(a[i] + b[i] * c[n] < mid) rk += n;
		else rk += std::lower_bound(c + 1, c + n + 1, (mid - a[i] - 1) / b[i] + 1) - (c + 1);
	}
	return rk;
}

signed main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	read(n);
	for(int i = 1; i <= n; i++) read(a[i]);
	for(int i = 1; i <= n; i++) read(b[i]);
	for(int i = 1; i <= n; i++) read(c[i]);
	read(k);
	std::sort(c + 1, c + n + 1);
	i64 l = 1, r = 1e18 + 1e9, ans = 1;
	while(l <= r) {
		i64 mid = (l + r) >> 1;
		if(getrank(mid) <= k) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	printf("%lld\n", ans);
	return 0;
}
