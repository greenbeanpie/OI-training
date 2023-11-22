#include<bits/stdc++.h>
using namespace std;
constexpr int N=200200;
struct node
{
	int rot,val;
	vector<int> son[2];
}a[N];
int c,t,n,m,lst[N];
int Find(int x)
{
	return (a[x].rot==x)? x:a[x].rot=Find(a[x].rot);
}
inline void Add(int u,int fa,int dis)
{
	a[u].rot=a[fa].rot,a[fa].son[dis].emplace_back(u);
}
void dfs(int u,int col)
{
	a[u].val=col;
	for(int to:a[u].son[0])
		dfs(to,col);
	for(int to:a[u].son[1])
		dfs(to,(col==-1)? col:(col^1));
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1; i<=n+m; ++i)
			lst[i]=i,a[i].rot=i,a[i].val=-2,a[i].son[0].clear(),a[i].son[1].clear();
		for(int i=1; i<=3; ++i)
			a[N-i].rot=N-i,a[N-i].val=i-2,a[N-i].son[0].clear();
		int cnt=n;
		while(m--)
		{
			char op;
			int x,y;
			cin>>op>>x,++cnt;
			if(op=='T')
				Add(cnt,N-3,0);
			if(op=='F')
				Add(cnt,N-2,0);
			if(op=='U')
				Add(cnt,N-1,0);
			if(op=='+')
				cin>>y,Add(cnt,lst[y],0);
			if(op=='-')
				cin>>y,Add(cnt,lst[y],1);
			lst[x]=cnt;
		}
		for(int i=1; i<=n; ++i)
			if(Find(lst[i])!=i)
				Add(i,lst[i],0);
		dfs(N-3,1),dfs(N-2,0),dfs(N-1,-1);
		for(int i=1; i<=n; ++i)
			if(Find(lst[i])==i)
			{
				dfs(i,1);
				if(a[lst[i]].val!=a[i].val)
					dfs(i,-1);
			}
		int cntu=0;
		for(int i=1; i<=n; ++i)
			cntu+=(a[lst[i]].val==-1);
		cout<<cntu<<'\n';
	}
	return 0;
}
