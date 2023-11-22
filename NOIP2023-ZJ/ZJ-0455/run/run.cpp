#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL c, T;
LL n, m, k, d;
void work1() {
	while(T--) {
		scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
		LL res = 0;
		for(LL i = 1; i <= m; i++) {
			LL x, y, v;
			scanf("%lld%lld%lld", &x, &y, &v);
			if(y <= k && y * d <= v) res = res + (v - y * d); 
		}
		printf("%lld\n", res);
	}
}
int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	scanf("%d%d", &c, &T);
	if(c == 17 || c == 18) work1();
	return 0;
}

