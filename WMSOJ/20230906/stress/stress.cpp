#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#pragma GCC optimize("Ofast")
#define int __int128
#define double long double
#define endl "\n"
#define problemname "stress"
#define const constexpr
const int mod = 1e9 + 7;

int now = 0;

namespace SegTree
{
	template <typename T>
	struct SegTree
	{
	protected:
		struct node
		{
			int sum, add, mul, l, r, last, first;
			node()
			{
				sum = add = l = r = last = first = 0;
				mul = 1;
			}
		};
		vector<node> tree;
		vector<T> *arr;
		int size = 0, tot = 0;
		void build(int cl, int cr, int u)
		{
			tree[u].l = cl, tree[u].r = cr;
			if (cl == cr)
			{
				tree[u].sum = arr->at(++tot);
				return;
			}
			int mid = (cl + cr) >> 1;
			build(cl, mid, u << 1);
			build(mid + 1, cr, (u << 1) | 1);
			tree[u].sum = tree[u << 1].sum + tree[(u << 1) | 1].sum;
			tree[u].sum%=mod;
		}
		void maintain(int u)
		{
			int cl =u<<1, cr = cl|1;
			if (tree[u].mul != 1)
			{
				tree[cl].mul *= tree[u].mul;
				tree[cl].mul %= mod;
				tree[cl].add *= tree[u].mul;
				tree[cl].add%=mod;
				tree[cl].sum *= tree[u].mul;
				tree[cl].sum %= mod;
				tree[cr].mul *= tree[u].mul;
				tree[cr].mul %= mod;
				tree[cr].add *= tree[u].mul;
				tree[cr].add %= mod;
				tree[cr].sum *= tree[u].mul;
				tree[cr].sum %= mod;
				// tree[u].add *= tree[u].mul;
				tree[u].mul = 1;
			}
			if (tree[u].add)
			{
				tree[cl].add += tree[u].add;
				tree[cl].add%=mod;
				tree[cr].add += tree[u].add;
				tree[cr].add %= mod;
				tree[cl].sum += (tree[cl].r - tree[cl].l + 1) * tree[u].add;
				tree[cr].sum%=mod;
				tree[cr].sum += (tree[cr].r - tree[cr].l + 1) * tree[u].add;
				tree[cr].sum %= mod;
				tree[u].add = 0;
			}
		}
		void range_add(int l, int r, int u, int val)
		{
			int cl = tree[u].l, cr = tree[u].r;
			if (l <= cl && cr <= r && tree[u].last < now)
			{
				tree[u].sum += (cr - cl + 1) * val;
				tree[u].sum %= mod;
				tree[u].add += val;
				tree[u].add %= mod;
				return;
			}
			maintain(u);
			int mid = (cl + cr) >> 1;
			if (l <= mid && tree[u << 1].first < now)
			{
				range_add(l, r, u << 1, val);
			}
			if (r > mid && tree[(u << 1) | 1].first < now)
			{
				range_add(l, r, (u << 1) | 1, val);
			}
			tree[u].sum = tree[u << 1].sum + tree[(u << 1) | 1].sum;
			tree[u].sum %= mod;
		}
		void range_mul(int l, int r, int u, int val)
		{
			int cl = tree[u].l, cr = tree[u].r;
			if (l <= cl && cr <= r && tree[u].last < now)
			{
				tree[u].mul *= val;
				tree[u].mul %= mod;
				tree[u].add *= val;
				tree[u].add %= mod;
				tree[u].sum *= val;
				tree[u].sum %= mod;
				return;
			}
			maintain(u);
			int mid = (cl + cr) >> 1;
			if (l <= mid && tree[u << 1].first < now)
			{
				range_mul(l, r, u << 1, val);
			}
			if (r > mid && tree[(u << 1) | 1].first < now)
			{
				range_mul(l, r, (u << 1) | 1, val);
			}
			tree[u].sum = tree[u << 1].sum + tree[(u << 1) | 1].sum;
			tree[u].sum %= mod;
		}
		void range_block(int l, int r, int u, int val)
		{
			int cl = tree[u].l, cr = tree[u].r;
			if (l <= cl && cr <= r)
			{
				tree[u].last = max(tree[u].last, now + val);
				tree[u].first = max(tree[u].first, now + val);
				return;
			}
			int mid = (cl + cr) >> 1;
			if (l <= mid)
			{
				range_block(l, r, u << 1, val);
			}
			if (r > mid)
			{
				range_block(l, r, (u << 1) | 1, val);
			}
			tree[u].last = max(tree[u << 1].last, tree[(u << 1) | 1].last);
			tree[u].first = min(tree[u << 1].first, tree[(u << 1) | 1].first);
		}
		int range_sum(int l, int r, int u)
		{
			int cl = tree[u].l, cr = tree[u].r, res = 0;
			if (l <= cl && cr <= r)
			{
				return tree[u].sum;
			}
			int mid = (cl + cr) >> 1;
			maintain(u);
			if (l <= mid)
			{
				res += range_sum(l, r, u << 1);
			}
			if (r > mid)
			{
				res += range_sum(l, r, (u << 1) | 1);
			}
			return res % mod;
		}

	public:
		SegTree(vector<T> *arr)
		{
			this->arr = arr;
			tree = vector<node>(arr->size() * 4);
			size = arr->size() - 1;
			build();
		}
		void build()
		{
			build(1, size, 1);
		}
		void range_add(int l, int r, int val)
		{
			if(tree[1].first>now){
				return;
			}
			return range_add(l, r, 1, val%mod);
		}
		void range_mul(int l, int r, int val)
		{
			if (tree[1].first > now)
			{
				return;
			}
			return range_mul(l, r, 1, val%mod);
		}
		void range_block(int l, int r, int val)
		{
			return range_block(l, r, 1, val);
		}
		int range_sum(int l, int r)
		{
			return range_sum(l, r, 1);
		}
	};
}

namespace Main
{
	vector<int> num = vector<int>(1);
	int main()
	{
		long long n, m;
		cin >> n >> m;
		long long temp;
		for (int i = 1; i <= n; i++)
		{
			cin >> temp;
			num.push_back(temp);
		}
		SegTree::SegTree<int> Tree(&num);
		long long op, l, r, x;
		for (int i = 1; i <= m; i++)
		{
			++now;
			cin >> op >> l >> r;
			if (op == 1)
			{
				cin >> x;
				Tree.range_add(l, r, x);
			}
			else if (op == 2)
			{
				cin >> x;
				Tree.range_mul(l, r, x);
			}
			else if (op == 3)
			{
				cin >> x;
				Tree.range_block(l, r, x);
			}
			else
			{
				cout << (long long)(Tree.range_sum(l, r)%mod) << endl;
			}

		}
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname "3.in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main::main();
	return 0;
}