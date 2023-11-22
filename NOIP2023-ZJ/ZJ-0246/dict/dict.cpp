#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -f; c = getchar();}
	while (c >= '0' && c <= '9') {x = (x << 3) + (x << 1) + (c ^ 48); c = getchar();}
	return x * f;
}

const int N = 3050, M = 6050, inf = 1e9;

inline void chmin(int &x, int v) {x = x > v ? v : x;}

inline void chmax(int &x, int v) {x = x > v ? x : v;}

int n, m, mn[N], mx[N];
char s[N];

int ct[300];

struct node {
	char c[N]; int id;
	friend inline bool operator <(const node &x, const node &y) {
		for (int j = 1; j <= m; ++ j)
			if (x.c[j] != y.c[j])
				return x.c[j] < y.c[j];
		return 0;
	}
	friend inline bool operator ==(const node &x, const node &y) {
		for (int j = 1; j <= m; ++ j)
			if (x.c[j] != y.c[j])
				return 0;
		return 1;
	}
	friend inline bool operator !=(const node &x, const node &y) {
		for (int j = 1; j <= m; ++ j)
			if (x.c[j] != y.c[j])
				return 1;
		return 0;
	}
} f[M];

int pre[N], suf[N];

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	n = read(); m = read(); 
	for (int i = 1, t; i <= n; ++ i) {
		scanf("%s", s + 1);
		for (int j = 1; j <= m; ++ j)
			ct[s[j]] ++;
		t = 0;
		for (int j = 'a'; j <= 'z'; ++ j)
			for (int k = 1; k <= ct[j]; ++ k)
				f[i*2-1].c[++ t] = j;
		t = 0;
		for (int j = 'z'; j >= 'a'; -- j)
			for (int k = 1; k <= ct[j]; ++ k)
				f[i*2].c[++ t] = j;
		f[i*2-1].id = f[i*2].id = i;
		for (int j = 'a'; j <= 'z'; ++ j)
			ct[j] = 0;
	} sort(f + 1, f + 1 + 2*n);
	memset(mn, 0x3f, sizeof mn); mn[f[1].id] = mx[f[1].id] = 1;
	for (int i = 2, j = 1; i <= 2*n; ++ i) {
		if (f[i] != f[i-1]) ++ j;
		chmin(mn[f[i].id], j);
		chmax(mx[f[i].id], j);
	}
	pre[0] = suf[n+1] = inf;
	for (int i = 1; i <= n; ++ i)
		pre[i] = min(pre[i-1], mx[i]);
	for (int i = n; i >= 1; -- i)
		suf[i] = min(suf[i+1], mx[i]);
	for (int i = 1; i <= n; ++ i)
		if (pre[i-1] > mn[i] && suf[i+1] > mn[i])
			putchar('1');
		else
			putchar('0');
	putchar('\n');
	return 0;
}