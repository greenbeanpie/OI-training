#include <bits/stdc++.h>

typedef long long ll;
const int maxn = (int) 1007;
ll dp[maxn][maxn];

struct Task
{
	ll x, y, v;
	Task(ll _x, ll _y, ll _v) : x(_x), y(_y), v(_v){}
	bool operator< (Task a)
	{
		if(x != a.x) return x < a.x;
		return y < a.y;
	}
};
std::vector<Task> task;
int main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int c, t;
	scanf("%d%d", &c, &t);
	while(t--)
	{
//		std::cerr << std::endl;
		task.clear();
		ll n, m, k, d;
		scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
		ll xx, yy, vv;
		for(int i = 0; i < m; i++) {scanf("%lld%lld%lld", &xx, &yy, &vv); task.push_back(Task(xx, yy, vv));}
		std::sort(task.begin(), task.end());
		ll cur = 0;
//		for(int i = 0; i < m; i++) std::cerr << task[i].y << " " << task[i].x << std::endl;
		for(int i = 1; i <= n; i++)
		{
			dp[i][0] = 0;
			ll sumt = 0;
			for(int j = 0; j <= std::min(k, (ll)i - 1); j++) dp[i][0] = std::max(dp[i][0], dp[i - 1][j]);
			for(int j = 1; j <= std::min(k, (ll)i); j++)
			{
				while(cur < m && task[cur].x < i) cur++;
				while(cur < m && task[cur].x == i && task[cur].y <= j)
				{
//					std::cerr << task[cur].y << " " << task[cur].x << std::endl;
					sumt += task[cur].v; cur++;
				}
				
				dp[i][j] = dp[i - 1][j - 1] - d + sumt;
			}
		}
//		std::cerr << m << " " << cur;
		ll ans = 0;
		for(int i = 0; i <= std::min(n, k); i++) ans = std::max(ans, dp[n][i]);
		printf("%lld\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}