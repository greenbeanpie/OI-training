#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "clear"
#define const constexpr

namespace Main
{
	int wk[8][2] = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
	const int N = 55;
	int mp[N][N];
	int block[N * N];
	int tot = 0;
	int main()
	{
		int n;
		cin >> n;
		char c;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> c;
				if (c == '#')
				{
					mp[i][j] = -1;
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (mp[i][j] < 0)
				{
					mp[i][j] = ++tot;
					queue<pair<int, int>> q;
					q.push({i, j});
					while (q.size())
					{
						++block[tot];
						auto now = q.front();
						q.pop();
						// mp[now.first][now.second] = tot;
						for (int k = 0; k < 8; k++)
						{
							if (mp[now.first + wk[k][0]][now.second + wk[k][1]] == -1)
							{
								mp[now.first + wk[k][0]][now.second + wk[k][1]] = tot;
								q.emplace(now.first + wk[k][0], now.second + wk[k][1]);
							}
						}
					}
				}
			}
		}
		int maxb, sum = 0;
		for (int i = 1; i <= tot; i++)
		{
			maxb = 0;
			for (int j = 1; j <= tot; j++)
			{
				if (block[j] > block[maxb])
				{
					maxb = j;
				}
			}
			if(!block[maxb]){
				break;
			}
			int l = n, r = 0, u = n, d = 0;
			int cost = 0;
			for (int x = 1; x <= n; x++)
			{
				for (int y = 1; y <= n; y++)
				{
					if (mp[y][x] == maxb)
					{
						l = min(l, x), r = max(r, x), u = min(u, y), d = max(d, y);
					}
				}
			}
			while(r-l<d-u){
				int sum1 = 0, sum2 = 0;
				for (int y = u; y <= d; y++)
				{
					if(mp[y][l-1]){
						++sum1;
					}
					if(mp[y][r+1]){
						++sum2;
					}
				}
				if(sum2>sum1){
					++r;
				}
				else{
					--l;
				}
			}
			while(d-u<r-l){
				int sum1 = 0, sum2 = 0;
				for (int x = l; x <= r;x++){
					if(mp[u-1][x]){
						++sum1;
					}
					if(mp[d+1][x]){
						++sum2;
					}
				}
				if(sum2>sum1){
					++d;
				}
				else{
					--u;
				}
			}
			for (int x = l; x <= r; x++)
			{
				for (int y = u; y <= d; y++)
				{
					if (mp[y][x])
					{
						--block[mp[y][x]];
						mp[y][x] = 0;
						cost = r - l + 1;
					}
				}
			}
			sum += cost;
		}
		cout << sum << endl;
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main::main();
	return 0;
}