#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
int cs,n,m,q,kx,ky,f[maxn][maxn],a[maxn],b[maxn],g[maxn][maxn],c[maxn],d[maxn];
bool sol(){
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)f[i][j]=g[i][j]=0;
	f[0][0]=g[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]|=(f[i-1][j]&&(c[i]>d[j]));
			f[i][j]|=(f[i][j-1]&&(c[i]>d[j]));
			f[i][j]|=(f[i-1][j-1]&&(c[i]>d[j]));
			g[i][j]|=(g[i-1][j]&&(c[i]<d[j]));
			g[i][j]|=(g[i][j-1]&&(c[i]<d[j]));
			g[i][j]|=(g[i-1][j-1]&&(c[i]<d[j]));
		}
	}
	return f[n][m]||g[n][m];
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&cs,&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)c[i]=a[i];
	for(int i=1;i<=m;i++)d[i]=b[i];	
	if(sol())printf("1");
	else printf("0");
	if(cs<=7){
		while(q--){
			scanf("%d%d",&kx,&ky);
			for(int x,y,i=1;i<=kx;i++)
				scanf("%d%d",&x,&y),c[x]=y;
			for(int x,y,i=1;i<=ky;i++)
				scanf("%d%d",&x,&y),d[x]=y;
//			for(int i=1;i<=n;i++)cout<<c[i]<<" ";
//			cout<<endl;
//			for(int i=1;i<=m;i++)cout<<d[i]<<" ";
//			cout<<endl;
			if(sol())printf("1");
			else printf("0");
			for(int i=1;i<=n;i++)c[i]=a[i];
			for(int i=1;i<=m;i++)d[i]=b[i];		
		}
	}
	return 0;
}
/*
908769963 747202998 695274448 912972658 681355925 855511382
741380908 725577864 753807716 615096979 827516564 688016923	
*/
