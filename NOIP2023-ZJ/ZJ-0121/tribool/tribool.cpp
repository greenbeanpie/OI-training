#include <bits/stdc++.h>
using namespace std;
int a[300010],nxt[300010][2],val[300010],ans=0,n,m,tmp[300010],t=0;
bool vis[200010];
vector<int> q[200010];
void dfs1(int x,int w)
{
	if(x>n) return;
	if(val[x]>=0)
	{
		if((w-val[x])%2==1) for(int i=x;a[i]!=2*n+2;i=nxt[i][0]) a[i]=2*n+2;
		return;
	}
	tmp[++t]=x;
	val[x]=w;if(!vis[nxt[x][0]]) dfs1(nxt[x][0],w+nxt[x][1]);
}
void dfs2(int x)
{
	vis[x]=true;ans++;
	for(int i=0;i<q[x].size();i++) if(!vis[q[x][i]]) dfs2(q[x][i]);
}
int main()
{
	freopen("tribool.in","r",stdin);freopen("tribool.out","w",stdout);
	int sid,T;scanf("%d%d",&sid,&T);while(T--)
	{
		scanf("%d%d",&n,&m);for(int i=1;i<=n;i++) a[i]=(i<<1)-1;
		for(int i=1;i<=m;i++)
		{
			char op;int x,y;op=getchar();op=getchar();
			if(op=='T') scanf("%d",&x),a[x]=2*n+1;
			else if(op=='F') scanf("%d",&x),a[x]=2*n;
			else if(op=='U') scanf("%d",&x),a[x]=2*n+2;
			else if(op=='+') scanf("%d%d",&x,&y),a[x]=a[y];
			else scanf("%d%d",&x,&y),a[x]=a[y]^1;
		}
		for(int i=1;i<=n;i++) nxt[i][0]=(a[i]+2)>>1,nxt[i][1]=(a[i]%2==0)?1:0,val[i]=-1;
		for(int i=1;i<=n;i++) if(val[i]==-1)
		{
			t=0;dfs1(i,0);
			for(int i=1;i<=t;i++) vis[tmp[i]]=1;
		}
		for(int i=1;i<=n+2;i++) vis[i]=false;
		for(int i=1;i<=n;i++) q[(a[i]+2)>>1].push_back(i);
		ans=0;dfs2(n+2);printf("%d\n",ans-1);
		for(int i=1;i<=n+2;i++) vis[i]=false,q[i].clear();
	}
	return 0;
}