/*
Time complexity: O(3^n * m) / O(n)
Esimated score: 20

mei zi xi kan bu fen fen, lai bu ji le.

written at 12: 49.
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct opt {
	int tp, x, y;
} a[N];

int c, t, n, m, ans, x[N], xt[N], fa[N];
char b[N];

int get(int p, int t) {
	if(t == 1) return x[p];
	else {
		if(x[p] == 2) return 2;
		else return 1 - x[p];
	}
}

void check() {
	for(int i = 1; i <= n; ++ i) xt[i] = x[i];
	for(int i = 1; i <= m; ++ i) {
		if(a[i].tp == 0) x[a[i].x] = get(a[i].y, 2);
		else if(a[i].tp == 1) x[a[i].x] = get(a[i].y, 1);
		else x[a[i].x] = a[i].y;
	}
	int cnt = 0, f = 0;
	for(int i = 1; i <= n; ++ i) {
		cnt += (xt[i] == 2);
		if(x[i] != xt[i]) {
			f = 1;
			break;
		}
	}
	if(!f) ans = min(ans, cnt);
	for(int i = 1; i <= n; ++ i) x[i] = xt[i];
}

void dfs(int dep, int cnt) {
	if(cnt >= ans) return ;
	if(dep == n + 1) {
		check();
		return ;
	}
	
	x[dep] = 0;
	dfs(dep + 1, cnt);
	x[dep] = 1;
	dfs(dep + 1, cnt);
	x[dep] = 2; 
	dfs(dep + 1, cnt + 1);
} 

void clear() { ans = INT_MAX; }
void slove1() {
	cin >> n >> m;
	for(int i = 1; i <= m; ++ i) {
		char ch; cin >> ch;
		if(ch == '+' || ch == '-') {
			a[i].tp = (ch == '+');
			cin >> a[i].x >> a[i].y;
		} else {
			a[i].tp = 2;
			cin >> a[i].x;
			switch(ch) {
				case 'T': a[i].y = 1; break;
				case 'F': a[i].y = 0; break;
				case 'U': a[i].y = 2; break;
			}
		}
	}
	dfs(1, 0);
	cout << ans << endl;
}

void slove2() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i) b[i] = 'T';
	for(int i = 1; i <= m; ++ i) {
		char ch; int p;
		cin >> ch >> p;
		b[p] = ch;
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++ i) cnt += (b[i] == 'U');
	cout << cnt << endl;
}

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void slove3() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i) fa[i] = i, b[i] = 'T';
	for(int i = 1; i <= m; ++ i) {
		char ch; cin >> ch;
		if(ch == 'U') {
			int p; cin >> p;
			b[p] = ch, fa[p] = p;
		} else {
			int x, y; cin >> x >> y;
			fa[x] = y;
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++ i) if(b[find(i)] == 'U') ++ cnt;
	cout << cnt << endl;
}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin >> c >> t;
	
	while(t --> 0) {
		clear();
		if(c <= 2) slove1();
		else if(c == 3 || c == 4) slove2();
		else slove3();
	}
	return 0;
}