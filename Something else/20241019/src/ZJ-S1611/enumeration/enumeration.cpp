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
int N, N3, P;

namespace BF {
	void main() {
		std::vector<std::array<int, 3>> ans;
		i64 N0 = 1ll * N * N + 1;
		for(int a = 1; a <= P; a++) {
			for(int b = 0; b <= P; b++) {
				for(int c = 1; c <= P; c++) {
					if((N0 % a + b) % c == N3) ans.push_back({a, b, c});
				}
			}
		}
		printf("%d\n", (int)ans.size());
		for(int i = 0; i < std::min((int)ans.size(), 100000); i++) {
			printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
		}
	}
}

namespace Sol {
	constexpr int _ = 1e6 + 5;
	std::vector<int> A[_], C[_];
	int bucA[_], bucC[_];
	i64 ans = 0;
	void main() {
		i64 N0 = 1ll * N * N + 1;
		int maxN1 = 0;
		for(int a = 1; a <= P; a++) {
			int N1 = N0 % a;
			A[N1].push_back(a);
			bucA[N1]++;
			maxN1 = std::max(maxN1, N1);
		}
		int maxN2 = maxN1 + P;
		for(int c = N3 + 1; c <= P; c++) {
			for(int N2 = N3; N2 <= maxN2; N2 += c) {
				bucC[N2]++;
				C[N2].push_back(c);
			}
		}
		std::vector<int> N2;
		N2.push_back(-1);
		for(int i = N3; i <= maxN2; i++) if(bucC[i] > 0) N2.push_back(i);
		N2.push_back(1e9);
		for(int i = N3; i <= maxN2; i++) bucC[i] += bucC[i - 1];
		for(int N1 = 0; N1 <= maxN1; N1++) {
			ans += 1ll * bucA[N1] * (bucC[N1 + P] - (N1 == 0 ? 0 : bucC[N1 - 1]));
		}
		printf("%lld\n", ans);
		int tot = 0;
		auto print = [&](int a, int b, int c) -> void {
			if(++tot > 100000) std::exit(0);
			printf("%d %d %d\n", a, b, c);
		};
		for(int a = 1; a <= P; a++) {
			int N1 = N0 % a;
			auto l = std::lower_bound(N2.begin(), N2.end(), N1);
			auto r = std::upper_bound(N2.begin(), N2.end(), N1 + P);
			r = std::prev(r);
			if(*l == -1 || *l == 1e9 || *r == -1 || *r == 1e9) continue;
			for(r = std::next(r); l != r; l++) {
				int N2 = *l;
				for(auto& c : C[N2]) {
					print(a, N2 - N1, c);
				}
			}
		}
	}
}

signed main() {
	freopen("enumeration.in", "r", stdin);
	freopen("enumeration.out", "w", stdout);
	read(N, N3, P);
	if(P <= 100) BF::main();
	else Sol::main();
	return 0;
}
/*
4
2 1 3 4
3 2 4 1
*/
