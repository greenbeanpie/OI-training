#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,l,r) for(ll i=l,i##e=r;i<=i##e;++i)
#define Rep(i,l,r) for(ll i=l,i##e=r;i<i##e;++i)
#define FOR(i,l,r) for(ll i=l,i##e=r;i>=i##e;--i)
ll read(){
	char c=getchar();ll v=0;bool f=1;
	for(;'0'>c||c>'9';c=getchar())
	    if(c=='-') f = 0;
	for(;'0'<=c&&c<='9';c=getchar())
	    v = (v<<1)+(v<<3)+(c^48);
	return f?v:-v;
}
ll n,m,k,d;
const ll M = 1e5+10;
const ll inf = 2e18;
struct TZ{ll x,y,v;}tz[M];
bool cmp(TZ a,TZ b){return a.x<b.x;}
void init(){
	n=read(),m=read(),k=read(),d=read();
	For(i,1,m) tz[i].x=read(),tz[i].y=read(),tz[i].v=read();
	sort(tz+1,tz+m+1,cmp);
}
namespace W1{
ll f[1010][1010];
void work(){
	init();
	ll now = 1;k = min(n,k);
	f[0][0] = 0;
	For(i,1,n){
		f[i][0] = -inf;
		For(j,0,min(i-1,k))
		    f[i][0] = max(f[i][0],f[i-1][j]);
		For(j,1,min(i,k))
			f[i][j] = f[i-1][j-1]-d;
		for(;now<=m&&tz[now].x==i;++now)
		    For(j,tz[now].y,k)
			    f[i][j] += tz[now].v; 
	}
	ll ans = -inf;
	For(j,0,k) ans = max(ans,f[n][j]);
	printf("%lld\n",ans);
}
}
namespace W2{
ll maxf[1010],f[2][1010];//g[i][j]= SZSZ of f[i][j]-f[i][j-1]
void work(){
	init();
	ll now = 1;k = min(n,k);
	f[0][1] = 0,maxf[0] = 0;//f[i][j] = [j,i]
	For(i,1,n){
		f[i&1][i+1] = maxf[i-1];//maxf = max f[i-1][1/i-k+1..i]
		For(j,max(1ll,i-k+1),i) f[i&1][j] = f[i-1&1][j]-d;
		for(;now<=m&&tz[now].x==i;++now)
		    For(j,max(1ll,i-k+1),max(1ll,i-tz[now].y+1))
			    f[i&1][j] += tz[now].v; 
		maxf[i] = -inf;
		For(j,max(1ll,i-k+1),i+1) maxf[i] = max(maxf[i],f[i&1][j]);
	}
//	For(i,1,n) printf("%lld ",maxf[i]);
	printf("%lld\n",maxf[n]);
}
}
namespace W3{
ll tr[M<<2],tg[M<<2],maxf[M];
//ll ask(ll *c,ll x){ll res = 0;
//	for(ll i=x;i;i-=i&-i) res += c[i];
//	return res;
//}
//ll add(ll *c,ll x,ll n,ll v){
//	for(ll i=x;i<=n;i+=i&-i) c[i] += v;
//}
void pdn(ll p,ll l,ll r){
	tg[p<<1] += tg[p];
	tg[p<<1|1] += tg[p];
	tr[p<<1] += tg[p];
	tr[p<<1|1] += tg[p];
	tg[p] = 0;
}
void upt(ll p,ll l,ll r,ll nl,ll nr,ll v){
	if(nl<=l&&r<=nr){
	    tr[p] += v,tg[p] += v;return;
	}
	ll mid = (l+r)>>1;pdn(p,l,r);
	if(nl<=mid) upt(p<<1,l,mid,nl,nr,v);
	if(nr>mid) upt(p<<1|1,mid+1,r,nl,nr,v);
	tr[p] = max(tr[p<<1],tr[p<<1|1]);
}
ll ask(ll p,ll l,ll r,ll nl,ll nr){
	if(nl<=l&&r<=nr) return tr[p];
	ll mid = (l+r)>>1,res = -inf;pdn(p,l,r);
	if(nl<=mid) res=max(res,ask(p<<1,l,mid,nl,nr));
	if(nr>mid) res=max(res,ask(p<<1|1,mid+1,r,nl,nr));
	return res;
}
void work(){
	init();
	ll now = 1;k = min(n,k);
	memset(tr,0,sizeof tr);
	memset(tg,0,sizeof tg);
//	upt(1,1,n+1,1,1,0);
	maxf[0] = 0;//f[i][j] = [j,i]
	For(i,1,n){
//		f[i][i+1] = maxf[i-1];//maxf = max f[i-1][1/i-k+1..i]
		maxf[i] = -inf;
		upt(1,1,n+1,i+1,i+1,maxf[i-1]);
		ll minx = max(1ll,i-k+1);
//		For(j,minx,i) f[i][j] = f[i-1][j]-d;
		upt(1,1,n+1,minx,i,-d);
		for(;now<=m&&tz[now].x==i;++now){
//		    For(j,max(1ll,i-k+1),max(1ll,i-tz[now].y+1))
//			    f[i][j] += tz[now].v; 
			ll maxx = max(1ll,i-tz[now].y+1);
//			ll want = ask(g,maxx);
			upt(1,1,n+1,minx,maxx,tz[now].v);
//			add(g,minx,n+2,tz[now].v);
//			add(g,maxx+1,n+2,-tz[now].v);
//			maxf[i] = max(maxf[i],ask(g,maxx));
		}
		maxf[i] = ask(1,1,n+1,1,i+1);
//		maxf[i] = max(maxf[i],ask(g,i+1));
//		For(j,max(1ll,i-k+1),i+1) maxf[i] = max(maxf[i],f[i][j]);
	}
//	For(i,1,n) printf("%lld ",maxf[i]);
	printf("%lld\n",maxf[n]);
}
}
void dowork(ll c){
	if(c<=7) W1::work();
	else W3::work();
}

int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	
	ll c=read(),t=read();
	For(qwq,1,t) dowork(c);
	
	fclose(stdin);fclose(stdout);
	return 0;
}
