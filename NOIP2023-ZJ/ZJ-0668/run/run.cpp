#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,m,k,d,cnt[100005],ans;
struct node
{
	int x,y,v;
} tz[100005];
bool cmp(node a,node b)
{
	return a.y<b.y;
}
void dfs(int now,int e,int kk)
{
	if(now==n)
	{
		ans=max(ans,e);
		return;
	}
	int p=e;
	for(int i=1;i<=m;i++)
	{
		if(tz[i].y==now&&kk>=tz[i].y-tz[i].x+1)
		{
			p+=tz[i].v;
		}
	}
	if(kk+1<=k)
	{
		cnt[now+1]=1;
		dfs(now+1,p-d,kk+1);
		cnt[now+1]=0;
		dfs(now+1,p,0);
	}
	else
	{
		cnt[now+1]=0;
		dfs(now+1,p,0);
	}
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	if(c!=17&&c!=18)
	{
		while(t--)
		{
			ans=-1e9;
			cin>>n>>m>>k>>d;
			for(int i=1;i<=m;i++)
			{
				int xx,yy,zz;
				cin>>xx>>yy>>zz;
				tz[i].x=xx-yy+1,tz[i].y=xx,tz[i].v=zz;
			}
			sort(tz+1,tz+1+m,cmp);
			dfs(0,0,0);
			cout<<ans<<"\n";
		}
	}
	if(c==17||c==18)
	{
		while(t--)
		{
			ans=0;
			cin>>n>>m>>k>>d;
			for(int i=1;i<=m;i++)
			{
				int xx,yy,zz;
				cin>>xx>>yy>>zz;
				if(yy*d<zz)
				{
					ans+=zz-yy*d;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
