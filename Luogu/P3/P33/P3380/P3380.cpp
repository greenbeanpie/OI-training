#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define endl "\n"

int n, m, mod = 571313;
vector<int> num;
template <typename T>
struct SegTree
{
	int tot=0;
	tree<pair<int,int>,less<pair<int,int> >,
};
inline int range_sum(SegTree<int> *st, int l, int r)
{
	return st->range_sum(l, r, 1, n, (*st).root);
}
inline void range_add(SegTree<int> *st, int l, int r, int val)
{
	st->range_add(l, r, val, 1, n, (*st).root);
}
inline void range_mul(SegTree<int> *st, int l, int r, int val)
{
	st->range_mul(l, r, val, 1, n, (*st).root);
}
/*public:
		T range_sum(int l, int r)
		{
			return range_sum(l, r, 0, end, root);
		}
		void range_add(int l, int r, int val)
		{
			range_add(l, r, val, 0, end, root);
		}
};*/


signed main(){
#ifndef ONLINE_JUDGE
	freopen("P3380.in","r",stdin);
	freopen("P3380.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	return 0;
}