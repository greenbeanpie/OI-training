#include <bits/stdc++.h>
const int N=3e5+5;
using namespace std;
namespace sub1
{
	int n,m;
	int ans;
	struct ask{char type;int x,y;}q[N];
	int minn;
	char a[N],b[N];
	void check()
	{
		for(int i=1;i<=n;i++)b[i]=a[i];
		for(int i=1;i<=m;i++)
		{
			if(q[i].type=='+')b[q[i].x]=b[q[i].y];
			else if(q[i].type=='-')
			{
				char t1=b[q[i].y];
				if(t1=='T')b[q[i].x]='F';
				if(t1=='F')b[q[i].x]='T';
				if(t1=='U')b[q[i].x]='U';
			}
			else b[q[i].x]=q[i].type;
		}
		for(int i=1;i<=n;i++)if(a[i]!=b[i])return;
		int res=0;
		for(int i=1;i<=n;i++)res+=(a[i]=='U');
		minn=min(minn,res);
	}
	void dfs(int x)
	{
		if(x==n+1){check();return;}
		a[x]='T';dfs(x+1);
		a[x]='F';dfs(x+1);
		a[x]='U';dfs(x+1);
	}
	void solve()
	{
		minn=1e9;
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>q[i].type;
			if(q[i].type=='+'||q[i].type=='-')
			cin>>q[i].x>>q[i].y;
			else cin>>q[i].x;
		}
		dfs(1);
		cout<<minn<<'\n';
	}
}
namespace sub2
{
	int n,m;
	int ans;
	char w[N];
	char type;int x,y;
	void solve()
	{
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=m;i++)cin>>type>>x,w[x]=type;
		for(int i=1;i<=n;i++)ans+=(w[i]=='U');
		cout<<ans<<'\n';
	}
}
namespace sub3
{
	int n,m;
	basic_string<int>e[N];
	char w[N];
	int last[N];
	int vv[N],v[N];
	void run(int x)
	{
		w[x]='U';
		if(vv[x])return;
		vv[x]=1;
		if(v[x])run(v[x]);
		for(auto y:e[x]){w[y]=w[x];run(y);}
	}
	int ans,cnt;
	char type;int x,y;
	void solve()
	{
		memset(v,0,sizeof(v));
		memset(vv,0,sizeof(vv));
		for(int i=1;i<=cnt;i++)e[i].clear();
		ans=0;
		cin>>n>>m;
		fill(w+1,w+n+1,'T');cnt=n;
		iota(last+1,last+n+1,1);
		for(int i=1;i<=m;i++)
		{
			cin>>type;
			if(type=='+')
			{
				cin>>x>>y;
				int temp=last[y];
				w[(last[x]=++cnt)]=w[temp];
				e[temp]+=cnt;
			}
			else{cin>>x;w[(last[x]=++cnt)]=type;}
		}
		for(int i=1;i<=n;i++)v[last[i]]=i;
		for(int i=1;i<=n;i++)
		if(w[i]!=w[last[i]])
		{w[i]='U';run(i);}
		for(int i=1;i<=n;i++)ans+=(w[i]=='U');
		cout<<ans<<'\n';
	}
}
namespace sub45
{
	int n,m;
	struct edge{int y,z;};
	basic_string<edge>e[N];
	char w[N];
	int last[N];
	char type;int x,y;
	void run(int x)
	{
		for(auto [y,z]:e[x])
		{
			if(z==1)w[y]=w[x];
			if(z==-1)
			{
				if(w[x]=='T')w[y]='F';
				if(w[x]=='F')w[y]='T';
				if(w[x]=='U')w[y]='U';
			}
			run(y);
		}
	}
	int ans,cnt;
	void solve()
	{
		for(int i=1;i<=cnt;i++)e[i].clear();
		ans=0;
		cin>>n>>m;
		fill(w+1,w+n+1,'T');cnt=n;
		iota(last+1,last+n+1,1);
		for(int i=1;i<=m;i++)
		{
			cin>>type;
			if(type=='+')
			{
				cin>>x>>y;
				int temp=last[y];
				w[(last[x]=++cnt)]=w[temp];
				e[temp]+=(edge){cnt,1};
			}
			else if(type=='-')
			{
				cin>>x>>y;
				int temp=last[y];char T1=w[temp];
				if(T1=='T')w[(last[x]=++cnt)]='F';
				if(T1=='F')w[(last[x]=++cnt)]='T';
				if(T1=='U')w[(last[x]=++cnt)]='U';
				e[temp]+=(edge){cnt,-1};
			}
			else{
				cin>>x;
				w[(last[x]=++cnt)]=type;
			}
		}
		
		for(int i=1;i<=n;i++)
		if(w[i]!=w[last[i]]&&w[last[i]]!='U')
		{
			if(w[i]=='T')w[i]='F';
			else if(w[i]=='F')w[i]='T';
			run(i);
		}
		for(int i=n;i>=1;i--)
		if(w[i]!=w[last[i]]&&w[last[i]]!='U')
		{
			if(w[i]=='T')w[i]='F';
			else if(w[i]=='F')w[i]='T';
			run(i);
		}
		
		for(int i=1;i<=n;i++)
		if(w[i]!=w[last[i]])
		{
			w[i]='U';run(i);
		}
		for(int i=n;i>=1;i--)
		if(w[i]!=w[last[i]])
		{
			w[i]='U';run(i);
		}
		for(int i=1;i<=n;i++)ans+=(w[i]=='U');
		cout<<ans<<'\n';
	}
}
int id,T;
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>id>>T;
	while(T--)
	{
		if(id<=2)sub1::solve();
		else if(id<=4)sub2::solve();
		else if(id<=6)sub3::solve();
		else if(id<=10)sub45::solve();
	}
}
