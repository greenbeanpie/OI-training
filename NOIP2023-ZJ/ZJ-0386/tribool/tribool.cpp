#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') f=(ch=='-')?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int N=200105;
int now[N],low[N],dfn[N],cnt,top,ttt,col[N],zhi[N],st[N],n,m,ans,v[N],fa[N];
bool nn[N];
int ver[N<<1],ne[N<<1],head[N],tot;
void add(int x,int y){ver[++tot]=y,ne[tot]=head[x],head[x]=tot;return;}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void dfs(int x,int k)
{
//	cout<<x<<endl;
	low[x]=dfn[x]=++cnt,st[++top]=x,v[x]=k;
	for(int i=head[x];i;i=ne[i])
	{
		int y=ver[i];
		if(v[y]&&v[y]!=k) continue;
		if(!dfn[y]) dfs(y,k),low[x]=min(low[x],low[y]);
		else low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x])
	{
		ttt++,zhi[ttt]=0;
//		cout<<ttt<<":";
		while(st[top+1]!=x)
		{
			int z=st[top--];
			col[z]=ttt;
//			cout<<z<<' ';
			if(now[z]>n) zhi[ttt]=now[z];
		}
//		cout<<zhi[ttt];
//		puts("");
	}
	return;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int C=read(),T=read();
	while(T--)
	{
		n=read(),m=read(),ans=0;
		ttt=cnt=top=tot=0,memset(head,0,sizeof(head)),memset(dfn,0,sizeof(dfn)),memset(v,0,sizeof(v)),memset(st,0,sizeof(st));
		for(int i=1;i<=n;i++) now[i]=i,nn[i]=false;
		for(int i=n+n;i>n;i--) now[i]=i-n,nn[i]=true;
		while(m--)
		{
			char opt;
			scanf(" %c",&opt);
			if(opt=='T') now[read()]=n+1;
			else if(opt=='F') now[read()]=n+2;
			else if(opt=='U') now[read()]=n+3;
			else if(opt=='+')
			{
				int x=read(),y=read();
				now[x]=now[y],nn[x]=nn[y];
			}
			else if(opt=='-')
			{
				int x=read(),y=read();
				if(now[y]==n+3) now[x]=n+3;
				else if(now[y]==n+2) now[x]=n+1;
				else if(now[y]==n+1) now[x]=n+2;
				else now[x]=now[y],nn[x]=!nn[y];
			}
		}
//		for(int i=1;i<=n;i++) cout<<now[i]<<' '<<nn[i]<<endl;
		for(int i=1;i<=n;i++)
			if(now[i]<=n)
			{
				if(nn[i]) add(i,now[i]+n),add(i+n,now[i]);
				else add(i,now[i]),add(i+n,now[i]+n);
			}
			else
			{
				if(now[i]==n+1) now[i+n]=n+2;
				else if(now[i]==n+2) now[i+n]=n+1;
				else now[i+n]=n+3;
			}
		for(int i=(n<<1);i>=1;i--)
			if(!dfn[i])
				dfs(i,i);
		for(int i=1;i<=n;i++)
			if(col[i]==col[i+n])
				zhi[col[i]]=n+3;
		for(int i=1;i<=ttt;i++) fa[i]=i;
		for(int i=1;i<=n;i++)
		{
			if(now[i]<=n)
			{
				if(nn[i])
				{
					int x=col[i],y=col[now[i]+n];
					if(find(x)!=find(y)) fa[fa[x]]=y;
					x=col[i+n],y=col[now[i]];
					if(find(x)!=find(y)) fa[fa[x]]=y;
				}
				else
				{
					int x=col[i],y=col[now[i]];
					if(find(x)!=find(y)) fa[fa[x]]=y;
					x=col[i+n],y=col[now[i]+n];
					if(find(x)!=find(y)) fa[fa[x]]=y;
				}
			}
		}
		for(int i=1;i<=n;i++)
			if(zhi[find(col[i])]==n+3)
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}
