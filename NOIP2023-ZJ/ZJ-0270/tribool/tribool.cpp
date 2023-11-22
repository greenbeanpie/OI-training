#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int C, T, n, m;
int id[N], fa[N], siz[N], a[N];
bool flag[N];
int find(int x) {
	while (x != fa[x]) x = fa[x];
	return x;
}
void merge(int x, int y) {
	x = find(x); 
	y = find(y);
	if (x != y) {
		if (siz[y] < siz[x]) {
			a[x] |= a[y]; fa[y] = x; siz[x] += siz[y];		
		} else {
			a[y] |= a[x]; fa[x] = y; siz[y] += siz[x];	
		}
	}
	return;
}
int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin >> C >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			id[i] = fa[i] = i; siz[i] = 1; a[i] = 0; flag[i] = 0;
		}
		while (m--) {
			char op; cin >> op;
			int x, y;
			if (op == 'T') {
				cin >> x; id[x] = 100001;
			}
			if (op == 'F') {
				cin >> x; id[x] = -100001;
			}
			if (op == 'U') {
				cin >> x; id[x] = 0;
			}
			if (op == '+') {
				cin >> x >> y; id[x] = id[y];
			}
			if (op == '-') {
				cin >> x >> y; id[x] = -id[y];
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (!id[i]) a[i] = 1;
		}
		for (int i = 1; i <= n; i++) {
			if (id[i] && abs(id[i]) <= n) merge(i, abs(id[i]));
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] && (find(i) == i)) ans += siz[i];
		}
		//cout << ans << endl;
		for (int i = 1; i <= n; i++) {
			int x = find(i);
			if (!a[x]) {
				int cnt = 0;
				int now = i;
				while (!flag[now] && abs(id[now]) > 0 && abs(id[now]) <= n && abs(id[now]) != i) {
					flag[now] = 1;
					if (id[now] < 0) cnt ^= 1;
					now = abs(id[now]);
				}
				if (id[now] == -i) cnt ^= 1;
				if (abs(id[now]) == i && cnt) {
					ans += siz[x]; a[x] = 1;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}