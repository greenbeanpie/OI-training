#include <bits/stdc++.h>
using namespace std;
int c, n, m, q, a[7], b[7], aa[1010], bb[1010], fflag, A[7], B[7];
bool dfs(int x, int y, int dep, int now) {
	if(now > dep) {
//		for(int i = 1; i <= dep; ++i) cout << aa[i] << ' ';
//		cout << endl;
//		for(int i = 1; i <= dep; ++i) cout << bb[i] << ' ';
//		cout << endl;
		if(x != n + 1 || y != m + 1) return 0;
		int fl = 0;
		if(aa[1] < bb[1]) fl = 1;
//		for(int i = 1; i <= dep; ++i) cout << aa[i] << ' ';
//		cout << endl;
//		for(int i = 1; i <= dep; ++i) cout << bb[i] << ' ';
//		cout << endl;
		for(int i = 1; i <= dep; ++i) {
			if(fl && aa[i] > bb[i]) return 0;
			if(!fl && aa[i] < bb[i]) return 0;
		}
		return 1;
	}
	if(fflag == 0) {
		bool tmp;
		if(a[x] > b[y]) {
			aa[now] = a[x]; bb[now] = b[y]; 
			tmp = dfs(x + 1, y + 1, dep, now + 1);
			if(tmp) return 1;
		}
		if(a[x - 1] > b[y] && x != 1) {
			aa[now] = a[x - 1]; bb[now] = b[y];
			tmp = dfs(x, y + 1, dep, now + 1);
			if(tmp) return 1;
		}
		if(a[x] > b[y - 1] && y != 1) {
			aa[now] = a[x]; bb[now] = b[y - 1]; 
			tmp = dfs(x + 1, y, dep, now + 1);
			if(tmp) return 1;
		}
	} else {
		bool tmp;
		if(a[x] < b[y]) {
			aa[now] = a[x]; bb[now] = b[y]; 
			tmp = dfs(x + 1, y + 1, dep, now + 1);
			if(tmp) return 1;
		}
		if(a[x - 1] < b[y] && x != 1) {
			aa[now] = a[x - 1]; bb[now] = b[y];
			tmp = dfs(x, y + 1, dep, now + 1);
			if(tmp) return 1;
		}
		if(a[x] < b[y - 1] && y != 1) {
			aa[now] = a[x]; bb[now] = b[y - 1]; 
			tmp = dfs(x + 1, y, dep, now + 1);
			if(tmp) return 1;
		}
	}
	return 0;
}
void solve() {
	for(int i = 1; i <= n * m; ++i) aa[i] = bb[i] = 0;
	for(int i = 1; i <= n * m; ++i) {
		if(dfs(1, 1, i, 1)) {
			cout << "1";
			return ;
		}
	}
	cout << "0";
}
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin >> c >> n >> m >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		A[i] = a[i];
	}
	for(int i = 1; i <= m; ++i) {
		cin >> b[i];
		B[i] = b[i];
	}
	if(a[1] < b[1]) fflag = 1;
	else fflag = 0;
	while(q --) {
		solve();
		int kx, ky;
		cin >> kx >> ky;
		for(int i = 1; i <= n; ++i) a[i] = A[i], b[i] = B[i];
		for(int i = 1, px, tx; i <= kx; ++i) {
			cin >> px >> tx;
			a[px] = tx;
		}
		for(int i = 1, py, ty; i <= ky; ++i) {
			cin >> py >> ty;
			b[py] = ty;
		}
		if(a[1] < b[1]) fflag = 1;
		else fflag = 0;
	}
	solve();
	return 0;
}