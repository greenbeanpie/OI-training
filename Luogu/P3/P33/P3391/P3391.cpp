#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "P3391"
#define const constexpr

namespace Main
{
	const int N = 1e6 + 5;
	struct Balancing_Tree
	{
		struct node
		{
			int size, cnt, val, tag;
			node *lson, *rson, *fa;
		} tree[N];
		bool checkls(int x)
		{
			return tree + x == tree[x].fa->lson;
		}
		void update(int x)
		{
			tree[x].size = tree[x].cnt;
			if (tree[x].lson)
			{
				tree[x].size += tree[x].lson->size;
			}
			if (tree[x].rson)
			{
				tree[x].size += tree[x].rson->size;
			}
		}
		void maintain(int x)
		{
			if (tree[x].tag)
			{
				tree[x].tag=0;
				swap(tree[x].lson, tree[x].rson);
				tree[x].lson->tag^=1;
				tree[x].rson->tag^=1;
			}
		}
		void maintain(node *x){
			if(x->tag){
				x->tag=0;
				swap(x->lson, x->rson);
				x->lson->tag^=1;
				x->rson->tag^=1;
			}
		}
		void rotate(int x)
		{
			auto father1 = tree[x].fa, father2 = father1->fa;
			maintain(father2),maintain(father1);
			
		}
	} BT;
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