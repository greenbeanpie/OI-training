#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int w=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) w=w*10+ch-'0',ch=getchar();
	return w;
}
int n,m,q;
int x[500005],y[500005],sx[500005],sy[500005];
int flag;
bool check(int lv,int rv){return flag?lv>rv:lv<rv;}
int dp[2005][2005];
int solve(int nf){
	flag=nf;
//	for(int i=1;i<=n;i++) printf("%d ",x[i]);puts("");
//	for(int i=1;i<=m;i++) printf("%d ",y[i]);puts("");
	if(!check(x[1],y[1])) return 0;
	if(!check(x[n],y[m])) return 0;
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(!dp[i][j]) continue;
			if(i<n&&j&&check(x[i+1],y[j])) dp[i+1][j]=1;
			if(j<m&&i&&check(x[i],y[j+1])) dp[i][j+1]=1;
			if(i<n&&j<m&&check(x[i+1],y[j+1])) dp[i+1][j+1]=1;
		}
	}
	return dp[n][m];
}
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	read();n=read(),m=read();q=read();
	for(int i=1;i<=n;i++) sx[i]=x[i]=read();
	for(int i=1;i<=m;i++) sy[i]=y[i]=read();
	putchar((solve(0)||solve(1))+'0');
	while(q--){
		int kx=read(),ky=read();
		while(kx--){
			int u=read(),v=read();
			x[u]=v;
		}
		while(ky--){
			int u=read(),v=read();
			y[u]=v;
		}
		putchar((solve(0)||solve(1))+'0');
		for(int i=1;i<=n;i++) x[i]=sx[i];
		for(int i=1;i<=m;i++) y[i]=sy[i];
	}
	return 0;
}