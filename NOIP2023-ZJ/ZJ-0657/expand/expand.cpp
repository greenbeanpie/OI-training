#include<bits/stdc++.h>
using namespace std;
const int MAXN=5*1e5+10;
int ans[MAXN],x11[MAXN],y11[MAXN];
int c,q,n,m,x[MAXN],y[MAXN],fl;
bool solve()
{
	int minn=x[1],maxn=x[1];
	int minw=y[1],maxw=y[1];
	if((x[n]<=y[m]&&x[1]>y[1])||(x[n]>y[m]&&x[1]<=y[1])) return 0;
	for(int i=1;i<=n;i++) minn=min(minn,x[i]),maxn=max(maxn,x[i]);
	for(int i=1;i<=m;i++) minw=min(minn,y[i]),maxw=max(maxn,y[i]);
	if(minn<=minw&&maxn>maxw) return 0;
	int j=1;
	for(int i=1;i<=m;i++)
	{
		if(j>=n) break;
		if(x[j]>=y[i]) return 0;
		while(x[j]<y[i]&&j<=n) j++;
	}
	return 1;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int u,v,t1,t2;
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	for(int i=1;i<=m;i++) scanf("%d",&y[i]);
	for(int i=1;i<=n;i++) x11[i]=x[i];
	for(int i=1;i<=m;i++) y11[i]=y[i];
	ans[1]=solve();
	for(int k=1;k<=q;k++)
	{
		for(int i=1;i<=n;i++) x[i]=x11[i];
		for(int i=1;i<=m;i++) y[i]=y11[i];
		scanf("%d%d",&u,&v);
		for(int i=1;i<=u;i++)
		{
			scanf("%d%d",&t1,&t2);
			x[t1]=t2;
		}
		for(int i=1;i<=v;i++)
		{
			scanf("%d%d",&t1,&t2);
			y[t1]=t2;
		}
		ans[k+1]=solve();
	}
	for(int i=1;i<=q+1;i++) printf("%d",ans[i]);
	return 0;
}
