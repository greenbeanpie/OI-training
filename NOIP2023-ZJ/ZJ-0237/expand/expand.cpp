#include <bits/stdc++.h>

const int maxn=5e5;
int c, n, m, q, x[maxn+5], y[maxn+5], kx, ky, p, v, xx[maxn+5], yy[maxn+5];

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	scanf("%d%d%d%d", &c, &n, &m, &q);
	for(int i=1; i<=n; ++i) {
		scanf("%d", &x[i]);
	}
	for(int i=1; i<=m; ++i) {
		scanf("%d", &y[i]);
	}
	if(c==1) {
		if(x[1]==y[1]) {
			putchar('0');
		} else {
			putchar('1');
		}
		while(q--) {
			memcpy(xx, x, sizeof(x));
			memcpy(yy, y, sizeof(y));
			scanf("%d%d", &kx, &ky);
			for(int i=1; i<=kx; ++i) {
				scanf("%d%d", &p, &v);
				xx[p]=v;
			}
			for(int i=1; i<=ky; ++i) {
				scanf("%d%d", &p, &v);
				yy[p]=v;
			}
			if(x[1]==y[1]) {
				putchar('0');
			} else {
				putchar('1');
			}
		}
		putchar('\n');
	} else if(c==2) {
		if((x[1]>y[1]&&x[2]>y[2])||(x[1]<y[1]&&x[2]<y[2])) {
			putchar('1');
		} else {
			putchar('0');
		}
		while(q--) {
			memcpy(xx, x, sizeof(x));
			memcpy(yy, y, sizeof(y));
			scanf("%d%d", &kx, &ky);
			for(int i=1; i<=kx; ++i) {
				scanf("%d%d", &p, &v);
				xx[p]=v;
			}
			for(int i=1; i<=ky; ++i) {
				scanf("%d%d", &p, &v);
				yy[p]=v;
			}
			if((x[1]>y[1]&&x[2]>y[2])||(x[1]<y[1]&&x[2]<y[2])) {
				putchar('1');
			} else {
				putchar('0');
			}
		}
		putchar('\n');
	} else {
		++q;
		while(q--) {
			putchar('0');
		}//bukeyi,zongsiling
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}