#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int sum = 0, f = 1;
	char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = -f;
	for(; isdigit(ch); ch = getchar()) sum = (sum << 3) + (sum << 1) + (ch ^ 48);
	return sum * f;
}
void write(int x){
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar('0' + x % 10);
	return;
}
const int N = 1e5 + 10;
int ID, T, n, tot, m, f[N << 2], idx[N], val[N << 2];
int x[N], fa[N], vis[N];
char c[5];
int dis[N];
int getf(int x){
	return x == f[x] ? x : f[x] = getf(f[x]);
}
int ord(char x){
	if(x == 'T') return 1;
	if(x == 'F') return 0;
	return 2;
}
void dfs(int u, int s){
	if(dis[u] != -1) return;
	if(vis[u] != -1){
		if(vis[u] != s) dis[u] = 2;
		else dis[u] = s;
		return;
	}
	vis[u] = s;
	dfs(fa[u], (s ^ x[u]));
	dis[u] = dis[fa[u]] == 2 ? 2 : (dis[fa[u]] ^ x[u]);
	return;
}
void solve(){
	n = read(), m = read();
	tot = n;
	for(int i = 1; i <= n; ++ i) idx[i] = i;
	for(int i = 1; i <= 2 * (n + m); ++ i) fa[i] = 0, f[i] = i, val[i] = dis[i] = vis[i] = -1;
	for(int i = 1, u, v, fu, fv; i <= m; ++ i){
		scanf("%s", c);
		if(c[0] == '+' || c[0] == '-'){
			u = read(), v = read();
			++ tot;
			if(c[0] == '+')
				f[tot] = getf(idx[v]),
				f[tot + n + m] = getf(idx[v] + n + m);
			else
				f[tot] = getf(idx[v] + n + m),
				f[tot + n + m] = getf(idx[v]);
			idx[u] = tot;
		}else{
			u = read();
			idx[u] = ++ tot;
			val[idx[u]] = ord(c[0]);
			val[idx[u] + n + m] = (ord(c[0]) == 2) ? 2 : 1 - ord(v);
		}
	}
//	for(int i = 1; i <= n; ++ i){
//		cout << i << " " << getf(idx[i]) << " " << val[getf(idx[i])] << "\n";
//	}
	for(int i = 1, u, v, w; i <= n; ++ i){
		if(val[getf(idx[i])] != -1)
			dis[i] = val[getf(idx[i])];
		else{
			u = getf(idx[i]), v = i, w = 0;
			if(u > n + m) u -= n + m, w = 1;
			fa[v] = u, x[v] = w;
//			cout << u << " " << v << " " << w << "\n";
		}
	}
	for(int i = 1; i <= n; ++ i)
		if(dis[i] == -1) dfs(i, 0);
//	for(int i = 1; i <= n; ++ i) cout << dis[i] << " ";
//	cout << "\n";
	int ans = 0;
	for(int i = 1; i <= n; ++ i) ans += (dis[i] == 2);
	write(ans);
	puts("");
	return;
}
signed main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ID = read(), T = read();
	while(T --){
		solve();
	}
	return 0;
}
/*
0 1
10 10
- 7 3
- 5 3
+ 3 7
- 1 6
+ 4 6
- 8 4
- 6 8
+ 2 2
- 9 9
- 10 10
*/