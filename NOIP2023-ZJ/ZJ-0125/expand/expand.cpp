#include <bits/stdc++.h>
using namespace std;
int ID,n,m,ca,a[500005],b[500005],x[500005],y[500005],p,q;
int dp[2005][2005];
int dfs(int sx,int sy){
	if(~dp[sx][sy]) return dp[sx][sy];
	if(sx==n+1&&sy==m+1) return dp[sx][sy]=1;
	if(sx==n+1||sy==m+1) return dp[sx][sy]=0;
	if(x[sx]<=y[sy]) return dp[sx][sy]=0;
	for(int i=sy;i<=m&&x[sx]>y[i];i++) if(dfs(sx+1,i+1)) return dp[sx][sy]=1;
	for(int i=sx;i<=n&&x[i]>y[sy];i++) if(dfs(i+1,sy+1)) return dp[sx][sy]=1;
	return dp[sx][sy]=0;
}
void solve1(){
	for(int i=0;i<=ca;i++){
		int kx,ky;
		if(i) scanf("%d%d",&kx,&ky);
		else kx=ky=0;
		for(int i=1;i<=p;i++) x[i]=a[i];
		for(int i=1;i<=q;i++) y[i]=b[i];
		for(int i=1,u,v;i<=kx;i++) scanf("%d%d",&u,&v),x[u]=v;
		for(int i=1,u,v;i<=ky;i++) scanf("%d%d",&u,&v),y[u]=v;
		n=p,m=q;
		if(x[1]<y[1]&&x[n]>y[m]||x[1]>y[1]&&x[n]<y[m]||x[1]==y[1]||x[n]==y[m]){printf("0");continue;}
		if(x[1]<y[1]){
			swap(n,m);
			for(int i=1;i<=max(n,m);i++) swap(x[i],y[i]);
		}
		int minnx=2e9,minny=2e9,maxxx=-1,maxxy=-1;
		for(int i=1;i<=n;i++) minnx=min(minnx,x[i]),maxxx=max(maxxx,x[i]);
		for(int i=1;i<=m;i++) minny=min(minny,y[i]),maxxy=max(maxxy,y[i]);
		if(minnx<=minny||maxxx<=maxxy){printf("0");continue;}
		for(int i=1;i<=2001;i++) for(int j=1;j<=2001;j++) dp[i][j]=-1;
		printf("%d",dfs(1,1));
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&ID,&p,&q,&ca);
	for(int i=1;i<=p;i++) scanf("%d",&a[i]);
	for(int i=1;i<=q;i++) scanf("%d",&b[i]);
	solve1();
	return 0;
}
