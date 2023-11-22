#include<bits/stdc++.h>
#define int long long
using namespace std; 
int winc,T;
namespace subtask1{ constexpr int maxn(2e3+10),inf(1e15+7);
	int n,m,k,d,f[maxn][maxn],x[maxn],y[maxn],v[maxn];
	int vis[maxn][maxn],sum[maxn][maxn]; // di x tian pao le y
// f[i][j] daibiao dao i tian lian xu pao le j tian de zui da zhi
	inline void solve(){
		cin >> n >> m >> k >> d;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=k;j++)
				vis[i][j]=0;
		for(int i=0;i<=n;i++) for(int j=0;j<=k;j++){
			if(j==0) f[i][j]=0; else f[i][j]=-inf;
		}
		for(int i=1;i<=m;i++){
			cin >> x[i] >> y[i] >> v[i];
			vis[x[i]][y[i]]+=v[i];
			for(int j=y[i]+1;j<=k;j++)
				vis[x[i]][j]+=v[i];
		}
		for(int i=0;i<n;i++) for(int j=0;j<=k;j++){
			if(j==k){
				f[i+1][0]=max(f[i+1][0],f[i][j]);
			}else{
				if(vis[i+1][j+1])
					f[i+1][j+1]=max(f[i+1][j+1],f[i][j]-d+vis[i+1][j+1]);
				f[i+1][j+1]=max(f[i+1][j+1],f[i][j]-d),f[i+1][0]=max(f[i+1][0],f[i][j]);
			}
		} int ans=0; for(int j=0;j<=k;j++) ans=max(ans,f[n][j]);
		cout << ans << '\n';
	}
}
signed main(){ freopen("run.in","r",stdin),freopen("run.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin >> winc >> T;
	if(winc<=9) while(T--) subtask1::solve();
	return 0;
}