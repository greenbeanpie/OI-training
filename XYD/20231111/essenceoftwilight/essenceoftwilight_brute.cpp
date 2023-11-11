#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
static const int N = 5e5 + 5;

struct Segtree
{

	struct node
	{
		int ls, rs, val, cl, cr;
	} tree[N << 5];

	int tot = 0;
	vector<int> root;

	void build_tree(int l, int r, int p)
	{
		tree[p].ls = tree[p].rs = tree[p].val = 0;
		tree[p].cl = l, tree[p].cr = r;
		if (l == r)
		{
			return;
		}
		int mid = (l + r) >> 1;
		// tree[tree[p].cl].cl = l;
		// tree[tree[p].cl].cr = mid;
		build_tree(l, mid, tree[p].ls = ++tot);
		tree[p].rs = ++tot;
		build_tree(mid + 1, r, tot);
		return;
	}
	void build_tree(int n)
	{
		tot = 0;
		root.clear();
		root.emplace_back(1);
		return build_tree(1, n, ++tot);
	}

	void add(int pos, int ori, int p)
	{
		tree[p] = tree[ori];
		++tree[p].val;
		if (tree[p].cl == tree[p].cr)
		{
			return;
		}
		int mid = (tree[p].cl + tree[p].cr) >> 1;
		if (mid >= pos)
		{
			add(pos, tree[ori].ls, tree[p].ls = ++tot);
		}
		else
		{
			add(pos, tree[ori].rs, tree[p].rs = ++tot);
		}
	}
	void add(int pos)
	{
		root.emplace_back(tot + 1);
		add(pos, *++root.rbegin(), ++tot);
		return;
	}
	int query(pair<int, int> range, int o, int p)
	{
		int l = range.first, r = range.second;
		if (l <= tree[p].cl && tree[p].cr <= r)
		{
			return tree[p].val - tree[o].val;
		}
		int mid = (tree[p].cl + tree[p].cr) >> 1, res = 0;
		if (l <= mid)
		{
			res += query(range, tree[o].ls, tree[p].ls);
		}
		if (r > mid)
		{
			res += query(range, tree[o].rs, tree[p].rs);
		}
		return res;
	}
	int query(int v1, int v2, int l, int r)
	{
		if (v1 > v2 || l > r)
		{
			return 0;
		}
		return query({l, r}, root[v1], root[v2]);
	}
} PStree;

int T, o, n;
int num[N];

signed main()
{
	int st = clock();
	freopen("essenceoftwilight.in", "r", stdin);
	freopen("essenceoftwilight.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> T >> o;
	int oriT = T;
	while (T--)
	{
		cin >> n;
		int w = 0;
		PStree.build_tree(n);
		for (int i = 1, temp; i <= n; i++)
		{
			cin >> num[i];
			PStree.add(num[i]);
		}

		for (int i = 1; i <= n; i++)
		{
			w += i - PStree.query(0, i, 1, num[i]);
		}
		int maxi = 1, maxj = 1, maxval = 0;
		for (int i = 1; i <= n; i++)
		{
			if (1.0 * (clock() - st) / CLOCKS_PER_SEC >= 4.8 * (oriT - T) / oriT)
			{
				break;
			}
			assert(4.8 * (oriT - T) / oriT <= 5 * CLOCKS_PER_SEC);
			for (int j = i + 1; j <= n; j++)
			{
				if (num[i] < num[j])
				{
					continue;
				}
				int res = PStree.query(i, j - 1, 1, num[i]) - PStree.query(i, j - 1, 1, num[j]);
				res *= 2;
				if (res > maxval)
				{
					maxval = res;
					maxi = i, maxj = j;
				}
			}
		}
		// cerr << "Swap pos is: " << maxi << ", " << maxj << endl;
		// cerr << "Swaped range is:" << endl;
		// for (int i = maxi; i <= maxj; i++)
		// {
		// 	cerr << num[i] << " ";
		// }
		// cerr << endl;
		// cerr << "Reduced value is: " << maxval + 1 << endl;
		// cerr << "Left value is: " << w - maxval - 1 << endl;
		cout << max(w - maxval - 1, 0ll) << endl;
	}
	return 0;
}
