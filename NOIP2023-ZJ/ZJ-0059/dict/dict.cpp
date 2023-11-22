#include<bits/stdc++.h>
using namespace std;
#define maxn
#define ll long long 
#define LL __int128
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
int n,m;
int a[3005],b[6005][3005];
int id[6005];
const LL mod=LL(1e18)+3;
const LL base=998244353;
ll s[6005][3005]; 
int ans[6005];
bool cmp(int x,int y) {
	int l=0,r=m+1;
	while (l+1<r) {
		int mid=l+r>>1;
		if (s[x][mid]==s[y][mid]) l=mid;
		else r=mid;
	}
	return b[x][l+1]<b[y][l+1];
}

signed main(void) {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int i,j,k;char ch;
	read(n);read(m);
	for (i=1;i<=n;i++) {
		cin>>ch;
		for (j=1;j<=m;j++,ch=getchar()) a[j]=ch;
		sort(a+1,a+1+m);
		for (j=1;j<=m;j++) s[i][j]=(base*s[i][j-1]+a[j])%mod,b[i][j]=a[j];
		reverse(a+1,a+1+m);
		for (j=1;j<=m;j++) s[i+n][j]=(base*s[i+n][j-1]+a[j])%mod,b[i+n][j]=a[j];//,gdb(s[i+n][j]);
	}
	int N=2*n;
	for (i=1;i<=2*n;i++) id[i]=i;
	sort(id+1,id+1+N,cmp);
	int nums=0;
	for (i=1;i<=2*n;i++) {
		int res=0;
		if (id[i]>n) nums++,res=id[i];
		for (j=i;j<2*n&&cmp(id[i],id[j+1])==cmp(id[j+1],id[i]);j++) {
			if (id[j+1]>n) res=id[j+1],nums++;
		}
//		gdb(i,j,n,res,id[1],id[2],nums);
		if (nums==0) {
			for (k=i;k<=j;k++) ans[id[k]]=1;
		}
		else if (nums==1) {
			for (k=i;k<=j;k++) if (id[k]==res-n) ans[id[k]]=1;
		}
		else break;
		i=j;
	}
	for (i=1;i<=n;i++) printf("%d",ans[i]);
	return 0;
}
// you ji ? may be 100+100+[45,70]+100. it's my lucky day!