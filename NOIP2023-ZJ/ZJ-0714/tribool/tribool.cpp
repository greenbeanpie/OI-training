#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 57;
int read(){
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') f = -f; ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
	return x * f;
}

bool _u;

int c, t, n, m, ans;
int a[N], b[N];
int fa[N];
struct Query{
	int opt, x, y;
}q[N];


void dfs(int x){
	if(x > n){
		int res = 0;
		for(int i = 1; i <= n; ++i){	
			if(a[i] == 3) ++res;
			b[i] = a[i];
		} 
		if(res > ans) return ;
		for(int i = 1; i <= m; ++i){
			if(q[i].opt <= 3) b[q[i].x] = q[i].opt;
			else if(q[i].opt == 4){
				b[q[i].x] = b[q[i].y];
			}else {
				if(b[q[i].y] <= 2) b[q[i].x] = 3 - b[q[i].y];
				else b[q[i].x] = b[q[i].y];
			}
		}
		bool flag = 1;
		for(int i = 1; i <= n; ++i) if(a[i] != b[i]) flag = 0;
		if(flag) ans = min(ans, res);
		return ;
	}
	for(int i = 1; i <= 3; ++i){
		a[x] = i;
		dfs(x + 1);
	}
}

int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}

void solve(){
	n = read(), m = read(); ans = 1e9; 
	int cnt = 0;
	for(int i = 1; i <= n; ++i) a[i] = b[i] = 0;
	if(c >= 3 && c <= 4){
		while(m--){
			char opt[5]; scanf("%s", opt + 1);
			int x = read();
			if(opt[1] == 'T') a[x] = 1;
			else if(opt[1] == 'F') a[x] = 2;
			else if(opt[1] == 'U') a[x] = 3;
		}
		for(int i = 1; i <= n; ++i) if(a[i] == 3) ++cnt;
		printf("%d\n", cnt);
		return ;
	}
	for(int i = 1; i <= m; ++i){
		char opt[5]; scanf("%s", opt + 1), q[i].x = read();
		if(opt[1] == 'T') q[i].opt = 1;
		else if(opt[1] == 'F') q[i].opt = 2;
		else if(opt[1] == 'U') q[i].opt = 3;
		else if(opt[1] == '+') q[i].opt = 4, q[i].y = read();
		else q[i].opt = 5, q[i].y = read();
	}
	if(c >= 1 && c <= 2){
		dfs(1);
		printf("%d\n", ans);
		return ;
	}
	if(c >= 5 && c <= 6){
		for(int i = 1; i <= n; ++i) fa[i] = i;
		for(int i = 1; i <= m; ++i){
			if(q[i].opt == 3) a[find(q[i].x)] = 1;
			else {
				int x = find(q[i].x);
				int y = find(q[i].y);
				fa[x] = y; a[y] = a[x];
			}
		}
		for(int i = 1; i <= n; ++i) if(a[find(i)]) ++cnt;
		printf("%d\n", cnt);
		return ;
	}
}

bool _v;

int main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	
	cerr << abs(&_u - &_v) / 1048576.0 << " MB\n";
	
	c = read(), t = read();
	while(t--) solve();
	return 0;
}
