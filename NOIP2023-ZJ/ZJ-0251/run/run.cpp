#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

namespace Solution
{
    #define flp(name, lpst, lped) for (int name = lpst, name##end = lped; name <= name##end; ++name)
    #define plf(name, lpst, lped) for (int name = lpst, name##end = lped; name >= name##end; --name)
    
    
    std::ifstream cin("run.in");
    std::ofstream cout("run.out");
    
    using ll = long long;
    
    
    constexpr int maxm = 1e5 + 5;
    constexpr ll inf = 1e18;
    
    struct Task
    {
    	int x, y;
    	ll v;
    } a[maxm];
    
    int n, m, k, c, t;
    ll d;
    
    namespace Subtask1
    {
    	ll dp[105][105], mx[105];
    	
    	void rmain(void)
    	{
    		std::memset(dp, 0, sizeof(dp));
    		std::memset(mx, 0, sizeof(mx));
    		cin >> n >> m >> k >> d;
    		flp (i, 1, m) { cin >> a[i].x >> a[i].y >> a[i].v; }
    		flp (i, 1, n)
    		{
    			flp (j, 1, i - 1) { dp[i][0] = std::max(dp[i][0], mx[j]); }	
    			flp (j, 1, std::min(i, k)) 
    			{
    				dp[i][j] = dp[i - j][0] - j * d;
    				flp (l, 1, m)
    				{
    					if (a[l].x - a[l].y >= i - j && a[l].x <= i)
    					{
    						dp[i][j] += a[l].v;
    					}
    				}
    			}
    			flp (j, 0, std::min(i, k)) { mx[i] = std::max(mx[i], dp[i][j]); } 
    		}	
    		ll ans = 0;
    		flp (i, 1, n) { ans = std::max(ans, mx[i]); }
    		cout << ans << "\n";
    	}
    	
    	void main(void)
    	{
    		int t; cin >> t;
    		while (t--) { rmain(); }
    	}
    }
    
    namespace Subtask2
    {
    	ll mx[1005], mx0[1005];
    	
    	void rmain(void)
    	{
    		std::memset(mx, 0, sizeof(mx));
    		std::memset(mx0, 0, sizeof(mx0));
    		cin >> n >> m >> k >> d;
    		flp (i, 1, m) { cin >> a[i].x >> a[i].y >> a[i].v; }
    		flp (i, 1, n)
    		{
    			std::priority_queue<std::pair<int, ll>> s;
    			flp (j, 1, m)
    			{
    				if (a[j].x <= i) { s.emplace(a[j].x - a[j].y + 1, a[j].v); }  
    			}
    			ll ans = 0, sum = 0;
    			plf (j, 1, std::min(i, k))
    			{
    				while (!s.empty() && s.top().first >= i - j + 1) { sum += s.top().second, s.pop(); }
    				ans = std::max(ans, mx0[i - j] - j * d + sum);
    			}
    			mx0[i] = mx[i - 1];
    			mx[i] = std::max(ans, mx[i - 1]);
    		}	
    		ll ans = 0;
    		flp (i, 1, n) { ans = std::max(ans, mx[i]); }
    		cout << ans << "\n";
    	}
    	
    	void main(void)
    	{
    		int t; cin >> t;
    		while (t--) { rmain(); }
    	}
    }
    
    
    void main(void)
    {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);
        
        
        cin >> c;
        if (c <= 4)
        {
        	return Subtask1::main();
        }
        Subtask2::main();
        
        
    } 
}

int main(void)
{
    Solution::main();
    return 0;
}

