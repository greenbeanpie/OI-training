#include <bits/stdc++.h>
#define y1 y114514

using namespace std;

const int N = 2e2 + 10;

string s[N] = "";

signed main()
{
    char a;
    int tot = 1;
    while(tot <= 200)
    {
    	a = getchar();
    	if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
    	{
    		s[tot] = s[tot] + a;
    	}
    	else 
    	{
    		tot++;
    	}
    }
    
    int maxn = -1, minn = 200;
    for(int i = 1;i <= tot;i++)
    {
    	if(int(s[i].size()) != 0)
    	{
    		maxn = max(maxn,int(s[i].size()));
    		minn = min(minn,int(s[i].size()));
    	}
    }
    
    for(int i = 1;i <= tot;i++)
    	if(int(s[i].size()) == maxn)
    	{
    		cout << s[i] << endl;
    		break;
    	}
    	
    for(int i = 1;i <= tot;i++)
    	if(int(s[i].size()) == minn)
    	{
    		cout << s[i] << endl;
    		break;
    	}
	return 0;
}