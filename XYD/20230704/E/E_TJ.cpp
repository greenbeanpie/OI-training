#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=110,mod=1e9+9;
int n,a[110][110],f[110][110],g[110][110],mn,fw[110][110][4];
int val(int x,int y) {
	if(x+y==n+1) return a[x][y];
	return a[x][y]+a[n-y+1][n-x+1];
}
bool zxf() {
	bool res=0;
	for(int i=3; i<=n+1; i++)
		for(int x=1; x<i; x++) {
			int y=i-x;
			if(min(f[x][y-1],f[x-1][y])+val(x,y)<f[x][y]) f[x][y]=min(f[x][y-1],f[x-1][y])+val(x,y),res=1;
		}
	return res;
}
bool fxf() {
	bool res=0;
	for(int i=n; i>=2; i--)
		for(int x=1; x<i; x++) {
			int y=i-x;
			if(min(f[x][y+1],f[x+1][y])+val(x,y)<f[x][y]) f[x][y]=min(f[x][y+1],f[x+1][y])+val(x,y),res=1;
		}
	return res;
}
bool zxg() {
	bool res=0;
	for(int i=3; i<=n+1; i++)
		for(int x=1; x<i; x++) {
			int y=i-x;
			if(f[x][y]+val(x-1,y)==f[x-1][y] && g[x-1][y]>fw[x][y][0]) (g[x][y]+=g[x-1][y]-fw[x][y][0])%=mod,fw[x][y][0]=g[x-1][y],res=1;
			if(f[x][y]+val(x,y-1)==f[x][y-1] && g[x][y-1]>fw[x][y][1]) (g[x][y]+=g[x][y-1]-fw[x][y][1])%=mod,fw[x][y][1]=g[x][y-1],res=1;
		}
	return res;
}
bool fxg() {
	bool res=0;
	for(int i=n; i>=2; i--)
		for(int x=1; x<i; x++) {
			int y=i-x;
			if(f[x][y]+val(x+1,y)==f[x+1][y] && g[x+1][y]>fw[x][y][2]) (g[x][y]+=g[x+1][y]-fw[x][y][2])%=mod,fw[x][y][2]=g[x+1][y],res=1;
			if(f[x][y]+val(x,y+1)==f[x][y+1] && g[x][y+1]>fw[x][y][3]) (g[x][y]+=g[x][y+1]-fw[x][y][3])%=mod,fw[x][y][3]=g[x][y+1],res=1;
		}
	return res;
}
void dp() {
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) scanf("%d",&a[i][j]);
	memset(f,0x3f,sizeof(f));
	f[1][1]=val(1,1);
	for(int i=1; i<=n; i++) if( !zxf() && !fxf() ) break;
	mn=inf;
	for(int i=1; i<=n; i++) mn=min(mn,f[i][n+1-i]);
	memset(g,0,sizeof(g));
	for(int i=1; i<=n; i++) if(f[i][n+1-i]==mn) g[i][n+1-i]=1;
	memset(fw,0,sizeof(fw));
	for(int i=1; i<=n; i++) if( !fxg() && !zxg() ) break;
	printf("%d\n",g[1][1]);
}
int main() {
	#ifndef ONLINE_JUDGE
		freopen("E.in","r",stdin);
		freopen("E_TJ.out","w",stdout);
	#endif
	scanf("%d",&n);
	while(n) dp(),scanf("%d",&n);
	return 0;
}
