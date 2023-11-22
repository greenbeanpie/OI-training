#include<bits/stdc++.h>
using namespace std;
#define maxn 500005
#define ll long long 
#define Tp template<typename T>
#define Ts template<typename T,typename ... S>
#define put() putchar('\n')
Tp void read(T &x) {
	int f=1;x=0;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x*=f;
}
namespace Debug {
	Tp void _debug(char *f,T x) {cerr<<f<<'='<<x<<endl;}
	Ts void _debug(char *f,T x,S ...t) {while (*f!=',') cerr<<*f++;cerr<<'='<<x<<',';_debug(f+1,t...);}
	#define gdb(...) _debug((char *)#__VA_ARGS__,__VA_ARGS__)
}
using namespace Debug;
int op,N,M,q;
int aa[maxn],bb[maxn],a[maxn],b[maxn];
int f[2005][2005];
void solve(void) {
	int i,j;
	int n=N,m=M;
	if (a[1]<b[1]) {
		swap(n,m);
		for (i=1;i<=max(n,m);i++) swap(a[i],b[i]);
	}
	if (a[1]==b[1]||a[n]<=b[m]) return putchar('0'),void();
	for (i=1;i<=n;i++) for (j=1;j<=m;j++) f[i][j]=0;
	f[1][1]=1;
	for (i=1;i<=n;i++) {
		for (j=1;j<=m;j++) if (a[i]>b[j]&&f[i][j]) {
			f[i+1][j]=f[i+1][j+1]=f[i][j+1]=1;
		}
	}
	printf("%d",f[n][m]);
}
signed main(void) {
	freopen("expand.in","r",stdin);
	freopen("std.out","w",stdout);
	int i,x,y,k,ky;
	read(op);read(N);read(M);read(q);
	int n=N,m=M;
	for (i=1;i<=n;i++) read(aa[i]);
	for (i=1;i<=m;i++) read(bb[i]);
	n=N,m=M;
	for (i=1;i<=n;i++) a[i]=aa[i];
	for (i=1;i<=m;i++) b[i]=bb[i];
	solve();
	while (q--) {
		n=N,m=M;
		for (i=1;i<=n;i++) a[i]=aa[i];
		for (i=1;i<=m;i++) b[i]=bb[i];
		read(k);read(ky);
		for (i=1;i<=k;i++) read(x),read(y),a[x]=y;
		k=ky;
		for (i=1;i<=k;i++) read(x),read(y),b[x]=y;
		solve();
	}
	return 0;
}