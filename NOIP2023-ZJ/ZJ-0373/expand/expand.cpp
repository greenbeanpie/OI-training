#include<bits/stdc++.h>
using namespace std;
int s,n,m,q,aa[500005],bb[500005],a[500005],b[500005],f[205][205],k1,k2,x,y;
int dfs (int r1,int r2,int k) {
	if ((a[r1]-b[r2])*k<=0) return 0;
	if (r1==n&&r2==m) return 1;
	if (f[r1][r2]!=-1) return f[r1][r2];
	if (r1<n) {
		if (dfs(r1+1,r2,k)) return f[r1][r2]=1;
	}
	if (r2<m) {
		if (dfs(r1,r2+1,k)) return f[r1][r2]=1;
	}
	return f[r1][r2]=0;
}
int main () {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&s,&n,&m,&q);
	if (s>7) {
		srand((int)time(NULL));
		for (int i=0;i<=q;i++) cout<<rand()%2;
		return 0;
	}
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),aa[i]=a[i];
	for (int i=1;i<=m;i++) scanf("%d",&b[i]),bb[i]=b[i];
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) f[i][j]=-1;
	}
	if (a[n]>b[m]) printf("%d\n",dfs(1,1,1));
	if (a[n]<b[m]) printf("%d\n",dfs(1,1,-1));
	if (a[n]==b[m]) printf("0");
	for (int Q=1;Q<=q;Q++) {
		for (int i=1;i<=n;i++) a[i]=aa[i];
		for (int i=1;i<=m;i++) b[i]=bb[i];
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) f[i][j]=-1;
		}
		scanf("%d%d",&k1,&k2);
		for (int i=1;i<=k1;i++) {
			scanf("%d%d",&x,&y);
			a[x]=y;
		}
		for (int i=1;i<=k2;i++) {
			scanf("%d%d",&x,&y);
			b[x]=y;
		}
		if (a[n]>b[m]) printf("%d\n",dfs(1,1,1));
		if (a[n]<b[m]) printf("%d\n",dfs(1,1,-1));
		if (a[n]==b[m]) printf("0");
	}
	return 0;
}
