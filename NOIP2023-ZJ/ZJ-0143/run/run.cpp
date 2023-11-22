#include<bits/stdc++.h>
#define maxn 100005
#define lson x<<1,l,mid
#define rson x<<1|1,mid+1,r
#define int long long
using namespace std;
int _,T,res,g[maxn],f[maxn],ans;
int n,m,k,d,t[maxn<<2],tag[maxn<<2];
struct node{int l,w;};
vector<node> e[maxn];
void clear()
{
	ans=0;
	memset(t,0,sizeof(t));
	memset(tag,0,sizeof(tag));
	for(int i=1;i<=n;i++) e[i].clear();
}
void pushdown(int x)
{
	t[x<<1]+=tag[x];
	t[x<<1|1]+=tag[x];
	tag[x<<1]+=tag[x];
	tag[x<<1|1]+=tag[x];
	tag[x]=0;
}
void insert(int x,int l,int r,int id,int v)
{
	if(l==r)
	{
		t[x]=v;
		return ;
	}
	pushdown(x);
	int mid=(l+r)>>1;
	if(id<=mid) insert(lson,id,v);
	if(id> mid) insert(rson,id,v);
	t[x]=max(t[x<<1],t[x<<1|1]);
}
void update(int x,int l,int r,int L,int R,int v)
{
	if(L<=l && r<=R)
	{
		t[x]+=v;
		tag[x]+=v;
		return ;
	}
	int mid=(l+r)>>1;
	pushdown(x);
	if(L<=mid) update(lson,L,R,v);
	if(R> mid) update(rson,L,R,v);
	t[x]=max(t[x<<1],t[x<<1|1]);
}
void query(int x,int l,int r,int L,int R)
{
	if(L<=l && r<=R)
	{
		res=max(t[x],res);
		return ;
	}
	int mid=(l+r)>>1;
	pushdown(x);
	if(L<=mid) query(lson,L,R);
	if(R> mid) query(rson,L,R);
}
void solve()
{
	scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		e[u].push_back((node){u-v+1,w});
	}
	for(int i=1;i<=n;i++)
	{
		for(auto v:e[i]) update(1,0,n,0,max(v.l-1,0LL),v.w);
		res=-1e9;
		query(1,0,n,max(0LL,i-k),i-1);
		g[i]=res-i*d;
		f[i]=max(g[i-1],f[i-1]);
		insert(1,0,n,i,f[i]+i*d);
		ans=max(max(g[i],f[i]),ans);
	}
	printf("%lld\n",ans);
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&_,&T);
	while(T--)
	{
		clear();
		solve();
	}
	return 0;
}
