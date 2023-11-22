#include<cstdio>
#include<vector>
using namespace std;
vector < int > v[100010];
vector < bool > vb[100010];
int val[100010], siz[100010];
bool vis[100010], col[100010];
void addedge(int u1, int u2, bool k)
{
	v[u1].push_back(u2), vb[u1].push_back(k);
	v[u2].push_back(u1), vb[u2].push_back(k);
}
bool dfs(int p)
{
	vis[p] = 1, siz[p] = 1;
	bool res = 1;
	for(int i = 0; i < (int)v[p].size(); i++)
	{
		if(vis[v[p][i]])
		{
			if((col[p] ^ vb[p][i]) != col[v[p][i]]) res = 0;
			continue;
		}
		col[v[p][i]] = col[p] ^ vb[p][i];
		res &= dfs(v[p][i]);
		siz[p] += siz[v[p][i]];
	}
	return res;
}
int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int c0, t, n, m, o1, o2, ans;
	char str[10];
	scanf("%d%d", &c0, &t);
	while(t--)
	{
		scanf("%d%d", &n, &m), ans = 0;
		for(int i = 1; i <= n + 3; i++)
			v[i].clear(), vb[i].clear(), val[i] = i, siz[i] = 0, vis[i] = col[i] = 0;
		for(int i = 1; i <= m; i++)
		{
			scanf("%s", str);
			if(str[0] == '+')
				scanf("%d%d", &o1, &o2), val[o1] = val[o2];
			else if(str[0] == '-')
				scanf("%d%d", &o1, &o2), val[o1] = -val[o2];
			else
			{
				scanf("%d", &o1);
				if(str[0] == 'T') val[o1] = n + 1;
				else if(str[0] == 'F') val[o1] = n + 2;
				else val[o1] = n + 3;
			}
		}
		val[n + 1] = -n - 2, val[n + 2] = -n - 1, val[n + 3] = -n - 3;
		for(int i = 1; i <= n + 3; i++)
			if(val[i] > 0) addedge(i, val[i], 0);
			else addedge(i, -val[i], 1);
		for(int i = 1; i <= n + 3; i++)
		{
			if(vis[i]) continue;
			if(!dfs(i)) ans += siz[i];
		}
		printf("%d\n", ans - 1);
	}
	return 0;
}