#include <bits/stdc++.h>
using namespace std;
const int maxn=4e5+5;
int t,c,n,m,x,u,v;
char ch;
struct Node{
	int op;	//+-TFU
	int u,v;
}query[50];

int gene[50];
int ans_solve_1=15;
int fan(int x){
	if(x==1) return 2;
	if(x==2) return 1;
	if(x==3) return 3;
}
bool solve(){
	int a[15];
	for(int i=1;i<=n;i++){
		a[i]=gene[i];		
	}
	for(int i=1;i<=m;i++){
		int x=query[i].op;
		if(x==4){
			a[query[i].u]=a[query[i].v];
		}
		if(x==5){
			a[query[i].u]=fan(a[query[i].v]);
		}
		if(x<=3){
			a[query[i].u]=x;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=gene[i]) return false;
	}
	return true;
}

void dfs(int dep,int sum){
	if(dep>n){
		if(solve()) ans_solve_1=min(ans_solve_1,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		gene[dep]=i;
		if(gene[dep]==3) sum++;
		dfs(dep+1,sum);
	}
}
void solve_1(){
	char ch;
	int u,v;
	while(t--){
		ans_solve_1=15;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			cin>>ch;
			if(ch=='+' || ch=='-'){
				scanf("%d%d",&u,&v);
				if(ch=='+') query[i].op=4;
				else query[i].op=5;
				query[i].u=u;
				query[i].v=v;
			}
			if(ch=='T' || ch=='F' || ch=='U'){
				scanf("%d",&u);
				if(ch=='T') query[i].op=1;
				if(ch=='F') query[i].op=2;
				if(ch=='U') query[i].op=3;
				query[i].u=u;
			}
		}
		dfs(1,0);
		printf("%d\n",ans_solve_1);
	}
}
bool isunknown[maxn];
void solve_3(){
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			cin>>ch;
			scanf("%d",&x);
			if(ch=='U') isunknown[x]=1;
			if(ch=='T' || ch=='F') isunknown[x]=0;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(isunknown[i]){
				ans++;
				isunknown[i]=0;
			}
		}
		printf("%d\n",ans);
	}
}
int rk[maxn],fa[maxn],rev[maxn];
vector<int> G[maxn]; 
int dfn[maxn],low[maxn];
bool ispoint[maxn];
char op;
int sum,cntx,ans;
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
int cnt=0;
void solve_7(){
	while(t--){
		ans=0;
		scanf("%d%d",&n,&m);
		memset(rk,0,sizeof(rk));
		memset(fa,0,sizeof(fa));
		memset(rev,0,sizeof(rev));
		memset(ispoint,0,sizeof(ispoint));
		memset(vis,0,sizeof(vis));
		memset(sz,0,sizeof(sz));
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
}

signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==1){
		solve_1();
		return 0;
	}
	if(c==3 || c==4){
		solve_3();
		return 0;
	}
	else{
		solve_7();
		return 0;
	}
	return 0;
}
