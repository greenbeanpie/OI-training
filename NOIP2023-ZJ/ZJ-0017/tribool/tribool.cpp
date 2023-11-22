#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int val[500005],fa[500005];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
#ifndef LOCAL
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
#endif
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int x=1;x<=n;x++)
		val[x]=x;
		for(int x=1;x<=m;x++)
		{
			char op;
			int u;
			cin>>op>>u;
			if(op=='T')val[u]=n+1;
			else if(op=='F')val[u]=-n-1;
			else if(op=='U')val[u]=0;
			else if(op=='+')
			{
				int v;
				cin>>v;
				val[u]=val[v];
			}
			else if(op=='-')
			{
				int v;
				cin>>v;
				val[u]=-val[v];
			}
		}
		//for(int x=1;x<=n;x++)
		//cerr<<val[x]<<' ';cerr<<endl;
		for(int x=0;x<=2*n+2;x++)
		fa[x]=x;
		for(int x=1;x<=n;x++)
		{
			int u=x+n+1,v=val[x]+n+1;
			u=find(u),v=find(v);
			fa[u]=v;
			u=-x+n+1,v=-val[x]+n+1;
			u=find(u),v=find(v);
			fa[u]=v;
		}
		for(int x=1;x<=n;x++)
		if(find(x+n+1)==find(-x+n+1))
		{
			int u=x+n+1,v=n+1;
			u=find(u),v=find(v);
			fa[u]=v;
		}
		if(find(-n-1+n+1)==find(n+1+n+1))
		{
			int u=n+1,v=n+1+n+1;
			u=find(u),v=find(v);
			fa[u]=v;
		}
		int ans=0;
		for(int x=1;x<=n;x++)
		if(find(x+n+1)==find(n+1))ans++;
		cout<<ans<<endl;
	}
}
/*
1 1
10 10
- 9 8
- 8 6
- 6 5
- 5 4
- 4 3
+ 3 9
- 1 2
+ 2 7
+ 7 10
- 10 1
*/
