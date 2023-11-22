#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	char c=getchar();
	int res=0,b=1;
	while(!isdigit(c)){
		if(c=='-') b=-1;
		c=getchar();
	}
	while(isdigit(c)){
		res=res*10+(c^48);
		c=getchar();
	}
	return res*b;
}
inline void write(long long  x){
	if(x<0) putchar('-'),x=-x;
	if(x>9){
		write(x/10);
		putchar(x%10+'0');
	}
	else {
		putchar(x+'0');
	}
}
inline bool print(int x){
	write(x);
	putchar(' ');
	return 0;
}
inline bool put(int x){
	write(x);
	putchar('\n');
	return 0;
}
int c,t;
int n,m,k,d;
int calg[1005][1005];
namespace sub1{
	long long dp[1005][1005];
	int main(){
		//for(i=0;i<=k;++i) dp[0][i]=-998244353;
		memset(calg,0,sizeof calg);
		memset(dp,0,sizeof dp);
		n=read(),m=read(),k=read(),d=read();
		for(int i=1;i<=m;++i){
			int x=read(),y=read(),z=read();
			calg[x][y]+=z;
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=k;++j){
				calg[i][j]+=calg[i][j-1];
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=0;j<=min(k,n-1);++j)
				dp[i][0]=max(dp[i-1][j],dp[i][0]);
			for(int j=1;j<=min(k,i);++j){
				//cout<<i<<" "<<j<<" "<<dp[i-1][j-1]<<" "<<calg[(chal){i,j}]<<endl;
				dp[i][j]=dp[i-1][j-1]-d+calg[i][j];
			}
		}
		long long ans=0;
		for(int i=0;i<=k;++i){
			//cout<<dp[n][i]<<" ";
			ans=max(ans,dp[n][i]);
		}
		put(ans);
		//cout<<" dd";
		return 0;
	}
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read(),t=read();
	if(c<=7){
		while(t--){
			sub1::main();
		}
	}
	return 0;
}