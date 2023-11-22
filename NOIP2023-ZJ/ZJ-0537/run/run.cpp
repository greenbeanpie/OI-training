#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,sum,t,a[10000005],u[10000005],maxx,c,m,d,k,x[100005],y[100005],v[100005],l[100005],r[100005];

void dfs(int y,int q)
{
	if(q>k)return;
	if(y>=n)
	{
		sum=0;ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				ans++;
				sum-=d;
			}else ans=0;
			if(ans>k)return;
		}
		for(int i=1;i<=m;i++)
		{
			t=0;
			for(int j=l[i];j<=r[i];j++)
				if(a[j]!=1)
				{
					t=1;
					break;
				}
			if(t==0)sum+=v[i];
		}
		if(sum>maxx)maxx=sum;
		return;
	}
	a[y+1]=0;
	dfs(y+1,0);
	if(u[y+1]==1)
	{
		a[y+1]=1;
		dfs(y+1,q+1);
	}
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	for(int zth=1;zth<=t;zth++)
	{
	if(c==1 || c==2)
	{
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++)
		{
			cin>>x[i]>>y[i]>>v[i];
			l[i]=x[i]-y[i]+1;
			r[i]=x[i];
			if(y[i]*d<v[i])for(int j=l[i];j<=r[i];j++)u[j]=1;
		}
		maxx=-1e18;
		for(int i=1;i<=n;i++)a[i]=0;
		a[1]=0;
		dfs(1,0);
		for(int i=1;i<=n;i++)a[i]=0;
		a[1]=1;
		dfs(1,1);
		cout<<maxx<<endl;
	}
	if(c==15 || c==16)
	{
		cin>>n>>m>>k>>d;
		ans=0;
		for(int i=1;i<=m;i++)
		{
			cin>>x[i]>>y[i]>>v[i];
			if(y[i]<=k&&y[i]*d<v[i])ans+=(v[i]-y[i]*d);
		}
		cout<<ans<<endl;
	}
	if(c==17 || c==18)
	{
		cin>>n>>m>>k>>d;
		ans=0;
		for(int i=1;i<=m;i++)
		{
			cin>>x[i]>>y[i]>>v[i];
			if(y[i]<=k&&y[i]*d<v[i])ans+=(v[i]-y[i]*d);
		}
		cout<<ans<<endl;
	}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}