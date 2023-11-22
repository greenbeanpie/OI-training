#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18
const int maxn=1e3+5;
const int maxm=1e5+5;
int opt,T;
int n,m,k,d;
int v[maxn][maxn];
int f[maxn][maxn],mx[maxn];
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
    cin.tie(0),cout.tie(0);
	cin>>opt>>T;
	while(T--){
		cin>>n>>m>>k>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=min(i,k);j++){
				f[i][j]=v[i][j]=0;
			}
		}
		mx[0]=0;
		for(int i=1;i<=m;i++){
			int t,p;
			cin>>t>>p;
			cin>>v[t][p];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=min(i,k);j++){
				v[i][j]+=v[i][j-1];
			}
		}
		for(int i=1;i<=n;i++){
			mx[i]=f[i][0]=mx[i-1];
			for(int j=1;j<=min(i,k);j++){
				f[i][j]=f[i-1][j-1]-d+v[i][j];
				mx[i]=max(mx[i],f[i][j]);
			}
		}
		cout<<mx[n]<<endl;
	}
    return 0;
}