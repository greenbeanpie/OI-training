#include<bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
int test_id;
namespace Pai369
{
	const int N = 1e5 + 5;
	int n , m , fa[N * 2] , w[N * 2]; 
	struct Num
	{
		int tp , id;
	}a[N] , ans[N];
	Num operator !(const Num &a)
	{
		Num c = a;
		if(c.tp < 0)c.tp = c.tp == -1 ? -2 : -1;
		else if(c.tp < 2)c.tp = c.tp ^ 1;
		return c;
	}
	Num ToNum(char ch)
	{
		if(ch == 'T')return {1 , 0};
		if(ch == 'F')return {0 , 0};
		if(ch == 'U')return {2 , 0};
		assert(0);
	}
	int Find(int x)
	{
		if(x == fa[x])return x;
		int fx = fa[x] , rt = Find(fx);
		w[x] ^= w[fx];
		fa[x] = rt;
		return rt;
	}
	int Solve()
	{
		cin >> n >> m;
		for(int i = 1 ; i <= n ; i++)a[i] = {-1 , i};
		for(int i = 1 ; i <= m ; i++)
		{
			char op; int x , y;
			cin >> op >> x;
			if(op == '+')cin >> y , a[x] = a[y];
			else if(op == '-')cin >> y , a[x] = !a[y];
			else a[x] = ToNum(op);
		}
		for(int i = 1 ; i <= n ; i++)fa[n + i] = fa[i] = i , w[n + i] = 1 , w[i] = 0;
		for(int i = 1 ; i <= n ; i++)
		{
			if(a[i].tp < 0)ans[i] = {-1 , i};
			else ans[i] = a[i];
			// assert(a[i].tp < 0 || a[i].tp == 2);
		}
		for(int i = 1 ; i <= n ; i++)
		{
			if(a[i].tp < 0)
			{
				int x = i , y = a[i].id + (a[i].tp == -2) * n;
				// cerr << "x,y:" << ' ' << x << ' ' << y << "\n";
				// cerr << "\t" << Find(x) << ' ' << Find(y) << "\n";
				if(Find(x) == Find(y))
				{
					if((w[x] xor w[y]) != 0)
					{
						// assert(a[i].tp < 0 || a[i].tp == 2);
						ans[Find(x)] = {2 , 0};
					}
				}
				else
				{
					if(ans[Find(y)].tp < 0)
					{
						int fy = Find(y);
						w[fy] = w[x] xor w[y];
						fa[fy] = Find(x);
					}
					else if(ans[Find(x)].tp < 0)
					{
						int fx = Find(x);
						w[fx] = w[x] xor w[y];
						fa[fx] = Find(y);
					}
					else
					{
						// assert(0);
					}
				}
			}
			else ans[i] = a[i];
		}
		for(int i = 1 ; i <= n ; i++)
		{
			if(ans[i].tp < 0)
			{
				int f = Find(i);
				if(ans[f].tp < 0)
					ans[f] = {1 , 0}; // ?
				if(ans[f].tp == 2)ans[i].tp = 2;
				else ans[i].tp = w[i] xor ans[f].tp;
			}
		}
		// cerr << "--------------------------\n";
		// for(int i = 1 ; i <= n ; i++)
		// {
		// 	if(a[i].tp < 0)cerr << (a[i].tp == -1 ? "" : "!") << "x" << a[i].id;
		// 	else cerr << (a[i].tp == 0 ? "F" : (a[i].tp == 1 ? "T" : "U"));
		// 	cerr << " \n"[i == n];
		// }		
		// // for(int i = 1 ; i <= n * 2 ; i++)cerr << i << ":" << fa[i] << ' ' << w[i] << "\n";
		// for(int i = 1 ; i <= n ; i++)
		// {
		// 	if(ans[i].tp < 0)cerr << (ans[i].tp == -1 ? "" : "!") << "x" << ans[i].id;
		// 	else cerr << (ans[i].tp == 0 ? "F" : (ans[i].tp == 1 ? "T" : "U"));
		// 	cerr << " \n"[i == n];
		// }
		int cnt = 0;
		for(int i = 1 ; i <= n ; i++)
			if(ans[i].tp == 2)cnt++;
		cout << cnt << "\n";
		return 0;
	}
}
signed main()
{
	freopen("tribool.in" , "r" , stdin);
	freopen("tribool.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	int T; cin >> test_id >> T;
	while(T--)Pai369::Solve();
	return 0;
}