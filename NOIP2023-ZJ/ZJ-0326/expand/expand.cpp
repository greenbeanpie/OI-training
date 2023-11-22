#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=2007;
ll c,q,n,m,a[M],b[M],tmp[M],kx,ky,ta[M],tb[M];
bool dp[M+M][M],ok,op;
void work(){
	for(int i=0;i<=n+m;i++)
		for(int j=0;j<=n+1;j++)
			dp[i][j]=0;
	ok=0;
	if(a[1]==b[1]) dp[1][1]=0;
	else dp[1][1]=1;
	for(int i=2;i<=n+m-1;i++)
		for(int j=1;j<=min((ll)i,n);j++){
			if((dp[i-1][j] || dp[i-1][j-1])&&((a[j]-b[i+1-j])*(a[1]-b[1])>0)) dp[i][j]=1;
		}
	if(dp[n+m-1][n]) putchar('1');
	else putchar('0');
	return;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%lld%lld%lld%lld",&c,&n,&m,&q);
	if(c<=7){
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<=m;i++)
			scanf("%lld",&b[i]);
		work();
		while(q--){
			for(int i=1;i<=n;i++) ta[i]=a[i];
			for(int i=1;i<=m;i++) tb[i]=b[i];
			scanf("%lld%lld",&kx,&ky);
			for(int i=1,p,v;i<=kx;i++)
				scanf("%d%d",&p,&v),a[p]=v;
			for(int i=1,p,v;i<=ky;i++)
				scanf("%d%d",&p,&v),b[p]=v;
			work();
			for(int i=1;i<=n;i++) a[i]=ta[i];
			for(int i=1;i<=m;i++) b[i]=tb[i];
		}
	}
	return 0;
}