#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n,i,j,k,m,useless,t,x,num1,num2,num3;
LL dp[1005][1005];
queue<LL> q1[1005],q2[1005];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&useless,&t);
	if(useless>9){
		while(t--){
			scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
			LL ans=0;
			for(i=1;i<=m;i++){
				scanf("%lld%lld%lld",&num1,&num2,&num3);
				ans+=max(0ll,num3-num2*x);
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
	while(t--){
		scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
		for(i=1;i<=m;i++){
			scanf("%lld%lld%lld",&num1,&num2,&num3);
			q1[num1].push(num2),q2[num1].push(num3);
	    }
	    memset(dp,-0x7f,sizeof(dp));
		dp[0][0]=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=k;j++)
			  dp[i][j]=dp[i-1][j-1]-x;
			for(j=0;j<=k;j++)
			  dp[i][0]=max(dp[i][0],dp[i-1][j]);
			while(!q1[i].empty()){
				LL num=q1[i].front(),val=q2[i].front();
				for(j=num;j<=k;j++)
				  dp[i][j]+=val;
				q1[i].pop();q2[i].pop();
			}
		}
		LL ans=0;
		for(i=0;i<=k;i++){
			ans=max(ans,dp[n][i]);
		}
		printf("%lld\n",ans);
	}
}
