/*
b cost me 2h but only 40pts
IMSB

10:49 play the gomoku with the emacs and won ^_^
*/

#include<bits/stdc++.h>
using namespace std;

int a[500005], b[500005], c[500005], d[500005];
vector<pair<int, int> > vx, vy;
int id, n, m, q;
inline int solve() {
//	int amx = 1, bmx = 1, amn = 1, bmn = 1;
//	for(int i = 1; i <= n; i++) {
//		if(a[i] > a[amx]) amx = i;
//		if(a[i] < a[amn]) amn = i;
//	}
//	for(int i = 1; i <= m; i++) {
//		if(b[i] > b[bmx]) bmx = i;
//		if(b[i] < b[bmn]) bmn = i;
//	}
//	if(a[amx] == b[bmx]) return 0;
//	if(a[amx] > b[bmx]) {
//		for(int i = 1, j = 1; i <= amx; i++) {
//			if(a[i] < b[j]) return 0;
//		}
//		return 1;
//	} else {
//		for(int i = 1, j = 1; i <= bmx; i++) {
//			if(a[i] > b[j]) return 0;
//		}
//		return 1;
//	}
	for(int i = 1; i <= n; i++) cout << a[i] << " ";
	cout << endl;
	for(int i = 1; i <= m; i++) cout << b[i] << " ";
	cout << endl;
	if(m == 1) {
		if(a[1] > b[1] && a[2] > b[1]) return 1;
		if(b[1] > a[1] && b[1] > a[2]) return 1;
		return 0; 
	} else if(n == 1) {
		if(b[1] > a[1] && b[2] > a[1]) return 1;
		if(a[1] > b[1] && a[1] > b[2]) return 1;
		return 0; 
	} else {
		if(a[1] > b[1] && a[2] > b[2]) return 1;
		if(b[1] > a[1] && b[2] > a[2]) return 1;
		return 0;
	}
}
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	
	cin >> id >> n >> m >> q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> b[i];
	if(id == 1 || ((n == 1) && (m == 1))) {
		if(d[1] != c[1]) cout << 1;
		else cout << 0;
		while(q--) {
			int kx, ky;
			cin >> kx >> ky;
			for(int i = 1; i <= n; i++) c[i] = a[i];
			for(int i = 1; i <= m; i++) d[i] = b[i];
			for(int i = 1; i <= kx; i++) {
				int p, v;
				cin >> p >> v;
				c[i] = v;
			}
			for(int i = 1; i <= ky; i++) {
				int p, v;
				cin >> p >> v;
				d[i] = v;
			}
			if(d[1] != c[1]) cout << 1;
			else cout << 0;
		}
		cout << endl;
	} else {
		cout << solve();
		while(q--) {
			vx.clear();
			vy.clear();
			int kx, ky;
			cin >> kx >> ky;
			for(int i = 1; i <= kx; i++) {
				int p, v;
				cin >> p >> v;
				vx.push_back({p, a[p]});
				a[p] = v;
			}
			for(int i = 1; i <= ky; i++) {
				int p, v;
				cin >> p >> v;
				vy.push_back({p, b[p]});
				b[p] = v;
			}
			cout << solve();
			for(auto x : vx) a[x.first] = x.second;
			for(auto x : vy) b[x.first] = x.second; 
		}
		cout << endl;
	}
	return 0;
}
