#include<bits/stdc++.h>
using namespace std;
const int N = 500050;
const int M = 2010;
int dp[M][M];
int a[N],b[N],tmp1[N],tmp2[N];
int c,n,m,q,kx,ky,p,v;
bool check(){
	if(a[1] == b[1]) return false;
	memset(dp,0,sizeof(dp));
	dp[1][1] = 1;
	if(a[1] < b[1]){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++)if(dp[i][j] != 0){
				if(i != n && a[i+1] < b[j]) dp[i+1][j] = 1;
				if(j != m && a[i] < b[j+1]) dp[i][j+1] = 1;
				if(i != n && j != m && a[i+1] < b[j+1]) dp[i+1][j+1] = 1;
			}
		}
	}
	else{
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++)if(dp[i][j] != 0){
				if(i != n && a[i+1] > b[j]) dp[i+1][j] = 1;
				if(j != m && a[i] > b[j+1]) dp[i][j+1] = 1;
				if(i != n && j != m && a[i+1] > b[j+1]) dp[i+1][j+1] = 1;
			}
		}
	}
	return dp[n][m];
}
void solve1(){
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for(int i = 1;i <= m;i++) scanf("%d",&b[i]);
	for(int i = 1;i <= n;i++) tmp1[i] = a[i];
	for(int i = 1;i <= m;i++) tmp2[i] = b[i];
	if(check()) putchar('1');
	else putchar('0');
	for(int i = 1;i <= q;i++){
		for(int i = 1;i <= n;i++) a[i] = tmp1[i];
		for(int i = 1;i <= m;i++) b[i] = tmp2[i];
		scanf("%d%d",&kx,&ky);
		for(int j = 1;j <= kx;j++){
			scanf("%d%d",&p,&v);
			a[p] = v;
		}
		for(int j = 1;j <= ky;j++){
			scanf("%d%d",&p,&v);
			b[p] = v;
		}
		if(check()) putchar('1');
		else putchar('0');
	}
}
int main(){
	//35
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	solve1();
	return 0;
}