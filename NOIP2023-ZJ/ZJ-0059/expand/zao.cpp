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
const int mod=1e9;
int a[maxn],b[maxn];
int inf=1e9;
signed main(void) {
	freopen("expand.in","w",stdout);
	mt19937 rnd(time(0));
	int i,n=150000,m=150000,q=60,Min=inf,Max=-inf;
	printf("9 %d %d %d\n",n,m,q);
	for (i=1;i<n;i++) a[i]=rnd()%mod,Min=min(a[i],Min);
	a[n]=rnd()%(Min-1)+1;
	for (i=1;i<m;i++) b[i]=rnd()%mod,Max=max(b[i],Max);
	b[m]=rnd()%(Min-1)+1+Max;
	for (i=1;i<=n;i++) printf("%d ",a[i]);put();
	for (i=1;i<=m;i++) printf("%d ",b[i]);put();
	while (q--) {
		printf("%d %d\n",n,m);
		for (i=1;i<n;i++) a[i]=rnd()%mod,Min=min(a[i],Min);
		a[n]=rnd()%(Min-1)+1;
		for (i=1;i<m;i++) b[i]=rnd()%mod,Max=max(b[i],Max);
		b[m]=rnd()%(Min-1)+1+Max;
		for (i=1;i<=n;i++) printf("%d %d\n",i,a[i]);put();
		for (i=1;i<=m;i++) printf("%d %d\n",i,b[i]);put();
	}
	return 0;
}