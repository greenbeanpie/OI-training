#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node
{
	int l,r,w;
};
int t,ans,n,m,k,d,a[N],b[N];
node q[N];
void chk()
{
	int ret=0,x=1;
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	ret=-b[n]*d;
	for(int i=1;i<=m;i++)
	{
		if(b[q[i].r]-b[q[i].l-1]==q[i].r-q[i].l+1)
		{
			ret+=q[i].w;
		}
	}
	ans=max(ans,ret);
}
void dfs(int x,int s)
{
	if(x>n)
	{
		chk();
		return;
	}
	a[x]=0;
	dfs(x+1,0);
	if(s<k)
	{
		a[x]=1;
		dfs(x+1,s+1);
	}
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int x,y,z;
	cin>>x>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++)
		{
			cin>>x>>y>>z;
			y=x-y+1;
			q[i].l=y;
			q[i].r=x;
			q[i].w=z;
		}
		dfs(1,0);
		cout<<ans<<"\n";
	}
}