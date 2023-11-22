#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define foR(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=1e5+5;
//struct node{int u,v,nxt;}e[N<<1];
//int h[N<<1],num_e=0;

vector<int> g[N];
inline void add(int x,int y) {g[x].push_back(y);}

int n,m,a[N];
int id,T;
struct OP{char op;int x,y;};
OP opp[N];
int cnt=0;
//转化为图上强连通分量（有向图，拓展域） 

int dfn[N],low[N],tot=0;
int c[N],s[N],tp=0,ctot=0;
bool ins[N];
int sz[N];
bool t[N];
inline void Tarjan(int x) {
	dfn[x]=low[x]=++tot;
	s[++tp]=x,ins[x]=true;
	int len=g[x].size();
	for(int i=0;i<len;i++) {
		int y=g[x][i];
		if(!dfn[y]) {
			Tarjan(y);
			low[x]=min(low[x],low[y]);
		} else if(ins[y]) low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x]) {
		int y=s[tp];
		c[y]=++ctot;
		ins[y]=false;
		while(low[y]==dfn[x]) {
			y=s[--tp];
			c[y]=ctot;
			ins[y]=false;
		}
	}
	return;
}
bool vis[N];
inline void dfs(int x,int fa) {
	if(fa) a[x]=a[fa];
	int len=g[x].size();
	for(int i=0;i<len;i++) {
		int y=g[x][i];
		if(vis[y]||a[y]) continue;
		vis[y]=true;
		dfs(y,x);
	}
}
inline void solve() {
	cin>>n>>m;
	tp=tot=ctot=cnt=0;
	For(i,1,2*n) g[i].clear();
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(s,0,sizeof(s));
	memset(c,0,sizeof(c));
	memset(sz,0,sizeof(sz));
	memset(a,0,sizeof(a));
	memset(t,false,sizeof(t));
	
	For(i,1,m) {
		char op;
		int x,y;
		scanf(" %c",&op);
		if(op=='T') scanf("%lld",&x),a[x]=a[x+n]=1;
		if(op=='F') scanf("%lld",&x),a[x]=a[x+n]=2;
		if(op=='U') scanf("%lld",&x),a[x]=a[x+n]=3;
		if(op=='+'||op=='-') {
			scanf("%lld%lld",&x,&y);
			opp[++cnt]=(OP){op,x,y};
		}
	}
	For(i,1,cnt) {
		char op=opp[i].op;
		int x=opp[i].x,y=opp[i].y;
		if(op=='+') add(y,x),add(y+n,x+n);
		else add(y,x+n),add(y+n,x);
	}
	
	For(i,1,2*n) if(!a[i]&&!dfn[i]) Tarjan(i);
//	For(i,1,2*n) sz[c[i]]++;
	For(i,1,2*n) if(c[i]==c[i+n]&&c[i]!=0) {a[i]=3;}
	
	memset(vis,false,sizeof(vis));
	For(i,1,2*n) if(a[i]) dfs(i,0);
	
//	For(i,1,2*n) cout<<"???"<<i<<" "<<c[i]<<" "<<a[i]<<"\n";
	int ans=0;
	For(i,1,n) ans+=(a[i]==3);//已经确定的
//	cout<<ans<<"\n";
//	For(i,1,ctot) cout<<sz[i]<<" ";
//	puts("");
//	For(i,1,2*n) if(!t[c[i]]&&c[i]==c[i+n]&&c[i]!=0) {ans+=(sz[c[i]]/2);t[c[i]]=true;}
 	printf("%lld\n",ans);
//	For
}
signed main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%lld%lld",&id,&T);
	while(T--) solve();
	return 0;
}
/*
1 1
10 10
T 3
+ 1 2
- 7 1
+ 2 10
T 6
- 1 4
U 3
+ 7 10
F 5
+ 6 9
*/
