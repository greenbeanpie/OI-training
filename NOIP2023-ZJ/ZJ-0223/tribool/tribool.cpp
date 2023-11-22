#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
int c,T,n,m,ans;
int fin[N];
char op[2];
int x,y;
struct Edge{
	int u,v,nxt;
	Edge(int u=0,int v=0,int nxt=0): u(u),v(v),nxt(nxt) {}
}e[N<<2]; int tot=2;
int head[N<<1];
inline void add(int u,int v){
	e[tot]=Edge(u,v,head[u]); head[u]=tot++;
	e[tot]=Edge(v,u,head[v]); head[v]=tot++;
}
int fa[N<<1],dep[N<<1];
int find(int u){
	if(u==fa[u]) return u;
	int r=find(fa[u]);
	dep[u]=dep[r]+1;
	return fa[u]=r;
}             
int col[N<<1];
int vis[N<<1];
void dfs(int u,int cl){
	vis[u]=1; col[u]=cl; col[u+n]=-4-cl;
	for(int i=head[u];i;i=e[i].nxt){
		if(vis[e[i].v]) continue;
		dfs(e[i].v,cl);
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		for(int i=0;i<=2*n+3;i++) head[i]=col[i]=vis[i]=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) fin[i]=i;
		for(int i=1;i<=m;i++){
			scanf("%s",op+1);
			scanf("%d",&x);
			if(op[1]=='T') fin[x]=-1;
			else if(op[1]=='F') fin[x]=-3;
			else if(op[1]=='U') fin[x]=-2;
			else if(op[1]=='+'){
				scanf("%d",&y);
				fin[x]=fin[y];
			}
			else if(op[1]=='-'){
				scanf("%d",&y);
				if(fin[y]<0) fin[x]=-4-fin[y];
				else fin[x]=(fin[y]>n?(fin[y]-n):(fin[y]+n));
			}
		}
		tot=2;
		for(int i=1;i<=n;i++){
			if(fin[i]==i) continue;
			else if(fin[i]<0) add(i,n*2-fin[i]);
			else add(i,fin[i]),add(i+n,fin[i]>n?(fin[i]-n):(fin[i]+n));
		}
		for(int i=1;i<=n*2+3;i++) fa[i]=i,dep[i]=1;
		for(int i=2,fx,fy;i<=tot;i+=2){
			fx=find(e[i].u); fy=find(e[i].v);
			if(fx==fy) continue;
			if(dep[fx]<fy) fa[fx]=fy;
			else fa[fy]=fx;
		}
		col[n*2+1]=-1;
		col[n*2+2]=-2;
		col[n*2+3]=-3;
		for(int i=1;i<=n;i++)
			if(find(i)==find(i+n)) col[i]=col[i+n]=-2;
		if(!vis[n*2+1]) dfs(n*2+1,-1);
		if(!vis[n*2+2]) dfs(n*2+2,-2);
		if(!vis[n*2+3]) dfs(n*2+3,-3);
		for(int i=1;i<=2*n;i++){
			if(col[i]==0||vis[i]) continue;
			dfs(i,col[i]);
		}
		ans=0;
		for(int i=1;i<=n;i++)
			if(col[i]==-2) ans++;
		printf("%d\n",ans);
	}
	return 0;
}