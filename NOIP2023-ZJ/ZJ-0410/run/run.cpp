#include <iostream>
#include <algorithm>
using namespace std;

long long c,t;
long long n,m,k,d;
long long x,y,v;
long long dp[10010][10010];

int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> m >> k >> d;
		for(long long i = 0;i <= n;i++) for(long long j = 0;j <= k;j++) dp[i][j] = 0;
		for(long long i = 1;i <= m;i++)
		{
			cin >> x >> y >> v;
			for(long long j = y;j <= k;j++) dp[x][j] += v;
		}
		dp[1][0] = 0;
		dp[1][1] = -d;
		for(long long i = 1;i < n;i++)
		{
			for(long long j = 0;j <= k && j <= i;j++)
			{
				dp[i + 1][0] = max(dp[i + 1][0],dp[i][j]);
				dp[i + 1][j + 1] += dp[i][j] - d;
			}
		}
//		for(int i = 1;i <= n;i++)
//		{
//			for(int j = 0;j <= k;j++) cout << dp[i][j] << '\t';
//			cout << endl;
//		}
		long long ans = -1e17;
		for(long long i = 0;i <= k;i++) ans = max(ans,dp[n][i]);
		cout << ans << endl;
	}
	return 0;
}