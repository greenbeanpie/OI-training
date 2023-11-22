#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
int c;
long long n, m, k, d, ans;
struct challenge {
	long long l, r, lst, v;
}meal[N], tmp;
bool cmp(challenge a, challenge b) {
	return a.l < b.l;
}
namespace B {
	void solve(int t) {
		while (t --) {
			scanf ("%lld%lld%lld%lld", &n, &m, &k, &d);
			long long cnt = 0;
			ans = 0;
			while (m --) {
				scanf ("%lld%lld%lld", &tmp.r, &tmp.lst, &tmp.v);
				if (tmp.lst > k || d * tmp.lst >= tmp.v) continue;
				meal[++ cnt] = tmp;
				meal[cnt].l = meal[cnt].r - meal[cnt].lst + 1;
			}
			m = cnt;
			cnt = 0;
			for (int i = 1;i <= m; ++ i) {
				if ((i == 1 || meal[i - 1].r + 1 < meal[i].l) && (i == n || meal[i].r + 1 < meal[i + 1].l)) {
					ans += meal[i].v - meal[i].lst * d;
					continue;
				}
				meal[++ cnt] = meal[i];
			}
			m = cnt;
			int l = 1, r;
			for (int i = 2;i <= m; ++ i) {
				if (meal[i - 1].r + 1 < meal[i].l) {
					r = i - 1;
					long long s1 = 0, s2 = 0;
					for (int j = l;j <= r;j += 2)
						s1 += meal[i].v - meal[i].lst * d;
					for (int j = l + 1;j <= r;j += 2)
						s2 += meal[i].v - meal[i].lst * d;
					ans += (s1 > s2 ? s1 : s2);
					l = i;
				}
			}
			printf ("%lld\n", ans);
		}
	}
}
int main() {
	freopen ("run.in", "r", stdin);
	freopen ("run.out", "w", stdout);
	int t;
	scanf ("%d%d", &c, &t);
	if (c == 17 || c == 18) {
		B :: solve(t);
		return 0;
	}
	while (t --) {
		scanf ("%lld%lld%lld%lld", &n, &m, &k, &d);
		long long cnt = 0;
		ans = 0;
		while (m --) {
			scanf ("%lld%lld%lld", &tmp.r, &tmp.lst, &tmp.v);
			if (tmp.lst > k) continue;
			meal[++ cnt] = tmp;
			meal[cnt].l = meal[cnt].r - meal[cnt].lst + 1;
		}
		m = cnt;
	}
	return 0;
}
