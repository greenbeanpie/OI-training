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
	for (i=1;i<=n;i++) memset(f[i],0,sizeof(f[i]));
	f[1][1]=1;
	for (i=1;i<=n;i++) {
		for (j=1;j<=m;j++) if (a[i]>b[j]&&f[i][j]) {
			f[i+1][j]=f[i+1][j+1]=f[i][j+1]=1;
		}
	}
	printf("%d",f[n][m]);
}
int l[maxn],c[maxn],t[maxn],d[maxn],pre[maxn];
void solve2(void) {
	int i,j;
	int n=N,m=M;
	if (a[1]==b[1]||a[n]>=b[m]) return putchar('0'),void();
	reverse(a+1,a+1+n);
	reverse(b+1,b+1+m);
	for (i=1;i<=m;i++) if (b[i]<=a[1]) return putchar('0'),void();
	for (i=1;i<=n;i++) c[i]=d[i]=a[i];
	for (i=n-1;i>=1;i--) c[i]=max(c[i],c[i+1]),d[i]=min(d[i],d[i+1]);
	reverse(c+1,c+1+n);
	for (i=1;i<=max(n,m)+1;i++) t[i]=0;
//	for (i=1;i<=n;i++) printf("%d ",a[i]);put();
//	for (i=1;i<=m;i++) printf("%d ",b[i]);put();
//	for (i=1;i<=n;i++) printf("%d ",c[i]);put();
	for (i=1;i<=m;i++) {
		l[i]=lower_bound(c+1,c+1+n,b[i])-c-1;
		l[i]=n-l[i]+1,t[l[i]]=max(t[l[i]],i);
//		gdb(i,l[i]);
	}
	pre[m]=m;
	for (i=m-1;i>=1;i--) 
		if (b[pre[i+1]]<b[i]) pre[i]=pre[i+1];
		else pre[i]=i;
	int now=0,r=2;
	i=0;j=0;
	while (1) {
		int id=0;
		while (now<r) now++,id=max(id,t[now]);
		if (!id) return putchar('0'),void();
		i=pre[id];
		while (j<=n&&d[j]<b[i]) j++;
//		gdb(i,j,id,r);
		r=j;
		if (j>n) return putchar('1'),void();
		if (i==m) return putchar('0'),void();
	}
}
signed main(void) {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int i,x,y,k,ky;
	read(op);read(N);read(M);read(q);
	int n=N,m=M;
	for (i=1;i<=n;i++) read(aa[i]);
	for (i=1;i<=m;i++) read(bb[i]);
	n=N,m=M;
	for (i=1;i<=n;i++) a[i]=aa[i];
	for (i=1;i<=m;i++) b[i]=bb[i];
	if (op<=7||op>14) solve();
	else solve2();
	while (q--) {
		n=N,m=M;
		for (i=1;i<=n;i++) a[i]=aa[i];
		for (i=1;i<=m;i++) b[i]=bb[i];
		read(k);read(ky);
		for (i=1;i<=k;i++) read(x),read(y),a[x]=y;
		k=ky;
		for (i=1;i<=k;i++) read(x),read(y),b[x]=y;
		if (op<=7||op>14) solve();
		else solve2();
	}
	return 0;
}
// T3 is too hard for me.