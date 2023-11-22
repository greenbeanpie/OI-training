#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=(l),i##_end=(r);i<i##_end;++i)
using namespace std;
constexpr int N=2e5+5;
constexpr long long LLINF=0x3fffffffffffffff;
namespace seg
{
	constexpr int N=(1<<18)+5;
	struct data
	{
		long long max,tag;
	}s[N];
#define lc (p<<1)
#define rc (p<<1|1)
	void build(int p,int l,int r)
	{
		s[p].max=-LLINF;s[p].tag=0;
		if(r-l==1)return;
		int mid=(l+r)>>1;
		build(lc,l,mid);build(rc,mid,r);
	}
	void update(int p,long long v){s[p].max+=v;s[p].tag+=v;}
	void pushdown(int p){update(lc,s[p].tag);update(rc,s[p].tag);s[p].tag=0;}
	void updatep(int p,int l,int r,int x,long long v)
	{
		if(r-l==1)return s[p].max=max(s[p].max,v),void();
		int mid=(l+r)>>1;
		pushdown(p);
		if(x<mid)updatep(lc,l,mid,x,v);
		else updatep(rc,mid,r,x,v);
		s[p].max=max(s[lc].max,s[rc].max);
	}
	void update(int p,int l,int r,int x,long long v)
	{
		if(r-l==1)return update(p,v);
		int mid=(l+r)>>1;
		pushdown(p);
		if(x<=mid)update(lc,l,mid,x,v);
		else update(lc,v),update(rc,mid,r,x,v);
		s[p].max=max(s[lc].max,s[rc].max);
	}
	long long query(int p,int l,int r,int x)
	{
		if(x==l)return s[p].max;
		int mid=(l+r)>>1;
		pushdown(p);
		if(x<mid)return max(query(lc,l,mid,x),s[rc].max);
		return query(rc,mid,r,x);
	}
#undef lc
#undef rc
}
struct ep
{
	int tp,i,tm;
	friend bool operator<(const ep &u,const ep &v)
	{
		return u.tm!=v.tm?u.tm<v.tm:u.tp<v.tp;
	}
}e[N];
int tt,n,k,d,l[N],r[N],v[N],pos[N],posc;
int main()
{
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
#endif
#endif
	scanf("%*d%d",&tt);
	while(tt--)
	{
		long long ans=0;
		scanf("%*d%d%d%d",&n,&k,&d);
		posc=0;
		F(i,0,n)
		{
			int x,y;scanf("%d%d%d",&x,&y,&v[i]);
			l[i]=x-y;r[i]=x;
			pos[posc++]=l[i];
			e[2*i]={0,i,l[i]};
			e[2*i+1]={1,i,r[i]};
		}
		sort(pos,pos+posc);
		posc=(int)(unique(pos,pos+posc)-pos);
		sort(e,e+2*n);
		seg::build(1,0,posc);
		F(i_,0,2*n)
		{
			int u=e[i_].i;
			if(e[i_].tp)
			{
				int p=(int)(lower_bound(pos,pos+posc,l[u])-pos);
				seg::update(1,0,posc,p+1,v[u]);
				p=(int)(lower_bound(pos,pos+posc,r[u]-k)-pos);
				if(p<posc)ans=max(ans,seg::query(1,0,posc,p)-(long long)d*r[u]);
			}
			else
			{
				int p=(int)(lower_bound(pos,pos+posc,l[u])-pos);
				seg::updatep(1,0,posc,p,ans+(long long)d*l[u]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
