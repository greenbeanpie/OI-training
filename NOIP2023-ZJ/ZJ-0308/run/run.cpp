#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10,inf=0x7fffffffffffffff;
int C,T,n,m,k,d,lim;
int f[N][N],chifan[N][N],ans;
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--){
		memset(f,-0x3f,sizeof f);
		memset(chifan,0,sizeof chifan);
		cin>>n>>m>>k>>d;
		while(m--){
			int x,y,w;
			cin>>x>>y>>w;
			chifan[x][y]+=w;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k;j++)
				chifan[i][j]+=chifan[i][j-1];
		f[0][0]=0;
		for(int i=1;i<=n;i++){
			f[i][0]=f[i-1][0];
			lim=min(i,k);
			for(int j=1;j<=lim;j++){
				f[i][j]=f[i-j][0]-d*j;
				f[i][0]=max(f[i][0],f[i-1][j]);
			}
			for(int j=0;j<=k;j++)f[i][j]+=chifan[i][j];
		}
		ans=-inf;
		for(int i=0;i<=k;i++)ans=max(ans,f[n][i]);
		cout<<ans<<'\n';
	}
	return 0;
}