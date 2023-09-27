#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "P3369"
// #define const constexpr

const int N = 1e5 + 5;

namespace Main
{
	struct FHQ
	{
		int tot = 0;

		struct node
		{
			int val = 0, cnt = 0, size = 1;
			node *son[2] = {nullptr, nullptr}, *father = nullptr;
			node()
			{
				return;
			}
			node(int a, int b, int c)
			{
				val = a, cnt = b, size = c;
			}
			node(int a, int b, int c, node &d, node &e)
			{
				val = a, cnt = b, size = c;
				son[0] = &d, son[1] = &e;
			}
		};

		node _T[N];
		node *root;

		void maintain(node *u)
		{
			u->size = (u->son[0] ? u->son[0]->size : 0) + (u->son[1] ? u->son[1]->size : 0) + 1;
		}
		bool check(node *u)
		{
			return u->father && (u == (u->father->son[1]));
		}

		void not_rotate(node *x)
		{ // Of course FHQ doesn't need rotate(
			if (root == x)
			{
				return;
			}
			auto f1 = x->father, f2 = f1->father;
			auto r1 = check(x), r2 = check(f1);
			if (x->son[r1 != r2])
			{
				x->son[r1 != r2]->father = f1;
			}
			// f1->son[r1] = x->son[r1 ^ 1];
			x->son[r1 ^ 1] = f1;
			x->father = f2;
			f1->father = x;
			if (f2)
			{
				f2->son[r2] = x;
			}
			maintain(x), maintain(f1);
		}
		void fhq(node *x)
		{ // emmm,function fhq.
			while (x->father)
			{
				not_rotate(check(x) == check(x->father) ? x->father : x);
				not_rotate(x);
			}
		}
		void insert(int val)
		{
			if (root)
			{
				auto cur = root;
				while (1)
				{
					if (cur->val == val)
					{
						++cur->cnt;
						fhq(cur);
						break;
					}
					// auto father = cur->father;
					if (cur->son[cur->val < val])
					{
						cur = cur->son[cur->val < val];
					}
					else
					{
						node temp;
						temp.val = val;
						temp.father = cur;
						temp.cnt = 1;
						temp.father = cur;
						_T[++tot] = temp;
						cur->son[cur->val < val] = _T + tot;
						maintain(cur);
						maintain(cur->son[cur->val < val]);
						fhq(cur->son[cur->val < val]);
						break;
					}
				}
			}
			else
			{
				tot = 0;
				_T[++tot] = {val, 1, 1};
				root = _T + 1;
			}
		}
		int rk(int k)
		{
			auto cur = root;
			int now = 0;
			while (1)
			{
				if (k <= cur->val)
				{
					cur = cur->son[0];
				}
				else
				{
					now += cur->son[0]->size;
					if (k <= 0)
					{
						fhq(cur);
						return now + 1;
					}
					now += cur->cnt;
					cur = cur->son[1];
				}
			}
		}
		int kth(int k)
		{
			auto cur = root;
			while (1)
			{
				if (cur->son[0] && k <= cur->son[0]->size)
				{
					cur = cur->son[0];
				}
				else
				{
					k -= cur->cnt + cur->son[0]->size;
					if (k <= 0)
					{
						fhq(cur);
						return cur->val;
					}
					cur = cur->son[1];
				}
			}
		}
		node *pre(node *x)
		{
			auto cur = x->son[0];
			if (!cur)
			{
				return x;
			}
			while (cur->son[1])
			{
				cur = cur->son[1];
			}
			fhq(cur);
			return cur;
		}
		node *nxt(node *x)
		{
			auto cur = x->son[1];
			if (!cur)
			{
				return x;
			}
			while (cur->son[0])
			{
				cur = cur->son[0];
			}
			fhq(cur);
			return cur;
		}
		void del(int x){
			rk(x);
			auto cur=root;
			if(cur->cnt>1){
				--cur->cnt;
				maintain(cur);
				return;
			}
			if(!cur->)
		}
	};

	int main()
	{

		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main::main();
	return 0;
}