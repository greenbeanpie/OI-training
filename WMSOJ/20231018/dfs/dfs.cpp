#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define int long long

const int N = 1e5 + 5;
vector<int> e[N];

int n;
int siz[N],dep[N];

void dfs(int u,int fa=-1,int depth=1){
	siz[u] = 1;
	dep[u] = depth;
	for (int i : e[u])
	{
		if(i!=fa){
			dfs(i, u, depth + 1);
			siz[u] += siz[i];
		}
	}
}

signed main(){
	freopen("dfs.in","r",stdin);
	freopen("dfs.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1,u,v; i < n;i++){
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1);
	for (int i = 1; i <= n;i++){
		cout << dep[i] << " " << n - siz[i] + 1 << endl;
	}
	return 0;
}