#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,k,d,l[101],r[101],v[101],a[101],sum[101],ans;
void dfs(int i,int lian,int w)
{
	if(i<n)
	{
		if(lian<k)a[i+1]=1,dfs(i+1,lian+1,w-d);
		a[i+1]=0,dfs(i+1,0,w);	
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			sum[i]=sum[i-1]+a[i];
		//	cout<<a[i];
		}
		for(int i=1;i<=m;i++)
		{
			if(sum[r[i]]-sum[l[i]-1]==r[i]-l[i]+1)w+=v[i];
		//	cout<<sum[r[i]]-sum[l[i]-1]<<" "<<r[i]-l[i]+1<<endl;
		}
	//	cout<<" "<<w<<endl;
		ans=max(ans,w);
	}
	
	
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>m>>k>>d;
		ans=0;
		for(int j=1;j<=m;j++)
		{
			int x;
			cin>>r[j]>>x>>v[j];
			l[j]=r[j]-x+1;
		}
		dfs(1,0,0);
		a[1]=1;
		dfs(1,1,-d);
		cout<<ans<<endl;
	}
}

