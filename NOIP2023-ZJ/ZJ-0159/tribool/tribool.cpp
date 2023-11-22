#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define rep(k,l,r) for(int k=l;k<=r;++k)
#define per(k,r,l) for(int k=r;k>=l;--k)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define cl(f,x) memset(f,x,sizeof(f))
using namespace std;
const int N=1e6+5;
int pos[N],a[N],b[N],last[N];
bool used[N];
PII f[N];
char op[N];
int calc(char op) {
	if(op=='F')
		return 0;
	else if(op=='T')
		return 1;
	else
		return -1;
}
PII fei(PII val) {
	if(val.second==-1) {
		if(val.first>=0)
			val.first^=1;
		return val;
	} else {
		val.second^=1;
		return val;
	}
}
PII solve2(int x) {
	if(used[x])
		return f[x];
	used[x]=true;
	PII val=solve2(last[x]);
	if(op[x]=='+')
		f[x]=val;
	else
		f[x]=fei(val);
	return f[x];
}
int fa[N],pa[N];
bool g[N],vis[N],ok[N];
int find_fa(int x) {
	if(fa[x]!=x)
		fa[x]=find_fa(fa[x]);
	return fa[x];
}
int find_pa(int x) {
	if(pa[x]!=x)
		pa[x]=find_pa(pa[x]);
	return pa[x];
}
void init(int n,int m) {
	rep(i,1,n)
		pos[i]=0;
	rep(i,1,n+n) {
		pa[i]=i;
		ok[i]=false;
	}
	rep(i,1,m) {
		g[i]=false;
		fa[i]=i;
		f[i]={-2,-2};
		last[i]=0;
		vis[i]=used[i]=false;
	}
}
void merge_fa(int u,int v) {
	u=find_fa(u); v=find_fa(v);
	if(u!=v)
		fa[u]=v;
}
void merge_pa(int u,int v) {
	u=find_pa(u); v=find_pa(v);
	if(u!=v)
		pa[u]=v;
}
void solve1(int n,int m) {
	init(n,m);
	rep(i,1,m) {
		if(op[i]=='+'||op[i]=='-') {
			if(pos[b[i]]) {
				last[i]=pos[b[i]];
				merge_fa(i,last[i]);
			} else {
				f[i]={b[i],op[i]=='+'? 0:1};
				vis[i]=used[i]=true;
			}
		} else {
			f[i]={calc(op[i]),-1};
			used[i]=true;
		}
		pos[a[i]]=i;
	}
	rep(i,1,m) {
		if(vis[i])
			merge_fa(i,pos[b[i]]);
	}
	rep(i,1,n) {
		if(!pos[i])
			continue;
		PII val=solve2(pos[i]);
		if(val.second==-1) {
			if(val.first==-1)
				g[find_fa(pos[i])]=true;
		} else {
			int x=val.first;
			if(!val.second)
				merge_pa(i,x),merge_pa(i+n,x+n);
			else
				merge_pa(i+n,x),merge_pa(i,x+n);
		}
	}
	rep(i,1,n) {
		if(find_pa(i)==find_pa(i+n))
			ok[find_pa(i)]=true;
	}
	rep(i,1,n)
		g[find_fa(pos[i])]|=ok[find_pa(i)];
	int res=0;
	rep(i,1,n)
		res+=(int)g[find_fa(pos[i])];
	printf("%d\n",res);
}
void solve() {
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,m) {
		cin>>op[i];
		scanf("%d",&a[i]);
		if(op[i]=='+'||op[i]=='-')
			scanf("%d",&b[i]);
	}
	solve1(n,m);
}
//pretest at 11:08
signed main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int _,testcase;
	scanf("%d%d",&_,&testcase);
	while(testcase--)
		solve();
	return 0;
}
