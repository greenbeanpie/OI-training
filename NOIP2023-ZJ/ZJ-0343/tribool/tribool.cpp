#include <bits/stdc++.h>
#pragma optimize(2)
using namespace std;
struct Node {
	int type;//1:certain;0:uncertain
	int val;//T(2), F(0), U(1)
	int to, fl;//x[i] = x[j](1) || x[i] = !x[j](2)
}x[100005];
inline int read () {
	int res = 0, sym = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')
			sym = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		res = (res<<3) + (res<<1) + c - '0';
		c = getchar();
	}
	return sym * res;
}
inline char readopt () {
	char c = getchar(), st[6] = {'T', 'F', 'U', '-', '+'};
	while (1) {
		for (int i = 0; i < 5; i++) {
			if (c == st[i])
				return c;
		}
		c = getchar();
	}
}
int f[200005];
int find (int v) {
	return (v == f[v] ? v : f[v] = find(f[v]));
}
void merge (int u, int v) {
	int x = find(u), y = find(v);
	if (x != y) {
		f[x] = y;
	}
	return;
}
int main () {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int Case = read(), T = read();
	while (T--) {
		int n = read(), m = read();
		for (int i = 1; i <= n; i++) {
			x[i].type = 0;
			x[i].to = i;
			x[i].fl = 1;
		}
		while (m--) {
			char opt = readopt();
			if (opt == '+') {
				int i = read(), j = read();
				x[i] = x[j];
 			}else if (opt == '-') {
 				int i = read(), j = read();
 				x[i] = x[j];
 				if (x[i].type == 1) {
 					x[i].val = 2 - x[i].val;
				}else {
					x[i].fl ^= 1;
				}
			 }else {
			 	int i = read();
			 	x[i].type = 1;
			 	if (opt == 'T')
			 		x[i].val = 2;
			 	else if (opt == 'F')
			 		x[i].val = 0;
			 	else
			 		x[i].val = 1;
			 }
		}
		int True = n + 1, False = 2 * n + 2;
		n++;
		for (int i = 1; i <= 2 * n; i++) {
			f[i] = i;
		}
		int ans = 0;
		for (int i = 1; i < n; i++) {
			if (i == 100000) {
				int debug = 1;
			}
			if (x[i].type == 1)	{
				if (x[i].val == 1) {
					merge(i, i + n);
				}else if (x[i].val == 2) {
					merge(i, True);
					merge(i + n, False);
				}else {
					merge(i, False);
					merge(i + n, True);
				}
			}else {
				if (x[i].fl) {
					merge(i, x[i].to);
					merge(i + n, x[i].to + n);
				}else {
					merge(i, x[i].to + n);
					merge(i + n, x[i].to);
				}
			}
		}
		for (int i = 1; i < n; i++) {
			if (find(i) == find(i+n)) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}