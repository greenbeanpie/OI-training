#include<bits/stdc++.h>
#define ll long long
#define ph push_back
#define ord(i,l,r) for(int i=l;i<=r;i++)
#define dord(i,r,l) for(int i=r;i>=l;i--)
#define erd(i,x) for(int i=hd[x];i;i=e[i].nxt)
using namespace std;
const int N=1e5+20;
int n,m,w[N],c[N],ct; bool vis[N],rg[N];
struct edge{ int v,nxt,w; }e[N<<1]; int hd[N],ent; //!!!
void add(int u,int v,int w){ e[++ent]=(edge){v,hd[u],w},hd[u]=ent; }
void ADD(int u,int v,int w){ add(u,v,w),add(v,u,w); }
void col(int x,int p){
	if(c[x]) return ;
	c[x]=p,vis[x]=1;
	erd(i,x) col(e[i].v,p);
}
bool dfs(int x,int le){
	if(vis[x]) return rg[x]=1;
	vis[x]=1;
	erd(i,x) if(i!=le){
		if(dfs(e[i].v,i^1)){
			ct+=e[i].w;	
			if(rg[x]) return 0;
			return rg[x]=1;
		}
	}return 0;
}
int solve(){
	ent=1; ord(i,1,n+2) hd[i]=c[i]=vis[i]=rg[i]=0; //clear!!!
	scanf("%d%d",&n,&m);
	ord(i,1,n) w[i]=i;
	char op[2]; int x,y;
	ord(i,1,m){
		scanf("%s",op);
		if(op[0]=='+') scanf("%d%d",&x,&y),w[x]=w[y];
		else if(op[0]=='-') scanf("%d%d",&x,&y),w[x]=-w[y];
		else scanf("%d",&x),w[x]=(op[0]=='U'?0:(op[0]=='T'?n+1:-n-1));
	}
	ord(i,1,n){
		if(w[i]==0) ADD(i,n+2,0);
		else ADD(i,abs(w[i]),w[i]<0);
	}
	col(n+2,1);
	ord(u,1,n) if(!vis[u]){
		ct=0,dfs(u,0);
		col(u,1+(ct%2==0));
	}	
//	ord(i,1,n) printf("%2d %3d %2d %2d\n",i,w[i],c[i],rg[i]);
	int as=0;
	ord(i,1,n) as+=c[i]==1;
	return as;
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int Yao,T; scanf("%d%d",&Yao,&T);
	while(T--) printf("%d\n",solve());
	return 0;
}