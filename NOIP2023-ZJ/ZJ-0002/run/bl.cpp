#include<bits/stdc++.h>
using namespace std;
constexpr int N=1000;
typedef long long ll;
inline void up(ll &x,ll y){if(y>x) x=y;}
ll a[N+10][N+10],f[N+10][N+10];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cid,T;
	cin>>cid>>T;
	while(T--){
		int n,m,K,d;
		cin>>n>>m>>K>>d;
		memset(a,0,sizeof(a));
		int i,j;
		for(i=1;i<=m;++i){
			int x,y,v;
			cin>>x>>y>>v;
			if(y>K) continue;
			a[x][y]+=v;
		}
		memset(f,192,sizeof(f));
		f[0][0]=0;
		for(i=1;i<=n;++i){
			for(j=0;j<=K;++j) up(f[i][0],f[i-1][j]);
			ll sum=0;
			for(j=1;j<=K;++j){
				sum+=a[i][j];
				f[i][j]=f[i-1][j-1]+sum-d;
			}
		}
		ll ans=0;
		for(i=0;i<=K;++i) up(ans,f[n][i]);
		cout<<ans<<'\n';
	}
	return 0;
}
