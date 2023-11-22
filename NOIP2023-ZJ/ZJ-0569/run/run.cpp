#include<bits/stdc++.h>
using namespace std;
long long c,T;
long long n,m,k,d,ans;
map<pair<long long,long long>,long long>mp;
long long run[100];
void check() {
	long long qz[100],sum=0;
	qz[0]=0;
	for(long long i=1; i<=n; i++) {
		if(run[i]==1) qz[i]=qz[i-1]+1,sum-=d;
		else qz[i]=0;
		if(qz[i]>k) return ;
	}
//	for(long long i=1; i<=n; i++) cout<<run[i]<<" ";
//	cout<<endl;
//	for(long long i=1; i<=n; i++) cout<<qz[i]<<" ";
//	cout<<endl;
//	cout<<sum<<endl;
	for(long long i=1; i<=n; i++) {
		for(long long j=1; j<=qz[i]; j++) if(mp[make_pair(i,j)]!=0) sum+=mp[make_pair(i,j)];
	}
	ans=max(ans,sum);
//	cout<<ans<<"	"<<sum<<endl<<endl;
	return ;
}
void dfs(long long step) {
//	cout<<step<<endl;
	if(step==n+1) {
		check();
		return ;
	}
	dfs(step+1);
	run[step]=1;
	dfs(step+1);
	run[step]=0;
}
int main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--) {
		mp.clear();
		ans=0;
		scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		long long x,y,v;
		for(long long i=1; i<=m; i++) {
			scanf("%lld%lld%lld",&x,&y,&v);
			mp[make_pair(x,y)]+=v;
		}
		dfs(1);
		printf("%lld\n",ans);
	}
	return 0;
}