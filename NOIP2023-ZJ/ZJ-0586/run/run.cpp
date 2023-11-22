#include <bits/stdc++.h>
#define int long long
const int INF = 1e9+10;
const int N = 1010;
using namespace std;
int c,T;
int n,m,k,d,ans1,ans2;
int dp[N][N];
int sum[N];
bool vis[N];
struct node
{
	int x,y,v,l;
}a[100010];
bool cmp1(node a,node b)
{
	return a.v-d*a.y>b.v-d*b.y;
}
bool cmp2(node a,node b)
{
	return a.l<b.l;
}
void solve()
{
	ans1=0,ans2=0;
	cin>>n>>m>>k>>d;
	for(int i = 1;i<=m;i++) 
	{
		cin>>a[i].x>>a[i].y>>a[i].v,a[i].l=a[i].x-a[i].y+1;
	}
	memset(sum,0,sizeof sum);
	sort(a+1,a+m+1,cmp1);
	for(int i = 1;i<=m;i++)
	{
		if(sum[a[i].l-1]+a[i].y>k||a[i].y*d>a[i].v) continue;
		for(int j = a[i].l;j<=a[i].x;j++)
		{
			if(!vis[j]) ans1-=d;
			vis[j]=1;
		}
		memset(sum,0,sizeof sum);
		for(int i = 1;i<=n;i++) 
		{
			if(vis[i]) sum[i]=sum[i-1]+1;
			else sum[i]=0;
		}
		ans1+=a[i].v;
	}
	sort(a+1,a+m+1,cmp2);
	memset(vis,0,sizeof vis);
	memset(sum,0,sizeof sum);
	for(int i = 1;i<=m;i++)
	{
		if(sum[a[i].l-1]+a[i].y>k||a[i].y*d>a[i].v) continue;
		for(int j = a[i].l;j<=a[i].x;j++)
		{
			if(!vis[j]) ans2-=d;
			vis[j]=1;
		}
		memset(sum,0,sizeof sum);
		for(int i = 1;i<=n;i++) 
		{
			if(vis[i]) sum[i]=sum[i-1]+1;
			else sum[i]=0;
		}
		ans2+=a[i].v;
	}
	cout<<max(ans1,ans2)<<"\n";
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}