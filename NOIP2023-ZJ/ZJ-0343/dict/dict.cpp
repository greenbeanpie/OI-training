#include <bits/stdc++.H>
using namespace std;
struct String {
	char mn[3005], mx[3005];
}s[3005];
int n, m;
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
inline bool compare (char* x, char* y) {//return x > y
	for (int i = 0; i < m; i++) {
		if (x[i] > y[i])
			return true;
		if (x[i] < y[i])
			return false;
	}
	return false;
}
inline bool check (int x) {
	for (int i = 1; i < x; i++) {
		if (!compare(s[i].mx, s[x].mn))
			return false;
	}
	for (int i = x + 1; i <= n; i++) {
		if (!compare(s[i].mx, s[x].mn))
			return false;
	}
	return true;
}
int main () {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		scanf("%s", s[i].mn);
		sort(s[i].mn, s[i].mn + m);
		for (int j = 0; j < m; j++)
			s[i].mx[m-1-j] = s[i].mn[j];
	}
	for (int i = 1; i <= n; i++) {
		if (check(i)) {
			putchar('1');
		}else {
			putchar('0');
		}
	}
	putchar('\n');
	return 0;
}