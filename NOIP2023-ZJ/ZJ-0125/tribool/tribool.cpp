#include <bits/stdc++.h>
using namespace std;
const int T=114514,F=-114514,U=0;
int ID,ca;
int n,m,a[114520],head[114520],vis[114520],tot,flag;
struct EDGE{int nex,to,w;}e[1919810];
void add(int u,int v,int w){e[++tot].nex=head[u],e[tot].to=v,e[tot].w=w,head[u]=tot;}
void dfs(int u,int op){
	if(flag) return;
	if(op&&vis[u]!=0x3f3f3f3f){
		if(vis[u]!=op) flag=1;
		return;
	}
	if(!op&&!vis[u]) return;
	if(vis[u]) vis[u]=op;
	for(int i=head[u];i;i=e[i].nex) dfs(e[i].to,op*e[i].w);
}
void solve(){
	memset(vis,0x3f3f3f3f,sizeof(vis));
	tot=0;for(int i=0;i<=n;i++) head[i]=0;head[114514]=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) a[i]=i;
	for(int i=1,x,y;i<=m;i++){
		char op;
		cin>>op;scanf("%d",&x);
		if(op=='+'||op=='-') scanf("%d",&y),a[x]=(op=='+'?1:-1)*a[y];
		else a[x]=(op=='T'?T:(op=='F'?F:U));
	}
	for(int i=1;i<=n;i++){
		if(a[i]<0) add(i,-a[i],-1),add(-a[i],i,-1);
		else add(i,a[i],1),add(a[i],i,1);
	}
	flag=0;
	dfs(114514,1);
	if(vis[0]==0x3f3f3f3f) dfs(0,0);
	for(int i=1;i<=n;i++) if(vis[i]==0x3f3f3f3f){
		flag=0,dfs(i,1);
		if(flag) flag=0,dfs(i,0);
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans+=(vis[i]==0);
	printf("%d\n",ans);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&ID,&ca);
	while(ca--) solve();
	return 0;
}
