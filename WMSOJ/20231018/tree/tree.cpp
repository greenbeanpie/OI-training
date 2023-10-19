#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define int long long

namespace Subtask1
{
	const int N = 1e6 + 5;
	vector<int> temp[1005], e[N];

	int fa[1005];
	tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> sorted[1005];
	void dfs(int u, int father)
	{
		fa[u] = father;
		sorted[u].insert(u);
		for (int i : temp[u])
		{
			if (u != father)
			{
				dfs(i, u);
				for (auto j : sorted[i])
				{
					sorted[u].insert(j);
				}
			}
		}
	}
	void dfs2(int u, int ori, int id, int L)
	{
		for (auto i : e[ori])
		{
			if (i != fa[ori])
			{
				e[u].push_back(L + sorted->order_of_key(ori) + 1);
				dfs2(L + sorted->order_of_key(ori) + 1, i, id, L);
			}
		}
	}
	void solve(int n, int m)
	{
		int q;
		cin >> q;
		for (int i = 1, u, v; i <= n; i++)
		{
			cin >> u >> v;
			temp[u].push_back(v);
			temp[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)
		{
			e[i] = temp[i];
		}
		for (int i = 1, a, b; i <= m; i++)
		{
			cin >> a >> b;
			int L = n;
		}
	}
}

namespace Subtask2
{

	const int N = 1e5 + 5;
	vector<int> e[N];
	tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> sorted[N];
	int fa[N][20],dep[N];
	void dfs(int u, int father)
	{
		dep[u]=dep[father]+1;
		fa[u][0] = father;
		for (int i = 1; i <= 20; i++)
		{
			fa[u][i] = fa[fa[u][i - 1]][i - 1];
			if (!fa[u][i])
			{
				break;
			}
		}
		// fa[u] = father;
		sorted[u].insert(u);
		for (int i : e[u])
		{
			if (u != father)
			{
				dfs(i, u);
				for (auto j : sorted[i])
				{
					sorted[u].insert(j);
				}
			}
		}
	}
	int LCA(int u,int v){
		int sum = 0;
		if(dep[u]<dep[v]){
			swap(u, v);
		}
		if (dep[u] != dep[v])
		{
			for (int i = 20; i >= 0;i--){
				if(dep[u]-dep[v]>(1<<i)){
					u = fa[u][i];
					sum += (1 << i);
				}
			}
		}
		while(fa[u][0]!=fa[v][0]){
			for (int i = 20; i >= 1;i--){
				if(fa[u][i]!=fa[v][i]){
					u = fa[u][i], v = fa[v][i];
					sum += (1 << (i + 1));
					break;
				}
			}
		}
		if(fa[u][0]==fa[v][0]&&u!=v){
			u = v = fa[u][0];
			sum += 2;
		}
		return sum;
	}
	struct node
	{
		int root, id, last;
		node(int a)
		{
			last = a;
		}
		node(int a, int b, int c)
		{
			root = a, id = b, last = c;
		}
	} subtree[N];
	bool cmp(node a, node b)
	{
		return a.last < b.last;
	}
	void solve(int n, int m)
	{
		int q;
		cin >> q;
		for (int i = 1, u, v; i <= n; i++)
		{
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1, 0);
		int tot = n;
		for (int i = 1, a, b; i <= m; i++)
		{
			cin >> a >> b;
			subtree[i] = {b, a, tot + (int)sorted[a].size()};
			tot += sorted[a].size();
		}
		for (int i = 1, x, y; i <= q; i++)
		{
			cin >> x >> y;
			int xpos = lower_bound(subtree + 1, subtree + 1 + m, node(x), cmp) - subtree, ypos = lower_bound(subtree + 1, subtree + 1 + m, node(y), cmp) - subtree;
			if (xpos == ypos&&xpos!=1)
			{
				int x1 = *sorted[subtree[xpos].id].find_by_order(x - subtree[xpos - 1].last - 1);
				int y1 = *sorted[subtree[ypos].id].find_by_order(y - subtree[ypos - 1].last - 1);
				cout << LCA(x1, y1) << endl;
			}
			else if(xpos==ypos&&xpos==1){
				cout << LCA(x, y) << endl;
			}
			else{
				int sum = 0;
				int x1 = x, y1 = y;
				if (xpos != 1)
				{
					x1 = *sorted[subtree[xpos].id].find_by_order(x - subtree[xpos - 1].last - 1);
					sum += LCA(x1, 1);
					x = subtree[xpos].id;
				}
				if(ypos!=1){
					y1 = *sorted[subtree[ypos].id].find_by_order(y - subtree[ypos - 1].last - 1);
					sum += LCA(x1, 1);
					y=subtree[ypos].id;
				}
				sum += LCA(x, y);
				cout << sum << endl;
			}
		}
	}
}

signed main()
{
	int n, m;
	cin >> n >> m;
	if (n <= 1e3 && m <= 1e3)
	{
		Subtask1::solve(n, m);
	}
	else
	{
		Subtask2::solve(n, m);
	}
	return 0;
}
