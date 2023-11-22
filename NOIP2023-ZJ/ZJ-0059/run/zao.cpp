#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
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
	mt19937 rnd(time(0));
//	freopen("run.in","w",stdout);
	int T=10,i,x,y;
	printf("%d %d\n",0,T);
	while (T--) {
		int n=1e9,m=1e5,K=rnd()%n+1,d=rnd()+1;
		printf("%d %d %d %d\n",n,m,K,d);
		for (i=1;i<=m;i++) {
			x=rnd()%n+1;
			y=rnd()%n+1;
			if (x>y) swap(x,y);
			x=y-x+1;
			printf("%d %d %d\n",y,x,rnd()%n+1);
		}
	}
	return 0;
}