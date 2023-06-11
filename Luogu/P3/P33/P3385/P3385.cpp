#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int to, val;
};
bool operator<(node a,node b)
{
	return a.val<b.val;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P3385_2.in", "r", stdin);
#endif
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	int t;
	//cin >> t;
	scanf("%lld",&t);
	for (int T = 0; T < t; T++)
	{
		int n, m, u, v, w;
		bool flag = true;
		//cin >> n >> m;
		scanf("%lld %lld",&n,&m);
		vector<node> e[2005];
		for (int i = 0; i < m; i++)
		{
			//cin >> u >> v >> w;
			scanf("%lld %lld %lld",&u,&v,&w);
			e[u].push_back(node{v, w});
			if (w >= 0)
			{
				e[v].push_back(node{u, w});
			}
		}
		priority_queue<node> q;
		q.push({1,0});
		int dfn[2005]={0},val[2005];
		memset(val,0x3f3f3f,sizeof(val));
		dfn[1]=1;
		val[1]=0;
		while(!q.empty()&&flag){
			node now=q.top();
			q.pop();
			for(auto i:e[now.to]){
				if(val[i.to]>val[now.to]+i.val&&flag){
					q.push({i.to,now.val+i.val});
					val[i.to]=val[now.to]+i.val;
					dfn[i.to]=dfn[now.to]+1;
					if(dfn[now.to]>n){
						flag=false;
					}
				}
			}
		}
		if (flag)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	return 0;
}