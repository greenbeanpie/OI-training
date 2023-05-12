#include <bits/stdc++.h>
#define y1 y114514
#define int long long 

using namespace std;

const int N = 1e4 + 10;

int a, b, tot;
int maxx;

signed main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    cin >> a >> b;
    
    if(a >= b)
    {
    	int maxx = a * a - b * b;
    	for(int i = 0;i <= min(a - 1, b - 2);i++)
    	{
    		int c = b % (i + 2);
			int sum = i - c * (b / (i + 2) + 1) * (b / (i + 2) + 1) 
			- (i + 2 - c) * (b / (i + 2)) * (b / (i + 2));
    		maxx = max(maxx, (a - i) * (a - i) + sum);
    	}
    	cout << maxx;
    }
	else if(b - a == 1) cout << "-1";
	else
	{
		int maxx = a * a - b * b;
    	for(int i = 0;i <= min(a, b - 2);i++)
    	{
			if(i == a)
			{
				int c = b % (i + 1);
				int sum = i - c * (b / (i + 1) + 1) * (b / (i + 1) + 1) - (i + 1 - c) * (b / (i + 1)) * (b / (i + 1));
    			maxx = max(maxx, (a - i) * (a - i) + sum);
    			continue;
			}
    		int c = b % (i + 2);
			int sum = i - c * (b / (i + 2) + 1) * (b / (i + 2) + 1) - (i + 2 - c) * (b / (i + 2)) * (b / (i + 2));
    		maxx = max(maxx, (a - i) * (a - i) + sum);
    	}
    	cout << maxx;
	}
	return 0;
}