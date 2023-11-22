#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define minn 0
#define maxn 1

int c, n, m, Q;
int p[500010], q[500010];
int x[500010], y[500010];
int kx, ky;
int px, vx, py, vy;

queue <int> a;
int l;
bool in[500010];
/*
6 3 8 3 7 8 5
1 7 4

6 <1>
3 1
8 1,7,4 append 7,4(< 8)
3 1 remove 7,4(>= 3)
7 1
8 1,7,4
5 1,<4>

*/

bool checkover() {
	if (x[1] <= y[1])
		return false;
	for (register int i=2; i<=n; i++)
		in[i] = false;
	in[1] = true;
	a.push(1); l = 1;
	for (register int i=2; i<=m; i++) {
		for (register int j=1; j<=l; j++) {
			int tmp = a.front();
			a.pop();
			if (x[tmp] > y[i])
				a.push(tmp);
			else
				in[tmp] = false, --l;
		}
		if (! l)
			return false;
		for (register int j=1; j<=l; j++) {
			int tmp = a.front();
			a.pop(); in[tmp] = false;
			while (x[tmp] > y[i] && ! in[tmp]) {
				a.push(tmp);
				in[tmp++] = true;
			}
		}
	}
	while (! a.empty())
		a.pop();
	return in[n];
}
bool checkbelow() {
	if (x[1] <= y[1])
		return false;
	for (register int i=2; i<=n; i++)
		in[i] = false;
	in[1] = true;
	a.push(1); l = 1;
	for (register int i=2; i<=m; i++) {
		for (register int j=1; j<=l; j++) {
			int tmp = a.front();
			a.pop();
			if (x[tmp] < y[i])
				a.push(tmp);
			else
				in[tmp] = false, --l;
		}
		if (! l)
			return false;
		for (register int j=1; j<=l; j++) {
			int tmp = a.front();
			a.pop(); in[tmp] = false;
			while (x[tmp] < y[i] && ! in[tmp]) {
				a.push(tmp);
				in[tmp++] = true;
			}
		}
	}
	while (! a.empty())
		a.pop();
	return in[n];
}

bool check() {
	return checkover() || checkbelow();
}

int main() {
 	freopen("expand.in", "r", stdin);
 	freopen("expand.out", "w", stdout);
	scanf("%d %d %d %d", &c, &n, &m, &Q);
	for (register int i=1; i<=n; i++)
		scanf("%d", &p[i]);
	for (register int i=1; i<=m; i++)
		scanf("%d", &q[i]);
	for (register int i=1; i<=n; i++)
		x[i] = p[i];
	for (register int i=1; i<=m; i++)
		y[i] = q[i];
	printf("%d", check());
	while (Q--) {
		scanf("%d %d", &kx, &ky);
		for (register int i=1; i<=kx; i++) {
			scanf("%d %d", &px, &vx);
			x[px] = vx;
		}
		for (register int i=1; i<=ky; i++) {
			scanf("%d %d", &py, &vy);
			y[py] = vy;
		}
		printf("%d", check());
		for (register int i=1; i<=n; i++)
			x[i] = p[i];
		for (register int i=1; i<=m; i++)
			y[i] = q[i];
	}
 	return 0;
}
