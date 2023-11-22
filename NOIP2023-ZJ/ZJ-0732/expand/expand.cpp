#include <bits/stdc++.h>
typedef long long ll;
#define int ll
constexpr int maxn = 2e5 + 10;
constexpr int mod = 1e9 + 7;
using namespace std;

inline void FileIO(string name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}	

int c, n, m, q, kx, ky;
int a[maxn], b[maxn], pa[maxn], pb[maxn];

namespace Subtask1 {
	
	inline void Main() {
		
		for(int i = 1; i <= n; ++i) cin >> a[i], pa[i] = a[i];
		for(int i = 1; i <= m; ++i) cin >> b[i], pb[i] = b[i];
		
		cout << (a[1] != b[1]);
				
		while(q --) {
			for(int i = 1; i <= n; ++i) a[i] = pa[i];
			for(int i = 1; i <= m; ++i) b[i] = pb[i];
			cin >> kx >> ky;
			for(int u, v, i = 1; i <= kx; ++i) {
				cin >> u >> v;
				a[u] = v;
			}
			for(int u, v, i = 1; i <= ky; ++i) {
				cin >> u >> v;
				b[u] = v;
			}
			cout << (a[1] != b[1]);
		}
			
		return ;
	}
}

namespace Subtask2 {
	
	inline void Main() {
		
		for(int i = 1; i <= n; ++i) cin >> a[i], pa[i] = a[i];
		for(int i = 1; i <= m; ++i) cin >> b[i], pb[i] = b[i];
		
		if(n == 1) a[2] = a[1];
		if(m == 1) b[2] = b[1];
		
		cout << ((a[1] - b[1]) * (a[2] - b[2]) > 0);
		
		while(q --) {
			for(int i = 1; i <= n; ++i) a[i] = pa[i];
			for(int i = 1; i <= m; ++i) b[i] = pb[i];
			cin >> kx >> ky;
			for(int u, v, i = 1; i <= kx; ++i) {
				cin >> u >> v;
				a[u] = v;
			}
			for(int u, v, i = 1; i <= ky; ++i) {
				cin >> u >> v;
				b[u] = v;
			}
			if(n == 1) a[2] = a[1];
			if(m == 1) b[2] = b[1];
			cout << ((a[1] - b[1]) * (a[2] - b[2]) > 0);	
		}
			
		return ;
	}
}

namespace Subtask3 {
	
	inline void Main() {
		for(int i = 1; i <= n; ++i) cin >> a[i], pa[i] = a[i];
		for(int i = 1; i <= m; ++i) cin >> b[i], pa[i] = b[i];
		
		int posa = 1, posb = 1;
		while(posa <= n && posb <= m) {
			while(posb <= m && a[posa] > b[posb]) posb ++;
			posa ++;
		}
		cout << (posb <= m);
		while(q --) {
			for(int i = 1; i <= n; ++i) a[i] = pa[i];
			for(int i = 1; i <= m; ++i) b[i] = pb[i];
			cin >> kx >> ky;
			for(int u, v, i = 1; i <= kx; ++i) {
				cin >> u >> v;
				a[u] = v;
			}
			for(int u, v, i = 1; i <= ky; ++i) {
				cin >> u >> v;
				b[u] = v;
			}
			posa = 1, posb = 1;
			while(posa <= n && posb <= m) {
				while(posb <= m && a[posa] > b[posb]) posb ++;
				posa ++;
			}
			cout << (posb <= m);
		}
		
		return ;
	}
	
}

signed main() {

	FileIO("expand");

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> c >> n >> m >> q;
	if(c == 1){
		Subtask1::Main();
		return 0;
	}
	if(c == 2) {
		Subtask2::Main();
		return 0;
	}
	if(c >= 8 && c <= 14) {
		Subtask3::Main();
		return 0;
	}
	
	for(int i = 1; i <= n; ++i) cin >> a[i], pa[i] = a[i];
	for(int i = 1; i <= m; ++i) cin >> b[i], pa[i] = b[i];
	int res = 0;
	for(int i = 1; i <= min(n, m); ++i) res += (a[i] > b[i]);
	cout << res % 2;
	while(q --) {
		for(int i = 1; i <= n; ++i) a[i] = pa[i];
		for(int i = 1; i <= m; ++i) b[i] = pb[i];
		cin >> kx >> ky;
		for(int u, v, i = 1; i <= kx; ++i) {
			cin >> u >> v;
			a[u] = v;
		}
		for(int u, v, i = 1; i <= ky; ++i) {
			cin >> u >> v;
			b[u] = v;
		}
		res = 0;
		for(int i = 1; i <= min(n, m); ++i) res += (a[i] > b[i]);
		cout << res % 2;		
	}


	return 0;
}
