#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define MP make_pair
#define pii pair<int,int>
#define pil pair<int,ll>
using namespace std;
typedef long long ll;
constexpr int N=200005;
struct node{
	int x,y,z;
}a[N];
int Cas,T,n,m,K,d,va[N];
ll f[N],g[N];
vector<int> V[N];
struct SEG_TREE{
	ll tr[N<<2],tag[N<<2];
	void push_down(int p){
		if(!tag[p])return;
		int ls=p<<1,rs=p<<1|1;ll v=tag[p];
		tr[ls]+=v,tag[ls]+=v;
		tr[rs]+=v,tag[rs]+=v;
		tag[p]=0;
	}
	void build(int p,int l,int r){
		tr[p]=tag[p]=0;
		if(l==r)return;
		int mid=(l+r)>>1;
		build(p<<1,l,mid);build(p<<1|1,mid+1,r);
	}
	void change(int p,int l,int r,int ql,int qr,ll v){
		if(ql<=l&&r<=qr){tr[p]+=v,tag[p]+=v;return;}
		push_down(p);int mid=(l+r)>>1;
		if(ql<=mid)change(p<<1,l,mid,ql,qr,v);
		if(qr>mid)change(p<<1|1,mid+1,r,ql,qr,v);
		tr[p]=max(tr[p<<1],tr[p<<1|1]);
	}
	ll query(int p,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return tr[p];
		push_down(p);int mid=(l+r)>>1;ll res=0;
		if(ql<=mid)res=max(res,query(p<<1,l,mid,ql,qr));
		if(qr>mid)res=max(res,query(p<<1|1,mid+1,r,ql,qr));
		return res;
	}
}TR;
void clear(int nn){
	for(int i=0;i<=nn;i++)f[i]=g[i]=0,V[i].clear();
}
void solve0(){
	ll ans=0;
	for(int i=1;i<=m;i++)
		if(a[i].y<=K)ans+=max(a[i].z-(ll)a[i].y*d,0ll);
	cout<<ans<<'\n';
}
void solve1(){
	int nn=0;
	for(int i=1;i<=m;i++){
		a[i].y=a[i].x-a[i].y,va[++nn]=a[i].x;
		if(a[i].y)va[++nn]=a[i].y;
	}
	va[0]=0;
	sort(va+1,va+nn+1);
	nn=unique(va+1,va+nn+1)-va-1;
	for(int i=1;i<=m;i++){
		a[i].x=lower_bound(va,va+nn+1,a[i].x)-va;
		a[i].y=lower_bound(va,va+nn+1,a[i].y)-va;
		V[a[i].x].pb(i);
	}TR.build(1,0,nn);
	for(int i=1;i<=nn;i++){
		f[i]=g[i-1];
		for(int j:V[i])TR.change(1,0,nn,0,a[j].y,a[j].z);
		f[i]=max(f[i],TR.query(1,0,nn,lower_bound(va,va+nn+1,max(0,va[i]-K))-va,i-1)-(ll)va[i]*d);
		g[i]=max(g[i-1],f[i-1]);TR.change(1,0,nn,i,i,g[i]+(ll)va[i]*d);
	}
	cout<<max(g[nn],f[nn])<<'\n';clear(nn);
}
void solve(){
	cin>>n>>m>>K>>d;
	for(int i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].z;
	if(Cas==17||Cas==18)return solve0(),void();
	if(Cas>14)return solve1(),void();
	for(int i=1;i<=m;i++)V[a[i].x].pb(i);
	TR.build(1,0,n);
	for(int i=1;i<=n;i++){
		f[i]=g[i-1];
		for(int j:V[i])TR.change(1,0,n,0,i-a[j].y,a[j].z);
		f[i]=max(f[i],TR.query(1,0,n,max(0,i-K),i-1)-(ll)i*d);
		g[i]=max(g[i-1],f[i-1]);TR.change(1,0,n,i,i,g[i]+(ll)i*d);
	}
	cout<<max(g[n],f[n])<<'\n';clear(max(n,m));
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>Cas>>T;
	while(T--)solve();
	return 0;
}