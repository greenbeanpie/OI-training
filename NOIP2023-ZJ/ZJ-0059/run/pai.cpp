#include<bits/stdc++.h>
using namespace std;
#define maxn
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
signed main(void) {
	int i,T=20000;
	for (i=1;i<=T;i++) {
		printf("csae %d\n",i);
		system("zao.exe>run.in");
		system("run.exe");
		system("run2.exe");
		if (system("fc run.out std.out")) return 0;
	}
	return 0;
}