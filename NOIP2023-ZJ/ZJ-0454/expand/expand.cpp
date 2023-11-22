#include<bits/stdc++.h>
using namespace std;
const int N=4e3+10;
int c,n,m,q;
int a[N],b[N];
int ca[N],cb[N];
int dp[N][N];
int kx,ky;
int px[N],vx[N],py[N],vy[N];
void wrk(){
	cin>>kx>>ky;
	for(int i=1;i<=kx;i++) scanf("%d%d",&px[i],&vx[i]),a[px[i]]=vx[i];
	for(int i=1;i<=ky;i++) scanf("%d%d",&py[i],&vy[i]),b[py[i]]=vy[i];
//	printf("\n\n\n");
//	for(int i=1;i<=n;i++) printf("%d ",a[i]);printf("\n");
//	for(int i=1;i<=n;i++) printf("%d ",b[i]);printf("\n");
}
int getans1(){
	for(int i=1;i<=n+10;i++)
		for(int j=1;j<=m+10;j++) dp[i][j]=0;
	if(a[1]>b[1]) dp[1][1]=1;//printf("A");
	else return 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(dp[i][j]==0) continue;
			if(i+1<=n&&a[i+1]>b[j]) dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			if(j+1<=m&&a[i]>b[j+1]) dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
			if(i+1<=n&&j+1<=m&&a[i+1]>b[j+1])
				dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
		}
	return dp[n][m];
}
int getans2(){
	for(int i=1;i<=n+10;i++)
		for(int j=1;j<=m+10;j++) dp[i][j]=0;
	if(a[1]<b[1]) dp[1][1]=1;
	else return 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(dp[i][j]==0) continue;
			if(i+1<=n&&a[i+1]<b[j]) dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			if(j+1<=m&&a[i]<b[j+1]) dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
			if(i+1<=n&&j+1<=m&&a[i+1]<b[j+1])
				dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
		}
	return dp[n][m];
}
void remv(){
	for(int i=1;i<=kx;i++) a[px[i]]=ca[px[i]];
	for(int i=1;i<=ky;i++) b[py[i]]=cb[py[i]];
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	if(c>4e3+10){
		for(int i=1;i<=q;i++) printf("1");
		return 0;
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++) ca[i]=a[i];
	for(int i=1;i<=m;i++) cb[i]=b[i];
	printf("%d",max(getans1(),getans2()));
	for(int i=1;i<=q;i++)
		wrk(),printf("%d",max(getans1(),getans2())),remv();
	
//	printf("%d %d\n",getans1(),getans2());
//	for(int i=1;i<=q-1;i++) 
//		wrk(),printf("%d %d\n",getans1(),getans2()),remv();
//	
//	printf("\n\n\n");wrk();
//	for(int i=1;i<=n;i++) printf("%d ",a[i]);printf("\n");
//	for(int i=1;i<=m;i++) printf("%d ",b[i]);printf("\n");
//		printf("%d\n",getans1()),remv();
	return 0;
}
