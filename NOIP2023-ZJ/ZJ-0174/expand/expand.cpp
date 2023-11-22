#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,A[5010],B[5010],a[5010],b[5010],f[2010][2010];
void solve(){
    if(a[n]==b[m]){
    	printf("0");
    	return ;
	}
	memset(f,0,sizeof(f));
	int op=(a[n]<b[m]);
	if(op){
		f[1][1]=(a[1]<b[1]);
		for(int i=1;i<=n;i++)
		    for(int j=1;j<=m;j++){
		    	if(i>1)f[i][j]|=(f[i-1][j]&(a[i]<b[j]));
		    	if(j>1)f[i][j]|=(f[i][j-1]&(a[i]<b[j]));
			}
			    
	}
	else{
		f[1][1]=(a[1]>b[1]);
		for(int i=1;i<=n;i++)
		    for(int j=1;j<=m;j++){
		    	if(i>1)f[i][j]|=(f[i-1][j]&(a[i]>b[j]));
		    	if(j>1)f[i][j]|=(f[i][j-1]&(a[i]>b[j]));
			}
	}
	printf("%d",f[n][m]);
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	for(int i=1;i<=m;i++)scanf("%d",&B[i]);
	for(int i=1;i<=n;i++)a[i]=A[i];
	for(int i=1;i<=m;i++)b[i]=B[i];
	solve();
	while(q--){
		int kx,ky;
		scanf("%d%d",&kx,&ky);
		for(int i=1;i<=n;i++)a[i]=A[i];
		for(int i=1;i<=m;i++)b[i]=B[i];
		for(int i=1;i<=kx;i++){
			int px,vx;
			scanf("%d%d",&px,&vx);
			a[px]=vx;
		}
		for(int i=1;i<=ky;i++){
			int py,vy;
			scanf("%d%d",&py,&vy);
			b[py]=vy;
		}
		solve();
	}
}