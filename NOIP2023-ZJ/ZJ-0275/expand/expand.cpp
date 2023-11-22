#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, T;
int a[500009], b[500009];
int x[500009], y[500009];
int r[500009];
bool dfs(int pos){
	if(pos == n + 1){
		return r[n] == m;
	}
	if(x[pos] > y[r[pos - 1]] && pos != 1){
		for(int i = r[pos - 1]; i <= m ; i ++ ){
			if(x[pos] > y[i]){
				r[pos] = i;
				if(dfs(pos + 1)) return true;
			}else{
				return false;
			}
		}
	}else{
		if(x[pos] > y[r[pos - 1] + 1] && r[pos - 1] + 1 <= m){
			for(int i = r[pos - 1] + 1; i <= m ; i++ ){
				if(x[pos] > y[i]){
					r[pos] = i;
					if(dfs(pos + 1)) return true;
				}else{
					return false;
				}
			}
		}else{
			return false;
		}
	}
	return false;
}
void solve(){
	if((x[1] - y[1]) * (x[n] - y[m]) <= 0) {
		cout << 0;
		return ;
	}
	if(x[1] < y[1]){ for(int i = 1; i <= max(n, m); i ++ ) swap(x[i], y[i]); swap(n, m);}
	if(dfs(1)) cout << 1;
	else cout << 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin >> c >> n >> m >> T;
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	for(int j = 1; j <= m; j ++ ) cin >> b[j];
	for(int i = 1; i <= n; i ++ ) x[i] = a[i];
	for(int i = 1; i <= m; i ++ ) y[i] = b[i];
	solve();
	while(T --){
		for(int i = 1; i <= n; i ++ ) x[i] = a[i];
		for(int i = 1; i <=m; i ++ ) y[i] = b[i];
		int kx, ky;
		cin >> kx >> ky;
		for(int i = 1; i <= kx; i ++ ){
			int p, v;
			cin >> p >> v;
			x[p] = v;
		}
		for(int i = 1; i <= ky; i ++ ){
			int p, v;
			cin >> p >> v;
			y[p] = v;
		}
		solve();
	}
	return 0;
}
