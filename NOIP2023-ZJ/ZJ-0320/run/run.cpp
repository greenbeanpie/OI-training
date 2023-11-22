#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e5+5,M=1e3+5;
int tt,t,n,m,k;
ll d,ans,x,y,v,dp[M][M],f[M];

int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>tt>>t;
	if(tt<=7){
		while(t--){
			cin>>n>>m>>k>>d,ans=0,memset(dp,0,sizeof dp);
			for(int o=1;o<=m;o++){
				scanf("%lld%lld%lld",&x,&y,&v);
				for(int i=1;i<=x-y+1;i++){
					for(int j=x;j<=n;j++) dp[i][j]+=v;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=i&&i-j+1<=k;j++){
					f[i]=max(f[i],f[j-2]+dp[j][i]-d*(i-j+1));
				}
				ans=max(ans,f[i]);
			}
			cout<<ans<<"\n";
		}
	}else{
		while(t--){
			cin>>n>>m>>k>>d,ans=0;
			for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&x,&x,&v),ans+=max((x<=k)*(v-d*x),0ll);
			cout<<ans<<"\n";
		}
	}
}
