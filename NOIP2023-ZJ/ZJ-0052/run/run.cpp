#include<bits/stdc++.h>
#define int long long 
#define ll long long 
using namespace std;
const int N=4e5+100;
int n,m,len,d,tot,cnt;
int id;
namespace Seg
{
	#define ls (x<<1)
	#define rs (x<<1|1)
	#define mid ((L+R)>>1)
	struct Laz
	{
		ll add,mxadd;Laz(ll add=0,ll mxadd=0):add(add),mxadd(mxadd){}
		const friend Laz operator+(const Laz&x,const Laz&y)
		{
			Laz z;z.add=x.add+y.add;
			int t2=x.add+y.mxadd;
			z.mxadd=x.mxadd>=t2?x.mxadd:t2;
			z.mxadd=max(x.mxadd,x.add+y.mxadd);
			return z;
		}
	};
	Laz laz[N<<2],val[N<<2];
	void push(int x,const Laz&v){val[x]=val[x]+v;laz[x]=laz[x]+v;}
	void pushdown(int x){if(laz[x].add||laz[x].mxadd)push(ls,laz[x]),push(rs,laz[x]),laz[x]=Laz();}
	void update(int x,int l,int r,int L,int R,ll v)
	{
		if(l<=L&&R<=r)return push(x,Laz(v,v));
		pushdown(x);
		if(l<=mid)update(ls,l,r,L,mid,v);
		if(r>mid)update(rs,l,r,mid+1,R,v);
	}
	ll query(int x,int p,int L,int R)
	{
		if(L==R)return val[x].mxadd;
		pushdown(x);
		if(p<=mid)return query(ls,p,L,mid);
		return query(rs,p,mid+1,R);
	}
	void update(int l,int r,ll v){if(l<=r)update(1,l,r,1,n,v);}
	ll query(int p){return query(1,p,1,n);}
	void clear(){for(int i=1;i<=4*n;i++)val[i]=laz[i]=Laz();}
//	ll a[N],b[N];
//	void update(int l,int r,ll v){for(int i=l;i<=r;i++)b[i]=max(b[i],a[i]+=v);}
//	ll query(int p){return b[p];}
//	void clear(){for(int i=1;i<=4*n;i++)a[i]=b[i]=0;}
}
struct Line{int l,r,v;Line(int l=0,int r=0,int v=0):l(l),r(r),v(v){}}l1[N],l2[N];
int vt[N];
ll dp[N];
int pos(int x){return lower_bound(vt+1,vt+n+1,x)-vt;}
void solve()
{
	cin>>n>>m>>len>>d;tot=cnt=0;
	for(int i=1;i<=m;i++)
	{
		int x,y,v;cin>>x>>y>>v;
		if(y<=len&&x-y+1>=1)
		{
			l1[++tot]=Line(x-y+1,x,v);l2[tot]=l1[tot];
			vt[++cnt]=x-y+1;vt[++cnt]=x+2;
//			vt[++cnt]=x-y;vt[++cnt]=x;vt[++cnt]=x+1;
		}
	}
	vt[++cnt]=1;vt[++cnt]=n;vt[++cnt]=n+1;vt[++cnt]=n+2;
//	for(int i=1;i<=n+3;i++)vt[++cnt]=i;
	m=tot;n=cnt;
	sort(l1+1,l1+m+1,[&](const Line&x,const Line&y)
		{return x.l==y.l?x.r<y.r:x.l<y.l;});
	sort(l2+1,l2+m+1,[&](const Line&x,const Line&y)
		{return x.r==y.r?x.l<y.l:x.r<y.r;});
//	for(int i=1;i<=m;i++)cout<<l[i].l<<" "<<l[i].r<<endl;
	sort(vt+1,vt+n+1);n=unique(vt+1,vt+n+1)-vt-1;
	for(int i=1;i<=n;i++)dp[i]=0;	
//	for(int i=1;i<=n;i++)printf("%d ",vt[i]);puts("");
	for(int i=1,j=1,k=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(vt[i]>=2)dp[i]=max(dp[i],Seg::query(i)-1ll*(vt[i]-1)*d);
		while(j<=m&&l1[j].l<vt[i])
		{
			Seg::update(pos(l1[j].r+2),n,-l1[j].v),j++;
//			cout<<pos(l1[j].r+2)<<' '<<n<<endl;
		}
		while(k<=m&&l2[k].r<=vt[i]+len-1)
			Seg::update(pos(l2[k].r+2),n,l2[k].v),k++;
		Seg::update(pos(vt[i]+2),n,(dp[i]+1ll*vt[i]*d));
		Seg::update(pos(vt[i]+2),n,-(dp[i]+1ll*vt[i]*d));
//		cout<<i<<' '<<vt[i]<<' '<<dp[i]<<endl;
	}
	Seg::clear();
	cout<<dp[n]<<endl;
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int C,T;cin>>C>>T;
	for(id=1;id<=T;id++)solve();
	return 0;
}
/*
1 1
3 2 2 1
2 2 4
3 2 3
*/