#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1007,N=100007;
ll c,t,dp[M][M],n,m,k,lnk,d,mxdp[M];
struct node{
	ll x,y,v;
}task[N];
bool cmp(node a,node b){
	return a.x<b.x;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		for(int i=1;i<=m;i++)
			scanf("%lld%lld%lld",&task[i].x,&task[i].y,&task[i].v);
		sort(task+1,task+1+m,cmp),lnk=1;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=k;j++) dp[i][j]=0;
		for(int i=0;i<=n;i++) mxdp[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=min((ll)i,k);j++){
				if(j==0) dp[i][j]=mxdp[i-1];
				else dp[i][j]=dp[i-1][j-1]-d;
				mxdp[i]=max(mxdp[i],dp[i][j]);
			}
			while(lnk<=m && task[lnk].x==i){
				for(int j=task[lnk].y;j<=min((ll)i,k);j++){
					dp[i][j]+=task[lnk].v;
					mxdp[i]=max(mxdp[i],dp[i][j]);
				}
				lnk++;
			}
		}
		printf("%lld\n",mxdp[n]);
	}
	return 0;
}