#include<bits/stdc++.h>
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
	ll f[N];
	void clr(){Me(f,-0x3f);}
	void modify(int x,ll y){f[x]=y;}
	void add(int x,int y,ll z){for(int i=x;i<=y;i++) f[i]+=z;}
	ll qry(int x,int y){
		ll ans=-INF;for(int i=x;i<=y;i++) ans=max(ans,f[i]);
		return ans;
	}
}
void Solve(){
	int i,j;scanf("%d%d%d%d",&n,&m,&k,&d);
	H=0;for(i=1;i<=m;i++) {
		scanf("%d%d%d",&Y[i],&X[i],&Z[i]);
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
	freopen("run.in","r",stdin);freopen("run.ans","w",stdout);
	int c,t;scanf("%d%d",&c,&t);
	while(t--) Solve();
	cerr<<clock()*1.0/CLOCKS_PER_SEC<<'\n';
}