#include<bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
namespace Pai369
{
	const int N = 5e5 + 5;
	int test_id , n , m , q , x[N] , y[N] , px[N] , py[N] , vx[N] , vy[N];
	namespace BF
	{
		const int N = 2005;
		bitset<N>f[N];
		bool Calc()
		{
			f[0][1] = 1;
			// for(int i = 1 ; i <= n ; i++)cerr << x[i] << " \n"[i == n];
			// for(int i = 1 ; i <= m ; i++)cerr << y[i] << " \n"[i == m];
			// cerr << endl;
			for(int i = 1 ; i <= n ; i++)
			{
				for(int j = 1 ; j <= m ; j++)
				{
					f[i][j] = (f[i - 1][j] || f[i][j - 1]) && ((x[1] - y[1]) * (x[i] - y[j]) > 0);
				}
			}
			return f[n][m];
		}
		int Solve()
		{
			cout << Calc();
			while(q--)
			{
				int kx , ky; cin >> kx >> ky;
				for(int i = 1 ; i <= kx ; i++)
				{
					cin >> px[i] >> vx[i];
					swap(x[px[i]] , vx[i]);
				}
				for(int i = 1 ; i <= ky ; i++)
				{
					cin >> py[i] >> vy[i];
					swap(y[py[i]] , vy[i]);
				}
				cout << Calc();
				for(int i = 1 ; i <= kx ; i++)swap(x[px[i]] , vx[i]);
				for(int i = 1 ; i <= ky ; i++)swap(y[py[i]] , vy[i]);
			}
			cout << "\n";
			return 0;
		}
	}
	namespace BF2
	{
		const int LG = 20;
		int tmp[N] , a[N] , b[N] , cl[N] , cr[N] , d[N];
		int top , stk[N]; bool bridge[N];
		struct ST
		{
			int n , v[N] , st[LG][N];
			int Min(int i , int j)
			{
				return v[i] < v[j] ? i : j;
			}
			void init(int nn , int a[])
			{
				n = nn;
				for(int i = 1 ; i <= n ; i++)v[i] = a[i] , st[0][i] = i;
				for(int i = 1 ; i < LG ; i++)
					for(int j = 1 ; j + (1 << i) - 1 <= n ; j++)
						st[i][j] = Min(st[i - 1][j] , st[i - 1][j + (1 << (i - 1))]);
			}
			int qry(int l , int r)
			{
				if(l > r)return 0;
				int t = __lg(r - l + 1);
				return Min(st[t][l] , st[t][r - (1 << t) + 1]);
			}
		}stamin , stbmin , stbmax;
		int Calc()
		{
			int n = Pai369::n , m = Pai369::m;
			if(x[1] > y[1])
			{
				for(int i = 1 ; i <= n ; i++)a[i] = x[i];
				for(int i = 1 ; i <= m ; i++)b[i] = y[i];
			}
			else
			{
				for(int i = 1 ; i <= m ; i++)a[i] = y[i];
				for(int i = 1 ; i <= n ; i++)b[i] = x[i];
				swap(n , m);
			}
			for(int i = 1 ; i <= n ; i++)tmp[i] = a[i];
			stamin.init(n , tmp);
			for(int i = 1 ; i <= m ; i++)tmp[i] = b[i];
			stbmin.init(m , tmp);
			for(int i = 1 ; i <= m ; i++)tmp[i] = -b[i];
			stbmax.init(m , tmp);
			int mxb = b[stbmax.qry(1 , m)];
			for(int i = 1 ; i <= n ; i++)
			{
				if(a[i] - mxb > 0)cl[i] = cr[i] = d[i] = i , bridge[i] = 1;
				else cl[i] = cr[i] = 0 , d[i] = n + 1 , bridge[i] = 0;
			}
			top = 0;
			for(int i = n ; i >= 1 ; i--)
			{
				while(top && (a[i] > a[stk[top]] && !bridge[stk[top]]))top--;
				int p = stk[top];
				if(p)
				{
					int x = stamin.qry(i + 1 , p);
					if(a[x] - b[stbmin.qry(1 , m)] > 0)
					{
						int l = 1 , r = m;
						while(l < r)
						{
							int mid = (l + r) >> 1;
							if(a[x] - b[stbmin.qry(1 , mid)] <= 0)l = mid + 1;
							else r = mid;
						}
						int j = l;
						if(a[x] - b[j] > 0 && a[i] - b[stbmax.qry(1 , j)] > 0)
						{
							if(!cl[i])cl[i] = cl[p];
							cr[i] = max(cr[i] , cr[p]);
						}
					}
				}
				stk[++top] = i;
			}
			top = 0;
			for(int i = 1 ; i <= n ; i++)
			{
				while(top && (a[i] > a[stk[top]] && !bridge[stk[top]]))top--;
				int p = stk[top];
				if(p)
				{
					int x = stamin.qry(p , i - 1);
					// if(i == n)cerr << i << ":" << x << ' '  << a[x] << '-' << b[stbmax.qry(1 , m)] << "\n";
					if(a[x] - b[stbmin.qry(1 , m)] > 0)
					{
						int l = 1 , r = m;
						while(l < r)
						{
							int mid = (l + r + 1) >> 1;
							if(a[x] - b[stbmin.qry(mid , m)] <= 0)r = mid - 1;
							else l = mid;
						}
						int j = l;
						// if(i == n)cerr << i << ":" << x << ',' << j << ' ' << a[i] << '-' << b[stbmax.qry(j , m)] << "\n";
						if(a[x] - b[j] > 0 && a[i] - b[stbmax.qry(j , m)] > 0)
						{
							d[i] = min(d[i] , d[p]);
						}
					}
				}
				stk[++top] = i;
			}
			// for(int i = 1 ; i <= n ; i++)cerr << cl[i] << " \n"[i == n];
			// for(int i = 1 ; i <= n ; i++)cerr << cr[i] << " \n"[i == n];
			// for(int i = 1 ; i <= n ; i++)cerr << d[i] << " \n"[i == n];
			// cerr << endl;
			return (cl[1] <= d[n] && d[n] <= cr[1]);
		}
		int Solve()
		{
			cout << Calc();
			while(q--)
			{
				int kx , ky; cin >> kx >> ky;
				for(int i = 1 ; i <= kx ; i++)
				{
					cin >> px[i] >> vx[i];
					swap(x[px[i]] , vx[i]);
				}
				for(int i = 1 ; i <= ky ; i++)
				{
					cin >> py[i] >> vy[i];
					swap(y[py[i]] , vy[i]);
				}
				cout << Calc();
				for(int i = 1 ; i <= kx ; i++)swap(x[px[i]] , vx[i]);
				for(int i = 1 ; i <= ky ; i++)swap(y[py[i]] , vy[i]);
			}
			cout << "\n";
			return 0;
		}
	}
	int Solve()
	{
		freopen("expand.in" , "r" , stdin);
		freopen("expand.out" , "w" , stdout);
		ios::sync_with_stdio(0);
		cin.tie(0) , cout.tie(0);
		cin >> test_id >> n >> m >> q;
		for(int i = 1 ; i <= n ; i++)cin >> x[i];
		for(int i = 1 ; i <= m ; i++)cin >> y[i];
		// BF2::Solve();
		if(n <= 2000 && m <= 2000)BF::Solve();
		else BF2::Solve();
		return 0;
	}
}
signed main()
{
	Pai369::Solve();
	return 0;
}