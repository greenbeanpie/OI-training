#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
const int T=1000000,F=1000001,U=1000002;
int n,m,f[100005],x[200005];
int find(int u){return x[u]==u?u:x[u]=find(x[u]);}
vector <int> g[100005];
void work()
{
	cin>>n>>m;
	rep(i,1,n)f[i]=i;
	rep(i,1,n)g[i].clear();
	
	rep(t,1,m)
	{
		int i,j;char v;
		cin>>v;
		if(v=='T'){cin>>i;f[i]=T;}
		if(v=='F'){cin>>i;f[i]=F;}
		if(v=='U'){cin>>i;f[i]=U;}
		if(v=='+'){cin>>i>>j;f[i]=f[j];}
		if(v=='-')
		{
			cin>>i>>j;
			if(f[j]==T)f[i]=F;
			else if(f[j]==F)f[i]=T;
			else if(f[j]==U)f[i]=U;
			else f[i]=-f[j];
		}
	}
//	rep(i,1,n)cout<<f[i]<<' ';
//	cout<<endl;
	
	rep(i,1,2*n)x[i]=i;
	rep(i,1,n)if(f[i]==-i)f[i]=U;
	rep(i,1,n)if(f[i]<=n)
	{
		int u=find(i),v=find(abs(f[i]));
		int fg=(u<=n&&v<=n)||(u>n&&v>n);
		if(u>n)u-=n;
		if(v>n)v-=n;
		if(fg)
		{
			if(f[i]<0)
			{
				x[u]=x[v+n];
				x[u+n]=x[v];
			}
			else
			{
				x[u]=x[v];
				x[u+n]=x[v+n];
			}
		}
		else
		{
			if(f[i]>0)
			{
				x[u]=x[v+n];
				x[u+n]=x[v];
			}
			else
			{
				x[u]=x[v];
				x[u+n]=x[v+n];
			}
		}
	}
//	rep(i,1,n)cout<<find(i)<<' ';
//	cout<<endl;
//	rep(i,n+1,2*n)cout<<find(i)<<' ';
//	cout<<endl;
	
	rep(i,1,n)if(find(i)==find(i+n))f[i]=U;
	queue<int> q;
	rep(i,1,n)if(f[i]<=n)
		g[abs(f[i])].push_back(i);
	rep(i,1,n)if(f[i]==U)q.push(i);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int v:g[u])
		{
			if(f[v]!=U)
			{
				f[v]=U;
				q.push(v);
			}
		}
	}
	int ans=0;
	rep(i,1,n)ans+=(f[i]==U);
	
	cout<<ans<<endl;
}
signed main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
		work();	
}