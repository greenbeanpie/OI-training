#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define int long long

const int N = 3e5 + 5;

cc_hash_table<string, bool> check;

struct Trie
{
	struct node
	{
		char c;
		int son[27] = {0};
		bool last = 0;
		node()
		{
			c = 0;
			last = 0;
		}
	} tree[N];
	int root = 0, tot = 0;
	Trie()
	{
		tree[0].c = -1;
		tot = 0;
	}
	void insert(string c, int now, int p)
	{
		tree[p].c = c[now];
		if (now == c.size() - 1)
		{
			tree[p].last = 1;
			return;
		}
		if (!tree[p].son[c[now + 1] - 'a' + 1])
		{
			tree[p].son[c[now + 1] - 'a' + 1] = ++tot;
		}
		return insert(c, now + 1, tree[p].son[c[now + 1] - 'a' + 1]);
	}
	void insert(char *c, int now, int p)
	{
		tree[p].c = c[now];
		if (!c[now])
		{
			tree[p].last = 1;
			return;
		}
		if (!tree[p].son[c[now + 1] - 'a' + 1])
		{
			tree[p].son[c[now + 1] - 'a' + 1] = ++tot;
		}
		return insert(c, now + 1, tree[p].son[c[now + 1] - 'a' + 1]);
	}
	void insert(string c)
	{
		if (!tree[root].son[c[0] - 'a' + 1])
		{
			tree[root].son[c[0] - 'a' + 1] = ++tot;
		}
		return insert(c, 0, tree[root].son[c[0] - 'a' + 1]);
	}
	void insert(char *c)
	{
		if (!tree[root].son[c[0] - 'a' + 1])
		{
			tree[root].son[c[0] - 'a' + 1] = ++tot;
		}
		return insert(c, 0, tree[root].son[c[0] - 'a' + 1]);
	}
	vector<char> search;
	string str;
	void dfs(int p)
	{
		if (tree[p].last)
		{
			check[str] = 1;
			return;
		}
		if (p == 0)
		{
			for (int i = 1; i <= 26; i++)
			{
				if (tree[p].son[i])
				{
					search.push_back(tree[tree[p].son[i]].c);
					str.push_back(i + 'a' - 1);
					dfs(tree[p].son[i]);
					str.pop_back();
					search.pop_back();
				}
			}
			return;
		}
		for (auto i : search)
		{
			if (tree[p].son[i - 'a' + 1])
			{
				str.push_back(i);
				dfs(tree[p].son[i - 'a' + 1]);
				str.pop_back();
				return;
			}
		}
		for (int i = 1; i <= 26; i++)
		{
			if (tree[p].son[i])
			{
				search.push_back('a' + i - 1);
				str.push_back('a' + i - 1);
				dfs(tree[p].son[i]);
				search.pop_back();
				str.pop_back();
			}
		}
	}
} Tree;

string c[N];

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		Tree.insert(c[i]);
	}
	Tree.dfs(0);
	cout << check.size() << endl;
	for (int i = 1; i <= n;i++){
		if(check.find(c[i])!=check.end()){
			cout << c[i] << endl;
		}
	}
		return 0;
}
