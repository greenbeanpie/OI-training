#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,t,n,m,k,cnt;
long long dp[1005][1005],val[1005][1005],v[N],v1[N],len[N][3],d,x[N],y[N],x1[N],Y1[N];
long long f[N][3];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d", &c, &t);
	while(t--){
		scanf("%d%d%d%lld", &n, &m, &k, &d);
		if(n<=1000 && m<=1000){
			memset(val,0,sizeof(val));
			for(int i = 1; i <= n; i++){
				dp[i][0]=0;
				for(int j = 1; j <= min(i,k); j++) dp[i][j]=-(1e18+5);
			}
			dp[0][0]=0;
			for(int i = 1; i <= m; i++){
				scanf("%lld%lld%lld", &x[i], &y[i], &v[i]);
				for(int j = y[i]; j <= min(x[i],(long long)k); j++) val[x[i]][j]+=v[i];
			}
			for(int i = 1; i <= n; i++){
				for(int j = 0; j <= min(i-1,k); j++) dp[i][0]=max(dp[i][0],dp[i-1][j]);
			//	printf("dp[%d][0]=%lld\n", i, dp[i][0]);
				for(int j = 1; j <= min(i,k); j++) dp[i][j]=max(dp[i][j],dp[i-1][j-1]-d+val[i][j]);// printf("dp[%d][%d]=%lld\n", i,j,dp[i][j]);
			}
			long long ans=-(1e18+5);
			for(int i = 0; i <= min(k,n); i++) ans=max(ans,dp[n][i]);
			printf("%lld\n", ans);
		}else if(c==17 || c==18){
			x1[0]=-(1e9+5);
			f[0][1]=-(1e18+5);
			cnt=0;
			for(int i = 1; i <= m; i++) f[i][0]=0,f[i][1]=f[i][2]-(1e18+5);
			for(int i = 1; i <= m; i++){
				scanf("%lld%lld%lld", &x[i], &y[i], &v[i]);
				if(y[i]<=k && y[i]*d<v[i]){
					x1[++cnt]=x[i];
					Y1[cnt]=y[i];
					v1[cnt]=v[i];
				}
			}
			for(int i = 1; i <= cnt; i++){
				f[i][0]=max(f[i][0],max(f[i-1][0],max(f[i-1][2],f[i-1][1])));
				if(x1[i-1]<x1[i]-Y1[i]) f[i][1]=max(f[i][1],max(f[i-1][0],max(f[i-1][1],f[i-1][2]))-Y1[i]*d+v1[i]),len[i][1]=Y1[i];
				else{
					f[i][1]=max(f[i][1],f[i-1][0]-Y1[i]*d+v[i]);len[i][1]=Y1[i];
					if(len[i][1]+Y1[i]<=k && f[i][2]<f[i-1][1]-Y1[i]*d+v1[i]){
						f[i][2]=f[i-1][1]-Y1[i]*d+v1[i];
						len[i][2]=len[i][1]+Y1[i];
					}
					if(len[i][2]+Y1[i]<=k && f[i][2]<f[i-1][2]-Y1[i]*d+v1[i]){
						f[i][2]=f[i-1][2]-Y1[i]*d+v1[i];
						len[i][2]=len[i][2]+Y1[i];
					}
				}
			}
			printf("%lld\n", max(f[m][0],max(f[m][2],f[m][1])));
		}
	}
	return 0;
}
