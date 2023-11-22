#include<bits/stdc++.h>
using namespace std;
struct st{
	int x,y,v;
}s[10001];
int n,m,k,c,t,d,b[10001],ans=0;
void dfs(int xx,int yy,int zz)
{
	for(int i=1;i<=m;i++)
	{
		if(xx==s[i].x+1 && zz==s[i].y)
			{
				yy+=s[i].v;
			}
	}
	if(xx>=n+1)
	{
		ans=max(ans,yy);
		return;
	}
	
	if(zz<=k)
		dfs(xx+1,yy-d,zz+1);
	dfs(xx+1,yy,0);
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int kk=1;kk<=t;kk++)
	{
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++)
		{
			cin>>s[i].x>>s[i].y>>s[i].v;
		}
		dfs(1,0,0);
		cout<<ans<<"\n";
	}
	
	return 0;
}
