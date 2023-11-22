#include<bits/stdc++.h>
using namespace std;
int n,m,anss;
pair<int,int> a[100005];
vector<int> gr[100005],root;
stack<int> st;
bool vis[100005],in_stack[100005];
int dfs(int p,int fa)
{
	int ans=1;vis[p]=true;
	for(int i=0;i<gr[p].size();i++)
	{
		if(gr[p][i]==fa||gr[p][i]==p) continue;
		ans+=dfs(gr[p][i],p);
	}
	return ans;
}
void dfs2(int p,int fa)
{
	if(in_stack[p])
	{
		int cnt=0,flag=0;
		while(st.top()!=p)
		{
			root.push_back(st.top());cnt++;
			if(a[st.top()].second==-1) flag++;
			in_stack[st.top()]=false;
			st.pop();
		}
		if(a[st.top()].second==-1) flag++;
		root.push_back(st.top());cnt++;
		in_stack[st.top()]=false;
		st.pop();
		if(flag%2==0)
		{
			while(cnt--) root.pop_back();
		}
		return;
	}
	st.push(p);in_stack[p]=true;
	for(int i=0;i<gr[p].size();i++)
	{
		int son=gr[p][i];
		if(son==fa) continue;
		dfs2(son,p);
	}
	vis[p]=true;
	if(!st.empty()&&st.top()==p)
	{
		st.pop();in_stack[p]=false;
	}
	return;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	if(c>=3&&c<=6)
	{
		while(t--)
	{
		anss=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			a[i].first=i;
			a[i].second=1;
		}
		char v;int x,y;
		for(int i=1;i<=m;i++)
		{
			cin>>v;
			if(v=='+')
			{
				scanf("%d%d",&x,&y);
				a[x].first=a[y].first;a[x].second=1*a[y].second;
			}
			else if(v=='-')
			{
				scanf("%d%d",&x,&y);
				a[x].first=a[y].first;a[x].second=-1*a[y].second;
			}
			else
			{
				scanf("%d",&x);
				a[x].second=1;
				if(v=='T') a[x].first=n+1;
				else if(v=='F') a[x].first=n+2;
				else a[x].first=n+3;
			}
		}
		for(int i=1;i<=n;i++)
		{
			gr[a[i].first].push_back(i);
			gr[i].push_back(a[i].first);
		}
		anss+=dfs(n+3,0)-1;
		cout<<anss<<'\n';
		for(int i=1;i<=n+3;i++) gr[i].clear();
	}
	}
	else
	{
		while(t--)
	{
		anss=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			a[i].first=i;
			a[i].second=1;
		}
		char v;int x,y;
		for(int i=1;i<=m;i++)
		{
			cin>>v;
			if(v=='+')
			{
				scanf("%d%d",&x,&y);
				a[x].first=a[y].first;a[x].second=1*a[y].second;
			}
			else if(v=='-')
			{
				scanf("%d%d",&x,&y);
				a[x].first=a[y].first;a[x].second=-1*a[y].second;
			}
			else
			{
				scanf("%d",&x);
				a[x].second=1;
				if(v=='T') a[x].first=n+1;
				else if(v=='F') a[x].first=n+2;
				else a[x].first=n+3;
			}
		}
		for(int i=1;i<=n;i++)
		{
			gr[a[i].first].push_back(i);
			gr[i].push_back(a[i].first);
		}
		memset(vis,false,sizeof(vis));
		anss+=dfs(n+3,0)-1;
		dfs(n+1,0);dfs(n+2,0);
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				dfs2(i,0);
			}
		}
		for(int i=0;i<root.size();i++) anss+=dfs(root[i],0);
		cout<<anss<<'\n';
		for(int i=1;i<=n+3;i++) gr[i].clear();
		root.clear();
	}
	}
	return 0;
}
