#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,a[100005],b[100005],ans=1e9;
struct node
{
	char c;
	int x,y;
} stp[100005];
void dfs(int now)
{
	if(now==n+1)
	{
		for(int i=1;i<=n;i++) b[i]=a[i];
		for(int i=1;i<=m;i++)
		{
			if(stp[i].c=='U') b[stp[i].x]=0;
			if(stp[i].c=='T') b[stp[i].x]=1;
			if(stp[i].c=='F') b[stp[i].x]=-1;
			if(stp[i].c=='+') b[stp[i].x]=b[stp[i].y];
			if(stp[i].c=='-') b[stp[i].x]=-b[stp[i].y];
		}
		bool flag=1;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=b[i])
			{
				flag=0;
				break;
			}
			if(a[i]==0) cnt++;
		}
		if(flag==1) ans=min(ans,cnt);
		return;
	}
	for(int i=-1;i<=1;i++)
	{
		a[now]=i;
		dfs(now+1);
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	if(c==1||c==2)
	{
		while(t--)
		{
			ans=1e9;
			cin>>n>>m;
			for(int i=1;i<=m;i++)
			{
				cin>>stp[i].c;
				if(stp[i].c=='U'||stp[i].c=='T'||stp[i].c=='F') cin>>stp[i].x;
				if(stp[i].c=='+'||stp[i].c=='-') cin>>stp[i].x>>stp[i].y;
			}
			dfs(1);
			cout<<ans<<"\n";
		}
	}
	if(c==3||c==4)
	{
		while(t--)
		{
			cin>>n>>m;
			ans=0;
			for(int i=1;i<=m;i++)
			{
				cin>>stp[i].c>>stp[i].x;
				if(stp[i].c=='U') ans++;
			}
			cout<<ans<<"\n";
		}
	}
	if(c==5||c==6)
	{
		while(t--)
		{
			cin>>n>>m;
			ans=0;
			for(int i=1;i<=n;i++) a[i]=0;
			for(int i=1;i<=m;i++)
			{
				cin>>stp[i].c;
				if(stp[i].c=='U')
				{
					cin>>stp[i].x;
					if(a[stp[i].x]==0)
					{
						a[stp[i].x]=1;
					}
				}
				if(stp[i].c=='+')
				{
					cin>>stp[i].x>>stp[i].y;
					a[stp[i].x]=a[stp[i].y];
				}
			}
			for(int i=1;i<=n;i++) if(a[i]==1) ans++;
			cout<<ans<<"\n";
		}
	}
	return 0;
}
