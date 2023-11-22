#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 5, M = 1e5 + 5;
int T, _Tcase, n, m, f[N][N], K, d, E, ans, g[N];
struct lunc{
	int x, v, k;
}tem;
vector<lunc>a[N];
inline void read(int &res){
	res = 0;
	int f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		res = (res << 1) + (res << 3) + (ch - 48);
		ch = getchar();
	}
	res *= f;
}
inline void init(){
	for(int i = 1; i <= n; i++) for(int j = 0; j <= K; j++) f[i][j] = -d * j;
	for(int i = 1; i <= n; i++) a[i].clear();
	for(int i = 0; i <= n; i++) g[i] = 0;
	ans = 0;
}
signed main(){
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	read(_Tcase), read(T);
	while(T--){
		read(n), read(m), read(K), read(d);
		init();
		while(m--){
			read(tem.x), read(tem.k), read(tem.v);
			if(tem.k > K) continue ;
			a[tem.x].push_back(tem);
		}
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= i && j <= K; j++){
				if(j == 0){
					f[i][0] = max(f[i][0], g[i - 1]);
					g[i] = max(f[i][0], g[i]);
					continue ;
				}
				E = 0;
				for(auto kk : a[i]){
					if(kk.k <= j) E += kk.v;
				}
				f[i][j] = max(f[i][j], f[i - 1][j - 1] - d + E);
				g[i] = max(g[i], f[i][j]);
			}
			ans = max(ans, g[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
