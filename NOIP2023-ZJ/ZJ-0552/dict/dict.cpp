#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

int n, m;
int mx[1000], mn[1000];

int main()
{
	
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);	
	
	cin >> n >> m;
	if(n == 1)
	{
		cout << 1;
		return 0;
	}
	if(m == 1)
	{
		char c;
		int minn = 100, p = -1, f = 0;
		for(int i = 1 ; i <= n ; i ++)
		{
			cin >> c;
			int x = c - 'a' + 1;
			if(x < minn)
			{
				minn = x;
				p = i;
				f = 1;
			}
			else if(x == minn)
				f = 0;
		}
		if(f)
		{
			for(int i = 1 ; i <= n ; i ++)
				cout << (i == p ? 1 : 0);
		}
		else 
		{
			for(int i = 1 ; i <= n ; i ++)
				cout << 0;
		}
	}
	if(m == 2)
	{
		char a, b;
		for(int i = 1 ; i <= n ; i ++)
		{
			cin >> a >> b;
			if(a < b) mx[i] = b * 100 + a, mn[i] = a * 100 + b;
			else mx[i] = a * 100 + b, mn[i] = b * 100 + a;
		}
		for(int i = 1 ; i <= n ; i ++)
		{
			bool f = true;
			for(int j = 1 ; j <= n ; j ++)
			{
				if(i != j && mn[i] >= mx[j])
				{
					f = false;
					break;
				}
			}
			if(f) cout << 1;
			else cout << 0;
		}
	}
	
	
	return 0;
}
