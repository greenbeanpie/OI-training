#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define int long long 
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
int n,m,K,d;
struct node {
	int lazy,Max;
}f[maxn<<2];
int dp[maxn][2];
const int inf=1e18;
void pushup(int rt) {
	f[rt].Max=max(f[rt<<1].Max,f[rt<<1|1].Max);
}
void pushdown(int rt) {
	if (f[rt].lazy) {
		int k=f[rt].lazy;f[rt].lazy=0;
		f[rt<<1].lazy+=k,f[rt<<1|1].lazy+=k;
		f[rt<<1].Max+=k,f[rt<<1|1].Max+=k;
	}
}
void build(int l,int r,int rt) {
	f[rt].lazy=0,f[rt].Max=-inf;
	if (l==r) return ;
	int mid=l+r>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
}
void modify(int l,int r,int rt,int head,int k) {
	if (l==r) return f[rt].Max=k,void();
	int mid=l+r>>1;pushdown(rt);
	if (head<=mid) modify(l,mid,rt<<1,head,k);
	else modify(mid+1,r,rt<<1|1,head,k);
	pushup(rt);
}
void Update(int l,int r,int rt,int head,int tail,int k) {
	if (head<=l&&r<=tail) return f[rt].lazy+=k,f[rt].Max+=k,void();
	int mid=l+r>>1;pushdown(rt);
	if (head<=mid) Update(l,mid,rt<<1,head,tail,k);
	if (tail>mid)  Update(mid+1,r,rt<<1|1,head,tail,k);
	pushup(rt);
} 
int Query(int l,int r,int rt,int head,int tail) {
	if (head<=l&&r<=tail) return f[rt].Max;
	int mid=l+r>>1;pushdown(rt);
	int tmp1=-inf,tmp2=-inf;
	if (head<=mid) tmp1=Query(l,mid,rt<<1,head,tail);
	if (tail>mid)  tmp2=Query(mid+1,r,rt<<1|1,head,tail);
	return max(tmp1,tmp2);
}
#define fi first
#define se second
#define mk make_pair
vector<pair<int,int> >O[maxn];
int times;
void solve(void) {
	int i,x,y,z,ans=-inf;
	read(n);read(m);read(K);read(d);
	for (i=0;i<=n;i++) O[i].clear(),dp[i][0]=dp[i][1]=-inf;
	for (i=1;i<=m;i++) {
		read(x),read(y),read(z);
		y=x-y+1;
		O[x].push_back(mk(y,z));
	}
	build(0,n,1);
	dp[0][0]=0;
	modify(0,n,1,0,0);
	for (i=1;i<=n;i++) {
		for (auto tmp:O[i]) Update(0,n,1,0,tmp.fi-1,tmp.se);
		dp[i][1]=Query(0,n,1,max(0ll,i-K),i-1)-i*d;
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		modify(0,n,1,i,dp[i][0]+i*d);
		ans=max(ans,max(dp[i][0],dp[i][1]));
//		printf("%lld %lld %lld\n",i,dp[i][0],dp[i][1]);
	}
	printf("%lld\n",max(dp[n][1],dp[n][0]));
}//56
signed main(void) {
	freopen("run3.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,T;
	read(c);read(T);
	while (T--) ++times,solve();
	return 0;
}