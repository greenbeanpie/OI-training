#include<bits/stdc++.h>
#define N 400005
#define M 800005
using namespace std;
inline int read(){
	int ans=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
	return ans;
}
inline void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,m,T,q,k,s,vis[N],first[N<<1],head[N],cntx=0,d[N],dep[N],f[N][20],fa[N<<1],lastans=0,totx=0;
struct Node{int u,v,l,a;}e[M],p[N<<1];
struct edge{int v,next;}tr[M<<1];
struct node{int v,next,w;}t[M];
struct heap{int u,v;};
inline bool operator<(heap a,heap b){return a.v>b.v;}
inline void dijstra(int s=1){
	memset(vis,false,sizeof(vis));
	memset(d,0x3f,sizeof(d));
	priority_queue<heap>q;
	d[s]=0;
	q.push((heap){s,d[s]});
	while(!q.empty()){
		heap x=q.top();
		q.pop();
		if(vis[x.u])continue;
		vis[x.u]=true;
		for(int i=head[x.u];i;i=t[i].next){
			int v=t[i].v;
			if(vis[v])continue;
			if(d[v]>d[x.u]+t[i].w){
				d[v]=d[x.u]+t[i].w
				;
				q.push((heap){v,d[v]});
			}
		}
	}
	for(int i=1;i<=n;++i)p[i].l=d[i];
}
inline bool cmp(Node a,Node b){return a.a>b.a;}
inline int find(int x){return x==fa[x]?fa[x]:fa[x]=find(fa[x]);}
inline void add(int u,int v){
	tr[++cntx].v=v;
	tr[cntx].next=first[u];
	first[u]=cntx;
}
inline void addx(int u,int v,int w){
	t[++totx].v=v;
	t[totx].next=head[u];
	t[totx].w=w;
	head[u]=totx;
}
inline void dfs(int u,int pa){
	dep[u]=dep[pa]+1,f[u][0]=pa;
	for(int i=1;i<=19;++i)f[u][i]=f[f[u][i-1]][i-1];
	for(int i=first[u];i;i=tr[i].next){
		int v=tr[i].v;
		dfs(v,u);
		p[u].l=min(p[u].l,p[v].l);
	}
}
inline int query(int x,int y){
	for(int i=19;i>=0;--i)if(dep[x]-(1<<i)>0&&p[f[x][i]].a>y)x=f[x][i];
	return p[x].l;
}
inline void kruskal(){
	int tot=0,cnt=n;
	for(int i=1;i<=(n<<1);++i)fa[i]=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;++i){
		int u=e[i].u,v=e[i].v;
		int fx=find(u),fy=find(v);
		if(fx!=fy){
			add(++cnt,fx);
			add(cnt,fy);
			fa[fx]=cnt;
			fa[fy]=cnt;
			p[cnt].a=e[i].a;
			++tot;
		}
		if(tot==n-1)break;
	}
	dfs(cnt,0);
	while(q--){
		int x=(k*lastans+read()-1)%n+1,y=(k*lastans+read())%(s+1);
		write(lastans=query(x,y));
		puts("");
	}
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("return.in","r",stdin);
		freopen("return_TJ.out","w",stdout);
	#endif
	T=read();
	while(T--){
		lastans=0,n=read(),m=read();
		memset(e,0,sizeof(e)),cntx=0,totx=0;
		memset(first,0,sizeof(first));
		memset(head,0,sizeof(head));
		memset(f,0,sizeof(f));
		for(int i=1;i<=m;++i)e[i].u=read(),e[i].v=read(),e[i].l=read(),e[i].a=read(),addx(e[i].u,e[i].v,e[i].l),addx(e[i].v,e[i].u,e[i].l);
		for(int i=n+1;i<=(n<<1);++i)p[i].l=0x3f3f3f3f;
		dijstra();
		q=read(),k=read(),s=read();
		kruskal();
	}
	return 0;
}
