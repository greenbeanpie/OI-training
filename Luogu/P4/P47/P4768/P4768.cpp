#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define endl "\n"

struct side
{
	int u, v, l, a, nxt;
};
struct node{
	int u,v,val;
};
struct leaf{
	int lson,rson,father;
};
struct cmpl{
	bool operator()(node a,node b){
		return a.val<b.val;
	}
};
struct cmpa{
	bool operator()(side a,side b){
		return a.a<b.a;
	}
};

int T, n, m, u, v, l, a;
int head[200005],f[200005][20],mindis[200005];
vector<side> e;
extern void add_edge(int u, int v, int l, int a);
extern void dijkstra();
extern void kruskal();
extern void dfs(int u, int dep);
extern int solve();

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P4768.in", "r", stdin);
	freopen("P4768.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--)
	{
		e.clear();
		e.push_back({-1, -1, -1, -1});
		memset(head,-1,sizeof(head));
		cin >> n >> m;
		for (int i = 1; i <= m; i++)
		{
			cin >> u >> v >> l >> a;
			add_edge(u, v, l, a);
			add_edge(v, u, l, a);
		}
		dijkstra();
		kruskal();
		dfs(1,0);
	}
	return 0;
}
void add_edge(int u, int v, int l, int a)
{
	side now={u,v,l,a,head[u]};
	head[u] = e.size();
	e.push_back(now);
}
void dijkstra(){
	bool vis[200005]={0};
	fill(mindis,mindis+n+5,INT_MAX);
	mindis[0]=mindis[1]=0;
	vis[0]=1;
	__gnu_pbds::priority_queue<node,cmpl> q;
	q.push({0,1,0});
	while(q.size()){
		auto now=q.top();
		q.pop();
		if(now.val>mindis[now.v]||vis[now.v]){
			continue;
		}
		mindis[now.v]=now.val;
		vis[now.v]=1;
		for(int i=head[now.v];i;i=e[i].nxt){
			if(mindis[e[i].u]+e[i].l<mindis[e[i].v]){
				mindis[e[i].v]=mindis[e[i].u]+e[i].l;
				q.push({e[i].u,e[i].v,mindis[e[i].v]});
			}
		}
	}
}
