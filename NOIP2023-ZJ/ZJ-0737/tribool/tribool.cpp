#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int c, t;
int n, m;

int size[N];
int x[N];
int fa[N];
bool vis[N];

int find(int x){
	if(fa[x] == x) return x;
	else return find(fa[x]);
}

int h[N], e[2 * N], ne[2 * N], w[2 * N], idx, val[N];
bool visit[N];
void add(int a, int b, int c){
	e[++ idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
	w[idx] = c;
}
bool t_check(int s){
	memset(visit, false, sizeof(visit));
	memset(val, 0, sizeof(val));
	queue<int> q;
	q.push(s);
	val[s] = 1;
	while(!q.empty()){
		int t = q.front();q.pop();
		if(visit[t]) continue;
		visit[t] = true;
		for(int i = h[t]; i != -1; i = ne[i]){
			int y = e[i];
			int v = w[i] * val[t];
			if(val[y] != 0 && val[y] != v) return false;
			else{
				val[y] = v;
				q.push(y);
			}
		}
	}
	return true;
}

int main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin >> c >> t;
	while(t --){
		cin >> n >> m;
		for(int i = 1; i <= n; i ++){
			h[i] = -1;
			x[i] = N + i;
			fa[i] = i;
			size[i] = 1;
			vis[i] = false;
		}
		while(m --){
			char op;
			int a, b;
			cin >> op;
			if(op == '-'){
				cin >> a >> b;
				x[a] = -x[b];
			}
			else if(op == '+'){
				cin >> a >> b;
				x[a] = x[b];
			}
			else{
				cin >> a;
				if(op == 'T') x[a] = 1;
				else if(op == 'F') x[a] = -1;
				else x[a] = 0;
			}
		}
		for(int i = 1; i <= n; i ++){
			if(x[i] <= -N || x[i] >= N){
				int y = i, z;
				if(x[i] <= -N) z = x[i] + N;
				else z = x[i] - N;
				if(y == -z) x[i] = 0;
				else if(y == z) continue; 
				else{
					int tt = 1;
					if(z <= 0){
						z = -z;
						tt = -1;
					}
					int fy = find(y), fz = find(z);
					add(y, z, tt);
					add(z, y, tt);
					if(fy == fz) continue;
					fa[fy] = fz;
					size[fz] += size[fy];
				}
			}
		}
		int ans = 0, now = n;
		for(int i = 1; i <= n; i ++){
			int fi = find(i);
			if(vis[fi]) continue;
			if(x[i] == 0){
				ans += size[fi];
				now -= size[fi];
				vis[fi] = 1;
			}
			else if(x[i] == 1 || x[i] == -1)
				vis[fi] = 1;
		}
		
		for(int i = 1; i <= n; i ++){
			int fi = find(i);
			if(vis[fi]) continue;
			if(!t_check(fi)){
				ans += size[fi];
				vis[fi] = 1;
			}
			else vis[fi] = 1;
		}
		cout << ans << endl;
	}
	return 0;
}
