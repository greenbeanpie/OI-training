//Private Eye,dancing with the wind.The last time.
#include<bits/stdc++.h>
using namespace std;

#define MAXN 100015

inline int read()
{
	char c(getchar());
	int s(0);
	while(c<48) c=getchar();
	while(c>47) s=(s<<1)+(s<<3)+(c^48),c=getchar();
	return s;
}

namespace Dimly{
	int n,m,ans,a[MAXN],fr[MAXN],ty[MAXN],head[MAXN],nxt[MAXN],ver[MAXN],ed[MAXN],tot;
	bool vis[MAXN],qwq[MAXN];
	char s[15];
	inline void add(int x,int y,int z)
	{
		ver[++tot]=y,nxt[tot]=head[x],head[x]=tot,ed[tot]=z;
		fr[y]=x,ty[y]=z;
	}
	inline void dfs(int x,int k)
	{
		vis[x]=1;
		if(k==1) ans++;
		for(int i=head[x];i;i=nxt[i])
		{
			int y=ver[i];
			if(vis[y]) continue;
			dfs(y,k);
		}
	}
	inline int findroot(int x)
	{
		if(!fr[x] or qwq[fr[x]]) return x;
		qwq[x]=1;return findroot(fr[x]);
	}
	void solve()
	{
		n=read(),m=read(),tot=0,ans=-1;
		for(int i=1;i<=n+3;i++)
			a[i]=i,head[i]=fr[i]=ty[i]=vis[i]=qwq[i]=0;
		for(int i=1;i<=m;i++)
		{
			int s1,s2;
			scanf("%s",s),s1=read();
			if(s[0]=='T') a[s1]=n+1;
			if(s[0]=='F') a[s1]=n+2;
			if(s[0]=='U') a[s1]=n+3;
			if(s[0]=='+') s2=read(),a[s1]=a[s2];
			if(s[0]=='-') s2=read(),a[s1]=-a[s2];
		}
//		for(int i=1;i<=n+3;i++)
//			printf("%d ",a[i]);
//		putchar('\n');
		for(int i=1;i<=n+3;i++)
		{
			if(a[i]==i) continue;
			if(a[i]==-i) add(n+3,i,1);
			else if(a[i]>0) add(a[i],i,1);
			else add(-a[i],i,-1);
		}
		dfs(n+1,0),dfs(n+2,0),dfs(n+3,1);
		for(int i=1;i<=n+3;i++)
			if(!vis[i])
			{
				int r=findroot(i),s=fr[r],now=0;
//				printf("(%d:%d)\n",i,r);
				if(s==0)
				{
					dfs(r,0);
					continue;
				}
				if(ty[r]==-1) now^=1;
				while(s!=r)
				{
					if(ty[s]==-1) now^=1;
					s=fr[s];
				}
				if(now==0) dfs(r,0);
				else dfs(r,1);
			}
		printf("%d\n",ans);
	}
}

int c,T;

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read(),T=read();
	while(T--)
		Dimly::solve();
	return 0;
}
