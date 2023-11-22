#include<bits/stdc++.h>
using namespace std;
#define file(s) (freopen(#s".in","r",stdin),freopen(#s".out","w",stdout))
#define ll long long
#define il inline
#define ret return
#define cst const
#define gc getchar
#define pc putchar
#define pb push_back
#define pr pair<int,int>
#define prpr make_pair
#define fir first
#define sec second
il ll rd()
{
	ll res=0;int lab=1;char ch=gc();
	while((ch<'0'||ch>'9')&&(ch^EOF))lab^=(ch=='-'),ch=gc();
	while(ch>='0'&&ch<='9')res=res*10+(ch&15),ch=gc();
	ret lab?res:-res;
}
il void prt(ll x,char tail='\n')
{
	static int s[71];int t=0;
	if(x<0)pc('-'),x=-x;
	do{s[++t]=x%10;x/=10;}while(x);
	while(t)pc(s[t--]|48);
	if(tail)pc(tail);
}
namespace Sinclair
{
	int n,m,r[100005],v[100005],val[100005],fa[100005],en,h[100005];
	int dis[100005],rt[100005],vr[100005];
	struct edge{int nxt,to,w;}e[200005];
	il void adde(int u,int v,int w){e[++en]=(edge){h[u],v,w};h[u]=en;}
	il void addl(int u,int v,int w){adde(u,v,w);adde(v,u,w);}
	il int tr(int x){ret x==3?x:3-x;}
	il int ti(char x){ret x=='T'?1:(x=='F'?2:3);}
	il char rdc()
	{
		char ch=gc();
		while(ch!='T'&&ch!='F'&&ch!='U'&&ch!='+'&&ch!='-'&&ch!=EOF)ch=gc();
		ret ch;
	}
	il int gf(int x){while(x^fa[x])x=fa[x]=fa[fa[x]];ret x;}
	il bool merge(int x,int y){ret ((x=gf(x),y=gf(y)),x^y)&&(fa[x]=y,1);}
	il int abs(int x){ret x>0?x:-x;}
	il void dfs(int x,int r,int v)
	{
		rt[x]=r;if((dis[x]>>v)&1)ret;
		dis[x]|=1<<v;
		for(int i=h[x];i;i=e[i].nxt)dfs(e[i].to,r,v^e[i].w);
	}
	il void work()
	{
		n=rd();m=rd();int cnt=0;en=0;
		for(int i=1;i<=n;++i)h[i]=val[i]=vr[i]=0,r[i]=fa[i]=i;
		for(int p=1;p<=m;++p)
		{
			char op=rdc();int i=rd();
			if(op=='+')r[i]=r[rd()];
			else if(op=='-')r[i]=-r[rd()];
			else v[++cnt]=ti(op),r[i]=cnt+n;
		}
		for(int i=1;i<=n;++i)
		{
			if(r[i]&&abs(r[i])<=n)addl(i,abs(r[i]),r[i]<0),merge(i,abs(r[i]));
			rt[i]=-1;dis[i]=0;
		}
		for(int i=1;i<=n;++i)if(!dis[i])dfs(i,i,0);
		for(int i=1;i<=n;++i)
		{
			if(abs(r[i])<=n||vr[rt[i]])continue;
			int t=r[i]<0,id=abs(r[i])-n;t^=dis[i];
			vr[rt[i]]=t?tr(v[id]):v[id];
		}
		for(int i=1;i<=n;++i)
		{
			if(vr[rt[i]])continue;
			if(dis[i]==3)vr[rt[i]]=3;
		}
		//for(int i=1;i<=n;++i)cerr<<vr[i]<<' '<<rt[i]<<' '<<r[i]<<' '<<dis[i]<<endl;
		int ans=0;
		for(int i=1,t;i<=n;++i)if((t=vr[rt[i]])&&(dis[i]?tr(t):t)==3)++ans;
		prt(ans);
	}
}
int Kromer;
int main()
{
	file(tribool);
	rd();Kromer=rd();
	while(Kromer --> 0)Sinclair::work();
	ret 0;
}