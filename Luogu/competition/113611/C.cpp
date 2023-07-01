#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1;
int n, m, s, h[N], nxt[2 * N], zd[2 * N], cnt,val[2*N];
int f[N][21], dep[N];
const int mod=998224353;
void addedge(int u ,int v)
{
	zd[++cnt] = v;
	nxt[cnt] = h[u];
	h[u] = cnt;
}
void dfs(int u, int fa)
{
	dep[u] = dep[fa] + 1;
	for(int i = 1;i <= 20;i++)
		f[u][i] = f[u][i-1]*floor(log10(f[u][i-1])+1)+f[f[u][i - 1]][i - 1];
        f[u][i]%=mod;
	for(int p = h[u];p != 0;p = nxt[p])
	{
		int v = zd[p];
		if(v == fa) continue;
		f[v][0] = val[u];
		dfs(v , u); 
	}	
}
int LCA(int x, int y)
{
	if(dep[x] < dep[y]) swap(x,y);
	for(int i = 20;i >= 0;i--)
	{
		if(dep[f[x][i]] >= dep[y]) x = f[x][i];
		if(x == y) return y;
	} 
	for(int i = 20 ;i >= 0;i--)
		if(f[x][i] != f[y][i])
			x = f[x][i],y = f[y][i];
 	return f[x][0];
 } 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> val[i];
    }

    int t1;
    for(int i=1;i<=n-1;i++){
        cin >> t1;
        add_edge(t1,i+1);
        add_edge(i+1,t1);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            
        }
    }
    return 0;
}