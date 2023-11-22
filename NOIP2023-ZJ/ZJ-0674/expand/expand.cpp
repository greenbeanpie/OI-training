#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;

long long x[N], y[N], idx[N];
int c, n, m, q, kx, ky, bl1, bl2, pos[N];

inline int check(long long x[], long long y[]) {
	bl1 = 0, bl2 = 0;
	if (x[1] - y[1] > 0) bl1 = 1;
	if (x[n] - y[n] > 0) bl2 = 1;
	if ((bl1 != bl2) || (x[1] == y[1] || x[n] == y[n])) {
		return 0;			
	} int k = 0, f = 0;
	for (k = 1; k <= n; k ++) {
		if (bl1 == 1 && x[2] > y[k]) {
			f = 1; break;
		} else if (bl1 == 0 && x[2] < y[k]) {
			f = 1; break;
		} 
	} if (f == 0) return 0;
	for (int i = 3; i < n; i++) {
		f = 0;
		if ((bl1 == 1 && x[i] > y[k]) || (bl1 == 0 && x[i] < y[k])) {
			f = 1; break;
		} else if ((bl1 == 1 && x[i] > y[k + 1]) || (bl1 == 0 && x[i] < y[k + 1])) {
			f = 1; k = k + 1; break;
		} if (f == 0) return 0;
	} return 1;
}
int main () {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin >> c >> n >> m >> q;
	
	if (c == 1) {
		long long xx, yy;
		cin >> xx >> yy;
		if (xx == yy) cout << 0;
		else cout << 1;
		for (int i = 1; i <= q; i++) {
			cin >> kx >> ky;
			long long xxx = xx, yyy = yy;
			for (int j = 1; j <= kx; j++) {
				int p; long long v;	
				cin >> p >> v; xxx = v;
			}
			for (int j = 1; j <= ky; j++) {
				int p; long long v;
				cin >> p >> v; yyy = v;
			}
			if (xxx == yyy) cout << 0;
			else cout << 1;
		} return 0;
	}
	
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i <= m; i++) cin >> y[i];
	cout << check(x, y);
	
	for (int i = 1;i <= q; i++) {
		cin >> kx >> ky; 
		memset(pos, 0, sizeof(pos));
		memset(idx, 0, sizeof(idx));
		
		for (int j = 1; j <= kx; j++) {
			int p; long long v;
			cin >> p >> v;
			pos[j] = p, idx[j] = x[p]; 
			x[p] = v;
		} 
		for (int j = 1; j <= ky; j++) {
			int p; long long v;
			cin >> p >> v; 
			pos[kx + j] = p, idx[kx + j] = y[p];
			y[p] = v;
		} cout << check(x, y);
	
		for (int j = 1; j <= kx; j++) {
			x[pos[j]] = idx[j];
		}
		for (int j = 1; j <= ky; j++) {
			y[pos[kx + j]] = idx[kx + j];
		}
	} return 0;
}