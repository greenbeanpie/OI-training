#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+5;
int n,m,k,d,c;
ll w[N][N],f[N][N];
void solve(){
    scanf("%d%d%d%d",&n,&m,&k,&d);
    if(c==17||c==18){
    	ll sum=0;
	    while(m--){
	        int x,y,v;
	        scanf("%d%d%d",&x,&y,&v);
	        if(y<=k)sum+=max(0ll,v-(1ll*y*d));
	    }
	    printf("%lld\n",sum);
	    return;
	}
    for(int i=0;i<=n;i++)
        for(int j=0;j<=i;j++)
            w[i][j]=0,f[i][j]=-1e18;
    while(m--){
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        w[x][y]+=v;
    }
    f[0][0]=0;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=min(i,k);j++)w[i][j]+=w[i][j-1];
        for(int j=0;j<min(i,k+1);j++){
            f[i][0]=max(f[i][0],f[i-1][j]);
            f[i][j+1]=max(f[i][j+1],f[i-1][j]+w[i][j+1]-d);
        }
    }
    ll ans=-1e18;
    for(int j=0;j<=k;j++)ans=max(ans,f[n][j]);
    printf("%lld\n",ans);
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
    int t;
    scanf("%d%d",&c,&t);
    while(t--)solve();
    return 0;
}