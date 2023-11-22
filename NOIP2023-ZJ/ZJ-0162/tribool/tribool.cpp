#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool f1;
int _TCase, T, a[N], x, y, n, m, ans, b[N], fir[N], nxt[N], son[N], tot, cnt, c[N], w[N], ou[N];
bool F, vis1[N], vis2[N];
char v;
bool f2;
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
	for(int i = 1; i <= n; i++) a[i] = i;
	for(int i = 1; i <= n; i++) b[i] = 0;
	for(int i = 1; i <= n; i++) fir[i] = 0;
	for(int i = 1; i <= n; i++) nxt[i] = 0;
	for(int i = 1; i <= n; i++) ou[i] = 0;
	for(int i = 1; i <= n; i++) vis1[i] = vis2[i] = 0;
	ans = tot = 0;
}
inline int _Inv(int x){
	if(x == 2 * n + 1) return 2 * n + 2;
	if(x == 2 * n + 2) return 2 * n + 1;
	if(x == 2 * n + 3) return 2 * n + 3;
	if(x > n) return x - n;
	return x + n;
}
inline void add(int x, int y, int z){
	nxt[++tot] = fir[x];
	fir[x] = tot;
	son[tot] = y;
	w[tot] = z;
}
inline void dfs(int x, int val){
	for(int i = fir[x]; i ; i = nxt[i]){
		if(b[son[i]]) return ;
		b[son[i]] = val + 1;
		ans += val;
		dfs(son[i], val);
	}
}
inline void dfs2(int x){
	b[x] = -1;
	cnt++;
	for(int i = fir[x]; i ; i = nxt[i]){
		if(b[son[i]] == 2){
			F = 1;
			continue ;
		}
		if(b[son[i]] == 1){
			F = 0;
		}
		if(b[son[i]]){
			if(c[son[i]] != c[x] ^ w[i]) F = 1; 
			continue ;
		}
		c[son[i]] = c[x] ^ w[i];
		dfs2(son[i]);
	}
}
inline bool tr(int x){
	bool res = 0;
	vis1[x] = 1;
	for(int i = fir[x]; i ; i = nxt[i]){
		if(vis2[son[i]]) continue ;
		if(vis1[son[i]]) return 1;
		res |= tr(son[i]);
	}
	return res;
}
inline void dfs3(int x){
	if(vis2[x]) return ;
	vis2[x] = 1;
	for(int i = fir[x]; i ; i = nxt[i]){
		dfs3(son[i]);
	} 
}
int main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
//	printf("%.2lfMB\n", (&f2 - &f1) / 1024.0 / 1024.0);
	read(_TCase), read(T);
	while(T--){
		read(n), read(m);
		init();
		while(m--){
			v = getchar();
			while(v != 'T' && v != 'F' && v != '-' && v != '+' && v != 'U') v = getchar();
			if(v == 'T'){
				read(x);
				a[x] = 2 * n + 1;
			}
			if(v == 'F'){
				read(x);
				a[x] = 2 * n + 2;
			}
			if(v == 'U'){
				read(x);
				a[x] = 2 * n + 3;
			}
			if(v == '+'){
				read(x), read(y);
				a[x] = a[y];
			}
			if(v == '-'){
				read(x), read(y);
				a[x] = _Inv(a[y]);
			}
		}
		for(int i = 1; i <= n; i++){
			if(a[i] == i) b[i] = 1;
			if(a[i] == n + i) b[i] = 2, ans++;
			if(a[i] <= n && a[i] != i) add(a[i], i, 0), ou[a[i]]++;
			if(n < a[i] && a[i] <= 2 * n && a[i] != n + i) add(a[i] - n, i, 1), ou[a[i] - n]++;
			if(a[i] == n * 2 + 1 || a[i] == n * 2 + 2) b[i] = 1;
			if(a[i] == n * 2 + 3) b[i] = 2, ans++;
		}
		for(int i = 1; i <= n; i++){
			if(b[i]) dfs(i, b[i] - 1);
		}
		/*
		for(int i = 1; i <= n; i++){
			printf("%d:\n", i);
			for(int j = fir[i]; j  ; j = nxt[j]){
				printf("   %d %d %d\n", i, son[j], w[j]);
			}
		}
		*/
		for(int i = 1; i <= n; i++){
			if(b[i] || ou[i] == 0) continue ;
			cnt = F = 0;
			if(tr(i)){
				dfs2(i);
				if(F) ans += cnt;
			}
			dfs3(i);
		}
		printf("%d\n", ans);
	}
	return 0;
}
