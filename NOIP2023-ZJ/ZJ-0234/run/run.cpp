#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2e5+5;
int p[MAXN],cnt;
int c,T,n,m,k,d,u[MAXN],v[MAXN],val[MAXN],del[MAXN];
vector<int> L[MAXN],R[MAXN];
ll ans,f[3005][3005],g[200005][105];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-'){f=-f;}ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	return x*f;
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read(),T=read();
	if(c<=11)
	{
		while(T--)
		{
			
			n=read(),m=read(),k=read(),d=read();
			for(int i=1;i<=m;i++)
			{
				u[i]=read(),v[i]=read(),val[i]=read(),del[i]=v[i]-1;
				swap(u[i],v[i]);
				u[i]=v[i]-u[i]+1;
				p[++cnt]=u[i],p[++cnt]=v[i];
			}
			sort(p+1,p+1+cnt);
			cnt=unique(p+1,p+1+cnt)-p-1;
			for(int i=1;i<=cnt;i++)L[i].clear(),R[i].clear();
			for(int i=1;i<=m;i++)
			{
				u[i]=lower_bound(p+1,p+1+cnt,u[i])-p;
				v[i]=lower_bound(p+1,p+1+cnt,v[i])-p;
				L[u[i]].push_back(i);
				R[v[i]].push_back(i);
			}
			for(int i=0;i<=cnt;i++)for(int j=0;j<=k;j++)f[i][j]=-0x7f7f7f7f;
			f[0][0]=0;
			for(int i=1;i<=cnt;i++)
			{
				for(int j=0;j<=k;j++) f[i][0]=max(f[i][0],f[i-1][j]);
				for(int j=1;j<p[i]-p[i-1];j++) f[i][j]=max(f[i][j],f[i][0]-1ll*j*d);
				for(int j=0;j<=k;j++)
				{
					if(j+p[i]-p[i-1]<=k)
					{
						int w=j+p[i]-p[i-1];
						f[i][w]=max(f[i][w],f[i-1][j]-1ll*d*(p[i]-p[i-1]));	
					}
					else break;
				}
				int len=R[i].size();
				for(int j=0;j<len;j++)
				{
					int id=R[i][j];
					for(int o=del[id]+1;o<=k;o++)
					{
						f[i][o]+=val[id];
					}
				}
			}
			ans=0;
			for(int i=0;i<=k;i++) ans=max(ans,f[cnt][i]);
			printf("%lld\n",ans);
		}
	}
	else if(c==15||c==16)
	{
		while(T--)
		{
			n=read(),m=read(),k=read(),d=read();
			for(int i=1;i<=m;i++)
			{
				u[i]=read(),v[i]=read(),val[i]=read(),del[i]=v[i]-1;
				swap(u[i],v[i]);
				u[i]=v[i]-u[i]+1;
				p[++cnt]=u[i],p[++cnt]=v[i];
			}
			sort(p+1,p+1+cnt);
			cnt=unique(p+1,p+1+cnt)-p-1;
			for(int i=1;i<=cnt;i++)L[i].clear(),R[i].clear();
			for(int i=1;i<=m;i++)
			{
				u[i]=lower_bound(p+1,p+1+cnt,u[i])-p;
				v[i]=lower_bound(p+1,p+1+cnt,v[i])-p;
				L[u[i]].push_back(i);
				R[v[i]].push_back(i);
			}
			for(int i=0;i<=cnt;i++)for(int j=0;j<=k;j++)g[i][j]=-0x7f7f7f7f;
			g[0][0]=0;
			for(int i=1;i<=cnt;i++)
			{
				for(int j=0;j<=k;j++) g[i][0]=max(g[i][0],g[i-1][j]);
				for(int j=1;j<p[i]-p[i-1];j++) g[i][j]=max(g[i][j],g[i][0]-1ll*j*d);
				for(int j=0;j<=k;j++)
				{
					if(j+p[i]-p[i-1]<=k)
					{
						int w=j+p[i]-p[i-1];
						g[i][w]=max(g[i][w],g[i-1][j]-1ll*d*(p[i]-p[i-1]));	
					}
					else break;
				}
				int len=R[i].size();
				for(int j=0;j<len;j++)
				{
					int id=R[i][j];
					for(int o=del[id]+1;o<=k;o++)
					{
						g[i][o]+=val[id];
					}
				}
			}
			ans=0;
			for(int i=0;i<=k;i++) ans=max(ans,g[cnt][i]);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
