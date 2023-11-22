#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int c,t,n,m,k,d,x[maxn],y[maxn],v[maxn],a[maxn],b[maxn];
long long ans;
void dfs(int step){
	if(step==n+1){
		long long tmp=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]) b[i]=++tmp,cnt-=d;
			else b[i]=tmp=0;
			if(tmp>k) return ;
		}for(int i=1;i<=m;i++) if(b[x[i]]>=y[i]) cnt+=v[i];
		ans=max(ans,cnt);
		return ;
	}a[step]=0;
	dfs(step+1);
	a[step]=1;
	dfs(step+1);
}int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t ;
	while(t--){
		ans=0;
		cin >> n >> m >> k >> d ;
		for(int i=1;i<=m;i++) cin >> x[i] >> y[i] >> v[i] ;
		dfs(1);
		cout << ans << "\n" ;
	}return 0;
}