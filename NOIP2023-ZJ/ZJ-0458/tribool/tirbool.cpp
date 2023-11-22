#include<bits/stdc++.h>
#define maxn 300010
#define maxm 500010
#define int long long
using namespace std;
namespace solve
{
	int n,m;
	pair<int,int>dat[maxn];
	struct EDGE
	{
		int v;
		int w;
		int nxt;
	}edge[maxm];
	int head[maxn],totedge=1;
	void addedge(int u,int v,int w)
	{
		totedge++;
		edge[totedge].v=v;
		edge[totedge].w=w;
		edge[totedge].nxt=head[u];
		head[u]=totedge;
	}
	vector<int>r;
	vector<pair<int,int>>graph[maxn];
	bool vis[maxn];
	bool inr[maxn];
	int findr(int p)
	{
		vis[p]=true;
		for(int i=head[p];i;i=edge[i].nxt)
		{
			int v=edge[i].v;
			if(vis[v])
			{
				r.push_back(p);
				inr[p]=true;
				return v;
			}
			else
			{
				int tmp=findr(v);
				if(tmp)
				{
					r.push_back(p);
					inr[p]=true;
					if(tmp==p)
						return 0;
					else return tmp;
				}
			}
		}
		return 0;
	}
	bool check(int p,int dat)
	{
		for(auto e:graph[p])
		{
			int v=e.first;
			int w=e.second;
			if(!inr[v])
				continue;
			if(v==r[0])
				return dat*w==1?1:0;
			return check(v,dat*w);
		}
	}
	int dfs(int p)
	{
		int res=1;
		for(auto e:graph[p])
		{
			int v=e.first;
			int w=e.second;
			if(inr[v])
				continue;
			res+=dfs(v);
		}
		return res;
	}
	int ans;
	int fa[maxn];
	int findfa(int p)
	{
		if(p==fa[p])
			return p;
		return fa[p]=findfa(fa[p]);
	}
	void merge(int u,int v)
	{
		u=findfa(u);
		v=findfa(v);
		if(u!=v)fa[u]=v;
	}
	int main()
	{
		totedge=1;
		memset(vis,0,sizeof(vis));
		memset(inr,0,sizeof(inr));
		memset(head,0,sizeof(head));
		cin>>n>>m;
		for(int i=1;i<=n+3;i++)
			fa[i]=i;
		for(int i=1;i<=n+3;i++)
			dat[i]=make_pair(i,1);
		for(int i=1;i<=m;i++)
		{
			char opt;
			int u,v;
			cin>>opt;
			switch(opt)
			{
				case 'T':
					cin>>u;
					dat[u]=make_pair(n+1,1);
					break;
				case 'U':
					cin>>u;
					dat[u]=make_pair(n+2,1);
					break;
				case 'F':
					cin>>u;
					dat[u]=make_pair(n+3,1);
					break;
				case '-':
					cin>>u>>v;
					dat[u]=make_pair(dat[v].first,-1*dat[v].second);
					break;
				case '+':
					cin>>u>>v;
					dat[u]=make_pair(dat[v].first,dat[v].second);
					break;
			}
		}
		for(int i=1;i<=n+3;i++)
		{
			addedge(i,dat[i].first,dat[i].second);
			graph[dat[i].first].push_back(make_pair(i,dat[i].second));
			merge(i,dat[i].first);
		}
//		for(int i=1;i<=n+3;i++)
//			cout<<"#"<<i<<" "<<dat[i].first<<" "<<dat[i].second<<"\n";
		ans=0;
//		for(int i=1;i<=n+3;i++)
//			for(int j=head[i];j;j=edge[j].nxt)
//			{
//				int v=edge[j].v;
//				cout<<i<<"->"<<v<<"\n";
//			}
		for(int i=1;i<=n+3;i++)
		{
			r.clear();
			if(fa[i]!=i)
				continue;
//			cout<<i<<"--\n";
			findr(i);
//			for(auto p:r)
//				cout<<p<<" ";
//			cout<<"\n";
			if(r.size()==1)
			{
				if(r[0]==n+2)
				{
//					cout<<"YES";
//					cout<<ans<<"\n";
					ans+=dfs(r[0])-1;
//					cout<<ans<<">\n";
					continue;
				}
				if(r[0]==n+1||r[0]==n+3)
					continue;
			}
			if(!check(r[0],1))
			{
				for(auto p:r)
					ans+=dfs(p);
			}
		}
		for(int i=1;i<=n+3;i++)
			graph[i].clear();
		cout<<ans<<"\n";
		return 0;
	}
}
int c,t;
signed main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--)
		solve::main();
	return 0;
}