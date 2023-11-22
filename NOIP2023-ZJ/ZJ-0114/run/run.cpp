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
#define pr pair<ll,ll>
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
//bool clonothakioi1;
int maggot;
namespace Gregor
{
	int n,m,k,d,x[300005],c;cst ll neinf=0xc0c0c0c0c0c0c0c0ll;
	struct orz{int x,y,v;}q[100005];
	il bool cmp(orz a,orz b){ret a.x<b.x;}
	/*cst int MX=24000005;
	ll v[MX],tg[MX];int ls[MX],rs[MX],cnt;
	il void up(int x)
	{
		v[x]=neinf;
		if(ls[x])v[x]=max(v[x],v[ls[x]]);
		if(rs[x])v[x]=max(v[x],v[rs[x]]);
		v[x]+=tg[x];
	}
	il int newp(){++cnt;v[cnt]=neinf;tg[cnt]=ls[cnt]=rs[cnt]=0;ret cnt;}
	il void check(int&x)
	{
		if(x)ret;
		x=newp();
	}
	il void modify(int lt,int rt,ll ve,int i=1,int l=-n,int r=0)
	{
		if(l>rt||r<lt)ret;
		if(lt<=l&&r<=rt){tg[i]+=ve;v[i]+=ve;ret;}
		int m=(l+r)>>1;
		if(m>=lt)check(ls[i]),modify(lt,rt,ve,ls[i],l,m);
		if(m<rt)check(rs[i]),modify(lt,rt,ve,rs[i],m+1,r);
		up(i);
	}
	il void assign(int lt,int rt,ll ve,int i=1,int l=-n,int r=0)
	{
		if(l>rt||r<lt)ret;
		if(lt<=l&&r<=rt){tg[i]+=ve;v[i]+=ve;ret;}
		int m=(l+r)>>1;
		if(m>=lt)check(ls[i]),assign(lt,rt,ve-tg[i],ls[i],l,m);
		if(m<rt)check(rs[i]),assign(lt,rt,ve-tg[i],rs[i],m+1,r);
		up(i);
	}
	il ll query(int lt,int rt,int i=1,int l=-n,int r=0)
	{
		if(l>rt||r<lt)ret neinf;
		if(lt<=l&&r<=rt)ret v[i];
		int m=(l+r)>>1;ll res=neinf;
		if(m>=lt)check(ls[i]),res=max(res,query(lt,rt,ls[i],l,m));
		if(m<rt)check(rs[i]),res=max(res,query(lt,rt,rs[i],m+1,r));
		up(i);ret res+tg[i];
	}*/
	ll tg[1200005],v[1200005];
	il void up(int x){v[x]=max(v[x<<1],v[(x<<1)|1]);}
	il void pmdf(int x,ll ve){tg[x]+=ve;v[x]+=ve;}
	il void dn(int x)
	{
		if(!tg[x])ret;
		pmdf(x<<1,tg[x]);pmdf((x<<1)|1,tg[x]);tg[x]=0;
	}
	il void modify(int lt,int rt,ll ve,int i=1,int l=1,int r=c)
	{
		if(l>rt||r<lt||lt>rt)ret;
		if(lt<=l&&r<=rt){pmdf(i,ve);ret;}
		int m=(l+r)>>1;dn(i);
		if(m>=lt)modify(lt,rt,ve,i<<1,l,m);
		if(m<rt)modify(lt,rt,ve,(i<<1)|1,m+1,r);
		up(i);
	}
	il void assign(int p,ll ve,int i=1,int l=1,int r=c)
	{
		if(l>p||r<p)ret;
		if(l==p&&r==p){tg[i]=0;v[i]=ve;ret;}
		int m=(l+r)>>1;dn(i);
		if(m>=p)assign(p,ve,i<<1,l,m);else assign(p,ve,(i<<1)|1,m+1,r);
		up(i);
	}
	il ll query(int lt,int rt,int i=1,int l=1,int r=c)
	{
		if(l>rt||r<lt||lt>rt)ret neinf;
		if(lt<=l&&r<=rt)ret v[i];
		int m=(l+r)>>1;ll res=neinf;dn(i);
		if(m>=lt)res=max(res,query(lt,rt,i<<1,l,m));
		if(m<rt)res=max(res,query(lt,rt,(i<<1)|1,m+1,r));
		up(i);ret res;
	}
	il int gid(int xx){ret lower_bound(x+1,x+1+c,xx)-x;}
	il void work()
	{
		n=rd();m=rd();k=rd();d=rd();c=0;
		for(int i=1;i<=m;++i)
		{
			q[i].x=rd(),q[i].y=rd(),q[i].v=rd();
			if(q[i].x>=q[i].y)x[++c]=q[i].x-q[i].y,x[++c]=q[i].x;
			//if(q[i].x>=k)x[++c]=q[i].x-k;
		}
		sort(x+1,x+1+c);c=unique(x+1,x+1+c)-x-1;sort(q+1,q+1+m,cmp);
		for(int i=1;i<=(c<<2);++i)tg[i]=0,v[i]=neinf;
		int tt=1;
		for(int i=1,j=1;i<=c;++i)
		{
			assign(i,max(query(tt,i-1),0ll));
			while(tt<=c&&x[i]>=k&&tt<gid(x[i]-k))++tt;
			if(i>1)modify(tt,i-1,-1ll*d*(x[i]-x[i-1]));
			while(j<=m&&q[j].x<=x[i])modify(tt,gid(x[i]-q[j].y),q[j].v),++j;
			//cerr<<x[i]<<endl;
			//for(int j=i;j>=1;--j)cerr<<x[i]-x[j]<<' '<<query(j,j)<<endl;
			//cerr<<endl;
		}
		prt(max(0ll,query(tt,c)));
	}
}
//bool clonothakioi2;
int main()
{
	file(run);
	rd();maggot=rd();
	while(maggot --> 0)Gregor::work();
	//cerr<<(&clonothakioi1-&clonothakioi2)*1.0/1048576<<endl;
	ret 0;
}