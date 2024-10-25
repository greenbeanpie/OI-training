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
constexpr int N = 75;
int n, a[N], sav[N];

namespace BF {
	int p[N], dp[N];
	void main() {
		std::iota(p + 1, p + n + 1, 1);
		do {
			memcpy(a + 1, sav + 1, sizeof(int) * n);
			for(int i = 1; i <= n; i++) {
				
			}
		} while(std::next_permutation(p + 1, p + n + 1));
	}
}

namespace SP {
	void main() {
		for(int i = 1, rst = 0, sum = 0; i <= n; i++) {
			int delta = std::max(a[i] - rst, 0);
			rst += delta, sum += delta;
			rst >>= 1;
			printf("%d%c", sum, " \n"[i == n]);
		}
	}
}

signed main() {
	freopen("qigong.in", "r", stdin);
	freopen("qigong.out", "w", stdout);
	read(n);
	for(int i = 1; i <= n; i++) read(a[i]), sav[i] = a[i];
	SP::main();
	return 0;
}
/*
5
10 3 3 8 4
*/
