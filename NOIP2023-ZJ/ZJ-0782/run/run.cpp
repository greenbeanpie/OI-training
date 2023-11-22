#include<iostream>
#include<cstdio>
using namespace std;

int c, t;
int n, k, d;//days, limit, reduce
int m;//challenges
long long x[100010], last[100010], get[100010];
long long ans;

int ds[20];

int main() {
 	freopen("run.in", "r", stdin);
 	freopen("run.out", "w", stdout);
	scanf("%d %d", &c, &t);
	if (c == 17 || c == 18) {
		while (t--) {
			ans = 0;
			scanf("%d %d %d %d", &n, &m, &k, &d);
			for (register int i=1; i<=m; i++) {
				scanf("%lld %lld %lld", &x[i], &last[i], &get[i]);
				if (last[i] > k || x[i]-last[i] < 0) {
					i--, m--;
					continue;
				}
				ans += max(0ll, get[i]-last[i]*d);
			}
			printf("%lld\n", ans);
		}
		return 0;
	}
	else if (c <= 2) {
		while (t--) {
			ans = -18000000000;
			long long tmp = 0;
			scanf("%d %d %d %d", &n, &m, &k, &d);
			for (register int i=1; i<=m; i++) {
				scanf("%lld %lld %lld", &x[i], &last[i], &get[i]);
				if (last[i] > k || x[i]-last[i] < 0)
					i--, m--;
			}
			for (register int i=0; i<(1<<n); i++) {
				for (register int k=n-1; ~k; k--)
					if ((i>>k) & 1) {
						tmp -= d;
						ds[n-k] = ds[n-k-1] + 1;
					}
				for (register int j=1; j<=m; j++)
					if (ds[x[j]] - ds[x[j]-last[j]] == last[j])
						tmp += get[j];
				ans = max(ans, tmp);
			}
			printf("%lld\n", ans);
		}
		return 0;
	}
 	return 0;
}
