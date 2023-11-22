#include <bits/stdc++.h>
#define file(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout); 
using namespace std;
const int N = 100000 + 5;
int a[N];
int n, m;
bool vis[N];
int ans, val[N], t[N];
void dfs(int u, int lst, int l){
	vis[u] = 1;
	val[u] = val[lst] ^ l;
	int tmp = (a[u] < 0);
	int v = abs(a[u]);
	if(u == v) {
		t[u] = 1;
		return;
	}
	if(v == 0) {
		t[u] = 2;
		return;
	}
	if(vis[v] && !t[v]) {
		if(val[v] == val[u] ^ tmp) t[u] = 1;
		else t[u] = 2;
		return;
	} 
	if(!vis[v]) dfs(v, u, tmp);
	t[u] = t[v];
}
int main(){
	file("tribool");
	int id, T;
	scanf("%d%d", &id, &T);
	while(T--){
		scanf("%d%d", &n, &m);
		ans = 0;
		for (int i = 1; i <= n; i++) {
			a[i] = i;
			vis[i] = 0;
			val[i] = 0;
			t[i] = 0;
		}
		val[0] = 0;
		for (int i = 1; i <= m; i++){
			char opt;
			cin >> opt;
			if(opt == '-') {
				int x, y;
				scanf("%d%d", &x, &y);
				a[x] = -a[y];
			}
			else if(opt == '+') {
				int x, y;
				scanf("%d%d", &x, &y);
				a[x] = a[y];
			}
			else {
				int x;
				scanf("%d", &x);
				if(opt == 'U') a[x] = 0;
				else a[x] = x;
			}
		}
		for (int i = 1; i <= n; i++) {
			if(!vis[i]) dfs(i, 0, 0);
			ans += t[i] - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*
1 1
10 10
- 9 8
- 8 6
- 6 5
- 5 4
- 4 3
+ 3 9
- 1 2
+ 2 7
+ 7 10
- 10 1

*/