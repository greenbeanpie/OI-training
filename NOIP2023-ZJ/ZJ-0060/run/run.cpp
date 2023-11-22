#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int t,n,m,k,d,l[N],r[N],val[N];
ll f[N],tg[N<<2],mx[N<<2],ans;
vector<pair<int,int> >v[N];
void upd(int p,ll v){tg[p]+=v,mx[p]+=v;}
void down(int p){
	if(tg[p]) upd(p<<1,tg[p]),upd(p<<1|1,tg[p]),tg[p]=0;
}
void build(int p,int l,int r){
	tg[p]=mx[p]=0;
	if(l==r) return ;
	int mid=(l+r)/2;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
}
void modify(int p,int l,int r,int lx,int rx,ll v){
	if(lx>rx) return ;
	if(l>=lx&&r<=rx) return upd(p,v);
	int mid=(l+r)/2;
	down(p);
	if(lx<=mid) modify(p<<1,l,mid,lx,rx,v);
	if(rx>mid) modify(p<<1|1,mid+1,r,lx,rx,v);
	mx[p]=max(mx[p<<1],mx[p<<1|1]);
}
ll query(int p,int l,int r,int lx,int rx){
	if(lx>rx) return -1e18;
	if(l>=lx&&r<=rx) return mx[p];
	int mid=(l+r)/2;
	ll ans=-1e18;
	down(p);
	if(lx<=mid) ans=query(p<<1,l,mid,lx,rx);
	if(rx>mid) ans=max(ans,query(p<<1|1,mid+1,r,lx,rx));
	return ans;
}
namespace sub{
	void work(){
		for(int i=1;i<=m;i++)
			if(r[i]-l[i]+1<=k) ans+=max(0ll,val[i]-1ll*(r[i]-l[i]+1)*d);
		printf("%lld\n",ans);
	}
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%*d%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&k,&d),ans=0;
		for(int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d%d",&x,&y,&val[i]),l[i]=x-y+1,r[i]=x;
		}
		if(n>1e5){sub::work();continue;}
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<=m;i++)
			v[r[i]].push_back({l[i],val[i]});
		build(1,0,n+1);
		for(int i=1;i<=n+1;i++){
			for(auto p:v[i-1])
				modify(1,0,n+1,0,p.first-1,p.second);
			f[i]=query(1,0,n+1,max(0,i-k-1),i-1)-1ll*(i-1)*d;
			ans=max(ans,f[i]);
			modify(1,0,n+1,i,i,f[i]+1ll*i*d);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
