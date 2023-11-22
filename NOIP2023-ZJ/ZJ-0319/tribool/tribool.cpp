#include <bits/stdc++.h>
#define FL(i, a, b) for(int i = (a); i <= (b); ++i)
#define FR(i, a, b) for(int i = (a); i >= (b); --i)
using namespace std;
constexpr int N = 1e5 + 10;
int n, m, T, F, U, a[N], b[N], w[N], in[N], vis[N];
queue<int> q; vector<int> id;
void Work(){
	FL(i, 1, n) ++in[abs(a[i])];
	FL(i, 1, n) if(!in[i]) q.emplace(i);
	while(!q.empty()){
		int u = q.front(); q.pop();
		b[u] = 1;
		--in[abs(a[u])];
		if(!in[abs(a[u])]) q.emplace(abs(a[u]));
	}
	FL(i, 1, n) if(!b[i] && !vis[i]){
		vector<int>().swap(id);
		for(int u = i; !vis[u]; vis[u] = 1, u = abs(a[u]))
			w[i] ^= (a[u] < 0), id.emplace_back(u);
		for(int x: id) w[x] = w[i];
	}
}
void Init(){
	memset(a, 0, sizeof(a));
	memset(w, 0, sizeof(w));
	memset(b, 0, sizeof(b));
	memset(in, 0, sizeof(in));
	memset(vis, 0, sizeof(vis));
}
void solve(){
	scanf("%d%d", &n, &m), Init();
	T = n + 1, F = n + 2, w[U = n + 3] = 1;
	vis[T] = vis[F] = vis[U] = vis[0] = 1;
	FL(i, 1, n) a[i] = i;
	while(m--){
		char v; int i, j;
		scanf(" %c", &v);
		switch(v){
			case 'T': scanf("%d", &i), a[i] = T; break;
			case 'F': scanf("%d", &i), a[i] = F; break;
			case 'U': scanf("%d", &i), a[i] = U; break;
			case '+': scanf("%d%d", &i, &j), a[i] = a[j]; break;
			case '-': scanf("%d%d", &i, &j), a[i] = -a[j]; break;
		}
	}
	Work();
	FL(i, 1, n) if(!vis[i]){
		int x = i; for(; !vis[x]; x = abs(a[x]));
		for(int u = i; !vis[u]; vis[u] = 1, u = abs(a[u]))
			w[u] = w[x];
	}
	int ans = 0;
	FL(i, 1, n) ans += w[i];
	printf("%d\n", ans);
}
int main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int C, T; scanf("%d%d", &C, &T);
	while(T--) solve();
	return 0;
}