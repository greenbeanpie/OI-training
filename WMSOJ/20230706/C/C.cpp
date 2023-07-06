#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define y1 y114514
#define endl '\n'

using namespace std;

const int N = 1e4 + 10;

int n, m, cnt;
bool a1[N][N];
int vis[N];
int ans[10 * N];

void dfs(int x)
{
	for(int i = 1;i <= n;i++)
		if(!vis[i] && !a1[x][i])
		{
			a1[x][i] = 1;
			a1[i][x] = 1;
			ans[cnt]++;
			vis[i] = 1;
			dfs(i);
		}
}

signed main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= m;i++)
    {
    	int c, b;
    	cin >> c >> b;
    	a1[c][b] = 1;
    	a1[b][c] = 1;
    }
    
    for(int i = 1;i <= n;i++) 	
    		if(!vis[i])
    		{
    			cnt++;
    			vis[i] = 1;
    			ans[cnt]++;
    			dfs(i);
    		}
    cout << cnt << endl;
    sort(ans + 1, ans + cnt + 1);
    for(int i = 1;i <= cnt;i++)
    	cout << ans[i] << " ";
    
	return 0;
}