#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int maxm=1e3+10;
typedef long long ll;
int cs,t,n,m,k;
ll d;
int tot=0;
int a[maxn];
struct node
{
	int r,st,v;
}p[maxn];
bool cmp(node a,node b)
{
	if(a.r==b.r)
		return a.st<b.st;
	return a.r<b.r;
}
ll dp[maxm][maxm];
void calc()
{
	memset(dp,-0x3f3f3f3f,sizeof(dp));
	int kr=1;
	dp[1][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
			dp[i][0]=max(dp[i][0],dp[i-1][j]);
		while(p[kr].r<i&&kr<=tot)
			kr++;
		ll sum=0;
		for(int j=1;j<=k;j++)
		{
			while(p[kr].r==i&&kr<=tot&&p[kr].st<=j)
				sum+=p[kr].v,kr++;
			dp[i][j]=dp[i-1][j-1]-d+sum;
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=k;j++)
//			cout<<dp[i][j]<<" ";
//		cout<<endl;
//	}
	ll ans=0;
	for(int i=0;i<=k;i++)
		ans=max(ans,dp[n][i]);
	printf("%lld\n",ans);
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d %d",&cs,&t);
	while(t--)
	{
		tot=0;
		scanf("%d %d %d %lld",&n,&m,&k,&d);
		for(int i=1;i<=m;i++)
		{
			int x,y,v;
			scanf("%d %d %d",&x,&y,&v);
			if(y<=k)
				p[++tot].r=x,p[tot].st=y,p[tot].v=v;
		}
		sort(p+1,p+tot+1,cmp);
		calc();
	}
	return 0;
}
/*
1 1
6 5 4 0
3 2 1
6 4 2
6 2 2
2 2 1
6 3 2
*/
