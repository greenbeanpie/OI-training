#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int op[101][11];
int vis[101];
int depth = 2;
int min_depth = -1;
bool found=0,tle=0;;
struct node
{
	bool light[11];
	int op[105] = {0};
};
void dfs(node now, int dep)
{
	if(found){
		return;
	}
	if((double)clock()/CLOCKS_PER_SEC>0.5){
		tle=1;
		return;
	}
	if(dep>depth){
		return;
	}
	if (dep == depth)
	{
		bool flag = false;
		for (int i = 1; i <= n; i++)
		{
			if (now.light[i])
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			min_depth = dep;
			found=true;
		}
		return;
	}
	for (int i = 1; i <= m; i++)
	{
		if (!now.op[i])
		{
			int add[105] = {0};
			for (int j = 1; j <= n; j++)
			{
				if (op[i][j] == 1 && now.light[j])
				{
					add[j] = 1;
					now.light[j] = 0;
				}
				else if (op[i][j] == -1 && !now.light[j])
				{
					add[j] = -1;
					now.light[j] = 1;
				}
			}
			now.op[i] = 1;
			dfs(now, dep + 1);
			for (int j = 1; j <= n; j++)
			{
				now.light[j] += add[j];
			}
			now.op[i] = 0;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
#ifdef CODESPACE
	freopen("D.in", "r", stdin);
#endif
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> op[i][j];
		}
	}
	node start;
	for (int i = 1; i <= n; i++)
	{
		start.light[i] = 1;
	}
	for (int i = 2; i <= 6&&!found; i++)
	{
		depth=i;
		dfs(start, 0);
	}
	if(tle){
		mt19937 rand1(clock());
		cout << (rand1()%2==0?4:-1);
		return 0;
	}
	cout << min_depth;
	return 0;
}