#include<bits/stdc++.h>
#define ri LL
using namespace std;
typedef long long LL;
const LL N=200005;
LL c,t,n,m,k,d,f[N],l[N],r[N],p[N],g[N],cn,tr[N<<2],tg[N<<2];vector<pair<LL,LL> >vc[N];
void pu(LL rt){tr[rt]=max(tr[rt<<1],tr[rt<<1|1]);}
void pd(LL rt){if(tg[rt])tr[rt<<1]+=tg[rt],tr[rt<<1|1]+=tg[rt],tg[rt<<1]+=tg[rt],tg[rt<<1|1]+=tg[rt],tg[rt]=0;}
void add(LL rt,LL l,LL r,LL x,LL y,LL z){
	if(x<=l&&r<=y){tr[rt]+=z;tg[rt]+=z;return;}ri md=l+r>>1;pd(rt);
	if(x<=md)add(rt<<1,l,md,x,y,z);if(y>md)add(rt<<1|1,md+1,r,x,y,z);pu(rt);
}
LL qr(LL rt,LL l,LL r,LL x,LL y){
	if(x<=l&&r<=y)return tr[rt];ri md=l+r>>1;pd(rt);ri o=-1e18;
	if(x<=md)o=max(o,qr(rt<<1,l,md,x,y));if(y>md)o=max(o,qr(rt<<1|1,md+1,r,x,y));
	return o;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	for(cin>>c>>t;t--;){
		cin>>n>>m>>k>>d;cn=0;
		for(ri i=1;i<=m;++i)cin>>r[i]>>l[i]>>p[i],l[i]=r[i]-l[i],g[++cn]=l[i],g[++cn]=r[i];
		g[++cn]=0;sort(g+1,g+1+cn);cn=unique(g+1,g+1+cn)-g-1;
		for(ri i=1;i<=cn;++i)vc[i].clear();
		for(ri i=1;i<=m;++i)vc[lower_bound(g+1,g+1+cn,r[i])-g].push_back({lower_bound(g+1,g+1+cn,l[i])-g,p[i]});
		for(ri i=1;i<=cn*4;++i)tr[i]=tg[i]=0;
		for(ri i=2,j=1;i<=cn;++i){
			for(auto o:vc[i])add(1,1,cn,1,o.first,o.second);
			while(g[i]-g[j]>k)++j;
			if(j<i)f[i]=max(f[i-1],qr(1,1,cn,j,i-1)-g[i]*d);else f[i]=f[i-1];
			add(1,1,cn,i,i,f[i-1]+g[i]*d);
		}
		cout<<f[cn]<<'\n';
	}
	return 0;
}
