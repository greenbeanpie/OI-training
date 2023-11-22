#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
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
int a[maxn],n,m,fa[maxn],siz[maxn],ans[maxn],fl[maxn],vis[maxn],b[maxn];
int getfa(int x) {return x==fa[x]?x:fa[x]=getfa(fa[x]);}
void merge(int x,int y) {
	x=getfa(x),y=getfa(y);
	if (x^y) fa[x]=y;
}
void solve(void) {
	int i,x,y,cnt=0;char ch;
	read(n);read(m);
	for (i=1;i<=n;i++) fa[i]=a[i]=i,siz[i]=1,fl[i]=0,ans[i]=vis[i]=b[i]=0;
	for (i=1;i<=m;i++) {
		ch=getchar();
		while (ch!='U'&&ch!='F'&&ch!='T'&&ch!='+'&&ch!='-') ch=getchar();
		if (ch=='U') read(x),a[x]=0;
		else if (ch=='F') read(x),a[x]=-(n+1);
		else if (ch=='T') read(x),a[x]=n+1;
		else if (ch=='+') {
			read(x),read(y);
			a[x]=a[y];
		}
		else if (ch=='-') {
			read(x);read(y);
			a[x]=-a[y];
		}
	}
	for (i=1;i<=n;i++) if (abs(a[i])>0&&abs(a[i])<=n) {
		merge(abs(a[i]),i);	
	}
	for (i=1;i<=n;i++) if (abs(a[i])>0&&abs(a[i])<=n) {
		b[i]=abs(a[i]);
	} 
	else if (a[i]==0) ans[i]=1,fl[getfa(i)]=1;
	else fl[getfa(i)]=2;
	for (i=1;i<=n;i++) if (fl[getfa(i)]==0) {
		int now=i,nums=0;
		while (vis[now]==0) {
			vis[now]=1;
			now=b[now];
		} 
		int rt=now;
		while (1) {
//			gdb(i,now,b[now],a[now],rt);
			nums+=(a[now]<0);
			now=b[now];
			if (now==rt) break;
		}
		if (nums%2) fl[getfa(i)]=1;
		else fl[getfa(i)]=2;
	}
	
	for (i=1;i<=n;i++) cnt+=(fl[getfa(i)]==1);
	printf("%d\n",cnt);
}
signed main(void) {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,T;
	read(c);read(T);
	while (T--) solve();
	return 0;
}