#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "coin"
#define const constexpr

const int N=1e5+5;
int n;

namespace Subtask1
{
	int dis[205][205];
	void solve()
	{
		int m;
		cin >> m;
		int u, v, val;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dis[i][j] = INT_MAX;
			}
			dis[i][i]=0;
		}
		for (int i = 1; i <= m; i++)
		{
			cin >> u >> v >> val;
			dis[u][v] = min(dis[u][v], val);
		}
		for (int k = 1; k <= n; k++)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{

					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
		for (int i = 2; i <= n; i++)
		{
			int minans = INT_MAX;
			for (int j = 1; j <= n; j++)
			{

				minans = min(minans, dis[1][j] + dis[i][j]);
			}
			if (minans > 1e9)
			{
				cout << -1 << " ";
			}
			else
			{
				cout << minans << " ";
			}
		}
	}
}

namespace Subtask2
{
	int dis[N];

	struct node{
		int to,val;
		node(int a,int b){
			to=a,val=b;
		}
	};
	vector<node> e[N];
	bool operator<(node a,node b){
		return a.val>b.val;
	}

	void dijkstra(){
		__gnu_pbds::priority_queue<node> q;
		q.push({1,0});
		while(q.size()){
			auto now=q.top();
			q.pop();
			if(now.val>dis[now.to]){
				continue;
			}
			dis[now.to]=now.val;
			for(auto i:e[now.to]){
				if(dis[i.to]>now.val+i.val){
					dis[i.to] = now.val+i.val;
					q.push({i.to,dis[i.to]});
				}
			}

		}
	}

	void solve()
	{
		fill(dis,dis+N,1e15);
		dis[1]=0;
		int m;
		cin >> m;
		for(int i=1,u,v,val;i<=m;i++){
			cin >> u >> v >> val;
			e[u].emplace_back(v,val);
		}
		dijkstra();
		for(int i=2;i<=n;i++){
			cout << (dis[i]<1e15?dis[i]:-1) << " ";
		}
	}
}

namespace Main
{

	int main()
	{

		cin >> n;
		if (n <= 200)
		{
			Subtask1::solve();
		}
		else
		{
			Subtask2::solve();
		}

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