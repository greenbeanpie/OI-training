#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3+10;
int v[N][N];
int f[N][N];
int n,m,ID,k,d,T;
void solve(){
	cin>>n>>m>>k>>d;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		v[x][y]+=z;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k&&j<=i;j++) v[i][j]+=v[i][j-1];
	}
	for(int i=1;i<=n+1;i++){
		for(int j=0;j<=i-1&&j<=k;j++) f[i][0]=max(f[i-1][j],f[i][0]);
		for(int j=1;j<=i&&j<=k;j++) f[i][j]=f[i-1][j-1]-d+v[i][j];
	}
	cout<<f[n+1][0]<<endl;
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>ID>>T;
	while(T--){
		memset(v,0,sizeof v);
		memset(f,0,sizeof f);
		solve();
	}
	return 0;
}