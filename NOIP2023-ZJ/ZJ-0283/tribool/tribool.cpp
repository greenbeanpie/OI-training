#include<bits/stdc++.h>
#define N 100005
#define fs(x) ((n<<1)-x+1)
using namespace std;
int n,m,T,C,fa[N],cnt,fi[N<<1],bel[N<<1],idx;
bool vis[N<<1],pd[N];
struct edge{
	int ne,to;
}l[N<<2];
inline void add(int x,int y){
	l[++cnt].to=y;
	l[cnt].ne=fi[x];
	fi[x]=cnt;
}
inline int read(){
	int res=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
	while(ch>='0'&&ch<='9')res=res*10+ch-'0',ch=getchar();
	return res*f;
}
inline void dfs(int u,int topf){
	bel[u]=topf,vis[u]=1;
	for(int i=fi[u];i;i=l[i].ne){
		int v=l[i].to;
		if(!vis[v])dfs(v,topf);
	}
}
inline void clear(){
	cnt=idx=0;for(int i=1;i<=(n<<1);++i)fi[i]=bel[i]=pd[i]=vis[i]=0;
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	C=read(),T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;++i)fa[i]=i;
		while(m--){
			char op;
			scanf("%c",&op);
			if(op=='+'){
				int x=read(),y=read();
				fa[x]=fa[y];
			}
			else if(op=='-'){
				int x=read(),y=read();
				fa[x]=fa[y]==-1?-1:fs(fa[y]);
			}
			else{
				int x=read();
				if(op=='U')fa[x]=-1;
				else if(op=='T')fa[x]=0;
				else fa[x]=(n<<1)+1;
			}
		}
		for(int i=1;i<=n;++i)if(fa[i]>=1&&fa[i]<=(n<<1))
		add(i,fa[i]),add(fa[i],i),add(fs(i),fs(fa[i])),add(fs(fa[i]),fs(i));
		for(int i=1;i<=n;++i)if(!vis[i])dfs(i,++idx);
		for(int i=1;i<=n;++i)pd[bel[i]]|=fa[i]==-1,pd[bel[fs(i)]]|=fa[i]==-1;
		int ans=0;
		for(int i=1;i<=n;++i)if(fa[i]!=i&&fa[i]&&fa[i]!=(n<<1)+1)
		ans+=(bel[i]==bel[fs(i)])|pd[bel[i]];
		printf("%d\n",ans);
		if(T)clear();
	}
	return 0;
}