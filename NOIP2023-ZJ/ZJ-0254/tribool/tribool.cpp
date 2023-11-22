#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, fa[N * 2], sz[N * 2];
bool c[N * 2];
struct rec {
	bool t;//值是否确定 
	int v;// 1 T 2 F 3 U 
	int i, c;
} a[N];
int calc(char ch) {
	if (ch == 'T') return 1;
	if (ch == 'F') return 2;
	if (ch == 'U') return 3;
}
rec _xor(rec a) {
	rec b;
	if (a.t == 1) {
		b = a;
		if (b.v == 2) b.v = 1;
		else if (b.v == 1) b.v = 2;
	} else {
		b = a;
		b.c ^= 1;
	}
	return b;
}
int get(int x) {
	return fa[x] == x ? x : fa[x] = get(fa[x]);
}
int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int cas, T;
	cin >> cas >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) a[i].i = i, a[i].v = a[i].c = a[i].t = 0;
		for (int i = 1; i <= 2 * n; ++i) fa[i] = i, c[i] = 0;
		for (int i = 1, x, y; i <= m; ++i) {
			char op[5];
			scanf("%s%d", op, &x);
			if (op[0] <= 'Z' && op[0] >= 'A') a[x].t = 1, a[x].v = calc(op[0]);
			else if (op[0] == '+') {
				scanf("%d", &y);
				a[x] = a[y]; 
			} else {
				scanf("%d", &y);
				a[x] = _xor(a[y]);
			}
		}
		for (int i = 1; i <= n; ++i)
			if (!a[i].t) {
				if (a[i].c) {
					fa[get(i)] = get(a[i].i + n);
					fa[get(i + n)] = get(a[i].i);
				} else {
					fa[get(i)] = get(a[i].i);
					fa[get(i + n)] = get(a[i].i + n);
				}
			}
		
//		for (int i = 1; i <= n; ++i)
//			if (a[i].t) printf("%d ", a[i].v);
//			else printf("[%d, %d] ", a[i].c, a[i].i);
		int ans = 0;
		for (int i = 1; i <= n; ++i) 
			if (a[i].t && a[i].v == 3) c[get(i)] = c[get(i + n)] = 1;
		for (int i = 1; i <= n; ++i) 
			if (get(i) == get(i + n)) c[get(i)] = c[get(i + n)] = 1;
		for (int i = 1; i <= n; ++i) 
			if (c[get(i)] || c[get(i + n)]) ++ans;
		printf("%d\n", ans);
	}
}
//10 10
//- 7 6
//+ 4 1
//+ 6 4
//T 1
//+ 2 9
//- 9 10
//U 10
//+ 5 5
//U 8
//T 3
//10 10
//- 1 1
//U 1
//T 7
//U 8
//- 9 6
//U 3
//- 9 3
//- 6 3
//+ 9 3
//- 9 8
