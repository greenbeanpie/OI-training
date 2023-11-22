#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -f; c = getchar();}
	while (c >= '0' && c <= '9') {x = x * 10 + (c ^ 48); c = getchar();}
	return x * f;
}
const int N = 5e5 + 5, M = 65, INF = 0x3f3f3f3f;
int Test_case;
int A[N], B[N], t1[N], t2[N], Ans[M], mn[N], mx[N], nxt1[N], nxt2[N], pre1[N], pre2[N], stk[N];
vector <int> num1, num2;
int getmn(int *a, int l, int r) {
	int res = INF;
	for (int i = l; i <= r; i++) res = min(res, a[i]);
	return res;
}
int getmx(int *a, int l, int r) {
	int res = 0;
	for (int i = l; i <= r; i++) res = max(res, a[i]);
	return res;
}
int get_ed(int *a, int *b) {
	int x = 0, y = 0;
	while (x + 1 < num1.size() || y + 1 < num2.size()) {
		int fl = 0;
		if (x + 1 < num1.size() && mx[x] < b[num2[y]]) {
			fl = 1;
			x++;
		}
		if (y + 1 < num2.size() && mn[y] > a[num1[x]]) {
			fl = 1;
			y++;
		}
		if (!fl) return 0;
	}
	return 1;
}
int calc(int *a, int *b, int n, int m) {
	int mx1 = 0, mx2 = 0, mn1 = INF, mn2 = INF, t = 0;
	for (int i = 1; i <= n; i++) mx1 = max(mx1, a[i]), mn1 = min(mn1, a[i]);
	for (int i = 1; i <= m; i++) mx2 = max(mx2, b[i]), mn2 = min(mn2, b[i]);
	if (mx1 >= mx2 || mn1 >= mn2) return 0;
	for (int i = 1; i <= n; i++) {
		while (t && a[i] <= a[stk[t]]) t--;
		pre1[i] = stk[t];
		stk[++t] = i;
	}
	t = 0;
	for (int i = 1; i <= m; i++) {
		while (t && b[i] >= b[stk[t]]) t--;
		pre2[i] = stk[t];
		stk[++t] = i;
	}
	t = 0;
	for (int i = n; i; i--) {
		while (t && a[i] <= a[stk[t]]) t--;
		nxt1[i] = stk[t];
		stk[++t] = i;
	}
	t = 0;
	for (int i = m; i; i--) {
		while (t && b[i] >= b[stk[t]]) t--;
		nxt2[i] = stk[t];
		stk[++t] = i;
	}
	num1.clear(); num2.clear(); t = 1;
	while (t) {
		num1.push_back(t);
		t = nxt1[t];
	}
	t = 1;
	while (t) {
		num2.push_back(t);
		t = nxt2[t];
	}
	mx[0] = a[1];
	for (int i = 0; i + 1 < num1.size(); i++) mx[i] = getmx(a, num1[i], num1[i + 1]);
	mn[0] = b[1];
	for (int i = 0; i + 1 < num2.size(); i++) mn[i] = getmn(b, num2[i], num2[i + 1]);
	if (!get_ed(a, b)) return 0;
	num1.clear(); num2.clear();
	t = n;
	while (t) {
		num1.push_back(t);
		t = pre1[t];
	}
	t = m;
	while (t) {
		num2.push_back(t);
		t = pre2[t];
	}
	mx[0] = a[n];
	for (int i = 0; i + 1 < num1.size(); i++) mx[i] = getmx(a, num1[i + 1], num1[i]);
	mn[0] = b[m];
	for (int i = 0; i + 1 < num2.size(); i++) mn[i] = getmn(b, num2[i + 1], num2[i]);
	if (!get_ed(a, b)) return 0;
	return 1;
}
void Solve() {
	int n, m, q;
	Test_case = read(); n = read(); m = read(); q = read();
	for (int i = 1; i <= n; i++) A[i] = read();
	for (int i = 1; i <= m; i++) B[i] = read();
	for (int i = 0; i <= q; i++) Ans[i] = 0;
	for (int k = 0; k <= q; k++) {
		for (int i = 1; i <= n; i++) t1[i] = A[i];
		for (int i = 1; i <= m; i++) t2[i] = B[i];
		if (k) {
			int k1 = read(), k2 = read();
			while (k1--) {
				int p = read(), v = read();
				t1[p] = v;
			}
			while (k2--) {
				int p = read(), v = read();
				t2[p] = v;
			}
		}
		if (t1[1] == t2[1] || t1[n] == t2[m]) continue;
		if (t1[1] < t2[1] && t1[n] > t2[m]) continue;
		if (t1[1] > t2[1] && t1[n] < t2[m]) continue;
		if (t1[1] > t2[1]) Ans[k] = calc(t2, t1, m, n);
		else Ans[k] = calc(t1, t2, n, m);
	}
	for (int i = 0; i <= q; i++) putchar(Ans[i] + '0'); putchar('\n');
}
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	int _ = 1;
	while (_--) Solve();
	return 0;
}