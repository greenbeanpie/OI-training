#include <bits/stdc++.h>
using namespace std;
const int maxn=4e5+5;
int c,t,n,m,cnt,u,v,ans,cntx;
int rk[maxn],fa[maxn],rev[maxn];
vector<int> G[maxn]; 
int dfn[maxn],low[maxn];
bool ispoint[maxn];
char op;
int sum;
stack<int> St;
vector<int> Point;
bool instack[maxn];
int belong[maxn],sz[maxn];
bool vis[maxn];

void tarjan(int u){
	dfn[u]=low[u]=++sum;
	St.push(u);
	instack[u]=1;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(instack[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		++cntx;
		int node=0;
		do{
			node=St.top();
			St.pop();
			instack[node]=0;
			belong[node]=cntx;
			sz[cntx]++;
		}while(node!=u);
	}
}

int main(){
	freopen("tribool1.in","r",stdin);
	scanf("%d%d",&c,&t);	
	while(t--){
		ans=0;
		scanf("%d%d",&n,&m);
		memset(rk,0,sizeof(rk));
		memset(fa,0,sizeof(fa));
		memset(rev,0,sizeof(rev));
		memset(ispoint,0,sizeof(ispoint));
		memset(vis,0,sizeof(vis));
		cnt=n;
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++){
			cin>>op;
			if(op=='T' || op=='F' || op=='U'){
				scanf("%d",&u);
				int x=0;
				if(op=='T') x=1;
				if(op=='F') x=2;
				if(op=='U') x=3;
				if(rk[fa[u]]==x) continue;
				cnt++;
				fa[cnt]=cnt;
				fa[u]=fa[cnt];
				rk[cnt]=x;
			}
			if(op=='+'){
				scanf("%d%d",&u,&v);
				fa[u]=fa[v];
			}
			if(op=='-'){
				scanf("%d%d",&u,&v);
				cnt++;
				rev[v]=cnt;
				rev[cnt]=v;
				fa[cnt]=cnt;
				fa[u]=cnt;
			}
		}
		for(int i=1;i<=n;i++){
			vis[fa[i]]=1;
			if(rev[i]){
				G[fa[i]].push_back(rev[i]);
			}
		}
		for(int i=1;i<=cnt;i++){
			if(vis[i]) Point.push_back(i);
			if(vis[i] && !dfn[i]){
				tarjan(i);
			}	
		}
		for(int i=1;i<=n;i++){
			if(fa[i]>n){
				if(rk[fa[i]]==3) ans++;
			}
		}
		for(int i=1;i<=cntx;i++){
			if(sz[i]>1) ans+=sz[i]-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
