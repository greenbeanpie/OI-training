#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P5064";
const int N = 1e5 + 1;
const int K = 31;

int n, m, k, block, a[N], b[N], cnt[N], h[N], t;
int fa[N], dep[N], num[N], ans[N];
unsigned short bot[N][K];
struct node{
	int op, x, y;
}nd[N];
struct edge{
	int v, nxt;
}e[N];

int find(int x){return (x == fa[x]) ? x : find(fa[x]);}

void dfs(int pos){
	int x = nd[pos].x, fx = 0,
	    y = nd[pos].y, fy = 0,
	    tmp = 0;
	if(nd[pos].op != 2)  fx = find(x), fy = find(y);
	if(nd[pos].op == 1 && fx != fy){
		if(dep[fy] > dep[fx])  swap(fx, fy);
		tmp = dep[fx], fa[fy] = fx, dep[fx] = max(dep[fx], dep[fy] + 1);
		for(int i = 1; i <= k; i ++)  bot[fx][i] += bot[fy][i];
	}
	else if(nd[pos].op == 3){
		for(int i = 1; i <= k; i ++){
			// cerr << fx << ' ' << i << ' ' << bot[fx][i] << '\n';
			if(bot[fx][i] >= y){
				for(int j = block * (i - 1) + 1; j <= block * i; j ++){
					if(find(num[j]) == fx){
						y --;
						if(!y){
							ans[pos] = b[j];
							break;
						}
					}
				}
				break;
			}
			y -= bot[fx][i];
		}
		if(y)  ans[pos] = -1;
	}
	for(int i = h[pos]; i; i = e[i].nxt)  dfs(e[i].v);
	if(nd[pos].op == 1 && fx != fy){
		fa[fy] = fy, dep[fx] = tmp;
		for(int i = 1; i <= k; i ++)  bot[fx][i] -= bot[fy][i];
	}
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	block = n / K + 1;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		b[i] = a[i], fa[i] = i, dep[i] = 1;
	}
	sort(b + 1, b + n + 1);
	for(int i = 1; i <= n; i ++){
		a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
		a[i] += cnt[a[i]] ++;
		num[a[i]] = i;
		bot[i][(a[i] - 1) / block + 1] = 1;
	}
	for(int i = 1; i <= m; i ++){
		cin >> nd[i].op >> nd[i].x;
		if(nd[i].op != 2)  t = i - 1, cin >> nd[i].y;
		else  t = nd[i].x;
		e[++ k] = {i, h[t]}, h[t] = k;
	}
	k = (n - 1) / block + 1;
	dfs(0);
	for(int i = 1; i <= m; i ++)  if(nd[i].op == 3)  cout << ans[i] << '\n';

	return 0;
}