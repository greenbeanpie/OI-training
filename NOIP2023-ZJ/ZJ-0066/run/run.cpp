#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr int M=1e5+5;
LL ans,f[M],dp[M];
int n,m,k,d,x,y,v,c,t,num,tot,lsh[M<<1];
vector<pair<int,int>>pos[M];
struct node{int l,r,v;}a[M];
int read(){
	int x=0;char ch=getchar();
	while (!isdigit(ch)) ch=getchar();
	while (isdigit(ch)) x=x*10+ch-48,ch=getchar();
	return x;
}
void solve(){ num=tot=0;
	n=read();m=read();k=read();d=read();
	for (int i=1;i<=n;i++) pos[i].clear();
	for (int i=1;i<=m;i++){
		x=read();y=read();v=read();
		if (y>k) continue;
		a[++tot]={y,x,v};
		lsh[++num]=a[i].l;lsh[++num]=a[i].r;
	}
	sort(lsh+1,lsh+num+1);num=unique(lsh+1,lsh+num+1)-lsh-1;
	for (int i=1;i<=tot;i++){
//		a[i].l=lower_bound(lsh+1,lsh+num+1,a[i].l)-lsh;
//		a[i].r=lower_bound(lsh+1,lsh+num+1,a[i].r)-lsh;
		pos[a[i].r].push_back({a[i].l,a[i].v});
	}
	for (int i=0;i<=k;i++) dp[i]=-1ll<<60;
	dp[0]=0;ans=-1ll<<60;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=k;j++) f[j]=0;
		for (auto [x,y]:pos[i]) f[x]+=y;
		for (int j=1;j<=k;j++) f[j]+=f[j-1];
		for (int j=1;j<=k;j++) f[j]+=dp[j-1]-d;
		for (int j=0;j<=k;j++) dp[0]=max(dp[0],dp[j]);
		for (int j=1;j<=k;j++) dp[j]=f[j];
	}
	for (int i=0;i<=k;i++)
		ans=max(ans,dp[i]);
	printf("%lld\n",ans);
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read();t=read();
	while (t--) solve();
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr int M=1e5+5;
LL ans,f[M],dp[M];
int n,m,k,d,x,y,v,c,t,num,tot,lsh[M<<1];
vector<pair<int,int>>pos[M];
struct node{int l,r,v;}a[M];
int read(){
	int x=0;char ch=getchar();
	while (!isdigit(ch)) ch=getchar();
	while (isdigit(ch)) x=x*10+ch-48,ch=getchar();
	return x;
}
struct SegTree{
	LL Max,lazy;
}tr[M<<2];
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
void build(int l,int r,int x){
	tr[x].Max=-1ll<<60;tr[x].tag=0;
	if (l==r) return ;
	int mid=l+r>>1;
	build(l,mid,ls(x));
	build(mid+1,r,rs(x));
}
void addtag(int x,int c){
	tr[x].Max+=c;tr[x].lazy+=c;
}
void pushdown(int x){
	if (!tr[x].lazy) return ;
	addtag(ls(x),tr[x].lazy);
	addtag(rs(x),tr[x].lazy);
}
void update(int u,int c,int l=0,int r=k,int x=1){
	if (l==r) tr[x].Max=max(tr[x].Max,c),void();
	int mid=l+r>>1;pushdown(x);
	if (u<=mid) update(u,c,l,mid,ls(x));
	if (u>mid) update(u,c,mid+1,r,rs(x));
	tr[x].Max=max(tr[ls(x)].Max,tr[rs(x)].Max);
}
void modify(int L,int R,int c,int l=0,int r=k,int x=1){
	if (L<=l&&r<=R) return addtag(x,c),void();
	int mid=l+r>>1;pushdown(x);
	if (L<=mid) modify(L,R,c,l,mid,ls(x));
	if (R>mid) modify(L,R,c,mid+1,r,rs(x));
	tr[x].Max=max(tr[ls(x)].Max,tr[rs(x)].Max);
}
void solve(){ num=tot=0;
	n=read();m=read();k=read();d=read();
	for (int i=1;i<=n;i++) pos[i].clear();
	for (int i=1;i<=m;i++){
		x=read();y=read();v=read();
		if (y>k) continue;
		a[++tot]={y,x,v};
		lsh[++num]=a[i].l;lsh[++num]=a[i].r;
	}
	sort(lsh+1,lsh+num+1);num=unique(lsh+1,lsh+num+1)-lsh-1;
	for (int i=1;i<=tot;i++){
		pos[a[i].r].push_back({a[i].l,a[i].v});
	}
	build(0,k,1);update(0,0);
	for (int i=1;i<=n;i++){
		const LL tmp=tr[1].Max;
		
		update(0,tr[1].Max);
	}
	printf("%lld\n",tr[1].Max);
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read();t=read();
	while (t--) solve();
	return 0;
}
*/