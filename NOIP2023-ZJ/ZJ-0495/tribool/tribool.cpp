#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;

int o, T, n, m, fa[N << 1], u, v, h[N], tot, ok[N];
struct edge{
	int v, nxt, k;
}e[N << 1];
struct node{
	char op;
	int u, v;
}nd[N << 1];
char op;

namespace bf{
	int r[N], now[N], ans;
	
	bool check(){
		for(int i = 1; i <= n; i ++)  now[i] = r[i];
		for(int i = 1; i <= m; i ++){
			if(nd[i].op == '+'){
				now[nd[i].v] = now[nd[i].u];
			}
			else if(nd[i].op == '-'){
				now[nd[i].v] = -now[nd[i].u];
			}
			else{
				if(nd[i].op == 'T')  now[nd[i].u] = 1;
				else if(nd[i].op == 'F')  now[nd[i].u] = -1;
				else  now[nd[i].u] = 0;
			}
		}
		for(int i = 1; i <= n; i ++)  if(now[i] != r[i])  return 0;
		return 1;
	}
	
	void dfs(int x, int k){
		if(x > n){
			if(check()){
				ans = min(ans, k);
			}
			return ;
		}
		r[x] = 1;  dfs(x + 1, k);
		r[x] = -1;  dfs(x + 1, k);
		r[x] = 0;  dfs(x + 1, k + 1);
	}
	
	void solve(){
		cin >> n >> m;  tot = 0;
		for(int i = 1; i <= (n << 1); i ++)  h[i] = 0;
		for(int i = 1; i <= m; i ++){
			cin >> nd[i].op;
			if(nd[i].op == '+' || nd[i].op == '-'){
				cin >> nd[i].v >> nd[i].u;
			}else{
				cin >> nd[i].u;
			}
		}
		ans = n;
		dfs(1, 0);
		cout << ans << '\n';
	}
}

namespace sub2{
	int r[N], u;
	char op;
	
	void solve(){
		cin >> n >> m;
		for(int i = 1; i <= m; i ++){
			cin >> op >> u;
			if(op == 'U')  r[i] = 2;
			else if(op == 'T')  r[i] = 1;
			else  r[i] = 3;
		}
		int ans = 0;
		for(int i = 1; i <= n; i ++){
			if(r[i] == 2)  ans ++;
		}
		cout << ans << '\n';
	}
}

signed main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	
	cin >> o >> T;
	if(o > 2 && o <= 4)
	while(T --)  sub2::solve();
	else
	while(T --)  bf::solve();

	return 0;
}
