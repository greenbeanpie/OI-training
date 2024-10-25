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
int n, a[N], b[N];
struct Element {
	int a, b, id;
	friend bool operator < (Element lhs, Element rhs) {
		return lhs.a < rhs.a;
	}
} e[N], sav[N];

namespace BF {
	int dp[N];
	void main() {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j < i; j++) {
				if(a[j] < a[i] && b[j] < b[i]) {
					dp[i] = std::max(dp[i], dp[j]);
				}
			}
			dp[i]++;
		}
		printf("%d\n", *std::max_element(dp + 1, dp + n + 1));		
	}
}

namespace Sol {
	int dp[N];
	struct BIT {
		int bit[N], tag[N], Tag = 0;
		inline void clr() { Tag++; }
		inline void add(int x, int y) {
			for(; x <= n; x += (x & -x)) {
				if(tag[x] == Tag) bit[x] = std::max(bit[x], y);
				else bit[x] = y, tag[x] = Tag;
			}
		}
		inline int qry(int x) {
			int res = 0;
			for(; x >= 1; x -= (x & -x)) {
				if(tag[x] == Tag) res = std::max(res, bit[x]);
			}
			return res;
		}
	} bit;
	void cdq(int l, int r) {
		if(l == r) return dp[l]++, void();
		int mid = (l + r) >> 1;
		cdq(l, mid);
		memcpy(e + l, sav + l, sizeof(Element) * (r - l + 1));
		std::sort(e + l, e + mid + 1);
		std::sort(e + mid + 1, e + r + 1);
		for(int j = mid + 1, i = l - 1; j <= r; j++) {
			while(i + 1 <= mid && e[i + 1].a < e[j].a) {
				i++;
				bit.add(e[i].b, dp[e[i].id]);
			}
			dp[e[j].id] = std::max(dp[e[j].id], bit.qry(e[j].b - 1));
		}
		bit.clr();
		cdq(mid + 1, r);
	}
	void main() {
		cdq(1, n);
		printf("%d\n", *std::max_element(dp + 1, dp + n + 1));
	}
}

signed main() {
	freopen("factor.in", "r", stdin);
	freopen("factor.out", "w", stdout);
	read(n);
	for(int i = 1; i <= n; i++) sav[i].id = i;
	for(int i = 1; i <= n; i++) read(a[i]), sav[i].a = a[i];
	for(int i = 1; i <= n; i++) read(b[i]), sav[i].b = b[i];
	if(n <= 1e3) BF::main();
	else Sol::main();
	return 0;
}
/*
4
2 1 3 4
3 2 4 1
*/
