#include <bits/stdc++.h>
#define y1 y114514

using namespace std;

const int N = 5e5 + 10;

int t, n, p, sum, ans;
int a[N], dp[N];
set<int> q;
set<int> q1;

void dfs(int x)
{
	if(x == 0)
	{
		memset(dp, 0, sizeof dp);
		for(int i = 1;i <= n;i++)
			dp[i] = 1;
		for(int i = 1;i <= n;i++)
			for(int j = i + 1;j <= n;j++)
				if(a[i] < a[j]) dp[j] = max(dp[j], dp[i] + 1);
		int maxn = 0;
		for(int i = 1;i <= n;i++)
			maxn = max(maxn, dp[i]);
		if(maxn == n - 1) ans++;
		/*for(int i = 1;i <= n;i++)
			cout << a[i] << " ";
		cout << endl;*/
		return;
	}
	
	for(auto iit = q1.begin();iit != q1.end();iit++)
		for(auto it = q.begin();it != q.end();it++)
			if(a[*iit] == 0)
			{
				a[*iit] = *it;
				q.erase(*it);
				q1.erase(*iit);
				dfs(x - 1);
				a[*iit] = 0;
				q.insert(*it);
				q1.insert(*iit);
			}
}

signed main()
{
    #ifdef CODESPACE
        freopen("B_pspy.in","r",stdin);
    #endif
	ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
    	cin >> n >> p;
    	q.clear();
    	sum = n, ans = 0;
    	memset(a, 0, sizeof a);
    	for(int j = 1;j <= n;j++)
    		q.insert(j), q1.insert(j);
    	for(int j = 1;j <= p;j++)
    	{
    		int x, y;
    		cin >> x >> y;
    		a[x] = y;
    		q.erase(y);
    		q1.erase(x);
    		sum--;
    	}
    	/*for(auto it:q1)
    		cout << it << " ";
    	cout << endl;*/
    	dfs(sum);
    	cout << ans;
    }
    
	return 0;
}