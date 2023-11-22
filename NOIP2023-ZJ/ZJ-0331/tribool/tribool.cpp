#include<bits/stdc++.h>
#define ZJL using
#define AK namespace
#define IOI std
#define Name "tribool"
#define ll long long
const ll N = 1e5 + 50;
ZJL AK IOI;

int Y, _;

int c, t, n, m;

inline ll read(){
	ll x = 0, y = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') y = -y;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x * y;
}

namespace sol2{
	int a[N];
	inline void sol(){
		memset(a, 0, sizeof a);
		for(int i = 1;i <= m;i++){
			char c = getchar();
			while(c ^ 'T' && c ^ 'F' && c ^ 'U') c = getchar();
			int x = read(), w = c == 'T' ? 1 : (c == 'F' ? 0 : 2);
			a[x] = w;
		}
		int ans = 0;
		for(int i = 1;i <= n;i++){
			if(a[i] == 2) ans++;
		}
		printf("%d\n", ans);
	}
}

namespace sol3{
	int a[N], b[N], c[N];
	
	inline void change(int x, int y, int o){//x <-- y
		a[x] = a[y], b[x] = b[y] ^ o;
	}
	
	struct Node{
		int v, w;
		Node(int v = 0, int w = 0): v(v), w(w){}
	};
	
	vector<Node> G[N];
	
	int dis[N], bk[N], sz;
	inline bool bfs(int s){
		sz = 0;
		bool flag = true;
		queue<int> q;
		bk[s] = true, q.push(s);
		while(!q.empty()){
			int u = q.front();
			q.pop(), sz++;
			for(auto e : G[u]){
				int v = e.v, w = e.w;
				if(bk[v]){
					if(dis[v] != (dis[u] ^ w)) flag = false;
					continue;
				}
				dis[v] = dis[u] ^ w;
				q.push(v), bk[v] = true;
			}
		}
		return flag;
	}
	
	inline void sol(){
		memset(dis, 0, sizeof dis);
		memset(c, 0, sizeof c);
		memset(bk, 0, sizeof bk);
		c[n + 2] = 2;
		for(int i = 1;i <= n + 2;i++) a[i] = i, b[i] = 0, G[i].clear();
		for(int i = 1;i <= m;i++){
			char c = getchar();
			while(c ^ '+' && c ^ '-' && c ^ 'T' && c ^ 'U' && c ^ 'F') c = getchar();
			if(c == '+' || c == '-'){
				int x = read(), y = read();
				change(x, y, c == '-');
			}
			else{
				int x = read();
				if(c == 'T') change(x, n + 1, 1);
				if(c == 'F') change(x, n + 1, 1);
				if(c == 'U') change(x, n + 2, 0);
			}
		}
		
		int ans = 0;
		for(int i = 1;i <= n;i++){
			G[i].push_back(Node(a[i], b[i]));
			G[a[i]].push_back(Node(i, b[i]));
		}
		bfs(n + 2), ans += sz - 1;
		for(int i = 1;i <= n + 1;i++){
			if(bk[i]) continue;
			bool res = bfs(i);
			if(!res) ans += sz;
		}
		printf("%d\n", ans);
	}
}

int main(){
	freopen(Name ".in", "r", stdin);
	freopen(Name ".out", "w", stdout);
	c = read(), t = read();
	while(t--){
		n = read(), m = read();
		sol3::sol();
	}
	
	return ~~(Y^_^Y);
}