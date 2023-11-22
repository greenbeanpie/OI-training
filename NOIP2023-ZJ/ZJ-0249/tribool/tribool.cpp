#include <bits/stdc++.h>
using namespace std;
const int MAXN=100010;
int o,t,a[MAXN],b[MAXN],c[MAXN],vis[MAXN],ans,vis1[MAXN];
int head[MAXN],cnt,sum,vis2[MAXN],f[MAXN],g[MAXN];
struct node{
	int to,next;
}e[MAXN];
void addedge(int u,int v)
{
	e[++cnt].next=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}
void dfs(int u,int cmp)
{
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(!vis[v]) vis[v]=1,ans+=cmp,dfs(v,cmp);
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&o,&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) b[i]=1,c[i]=i;
		for(int i=1;i<=m;i++)
		{
			char s;
			int x,y;
			cin>>s;
			if(s=='T')
			{
				scanf("%d",&x);
				a[x]=3,b[x]=c[x]=0;
			}
			else if(s=='U')
			{
				scanf("%d",&x);
				a[x]=2,b[x]=c[x]=0;
			}
			else if(s=='F')
			{
				scanf("%d",&x);
				a[x]=1,b[x]=c[x]=0;
			}
			else if(s=='+')
			{
				scanf("%d%d",&x,&y);
				if(a[y]) a[x]=a[y],b[x]=c[x]=0;
				else a[x]=0,b[x]=b[y],c[x]=c[y];
			}
			else if(s=='-')
			{
				scanf("%d%d",&x,&y);
				if(a[y]) a[x]=4-a[y],b[x]=c[x]=0;
				else a[x]=0,b[x]=-b[y],c[x]=c[y];
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i])
			c[i]=n+a[i];
		}
		vis[n+1]=vis[n+2]=vis[n+3]=1;
		for(int i=1;i<=n;i++)
		{
			if(c[i]>n) g[i]=-1;
			else g[i]=(1-b[i])/2;
			addedge(c[i],i);
		}
		dfs(n+1,0),dfs(n+2,1),dfs(n+3,0);
		for(int i=1;i<=n;i++)
		{
			if(vis1[i]||vis[i]||f[i]) continue;
			int j=i,k;
			while(!vis1[j]&&!vis[j]&&!f[j]) vis1[j]=1;j=c[j];
			if(f[j])
			{
				k=i;
				while(k!=j) f[k]=f[j],k=c[k];
			}
			else
			{
				k=j,sum++;
				int sum1=0;
				sum1+=g[k];
				f[k]=sum,k=c[k];
				while(!f[k])
				{
					sum1+=g[k];
					f[k]=sum,k=c[k];
				}
				if(sum1&1) vis2[sum]=1; 
				k=i;
				while(k!=j) f[k]=sum,k=c[k];
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]&&vis2[f[i]])
			ans++;
		}
		printf("%d\n",ans);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		memset(head,0,sizeof(head));
		memset(vis,0,sizeof(vis));
		memset(vis1,0,sizeof(vis1));
		memset(vis2,0,sizeof(vis2));
		ans=cnt=sum=0;
	}
	return 0;
}