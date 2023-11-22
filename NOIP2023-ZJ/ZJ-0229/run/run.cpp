#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5,inf=(1ll<<60);
int n,m,k,d;
int w[N][N],f[N][N];
void solve(){
	cin>>n>>m>>k>>d;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=min(i,k);j++){
			w[i][j]=0;
			f[i][j]=-(1ll<<60);
		}
	}
	for(int i=1;i<=m;i++){
		int x,y,v;
		cin>>x>>y>>v;
		w[x][y]=v;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=min(i,k);j++){
			w[i][j]+=w[i][j-1];
		}
		for(int j=1;j<=min(i,k);j++){
			w[i][j]+=w[i-1][j-1];
		}
	}
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=min(i-1,k);j++) f[i][0]=max(f[i][0],f[i-1][j]);
		for(int j=1;j<=min(i,k);j++){
			f[i][j]=max(f[i][j],f[i-j][0]+w[i][j]-j*d);
		}
	}
	int ans=-inf;
	for(int i=0;i<=min(n,k);i++){
		ans=max(ans,f[n][i]);
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--) solve();
}

