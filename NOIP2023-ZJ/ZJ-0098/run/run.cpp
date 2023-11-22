#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;
inline ll Read(){
	int c;
	while((c=getchar())<48);
	ll R=c^48;
	while((c=getchar())>47)R=(R<<1)+(R<<3)+(c^48);
	return R;
}
int n,m,k;
ll d;
void sol1(){
	ll ans=0;
	for(int i=1;i<=m;i++){
		ll x,y,v;
		x=Read();y=Read();v=Read();
		v-=y*d;
		if(v>0)ans+=v;
	}
	printf("%lld\n",ans);
}
vector<pil> fes[1005];
ll f[1005][1005];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int ccc,T;
	scanf("%d%d",&ccc,&T);
	while(T--){
		scanf("%d%d%d%lld",&n,&m,&k,&d);
		if(n>1000){
			sol1();
			continue;
		}
		for(int i=1;i<=n;i++){
			fes[i].clear();
		}
		for(int i=1;i<=m;i++){
			int x,y;ll v;
			scanf("%d%d%lld",&x,&y,&v);
			fes[x].push_back(make_pair(y,v));
		}
		for(int i=1;i<=n;i++)if(fes[i].size()){
			sort(fes[i].begin(),fes[i].end());
		}
		for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
		f[i][j]=-1e16;
		f[0][0]=0;
		for(int i=1;i<=n;i++){
			f[i][0]=f[i-1][0];
			for(int j=1;j<=i-1&&j<=k;j++)
			f[i][0]=max(f[i][0],f[i-1][j]);
			ll sum=0;
			int pt=0;
			for(int j=1;j<=i&&j<=k;j++){
				f[i][j]=f[i-1][j-1]-d;
				while(pt<fes[i].size()&&fes[i][pt].first<=j){
					sum+=fes[i][pt].second;
					pt++;
				}
				f[i][j]=max(f[i][j],f[i-1][j-1]+sum-d);
			}
		}
		ll ans=f[n][0];
		for(int i=1;i<=n&&i<=k;i++){
			ans=max(ans,f[n][i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}