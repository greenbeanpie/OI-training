#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100010,M=1010;
const ll INF=1e18;
int c,T,sum[25];
int n,m,k,d;
ll ans,f[M][M];
bool st[25];
struct seg{
	int l,r,k;
}s[N];
vector<pair<int,ll> >g[M];
void dfs(int u,int lst){
	if(u==n+1){
		ll tot=0;
		for(int i=1;i<=n;++i)sum[i]=sum[i-1]+st[i],tot-=st[i]*d;
		for(int i=1;i<=m;++i)
			if(sum[s[i].r]-sum[s[i].l-1]==s[i].r-s[i].l+1){
				tot+=s[i].k;
			}
		ans=max(ans,tot);
		return;
	}
	if(lst<k)st[u]=1,dfs(u+1,lst+1);
	st[u]=0,dfs(u+1,0);
}
ll get(int i,int j){
	auto &a=g[i];
	
	int pos=
	upper_bound(a.begin(),a.end(),make_pair(j,INF))
	-a.begin();
	if(!pos)return 0;
	--pos;
	return a[pos].second;
}
ll get2(int i,int j){
	ll tot=0;
	for(auto p:g[i]){
		if(p.first<=j)tot+=p.second;
	}
	return tot;
}
void solve(){
	ans=0;
	scanf("%d%d%d%d",&n,&m,&k,&d);
	if(c<=9)
		for(int i=1;i<=n;++i)g[i].clear();
	for(int i=1;i<=m;++i){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(::c<=9)
		g[a].push_back({b,c});
		b=a-b+1;
		swap(a,b);
		s[i]={a,b,c};
	}
	if(c<=9){
		
	for(int i=1;i<=n;++i){
		auto &a=g[i];
		sort(a.begin(),a.end());
		int len=a.size();
		for(int j=1;j<len;++j)
			a[j].second+=a[j-1].second;
	}
		for(int i=1;i<=n;++i){
			f[i][0]=f[i-1][0];
			for(int j=1;j<=k;++j)
				f[i][j]=f[i-1][j-1]-d+get(i,j)
				,f[i][0]=max(f[i-1][j],f[i][0]);
		}
		for(int i=0;i<=k;++i)ans=max(ans,f[n][i]);
		printf("%lld\n",ans);
	}
	else if(c==17||c==18){
		for(int i=1;i<=m;++i){
			ll len=s[i].r-s[i].l+1;
			if(len<=k&&s[i].k>len*d)ans+=s[i].k-len*d;
		}
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		solve();
	}
	return 0;
}