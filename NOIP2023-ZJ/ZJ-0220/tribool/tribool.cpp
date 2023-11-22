#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=100005,TRUE=-1,FALSE=-3,UNKNOWN=-2;
ll reverse(ll a){return -4-a;}
ll n,m,fa[maxn],a[maxn],b[maxn],cl[maxn];
ll tot,head[maxn<<1],nxt[maxn<<1],tail[maxn<<1],vl[maxn<<1];
void addedge(int u,int v,int w){
	tot++;
	nxt[tot]=head[u];
	head[u]=tot;
	tail[tot]=v;
	vl[tot]=w;
}
void setans(int u){
	for(int t=head[u];t;t=nxt[t]){
		int v=tail[t],w=vl[t];
		int clv=~w?a[u]:reverse(a[u]);
		if(a[v]==clv) continue;
		a[v]=clv;
		setans(v);
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ll c,T;
	for(scanf("%lld%lld",&c,&T);T--;){
		scanf("%lld%lld",&n,&m);getchar();
		for(int i=1;i<=n;i++) a[i]=i,cl[i]=0,b[i]=1;
		for(int i=1;i<=m;getchar(),i++){
			char ch=getchar();
			if(ch=='T'){
				ll x;
				scanf("%lld",&x);
				a[x]=TRUE;
			}
			else if (ch=='F'){
				ll x;
				scanf("%lld",&x);
				a[x]=FALSE;
			}
			else if(ch=='U'){
				ll x;
				scanf("%lld",&x);
				a[x]=UNKNOWN;
				
			}
			else if(ch=='+'){
				ll x,y;
				scanf("%lld%lld",&x,&y);
				if(a[y]<0) a[x]=a[y];
				else a[x]=a[y],b[x]=b[y];
			}
			else if(ch=='-'){
				ll x,y;
				scanf("%lld%lld",&x,&y);
				if(a[y]<0) a[x]=reverse(a[y]);
				else a[x]=a[y],b[x]=-b[y];
			}
		}
		for(int i=1;i<=n;i++) a[i]==i&&b[i]==-1?(a[i]=UNKNOWN,b[i]=0):0;
		for(int i=1;i<=n;i++) a[i]<0?void():(addedge(a[i],i,b[i]),addedge(i,a[i],b[i]));
		for(int i=1;i<=n;i++)
			a[i]<0?setans(i):void();
		for(int i=1;i<=n;i++)
			a[i]==i?a[i]=TRUE,setans(i):void();
		for(int i=1;i<=n;i++){
			if(a[i]<0) continue;
			ll cur=i,curcl=TRUE;
			while(cl[cur]>=0){
				cl[cur]=curcl;
				curcl=(~b[cur]?curcl:reverse(curcl));
				cur=a[cur];
			}
			if(cl[cur]==curcl) a[cur]=curcl;
			else a[cur]=UNKNOWN;
			setans(cur);
		}
		ll ans=0;
		for(int i=1;i<=n;i++) ans+=(a[i]==UNKNOWN);
		printf("%lld\n",ans);
		memset(head,0,sizeof(head));
		memset(nxt,0,sizeof(nxt));
		memset(tail,0,sizeof(tail));
		memset(vl,0,sizeof(vl));
		tot=0;
	}
	return 0;
}
