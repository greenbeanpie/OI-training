#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int c, n, m, q;
int a[N], b[N];

inline void ope(){
	if( c == 1 )
		cout << 1;
	if( c == 2 ){
		if( a[1] > b[1] && a[n] < b[m] )
			cout << 0;
		else if( a[1] < b[1] && a[n] > b[m] )
			cout << 0;
		else
			cout << 1;
	}
	return;
}

signed main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> c >> n >> m >> q;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++)
		cin >> b[i];
	
	ope();
	while( q-- ){
		int cnt1, cnt2;
		cin >> cnt1 >> cnt2;
		for(int j = 1; j <= cnt1; j++){
			int x, v;
			cin >> x >> v;
			a[x] = v;
		}
		for(int j = 1; j <= cnt2; j++){
			int x, v;
			cin >> x >> v;
			b[x] = v;
		}
		ope();
	}
	return 0;
}