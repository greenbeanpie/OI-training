#include<bits/stdc++.h>
#define Gc() getchar()
#define fi first
#define se second
#define LB lower_bound
#define UB upper_bound
#define Me(x,y) memset(x,y,sizeof x)
#define Mc(x,y) memcpy(x,y,sizeof x)
#define R(n) (rnd()%(n)+1)
using namespace std;using ll=long long;using LL=__int128;
const int N=2e5+5,M=N*4+5,K=1e7+5;const ll INF=4e18;mt19937 rnd(time(0));
int n,m,k,d,X[N],Y[N],Z[N];
pair<int,int> A[N];int H;
vector<pair<int,int> > S[N];
ll dp[N];
namespace Tree{
	#define ls v<<1
	#define rs v<<1|1
	ll f[M],g[M];
	void clr(){Me(f,-0x3f);Me(g,0);}
	void PF(int v,ll w){f[v]+=w;g[v]+=w;}
	void P(int v){g[v]&&(PF(ls,g[v]),PF(rs,g[v]),g[v]=0);}
	void up(int v){f[v]=max(f[ls],f[rs]);}
	void modify(int x,ll y,int l=1,int r=H,int v=1){
		if(l==r) {f[v]=y;return;}int m=l+r>>1;P(v);
		x<=m?modify(x,y,l,m,ls):modify(x,y,m+1,r,rs);up(v);
	}
	void add(int x,int y,ll z,int l=1,int r=H,int v=1){
		if(x<=l&&r<=y) return PF(v,z);int m=l+r>>1;P(v);
		x<=m&&(add(x,y,z,l,m,ls),0);y>m&&(add(x,y,z,m+1,r,rs),0);up(v);
	}
	ll qry(int x,int y,int l=1,int r=H,int v=1){
		if(x<=l&&r<=y) return f[v];int m=l+r>>1;P(v);
		return max(x<=m?qry(x,y,l,m,ls):-INF,y>m?qry(x,y,m+1,r,rs):-INF);
	}
}
void read(int &x){
	char c=Gc();x=0;
	while(c<'0'||c>'9') c=Gc();
	while(c>='0'&&c<='9') x=x*10+c-48,c=Gc();
}
void Solve(){
	int i,j;scanf("%d%d%d%d",&n,&m,&k,&d);
	H=0;for(i=1;i<=m;i++) {
		read(Y[i]);read(X[i]);read(Z[i]);
		X[i]=Y[i]-X[i]+1;
		A[++H]=make_pair(X[i]-1,-i);A[++H]=make_pair(Y[i],i);
	}
	A[++H]=make_pair(0,0);
	sort(A+1,A+H+1);
	for(i=1;i<=H;i++) {
		if(A[i].se>0) Y[A[i].se]=i;
		else X[-A[i].se]=i;
	}
	for(i=1;i<=H;i++) S[i].clear();
	for(i=1;i<=m;i++) S[Y[i]].emplace_back(X[i],Z[i]);
	Tree::clr();
	ll ans=0;int R=1;
	for(i=1;i<=H;i++){
		while(A[R].fi+k<A[i].fi) R++;
		for(auto j:S[i]) Tree::add(1,j.fi,j.se);
		if(!A[i].fi) dp[i]=0;
		else{
			if(A[i].se<0) dp[i]=ans;
			else dp[i]=Tree::qry(R,i)-1ll*A[i].fi*d;
		}
		if(A[i].se<0) Tree::modify(i,dp[i]+1ll*A[i].fi*d);
		ans=max(ans,dp[i]);
		// cerr<<R<<' '<<A[i].fi<<' '<<A[i].se<<' '<<dp[i]<<'\n';
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("run.in","r",stdin);freopen("run.out","w",stdout);
	int c,t;scanf("%d%d",&c,&t);
	while(t--) Solve();
	cerr<<clock()*1.0/CLOCKS_PER_SEC<<'\n';
}