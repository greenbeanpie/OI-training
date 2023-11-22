#include<stdio.h>
#include<bits/stdc++.h>
#define fir first
#define sec second
#define all(x) begin(x),end(x)
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
namespace __Clonoth__
{
template<typename type>
inline void chmin(type &x,const type &y)
{
	if(y<x)
		x=y;
}
template<typename type>
inline void chmax(type &x,const type &y)
{
	if(x<y)
		x=y;
}
char Buf[1<<23],*P1=Buf,*P2=Buf;
#define getchar() (P1==P2&&(P2=(P1=Buf)+fread(Buf,1,1<<23,stdin),P1==P2)?EOF:*P1++)
template<typename type>
inline void read(type &x)
{
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9')
		x=x*10+(ch^48),ch=getchar();
}
constexpr int Max=2e5+10,lim=262144,Size=524288+10;
constexpr ll inf=1e18;
int a[Max],b[Max],c[Max],d[Max],e[Max],n,m,K;
ll D;
int num[Max],len=0;
ll f[Max],g[Max];
#define ls(p) ((p)<<1)
#define rs(p) ((p)<<1|1)
ll tag[Size],val[Size];
inline void push_up(int p)
{
	val[p]=max(val[ls(p)],val[rs(p)])+tag[p];
}
inline void set_tag(int p,const ll &k)
{
	val[p]+=k,tag[p]+=k;
}
inline void update(int l,int r,const ll &k)
{
	for(l+=lim-1,r+=lim+1;l^r^1;l>>=1,r>>=1,push_up(l),push_up(r))
	{
		if(!(l&1))
			set_tag(l^1,k);
		if(r&1)
			set_tag(r^1,k);
	}
	for(l>>=1;l;l>>=1)
		push_up(l);
}
inline ll query(int l,int r)
{
	ll x=-inf,y=-inf;
	for(l+=lim-1,r+=lim+1;l^r^1;l>>=1,r>>=1,x+=tag[l],y+=tag[r])
	{
		if(!(l&1))
			chmax(x,val[l^1]);
		if(r&1)
			chmax(y,val[r^1]);
	}
	chmax(x,y);
	for(l>>=1;l;l>>=1)
		x+=tag[l];
	return x;
}
#undef ls
#undef rs
vector<int>o[Max];
void solve()
{
	read(n),read(m),read(K),read(D);
	for(int i=1;i<=m;++i)
	{
		read(b[i]),read(a[i]),read(c[i]);
		a[i]=b[i]-a[i]+1;
	}
	for(int i=1;i<=m;++i)
		num[++len]=a[i],num[++len]=b[i];
	sort(num+1,num+len+1);
	len=unique(num+1,num+len+1)-num-1;
	for(int i=1;i<=m;++i)
	{
		d[i]=lower_bound(num+1,num+len+1,a[i])-num;
		e[i]=lower_bound(num+1,num+len+1,b[i])-num;
		o[e[i]].push_back(i);
	}
	fill(all(val),-inf);
	memset(tag,0,sizeof(tag));
	for(int i=1;i<=len;++i)
	{
		g[i]=g[i-1];
		if(i>1&&num[i-1]!=num[i]-1)
			chmax(g[i],f[i-1]);
		if(i>2)
			chmax(g[i],f[i-2]);
		update(i,i,inf+g[i]+(num[i]-1)*D);
		for(auto j:o[i])
			update(1,d[j],c[j]);
		int w=lower_bound(num+1,num+len+1,num[i]-K+1)-num;
		f[i]=query(w,i)-num[i]*D;
	}
	ll ans=*max_element(f+1,f+len+1);
	chmax(ans,0ll);
	cout<<ans<<"\n";
}
void clear()
{
	for(int i=1;i<=len;++i)
		o[i].clear();
	len=0;
}
signed main()
{
	int c,t;
	read(c),read(t);
	while(t--)
		solve(),clear();
	return 0;
}
}
signed main()
{
	freopen("run.in","r",stdin),freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	__Clonoth__::main();
	return 0;
}