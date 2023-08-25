#include <bits/stdc++.h>

namespace Main
{
	using namespace FastIO;
	typedef long long i64;

	constexpr int N = 1e5 + 5;
	constexpr int K = 10;
	int n, k;

	struct Node
	{
		int max[K], min[K], siz;

		bool operator<(const Node &rhs) const
		{
			for (int i = 1; i <= k; i++)
			{
				if (max[i] > rhs.min[i])
				{
					return 1;
				}
			}
			return 0;
		}
	} cur;

	std::set<Node> s;

	inline void merge(Node &u, Node v)
	{
		for (int i = 1; i <= k; i++)
		{
			u.max[i] = std::max(u.max[i], v.max[i]);
		}
		for (int i = 1; i <= k; i++)
		{
			u.min[i] = std::min(u.min[i], v.min[i]);
		}
		u.siz += v.siz;
	}

	inline void main()
	{
		cin >> n >> k;
		while (n--)
		{
			for (int i = 1; i <= k; i++)
			{
				cin >> cur.max[i];
				 cur.min[i] = cur.max[i];
			}
			cur.siz = 1;
			if (!s.empty())
			{
				auto it = s.upper_bound(cur);
				while (it != s.end() && *it < cur && cur < *it)
				{
					merge(cur, *it), s.erase(it);
					it = s.upper_bound(cur);
				}
			}
			s.insert(cur);
			cout << s.begin()->siz << " ";
		}
		pc('\n');
		return;
	}
}

signed main()
{
	freopen("s.in", "r", stdin);
	freopen("s.out", "w", stdout);
	Main::main();
	return 0;
}