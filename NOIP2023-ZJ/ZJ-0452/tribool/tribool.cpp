#include<bits/stdc++.h>
using namespace std;
const int p=1000001;
int c,t,n,m,cnt;
int a[10001],b[10001];
void dfs1(int x)
{
		if(a[x]==-x || a[x]==0)
		{
			a[x]=0;
			for(int j=1;j<=n;j++)
			{
				if((a[j]==x || a[j]==-x) && !b[j])
				{
					a[j]=0;
					b[j]=1;
					dfs1(j);
				}
			}
		}
}
void dfs2(int x)
{
	if(a[x]==0)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]==x && b[j])
			{
				a[j]=0;
				b[j]=1;
				dfs2(j);
			}
		}
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	if(c==3 || c==4)
	{
		for(int k=1;k<=t;k++)
		{
			memset(a,0,sizeof(a));
			cin>>n>>m;
			cnt=0;
			for(int i=1;i<=m;i++)
			{	
				char v[10];
				int x;
				cin>>v>>x;
				if(v[0]=='U')
					a[x]=1;
				else
					a[x]=0;
			}
			for(int i=1;i<=n;i++)
			{
				if(a[i])
					cnt++;
			}
					
			cout<<cnt<<"\n";
		}
		
	}
	else if(c==5 || c==6)
	{
		for(int k=1;k<=t;k++)
		{
			memset(a,0,sizeof(a));
			cin>>n>>m;
			cnt=0;
			for(int i=1;i<=m;i++)
			{	
				char v[10];
				int x,y;
				cin>>v;
				if(v[0]=='U')
				{
					cin>>x;
					a[x]=1;
				}
				else
				{
					cin>>x>>y;
					a[x]=a[y];
				}	
			}
			for(int i=1;i<=n;i++)
				dfs2(i);
			for(int i=1;i<=n;i++)
			{
				if(a[i])
					cnt++;
			}
					
			cout<<cnt<<"\n";
		}
	}
	else
	{
		for(int k=1;k<=t;k++)
		{
			cnt=0;
			cin>>n>>m;
			for(int i=1;i<=n;i++)
				a[i]=i;
			for(int i=1;i<=m;i++)
			{
				
				int x, y;
				char v;
				cin>>v;
				if(v=='+')
				{
					cin>>x>>y;
					a[x]=a[y];
				}
				if(v=='-')
				{
					cin>>x>>y;
					a[x]=-a[y];
				}
				if(v=='U')
				{
					cin>>x;
					a[x]=0;
				}
				if(v=='T')
				{
					cin>>x;
					a[x]=p;
				}
				if(v=='F')
				{
					cin>>x;
					a[x]=-p;
				}
			}
			for(int i=1;i<=n;i++)
			{
				dfs1(i);
			}
			for(int i=1;i<=n;i++)
			{
				if(!a[i])
					cnt++;
			}
			cout<<cnt<<"\n";
		}
	}
	
	return 0;
}
