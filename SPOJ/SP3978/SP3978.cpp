#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5, M = 21;

int maxinum[N][M], mininum[N][M];
int val[N], fa[N][M], dep[N];

vector<int> e[N];

void dfs(int u, int father = 0)
{
	fa[u][0] = father;
	dep[u] = dep[father] + 1;
	for (int i = 1; i <= M; i++)
	{
	}
	for (int i : e[u])
	{
		dfs(i, u);
	}
}

signed main()
{
	return 0;
}
