#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
const int inf=1e15;
int subtask,testcase;
int n,m,k,d;
int dp[1010][1010];
int w[1010][1010];
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	
	subtask=read();
	testcase=read();
	while(testcase--){
		n=read();m=read();k=read(),d=read();
		memset(w,0,sizeof w);
		for(int i=1;i<=m;i++){
			int u=read(),v=read(),o=read();
			w[u][v]+=o;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				w[i][j]+=w[i][j-1];
			}
		}
		memset(dp,0,sizeof dp);
		dp[0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=i-1;j++){
				dp[i][0]=max(dp[i][0],dp[i-1][j]);
			}
			for(int j=1;j<=min(i,k);j++){
				dp[i][j]=dp[i-1][j-1]+w[i][j]-d;
			}
		}
		int ans=0;
		for(int i=0;i<=min(n,k);i++){
			ans=max(ans,dp[n][i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

/*

ni wan yuan shen ma ?

ni wan yuan shen wan de ba !

ni gai hui ba !

--thomas_zjl

*/
