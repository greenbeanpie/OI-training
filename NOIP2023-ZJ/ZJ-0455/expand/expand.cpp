#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int c, n, m, q;
int x[N], y[N], xx[N], yy[N];
int kx, ky, px, vx, py, vy;
void work2() {
	if(x[1] != y[1]) printf("1");
	else printf("0");
	while(q--) {
		for(int i = 1; i <= n; i++) {
			x[i] = xx[i];
		}
		for(int i = 1; i <= m; i++) {
			y[i] = yy[i];
		}
		scanf("%d%d", &kx, &ky);
		for(int i = 1; i <= kx; i++) {
			scanf("%d%d", &px, &vx);
			x[px] = vx;
		}
		for(int i = 1; i <= ky; i++) {
			scanf("%d%d", &py, &vy);
			y[py] = vy;
		}
		if(x[1] != y[1]) printf("1");
		else printf("0");
	}
}
void work3() {
	if((x[1] - y[1]) * (x[2] - y[2]) > 0) printf("1");
	else printf("0");
	while(q--) {
		for(int i = 1; i <= n; i++) {
			x[i] = xx[i];
		}
		for(int i = 1; i <= m; i++) {
			y[i] = yy[i];
		}
		scanf("%d%d", &kx, &ky);
		for(int i = 1; i <= kx; i++) {
			scanf("%d%d", &px, &vx);
			x[px] = vx;
		}
		for(int i = 1; i <= ky; i++) {
			scanf("%d%d", &py, &vy);
			y[py] = vy;
		}
		if((x[1] - y[1]) * (x[2] - y[2]) > 0) printf("1");
		else printf("0");
	}
}
void work4() {
	if((x[1] - y[1]) * (x[1] - y[2]) > 0) printf("1");
	else printf("0");
	while(q--) {
		for(int i = 1; i <= n; i++) {
			x[i] = xx[i];
		}
		for(int i = 1; i <= m; i++) {
			y[i] = yy[i];
		}
		scanf("%d%d", &kx, &ky);
		for(int i = 1; i <= kx; i++) {
			scanf("%d%d", &px, &vx);
			x[px] = vx;
		}
		for(int i = 1; i <= ky; i++) {
			scanf("%d%d", &py, &vy);
			y[py] = vy;
		}
		if((x[1] - y[1]) * (x[1] - y[2]) > 0) printf("1");
		else printf("0");
	}
}
void work5() {
	if((x[1] - y[1]) * (x[2] - y[1]) > 0) printf("1");
	else printf("0");
	while(q--) {
		for(int i = 1; i <= n; i++) {
			x[i] = xx[i];
		}
		for(int i = 1; i <= m; i++) {
			y[i] = yy[i];
		}
		scanf("%d%d", &kx, &ky);
		for(int i = 1; i <= kx; i++) {
			scanf("%d%d", &px, &vx);
			x[px] = vx;
		}
		for(int i = 1; i <= ky; i++) {
			scanf("%d%d", &py, &vy);
			y[py] = vy;
		}
		if((x[1] - y[1]) * (x[2] - y[1]) > 0) printf("1");
		else printf("0");
	}
}
void work1() {
	if((x[1] - y[1]) * (x[n] - y[m]) > 0) printf("1");
	else printf("0");
	while(q--) {
		for(int i = 1; i <= n; i++) {
			x[i] = xx[i];
		}
		for(int i = 1; i <= m; i++) {
			y[i] = yy[i];
		}
		scanf("%d%d", &kx, &ky);
		for(int i = 1; i <= kx; i++) {
			scanf("%d%d", &px, &vx);
			x[px] = vx;
		}
		for(int i = 1; i <= ky; i++) {
			scanf("%d%d", &py, &vy);
			y[py] = vy;
		}
		if((x[1] - y[1]) * (x[n] - y[m]) > 0) printf("1");
		else printf("0");
	}
}
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	scanf("%d%d%d%d", &c, &n, &m, &q);
	for(int i = 1; i <= n; i++) scanf("%d", &x[i]), xx[i] = x[i];
	for(int i = 1; i <= m; i++) scanf("%d", &y[i]), yy[i] = y[i];
	if(c == 1) work2();
	else if(c == 2) {
		if(n == 2 && m == 2) work3();
		else if(n == 1 && m == 2) work4();
		else if(n == 2 && m == 1) work5();
		else if(n == 1 && m == 1) work2();
	}
	else {
		work1();
	}
	return 0;
}

