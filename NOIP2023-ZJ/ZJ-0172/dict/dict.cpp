#include<bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
namespace Pai369
{
	const int N = 3005;
	int n , m , p[N]; string s[N] , r[N];
	int Solve()
	{
		freopen("dict.in" , "r" , stdin);
		freopen("dict.out" , "w" , stdout);
		ios::sync_with_stdio(0);
		cin.tie(0) , cout.tie(0);
		cin >> n >> m;
		for(int i = 1 ; i <= n ; i++)
		{
			cin >> s[i];
			sort(s[i].begin() , s[i].end());
			r[i] = s[i];
			reverse(r[i].begin() , r[i].end());
		}
		sort(r + 1 , r + n + 1);
		for(int i = 1 ; i <= n ; i++)
		{
			int t = lower_bound(r + 1 , r + n + 1 , s[i]) - r;
			if(t > 1)cout << "0";
			else
			{
				if(s[i] < r[t])cout << "1";
				else if(s[i] == r[t])
				{
					if(t < n && r[t] == r[t + 1])cout << "0";
					else cout << "1";
				}
			}
		}
		return 0;
	}
}
signed main()
{
	Pai369::Solve();
	return 0;
}