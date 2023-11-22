#include<bits/stdc++.h>
#define rep(i,l,r) for(int i = (l); i <= (r); ++i)
#define per(i,r,l) for(int i = (r); i <= (l); --i)
#define N 2005
using namespace std;

int read(){
	int x = 0, w = 1; char ch = getchar();
	while(ch > '9' || ch < '0'){if(ch == '-') w = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') x = (x<<1) + (x<<3) + (ch^48), ch = getchar();
	return x*w;
}

int c,n,m,q;

int a[N],b[N],a1[N],b1[N],ans[N];
int dp[N][N];

bool check(){
	int pos = 1;
	memset(dp,0,sizeof(dp));
	if(a[1] > b[1]) dp[1][1] = 1;
	rep(i,1,n) rep(j,1,m){
		if(a[i] <= b[j]) continue;
		if(dp[i-1][j-1] || dp[i][j-1] ||dp[i-1][j])dp[i][j] = 1;
	}
	if(dp[n][m]) return 1;
	memset(dp,0,sizeof(dp));
	if(a[1] < b[1]) dp[1][1] = 1;
	rep(i,1,n) rep(j,1,m){
		if(a[i] >= b[j]) continue;
		if(dp[i-1][j-1] || dp[i][j-1] || dp[i-1][j]) dp[i][j] = 1;
	}
	if(dp[n][m]) return 1;
	return 0;
}

signed main(){
	
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	
	c = read(); n = read(); m = read(); q = read();
	rep(i,1,n) a[i] = read(),a1[i] = a[i];
	rep(i,1,m) b[i] = read(),b1[i] = b[i];
	if(check()) ans[0] = 1;
	rep(j,1,q){
		int k1 = read(),k2 = read();
		rep(i,1,k1){
			int x = read(), y = read();
			a[x] = y;
		}
		rep(i,1,k2){
			int x = read(), y = read();
			b[x] = y;
		}
		if(check()) ans[j] = 1;
		rep(i,1,n) a[i] = a1[i];
		rep(i,1,m) b[i] = b1[i];
	}
	rep(i,0,q) printf("%d",ans[i]);
	return 0;
}
