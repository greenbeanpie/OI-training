#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ms(x,y) memset(x,y,sizeof(x))
const int M=114514;
int n,m,k,d;
//ll f[M][M];
struct T
{
	int x,y;
	ll v;
}t[M];
bool cmp(T a,T b) 
{
	return a.x<b.x;
}
struct CHTHOLLY
{
	#define lc(p) p<<1
	#define rc(p) (p<<1)|1
	ll t[M*4],lt[M*4];
	void push_up(int p) {t[p]=max(t[lc(p)],t[rc(p)]);}
	void build(int l,int r,int p)
	{
		if(l==r)
		{
			if(l==0) t[p]=0;
			else t[p]=-0x3f3f3f3f3f3f3f3f;
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,lc(p)),build(mid+1,r,rc(p));
		push_up(p);
	}
	void push_down(int p)
	{
		t[lc(p)]+=lt[p],t[rc(p)]+=lt[p];
		lt[lc(p)]+=lt[p],lt[rc(p)]+=lt[p];
		lt[p]=0;
	}
	void update(int l,int r,int p,int x,int y,ll k,int op)
	{
		if(x>y) return;
		if(l>=x&&r<=y)
		{
			if(op==0) t[p]+=k,lt[p]+=k;
			else t[p]=k;
			return;
		}
		int mid=(l+r)>>1;
		push_down(p);
		if(x<=mid) update(l,mid,lc(p),x,y,k,op);
		if(y>=mid+1) update(mid+1,r,rc(p),x,y,k,op);
		push_up(p);
	}
}ch;
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int C,T;
	scanf("%d%d",&C,&T);
	while(T--)
	{
//		ms(f,-0x3f);
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=m;i++) scanf("%d%d%lld",&t[i].x,&t[i].y,&t[i].v);
		if(C>=17&&C<=18)
		{
			ll ans=0;
			for(int i=1;i<=m;i++)
				if(t[i].y<=k&&t[i].v-1ll*t[i].y*d>0) ans+=t[i].v-1ll*t[i].y*d;
			cout<<ans<<"\n";
			continue;
		}
		sort(t+1,t+1+m,cmp);
		ch.build(0,n,1);
		int tp=1;
		ll last=0;
		for(int i=1;i<=n;i++)
		{
//			for(int j=max(1,i-k+1);j<i;j++)	f[i][j]=f[i-1][j]-d; 
//			for(int j=0;j<=i-1;j++) f[i][0]=max(f[i][0],f[i-1][j]);
//			f[i][i]=f[i-1][0]-d;
//			while(tp<=m&&t[tp].x==i)
//			{
//				for(int j=max(1,i-k+1);j<=max(0,i-t[tp].y+1);j++)
//					f[i][j]+=t[tp].v;
//				tp++;
//			}
			ll tmp=ch.t[1],tt=last;last=tmp;
			ch.update(0,n,1,0,0,tmp,1);
			ch.update(0,n,1,i,i,tt-d,1);
			int L=max(1,i-k+1),R=i-1;
			ch.update(0,n,1,L,R,-d,0);
			while(tp<=m&&t[tp].x==i)
			{
				L=max(1,i-k+1),R=max(0,i-t[tp].y+1);
				ch.update(0,n,1,L,R,t[tp].v,0);
				tp++;
			}
		}
//		ll ans=0;
//		for(int i=0;i<=n;i++) ans=max(ans,f[n][i]);
//		cout<<ans<<"\n";
		cout<<ch.t[1]<<"\n";
	}
	return 0;
}
