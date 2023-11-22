#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

namespace Solution
{
    #define flp(name, lpst, lped) for (int name = lpst, name##end = lped; name <= name##end; ++name)
    #define plf(name, lpst, lped) for (int name = lpst, name##end = lped; name >= name##end; --name)
    
    
    std::ifstream cin("tribool.in");
    std::ofstream cout("tribool.out");
    
    
    constexpr int maxn = 2e5 + 5;
    
    struct Stat
    {
        int val, from, nt;
    } st[maxn];
    
    int unk[maxn], n, m, ff[maxn], sz[maxn];
    
    void clear()
    {
        flp (i, 1, n + n) 
        {
            st[i].val = st[i].from = st[i].nt = unk[i] = ff[i] = sz[i] = 0;
        }
    }
    
    int getf(int x) { return x == ff[x] ? x : ff[x] = getf(ff[x]); }
    void mrg(int x, int y)
    {
    	x = getf(x), y = getf(y);
    	if (x == y)
    	{
    		return ;
    	}
    	if (sz[x] < sz[y]) { std::swap(x, y); }
    	ff[y] = x, sz[x] += sz[y], sz[y] = 0;
    }
    
    void rmain(void)
    {
        cin >> n >> m;
        flp (i, 1, n)
        {
            st[i].val = -1;
            st[i].from = i;
            st[i].nt = 0;
            unk[i] = 0;
            ff[i] = i, ff[i + n] = i + n;
            sz[i] = 1, sz[i + n] = 1;
        }   
        while (m--)
        {
        	char op; cin >> op;
        	if (op == 'T' || op == 'F' || op == 'U')
        	{
        		int i; cin >> i;
        		st[i].from = st[i].nt = 0;
        		if (op == 'T') { st[i].val = 2; }
        		else if (op == 'U') { st[i].val = 1; }
        		else if (op == 'F') { st[i].val = 0; }
        	}
        	else if (op == '+')
        	{
        		int i, j; cin >> i >> j;
        		st[i].val = st[j].val, st[i].from = st[j].from, st[i].nt = st[j].nt;
        	}
        	else if (op == '-')
        	{
        		int i, j; cin >> i >> j;
        		if (st[j].val == -1)
        		{
        			st[i].val == -1;
        		}
        		else 
        		{
        			st[i].val = 2 - st[j].val;
        		}
        		st[i].from = st[j].from, st[i].nt = !st[j].nt;
        	}
        }
        int ans = 0;
        flp (i, 1, n)
        {
       		if (st[i].val == -1)
       		{
       			if (st[i].nt)
       			{
       				mrg(i, st[i].from + n);
       				mrg(i + n, st[i].from);
       			}
       			else 
       			{
       				mrg(i, st[i].from);
       				mrg(i + n, st[i].from + n);
       			}
       		}
       		if (st[i].val == 1)
       		{
       			mrg(i, i + n);
       		}
       	}
       	flp (i, 1, n)
        {
        	if (st[i].val == 0 || st[i].val == 2)
        	{
        		continue;
        	}
        	if (st[i].val == 1 || getf(i) == getf(i + n))
        	{
        		unk[i] = unk[i + n] = 1;
        		// std::cerr << i << " ";
        	}
        }
        // std::cerr << "\n";
       	flp (i, 1, n)
       	{
       		ans += unk[getf(i)];
       		/* if (unk[getf(i)])
       		{
       			std::cerr << i << " ";
       		} */
       	}
       	// std::cerr << "\n";
        cout << ans << "\n";
        
        /*
        std::cerr << "\n";
        flp (i, 1, n)
        {
        	std::cerr << st[i].from << " ";
        } std::cerr << "\n";
        flp (i, 1, n + n)
        {
        	std::cerr << getf(i) << " ";
        }
        
        std::cerr << "\n\n\n";
        */
        
        clear();
    }
    
    
    void main(void)
    {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);
        
        
        int c, t; cin >> c >> t;
        while (t--) { rmain(); }
        
        
    } 
}

int main(void)
{
    Solution::main();
    return 0;
}

