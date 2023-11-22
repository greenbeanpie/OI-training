#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
using LL=long long;
using pii=pair<int,int>;
const int N=1e3+9;
LL dp[N][N],n,m,ma[N];
vector<pii> v[N];
int CDX,_;
void solve(){
    int n,m,k,d;
    scanf("%d%d%d%d",&n,&m,&k,&d);
    for(int i=1;i<=n;i++) v[i].clear();
    for(int x,y,val,i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&val);
        v[x].push_back({y,val});
    }
    for(int i=1;i<=n;i++){
        ma[i]=-1e17;
        for(int j=0;j<=min(k,i);++j){
            if(j)dp[i][j]=dp[i-1][j-1]-d;
            else dp[i][j]=ma[i-1];
            for(pii t:v[i]){
                if(j>=t.first) dp[i][j]+=t.second;
            }
            ma[i]=max(ma[i],dp[i][j]);
        }
    }
    printf("%lld\n",ma[n]);
}
int main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
    scanf("%d%d",&CDX,&_);
    while(_--){
        solve();
    }
	return 0;
}