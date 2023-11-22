#include <bits/stdc++.h>
#define rep(i, l, r) for(int i=l, _=r; i<=_; ++i)
using namespace std;
typedef long long ll;
typedef uniform_int_distribution<int> rd;
mt19937 rnd;
int n, m;
rd rdn(1, 14), rdm(1, 14);

int main() {
	unsigned seed=chrono::system_clock().now().time_since_epoch().count();
	fprintf(stderr, "seed: %u\n", seed);
	rnd.seed(seed);

	int T_T=6;
	printf("114 %d\n", T_T);
	while(T_T--) {

		n=rdn(rnd), m=rdm(rnd);
		printf("%d %d\n", n, m);
		rep(__, 1, m) {
			int opt=rd(0, 4)(rnd);
			putchar("TFU+-"[opt]);
			if(opt<=2) {
				printf(" %d\n", rd(1, n)(rnd));
			} else {
				printf(" %d %d\n", rd(1, n)(rnd), rd(1, n)(rnd));
			}
		}
	}
	return 0;
}