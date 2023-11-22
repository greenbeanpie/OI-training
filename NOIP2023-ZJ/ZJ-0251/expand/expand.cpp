#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

namespace Solution
{
    #define flp(name, lpst, lped) for (int name = lpst, name##end = lped; name <= name##end; ++name)
    #define plf(name, lpst, lped) for (int name = lpst, name##end = lped; name >= name##end; --name)
    
    
    std::ifstream cin("expand.in");
    std::ofstream cout("expand.out");
    
    
    constexpr int maxn = 5e5 + 5;
    
    int a[maxn], b[maxn], f[maxn], g[maxn], c, n1, m1, n, m, q;
    
    namespace Subtask1
    {
    	signed char vis[2005][2005];
    	
    	int dfs(int i, int j)
    	{
    		if (vis[i][j] != -1) { return vis[i][j]; }
    		if (f[i] <= g[j]) { return vis[i][j] = 0; }
    		// std::cerr << i << " f[i]=" << f[i] << " " << j << " g[j]=" << g[j] << "\n";
    		if (i == n && j == m) { return vis[i][j] = 1; }
    		if (i < n && dfs(i + 1, j)) { return vis[i][j] = 1; }
    		if (j < m && dfs(i, j + 1)) { return vis[i][j] = 1; }
    		return vis[i][j] = false;
    	} 
    	
    	void main(void)
    	{
    		flp (i, 1, n1) { cin >> a[i]; }
    		flp (i, 1, m1) { cin >> b[i]; }
    		if (a[1] > b[1])
    		{
    			n = n1, m = m1;
    			flp (i, 1, n) { f[i] = a[i]; }
    			flp (i, 1, m) { g[i] = b[i]; }
    		}
    		else 
    		{
    			n = m1, m = n1;
    			flp (i, 1, n) { f[i] = b[i]; }
    			flp (i, 1, m) { g[i] = a[i]; } 
    		}
    		flp (i, 1, n) flp (j, 1, m) { vis[i][j] = -1; }
    		cout << dfs(1, 1);
    		// std::cerr << "\n";
    		while (q--)
    		{
    			n = n1, m = m1;
    			flp (i, 1, n) { f[i] = a[i]; }
    			flp (i, 1, m) { g[i] = b[i]; } 
				int kx, ky; cin >> kx >> ky;
				flp (i, 1, kx) { int p, v; cin >> p >> v; f[p] = v; }
				flp (i, 1, ky) { int p, v; cin >> p >> v; g[p] = v; }
				if (f[1] < g[1])
				{
					std::swap(n, m);
					flp (i, 1, std::max(n, m)) { std::swap(f[i], g[i]); }
				}
				flp (i, 1, n) flp (j, 1, m) { vis[i][j] = -1; }
				cout << dfs(1, 1);
				// std::cerr << "\n";
    		}
    		cout << "\n";
    	}
    }
    
    
    void main(void)
    {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);
        
        
        cin >> c >> n1 >> m1 >> q;
        if (c <= 7)
        {
        	return Subtask1::main();
        }
        
        
    } 
}

int main(void)
{
    Solution::main();
    return 0;
}

