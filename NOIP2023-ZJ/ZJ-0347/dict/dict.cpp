#include<iostream>
#include<cstdio>
#define maxn 3005
using namespace std;
int n,m; char a[maxn][maxn],mmin[maxn],mmax[maxn];
int main(){
	freopen("dict.in","r",stdin); freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m); for(int i=1;i<=n;i++){
		scanf("%s",a[i]+1); mmin[i]=mmax[i]=a[i][1];
		for(int j=2;j<=m;j++) mmin[i]=min(mmin[i],a[i][j]),mmax[i]=max(mmax[i],a[i][j]);
	}
	for(int i=1;i<=n;i++){
		int flag=1; for(int j=1;j<=n;j++) if(j!=i&&mmin[i]>=mmax[j]) flag=0;
		printf("%d",flag);
	}
	return 0;
}
// Finished 8:47
