#include <bits/stdc++.h> 
#define PII array <int, 2>
using namespace std;

const int N = 1e5 + 2;

int n;
int dep[N];
bool vis[N];
vector <int> g[N];

struct node{
	int idx, a, b;
}nd[N], tmp[N];

void cdq(int l, int r){
	if(l == r)  return ;
	int mid = l + r >> 1;
	cdq(l, mid);  cdq(mid + 1, r);
	int i = l, j = mid + 1, k = l;
	while(i <= mid && j <= r){
		if(nd[i].a < nd[j].a){
			if(nd[i].b < nd[j].b)  g[nd[i].idx].push_back(nd[j].idx);
			tmp[k ++] = nd[i ++];
		}else{
			tmp[k ++] = nd[j ++];
		}
	}
	while(i <= mid)  tmp[k ++] = nd[i ++];
	while(j <= r)  tmp[k ++] = nd[j ++];
	for(int i = l; i <= r; i ++)  nd[i] = tmp[i];
}

int dfs(int u){
	vis[u] = 1;
	if(!g[u].size())
		return (dep[u] = 1);
	for(int v : g[u]){
		if(!vis[v])  dfs(v);
		dep[u] = max(dep[u], dep[v] + 1);
	}
	return dep[u];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	freopen("factor.in", "r", stdin);
	freopen("factor.out", "w", stdout);

	cin >> n;
	for(int i = 1; i <= n; i ++)  nd[i].idx = i;
	for(int i = 1; i <= n; i ++)  cin >> nd[i].a;
	for(int i = 1; i <= n; i ++)  cin >> nd[i].b;
	if(n <= 1e3){
		dep[1] = 1;
		int ans = 1;
		for(int i = 2; i <= n; i ++){
			for(int j = 1; j < i; j ++){
				if(nd[j].a < nd[i].a && nd[j].b < nd[i].b){
					dep[i] = max(dep[i], dep[j] + 1);
				}
			}
			ans = max(ans, dep[i]);
		}
		cout << ans;
		return 0;
	}
	for(int i = 1; i <= n; i ++)  g[0].push_back(i);
	cdq(1, n);
	cout << dfs(0) - 1;
	
	return 0;
}
