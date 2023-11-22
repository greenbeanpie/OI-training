#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
const int N=1e5+5;
const ll INF=1e18;

ll mx[N<<3],tg[N<<3];
void up(int k) {mx[k]=max(mx[ls],mx[rs]);}
void down(int k) {
	if(!tg[k]) return;
	tg[ls]+=tg[k],tg[rs]+=tg[k];
	mx[ls]+=tg[k],mx[rs]+=tg[k];
	tg[k]=0;
	return;
}
void build(int k,int l,int r) {
	mx[k]=-INF;
	tg[k]=0;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(lson),build(rson);
	up(k);
	return;
}
void updt(int k,int l,int r,int pl,int pr,ll vl) {
	if(pl<=l&&r<=pr) {
		tg[k]+=vl;
		mx[k]+=vl;
		return;
	}
	down(k);
	int mid=(l+r)>>1;
	if(pl<=mid) updt(lson,pl,pr,vl);
	if(pr>mid) updt(rson,pl,pr,vl);
	up(k);
	return;
}
ll qury(int k,int l,int r,int pl,int pr) {
	if(pl<=l&&r<=pr) return mx[k];
	down(k);
	int mid=(l+r)>>1;
	ll num=-INF;
	if(pl<=mid) num=max(num,qury(lson,pl,pr));
	if(pr>mid) num=max(num,qury(rson,pl,pr));
	return num;
}

int n,m,k,d;
int c[N<<1],tot;
ll f[N<<1];
int pl[N],pr[N],val[N];

vector<pair<int,int> > v[N<<1];
int main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int Komeji,Koishi;scanf("%d%d",&Komeji,&Koishi);
	while(Koishi--) {
		scanf("%d%d%d%d",&n,&m,&k,&d);tot=0;
		for(int i=1,x,y;i<=m;i++) {
			scanf("%d%d%d",&x,&y,&val[i]);
			pr[i]=x+1;
			pl[i]=x-y;
			c[++tot]=pl[i],c[++tot]=pr[i];
		}
		sort(c+1,c+tot+1);tot=unique(c+1,c+tot+1)-c-1;
		for(int i=1;i<=tot;i++) v[i].clear();
		for(int i=1;i<=m;i++) {
			pl[i]=lower_bound(c+1,c+tot+1,pl[i])-c;
			pr[i]=lower_bound(c+1,c+tot+1,pr[i])-c;
			v[pr[i]].push_back(make_pair(pl[i],val[i]));
		}
		build(1,1,tot);
		int p=0;ll ans=0;
		for(int i=1;i<=tot;i++) {
			while(p<i&&c[i]-c[p+1]-1>k) p++;
//			cerr<<i<<" "<<p<<endl;
			for(auto cur:v[i]) {
//				cerr<<"add : "<<"[1,"<<cur.first<<"]"<<" += "<<cur.second<<endl;
				updt(1,1,tot,1,cur.first,cur.second);
			}
			f[i]=ans;
			if(p+1<=i-1) f[i]=max(f[i],qury(1,1,tot,p+1,i-1)-1ll*d*(c[i]-1));
			ans=max(ans,f[i]);
//			if(p+1<=i-1) cerr<<i<<" : "<<f[i]<<" "<<p<<" "<<qury(1,1,tot,p+1,i-1)<<endl;
			updt(1,1,tot,i,i,f[i]+1ll*d*c[i]+INF);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
