#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "x"
#define const constexpr

const int N = 1e6 + 5;
int num[N];
int l1, l2, r1, r2;

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
	}
	int m;
	cin >> m;
	int idx = 0;
	for (int i = 1; i <= m; i++)
	{
		int sum = 0;
		cin >> l1 >> r1 >> l2 >> r2;
		// for (int size = l2; size <= r2; size++)
		// {
		// 	tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> Tree;
		// 	for(int i=1;i<=n;i++){
		// 		Tree.insert({num[i],++idx});
		// 		if(Tree.size()<size){
		// 			continue;
		// 		}
		// 		if(Tree.size()>size){
		// 			Tree.erase(Tree.lower_bound({num[i-size],-1}));
		// 		}
		// 		int res=Tree.find_by_order((size-1)/2)->first;
		// 		if(res>=l1&&res<=r1){
		// 			sum++;
		// 		}
		// 	}
		// }
		for(int j=1;j<=n;j++){
			if(num[j]>=l1&&num[j]<=r1){
				int leftspace=j*2,rightspace=(n-j)*2+1;
				sum+=max((int)min(min(leftspace,rightspace),r2)-l2+1,0ll);
			}
		}
		cout << sum << endl;
	}
	return 0;
}