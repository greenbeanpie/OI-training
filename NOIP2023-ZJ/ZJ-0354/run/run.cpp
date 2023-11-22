#include <cstdio>
#include <algorithm>
#include <cstring>
#define Maxn 100000
#define int long long
namespace FASTIO {
	int read() {
		int x = 0, f = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
		while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
		return x * f;
	}
	void write(int x) {
		if(x < 0) putchar('-'), write(-x);
		else if(x <= 9) putchar(x + '0');
		else write(x / 10), putchar(x % 10 + '0');
	}
}
int n, m, k, d, M;
struct TASKS {int l, r, v;} tsk[Maxn + 9];
namespace TASK1 {
	int f[Maxn + 9];
	bool CmpR(TASKS x, TASKS y) {return x.r == y.r ? x.l < y.l : x.r < y.r;}
	int Find(int x) {
		int left = 1, right = m, mid;
		while(left <= right) {
			mid = (left + right) >> 1;
			if(tsk[mid].r < x) left = mid + 1;
			else right = mid - 1;
		}
		return right;
	}
	void Solve() {
		n = FASTIO::read(), M = FASTIO::read(), k = FASTIO::read(), d = FASTIO::read(), m = 0;
		for(int i = 1; i <= M; ++ i) {
			int x = FASTIO::read(), y = FASTIO::read(), v = FASTIO::read();
			if(y > k) continue;
			tsk[++ m].l = x - y + 1, tsk[m].r = x, tsk[m].v = v;
		}
		std::sort(tsk + 1, tsk + m + 1, CmpR);
		std::memset(f, 0, sizeof(f));
		f[0] = 0;
		for(int i = 1; i <= m; ++ i) {
			int left = tsk[i].l, right = tsk[i].r, val = tsk[i].v;
			f[i] = std::max(f[i], f[Find(left - 1)] + val - d * (right - left + 1));
			for(int j = i - 1; j >= 1; -- j) {
				if(tsk[j].r < left - 1) break;
				left = std::min(left, tsk[j].l);
				if(right - left + 1 > k) break;
				val += tsk[j].v;
				f[i] = std::max(f[i], f[Find(left - 1)] + val - d * (right - left + 1));
			}
		}
		int ans = 0;
		for(int i = 1; i <= m; ++ i) ans = std::max(ans, f[i]);
		FASTIO::write(ans), puts("");
	}
}
namespace TASK2 {
	void Solve() {
		n = FASTIO::read(), M = FASTIO::read(), k = FASTIO::read(), d = FASTIO::read(), m = 0;
		for(int i = 1; i <= M; ++ i) {
			int x = FASTIO::read(), y = FASTIO::read(), v = FASTIO::read();
			if(y > k) continue;
			tsk[++ m].l = x - y + 1, tsk[m].r = x, tsk[m].v = v;
		}
		int ans = 0;
		for(int i = 1; i <= m; ++ i) if(tsk[i].v - d * (tsk[i].r - tsk[i].l + 1) > 0) ans += tsk[i].v - d * (tsk[i].r - tsk[i].l + 1);
		FASTIO::write(ans), puts("");
	}
}
signed main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int c = FASTIO::read(), T = FASTIO::read();
	if(c <= 7 || (c >= 10 && c <= 11)) while(T --) TASK1::Solve();
	else while(T --) TASK2::Solve();
	return 0;
}