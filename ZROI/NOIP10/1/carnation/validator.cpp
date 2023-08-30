#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
vector<vector<int>> e(100000);
int ind[20010];
int outd[20010];
bool judge1() // 欧拉图判断
{
	for (int i = 0; i < n; i++)
	{
		if (ind[i] != outd[i])
			return 0;
	}
	return 1;
}
int vis[20010];
int fa[20010];
int mark[20010];
int flag = 0;
void set(int u, int vv)
{
	mark[u]++;
	while (u != vv)
	{
		u = fa[u];
		mark[u]++;
		if (mark[u] > 1 && u != vv)
		{
			flag = 1;
			return;
		}
		if (u == 0)
			break;
	}
	mark[vv]--;
}
void dfs(int u)
{
	if (flag)
		return;
	for (int j = 0; j < e[u].size(); j++)
	{
		int vv = e[u][j];
		if (!vis[vv])
		{
			fa[vv] = u;
			vis[vv] = 1;
			dfs(vv);
		}
		else
			set(u, vv);
	}
	return;
}
bool judge2() // 判定2
{
	vis[0] = 1;
	dfs(0);
	if (flag)
		return 0;
	for (int i = 0; i < n; i++)
	{
		if (mark[i] > 1)
			return 0;
	}
	return 1;
}
int main()
{
	freopen("carnation.in", "r", stdin);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
	{
		fa[i] = -1;
		mark[i] = vis[i] = ind[i] = outd[i] = 0;
		e[i].clear();
	}
	flag = 0;
	int ta, tb,temp;
	for (int i = 1;i<=m;i++){
		cin >> ta >> tb >> temp >> temp;
		e[ta].push_back(tb);
		outd[ta]++;
		ind[tb]++;
	}

	if (!judge1())
	{
		return 0;
	}
	else
	{

		if (!judge2())
			return 1;
		else
			return 0;
	}
	return 0;
}