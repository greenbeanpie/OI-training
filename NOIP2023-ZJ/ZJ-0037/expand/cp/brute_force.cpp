#include <bits/stdc++.h>
using namespace std;
constexpr int max_n=2000;
int a[max_n+1],b[max_n+1],c[max_n+1],d[max_n+1];
bool f[max_n+1][max_n+1];
void solvex(const int n,const int m){
	memset(f,0,sizeof(f));
	f[1][1]=a[1]<b[1];
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			if(f[i][j]){
				// fprintf(stderr,"f %d %d: %d\n",i,j,(int)f[i][j]);
				if(i<n&&a[i+1]<b[j])
					f[i+1][j]=1;
				if(j<m&&a[i]<b[j+1])
					f[i][j+1]=1;
				if(i<n&&j<m&&a[i+1]<b[j+1])
					f[i+1][j+1]=1;
			}
	if(f[n][m])
		putchar('1');
	else
		putchar('0');
}
void solvey(const int n,const int m){
	memset(f,0,sizeof(f));
	f[1][1]=a[1]>b[1];
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			if(f[i][j]){
				if(i<n&&a[i+1]>b[j])
					f[i+1][j]=1;
				if(j<m&&a[i]>b[j+1])
					f[i][j+1]=1;
				if(i<n&&j<m&&a[i+1]>b[j+1])
					f[i+1][j+1]=1;
			}
	if(f[n][m])
		putchar('1');
	else
		putchar('0');
}
void solve(const int n,const int m){
	// fprintf(stderr,"first: %d %d\n",a[1],b[1]);
	if(a[1]<=b[1])
		solvex(n,m);
	else
		solvey(n,m);
}
int main(){
	int n,m,q;
	scanf("%*d%d%d%d",&n,&m,&q);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	for(int i=1; i<=m; ++i)
		scanf("%d",b+i);
	memcpy(c+1,a+1,n<<2);
	memcpy(d+1,b+1,m<<2);
	solve(n,m);
	for(int i=1,k,kx,p,v; i<=q; ++i){
		memcpy(a+1,c+1,n<<2);
		memcpy(b+1,d+1,m<<2);
		for(scanf("%d%d",&k,&kx); k; --k,a[p]=v)
			scanf("%d%d",&p,&v);
		for(k=kx; k; --k,b[p]=v)
			scanf("%d%d",&p,&v);
		solve(n,m);
	}
	putchar('\n');
	return 0;
}