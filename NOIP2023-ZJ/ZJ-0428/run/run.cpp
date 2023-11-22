#include <cstdio>
#include <algorithm>
using namespace std;

long long c, t;
long long n, m, k, d;
struct aminoac {
	long long y[101], z[101], top;
} day[20];

void work() {
	for (long long i = 1; i <= 19; i++) {
		for (long long j = 1; j <= 100; j++) {
			day[i].z[j] = 0;
			day[i].y[j] = 0;
		}
		day[i].top = 0;
	}
	scanf("%lld %lld %lld %lld", &n, &m, &k, &d);
	for (long long i = 1; i <= m; i++) {
		long long x;
		scanf("%lld", &x);
		long long tp = ++day[x].top;
		scanf("%lld %lld", &day[x].y[tp], &day[x].z[tp]);
	}
	long long ans = 0;
	for (long long i = 0; i <= (1 << n) - 1; i++) {
		long long seq = 0, ek = 0;
		for (long long j = 1; j <= n; j++)
			if (((i >> (j - 1)) & 1) && (seq < k)) {
				seq++;
				ek -= d;
				for (long long p = 1; p <= day[j].top; p++)
					if (seq >= day[j].y[p])
						ek += day[j].z[p];
			} else {
				seq = 0;
			}
		if (ek > ans)
			ans = ek;
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	scanf("%lld %lld\n", &c, &t);
	while (t--)
		work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}