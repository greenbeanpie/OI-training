#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,x,y,z) for(ll i=x;i<=y;i+=z)
#define fd(i,x,y,z) for(ll i=x;i>=y;i-=z)
ll c,T;
ll n,m,k,d;
ll dp[1005][1005];
struct Node{
	ll tim,dat;
};
vector<Node> v[1005];
bool cmp(Node x,Node y){
	return x.tim<y.tim;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		f(i,1,m,1){
			ll xx,yy,zz;
			scanf("%lld%lld%lld",&xx,&yy,&zz);
			if(n<=1000){
				v[xx].push_back(Node{
					yy,zz	
				});
			}
			
		}
		if(n<=1000){
			f(i,1,n,1){
				if(v[i].size()){
					sort(v[i].begin(),v[i].end(),cmp);
				}
			}
			dp[0][0]=0;
			f(i,1,n,1){
				ll sm=0,tp=0;
				f(j,1,k,1){
					dp[i][j]=dp[i-1][j-1]-d;
					if(v[i].size()){
						while(j>=v[i][tp].tim){
							if(tp==v[i].size()){
								break;
							}
							sm+=v[i][tp].dat;
							tp++;
						}
						dp[i][j]+=sm;
					}
				}
				f(j,0,k,1){
					dp[i][0]=max(dp[i][0],dp[i-1][j]);
				}
			}
			ll ans=0;
			f(i,0,k,1){
				//printf("%lld ",dp[n][i]);
				ans=max(ans,dp[n][i]);
			}
			//printf("\n");
			printf("%lld\n",ans);
			f(i,1,n,1){
				v[i].clear();
			}
			f(i,1,n,1){
				f(j,0,k,1){
					dp[i][j]=0;
				}
			}
		}
		else{
			puts("0");
		}
	}
	return 0;
}
