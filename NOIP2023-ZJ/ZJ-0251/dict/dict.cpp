#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>

namespace Solution
{
    #define flp(name, lpst, lped) for (int name = lpst, name##end = lped; name <= name##end; ++name)
    #define plf(name, lpst, lped) for (int name = lpst, name##end = lped; name >= name##end; --name)
    
    
    std::ifstream cin("dict.in");
    std::ofstream cout("dict.out");
    
    
    constexpr int maxn = 3e3 + 5;
    
    std::multiset<std::basic_string<int>> s;
    
    std::string a[maxn];
    std::basic_string<int> g[maxn], l[maxn];
    
    
    void main(void)
    {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);
        
        
        int n, m; cin >> n >> m;
        if (n == 1)
        {
            cout << "1\n";
            return ;
        }
        flp (i, 1, n)
        {
        	cin >> a[i];
        	g[i].resize(26);
        	for (char c : a[i])
        	{
        	    ++g[i][c - 'a'];
        	}
        	l[i] = g[i];
        	std::reverse(l[i].begin(), l[i].end());
            s.insert(l[i]);
        }
        flp (i, 1, n)
        {
            s.erase(l[i]);
            auto lst = *s.begin();
            std::reverse(lst.begin(), lst.end());
            int lp = 25;
            while (!lst[lp]) { --lp; }
            int gp = 0;
            while (!g[i][gp]) { ++gp; }
            if (gp >= lp) { cout << 0; }
            else { cout << 1; }
            s.insert(l[i]);        
        }
        cout << "\n";
        
        
        
    } 
}

int main(void)
{
    Solution::main();
    return 0;
}

