#include<bits/stdc++.h>
#define N 2005
using namespace std;
int Type,q,f[N][N],n,m,a[N],b[N],c[N],d[N];
int checkA(){//拓展后A的每个元素都比B大 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			f[i][j]=0;
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			f[i][j]=max(f[i-1][j-1],max(f[i-1][j],f[i][j-1]))*(a[i]>b[j]);
	return f[n][m];
}
int checkB(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			f[i][j]=0;
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			f[i][j]=max(f[i-1][j-1],max(f[i-1][j],f[i][j-1]))*(a[i]<b[j]);
	return f[n][m];
}
void solve(){
	//cout<<a[n]<<" "<<b[m]<<" "<<(a[n]>b[m])<<" "<<(a[n]<b[m])<<endl;
	//cout<<checkA()<<" "<<checkB()<<endl; 
	if(checkA()||checkB())printf("1");
		else printf("0");
}
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d %d %d %d",&Type,&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int j=1;j<=m;j++)scanf("%d",&b[j]);
	solve();
	while(q--){
		for(int i=1;i<=n;i++)c[i]=a[i];
		for(int j=1;j<=m;j++)d[j]=b[j];
		int kx,ky;scanf("%d %d",&kx,&ky);
		for(int i=1,p,v;i<=kx;i++){
			scanf("%d %d",&p,&v);a[p]=v;
		}
		for(int i=1,p,v;i<=ky;i++){
			scanf("%d %d",&p,&v);b[p]=v;
		}
		solve();
		for(int i=1;i<=n;i++)a[i]=c[i];
		for(int j=1;j<=m;j++)b[j]=d[j];
	}
}

