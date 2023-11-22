#include <bits/stdc++.h>

#define i64 long long
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)

using namespace std;

const int N = 1e5 + 5;

int n, m, ans, sz;
bool flag;
int type[N], val[N], sgn[N], siz[N], col[N];
bool vis[N], vis2[N];
vector<int> G1[N];
vector<pair<int, int> > G2[N];

void dfs1(int u) {
	siz[u] = 1;
	vis[u] = true;
	vis2[u] = true;
	for(auto v : G1[u]) {
		dfs1(v);
		siz[u] += siz[v];
	}
}

void dfs2(int u, int c) {
	if(!flag) return;
	if(col[u] != -1) {
		if(col[u] != c) flag = false;
		return;
	}
	col[u] = c;
	vis[u] = true;
	for(auto e : G2[u]) {
		int v = e.first, w = e.second;
		if(w == 0) dfs2(v, 1 - c);
		else dfs2(v, c);
	}
}

void dfs3(int u) {
	if(vis2[u]) return;
	vis2[u] = true; sz++;
	for(auto e : G2[u]) {
		int v = e.first;
		if(!vis2[v]) dfs3(v);
	}
}

int main() {
	
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); 
	
	int o, T;
	cin >> o >> T;
	while(T--) {
		cin >> n >> m;
		rep(i, 1, n) {
			type[i] = 1, val[i] = i, sgn[i] = 1, vis[i] = false, vis2[i] = false, col[i] = -1;
			G1[i].clear(); G2[i].clear();
		}
		rep(i, 1, m) {
			char op; int x, y;
			cin >> op >> x;
			
			if(op == '+') {
				cin >> y;
				type[x] = type[y];
				val[x] = val[y];
				sgn[x] = sgn[y];
			}
			
			if(op == '-') {
				cin >> y;
				type[x] = type[y];
				if(type[y] == 0) {
					val[x] = (val[y] == 2 ? 2 : 1 - val[y]);
					sgn[x] = 1;
				}
				else {
					val[x] = val[y];
					sgn[x] = 1 - sgn[y];
				}
			}
			
			if(op == 'F') {
				type[x] = 0;
				val[x] = 0;
				sgn[x] = 1;
			}
			
			if(op == 'T') {
				type[x] = 0;
				val[x] = 1;
				sgn[x] = 1;
			}
		
			if(op == 'U') {
				type[x] = 0;
				val[x] = 2;
				sgn[x] = 1;
			}
		}
		
		ans = 0;
		rep(i, 1, n) {
			if(type[i] == 1 && val[i] != i) {
				G1[val[i]].push_back(i);
			}
		}
		
		rep(i, 1, n) {
			if(type[i] == 0 || val[i] == i) dfs1(i);
			if(type[i] == 0 && val[i] == 2) ans += siz[i];
			else if(type[i] == 1 && val[i] == i && sgn[i] == 0) ans += siz[i];
		}		
		
		rep(i, 1, n) if(!vis[i]) {
			G2[i].push_back(make_pair(val[i], sgn[i]));
			G2[val[i]].push_back(make_pair(i, sgn[i]));
		}
		
		rep(i, 1, n) if(!vis[i]) {
			flag = true;
			dfs2(i, 0);
			sz = 0;
			dfs3(i);
			
			if(!flag) ans += sz;
		}
		
		cout << ans << "\n";
	}
	              
	return 0;
}
