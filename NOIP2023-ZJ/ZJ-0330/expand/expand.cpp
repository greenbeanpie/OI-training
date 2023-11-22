#include <bits/stdc++.h>
#define F(i, l, r) for(int i = l; i < r ; ++ i)
#define Fe(i, l, r) for(int i = l; i <= r; ++ i)
#define reopen(A) { freopen(#A".in", "r", stdin); freopen(#A".out", "w", stdout); }
using namespace std;

constexpr int N = 500005;

int c, q, n, m, ans, a[N], b[N], A[N], B[N];

void solve(){
	if(c == 1){
		if(a[1] != b[1]) cout << 1;
		else cout << 0;
		return ;	
	}
	
	if(c == 2){
		if(a[1] == b[1] || a[n] == b[m]) {
			cout << 0;
			return ;
		}
		if((a[1] > b[1] && a[n] < b[m]) || (a[1] < b[1] && a[n] > b[m])) {
			cout << 0;
			return ;
		}
		cout << 1;
		return ;
	}
	
	if(a[1] == b[1] || a[n] == b[m]) {
		cout << 0;
		return ;
	}
		
	if((a[1] > b[1] && a[n] < b[m]) || (a[1] < b[1] && a[n] > b[m])) {
		cout << 0;
		return ;
	}
//	
//	int cnt = 0;
//	int idx = 1;
//	Fe(i, 1, n){
//		if(b[idx] <= a[i]){
//			if(b[idx + 1] > a[i]) ++ idx;
//			else {
//				++ cnt;
//				if(cnt) {
//					cout << 0;
//					return ;	
//				}
//			}
//		};
//	}
//	cout << cnt << endl;
	cout << 1;
}

signed main(){
	reopen(expand);
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> c >> n >> m >> q;
	Fe(i, 1, n) cin >> A[i];
	Fe(i, 1, m) cin >> B[i];
	
	Fe(i, 1, n) a[i] = A[i];
	Fe(i, 1, m) b[i] = B[i];
	
	solve();
	
	while(q--){
		Fe(i, 1, n) a[i] = A[i];
		Fe(i, 1, m) b[i] = B[i];
		int kx, ky;
		cin >> kx >> ky;
		Fe(i, 1, kx){
			int p, v;
			cin >> p >> v;
			a[p] = v;
		}
		Fe(i, 1, ky){
			int p, v;
			cin >> p >> v;
			b[p] = v;
		}
		solve();
	}
	
	return 0;
}