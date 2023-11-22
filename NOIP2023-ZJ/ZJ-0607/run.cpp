#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,T;
int n,m,k,d;
struct stu
{
	int l,r,v;
}clg[N];
int cnt,ans;
void solveB()
{
	for(int i=1;i<=cnt;i++)
	{
		int t=clg[i].r-clg[i].l+1;
		if(t*d<clg[i].v) ans+=clg[i].v-t*d;
	}
	printf("%d",ans);
	return;
}
void solve()
{
	bool vis[N];
	memset(vis,0,sizeof vis);
	for(int i=1;i<=cnt;i++)
	{
		for(int j=clg[i].l;j<=clg[i].r;j++)
		{
			if(vis[j]) continue;
			ans-=d;
			vis[j]=1;
		}
		ans+=clg[i].v;
	}
	printf("%d",ans);
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=m;i++)
		{
			int x,y,v;
			scanf("%d%d%d",&x,&y,&v);
			if( y > x || y > k ) continue;
			clg[++cnt].r=x; clg[cnt].l=x-y+1; clg[cnt].v=v;
		}
	}
	if(c==17||c==18) { solveB(); return 0; }
	else { solve(); return 0; }
	return 0;
}
//r-l+1=x-x+y-1+1=y