#include <iostream>
#include <stdio.h>
using namespace std;

int c, t;
int n, m, k, d;

int main(void) {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	
	scanf("%d%d", &c, &t);
	
	int x, y, z, ans;
	while (t--) {
		scanf("%d%d%d%d", &n, &m, &k, &d);
		ans = -(k * d);
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d", &x, &y, &z);
			ans += z;
		}
		printf("%d\n", ans);
	}
	return 0;
}