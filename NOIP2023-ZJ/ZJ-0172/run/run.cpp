#include<bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
int test_id;
namespace Pai369
{
	const int M = 1e5 + 5;
	int n , m , k , d;
	struct Line{int x , y , v;}a[M];
	namespace BF
	{
		const int N = 1005;
		int f[N][N] , w[N][N];
		int Solve()
		{
			memset(w , 0 , sizeof w);
			for(int i = 1 ; i <= m ; i++)
			{
				auto [x , y , v] = a[i];
				for(int j = y ; j <= x ; j++)
					w[x][j] += v;
			}
			memset(f , 0xc0 , sizeof f);
			f[0][0] = 0;
			for(int i = 0 ; i < n ; i++)
			{
				for(int j = 0 ; j <= min(i , k) ; j++)
				{
					f[i + 1][0] = max(f[i + 1][0] , f[i][j]);
					if(j < k)f[i + 1][j + 1] = max(f[i + 1][j + 1] , f[i][j] + w[i + 1][j + 1] - d);
				}
			}
			cout << *max_element(f[n] , f[n] + k + 1) << "\n";
			return 0;
		}
	}
	namespace B
	{
		int Solve()
		{
			sort(a + 1 , a + m + 1 , [&](const Line &a , const Line &b){return a.x < b.x;});
			ll ans = 0;
			for(int i = 1 ; i <= m ; i++)
				if(a[i].y <= k)ans = max(ans , ans - a[i].y * d + a[i].v);
			cout << ans << "\n";
			return 0;
		}
	}
	int Solve()
	{
		// Init();
		cin >> n >> m >> k >> d;
		for(int i = 1 ; i <= m ; i++)cin >> a[i].x >> a[i].y >> a[i].v;
		if(n <= 1000)BF::Solve();
		else B::Solve();
		return 0;
	}
}
signed main()
{	
	freopen("run.in" , "r" , stdin);
	freopen("run.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	int T; cin >> test_id >> T;
	while(T--)Pai369::Solve();
	return 0;
}