#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
#define int long long

vector<int> v;

const int mod=998244353;

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("over.in", "r", stdin);
	freopen("over.out", "w", stdout);
#endif
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	string s;
	int n,m;
	cin >> n >> m;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int temp = 0;
		cin >> s;
		for(auto i:s){
			temp <<= 1;
			if(i=='1'){
				temp |= 1;
			}
		}
		for(int j:v){
			ans += (j ^ temp) * (j ^ temp);
			ans %= mod;
		}
		v.emplace_back(temp);
	}
	cout << ans << endl;
	return 0;
}
