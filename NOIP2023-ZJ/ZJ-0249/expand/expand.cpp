#include <bits/stdc++.h>
using namespace std;
const int MAXN=500050;
int o,n,m,q,a[MAXN],b[MAXN],ans[MAXN],c[MAXN],d[MAXN];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&o,&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	if(1ll*(a[1]-b[1])*(a[n]-b[m])>0) ans[0]=1;
	else ans[0]=0;
	for(int i=1;i<=q;i++)
	{
		memcpy(c,a,4*(n+1));
		memcpy(d,b,4*(m+1));
		int u,v;
		scanf("%d%d",&u,&v);
		for(int i=1;i<=u;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			c[x]=y;
		}
		for(int i=1;i<=v;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			d[x]=y;
		}
		if(1ll*(c[1]-d[1])*(c[n]-d[m])>0) ans[i]=1;
		else ans[i]=0;
	}
	for(int i=0;i<=q;i++) printf("%d",ans[i]);
	return 0;
}