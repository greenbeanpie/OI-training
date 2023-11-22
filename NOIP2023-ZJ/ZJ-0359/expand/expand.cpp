#include<bits/stdc++.h>
using namespace std;
bool vist[200005];
inline int read() {
	int f = 1, x = 0;
	char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') {
		ch = getchar();
	}
	if (ch == '-') {
		f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + int(ch) - 48;
		ch = getchar();
	}
	return x * f;
}int a[100005], b[100005], a1[100005], b1[100005];
map <int, int> Map, Map1;
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	int C = read(), n = read(), m = read(), Q = read();
	for (int i = 1; i <= n; ++ i) {
		a[i] = read();
		++ Map[a[i]];
	}
	bool flag = !Map[0];
	for (int i = 1; i <= m; ++ i) {
		b[i] = read();
		if (flag) {
			if (Map[b[i]]) {
				flag = 0;
			}
		}
	}
	if (flag)
		printf("1");
	else
		printf("0");
	while (Q --) {
		for (int i = 1; i <= n; ++ i) {
			a1[i] = a[i];
		}
		for (int i = 1; i <= m; ++ i) {
			b1[i] = b[i];
		}
		Map1 = Map;
		int kx = read(), ky = read();
		for (int i = 1; i <= kx; ++ i) {
			int x = read(), y = read();
			-- Map1[a1[x]];
			a1[x] = y;
			++ Map1[a1[y]];
		}
		flag = !Map1[0];
		for (int i = 1; i <= ky; ++ i) {
			int x = read(), y = read();
			b1[x] = y;
		}
		for (int i = 1; i <= m && flag; ++ i) {
			if (Map1[b1[i]]) {
					flag = 0;
			}
		}
		if (flag)
			printf("1");
		else
			printf("0");
	}
	return 0;
}
/*

*/
