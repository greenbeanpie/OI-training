#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+10;
int c,t,n,m,k,d,gz[N],ans,qzh[N];
struct node
{
	int x,l,w;
}tz[N];
int jy()
{
	int sum=0;
	qzh[0]=0;
	for(int i=1;i<=n;i++)
	{
		qzh[i]=qzh[i-1]+gz[i];
	}
	sum-=qzh[n]*d;
	for(int i=1;i<=m;i++)
	{
		if(qzh[tz[i].x]-qzh[tz[i].x-tz[i].l]==tz[i].l)
			sum+=tz[i].w;
	}
	return sum;
}
void dfs(int day,int la)
{
	if(day==n+1)
	{
		ans=max(ans,jy());
		return ;
	}
	gz[day]=0;
	dfs(day+1,k);
	if(la)
	{
		gz[day]=1;
		dfs(day+1,la-1);
	}
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{	
		ans=0;
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++)
		{
			cin>>tz[i].x>>tz[i].l>>tz[i].w;
		}
		dfs(1,k);
		cout<<ans<<endl;
	}
	return 0;
}
