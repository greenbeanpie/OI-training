#include <cstdio>
using namespace std;

int c, n, m, q;

void work1() {
	int x, y;
	scanf("%d %d", &x, &y);
	if (x == y)
		printf("0");
	else 
		printf("1");
	int kx, ky;
	while (q--) {
		scanf("%d %d", &kx, &ky);
		int xx = x, yy = y, aminoac;
		while (kx--)
			scanf("%d %d", &aminoac, &xx);
		while (ky--)
			scanf("%d %d", &aminoac, &yy);
		if (xx == yy)
			printf("0");
		else
			printf("1");
	}
}

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	scanf("%d %d %d %d", &c, &n, &m, &q);
	if (c == 1) 
		work1();
	fclose(stdin);
	fclose(stdout);
	return 0;
}