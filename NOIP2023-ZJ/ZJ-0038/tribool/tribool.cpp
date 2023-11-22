#include<bits/stdc++.h>
using namespace std;
#define pb push_back
bool st;
const int N=5e6+100;
int TT,n,m,up,fa[N],G[N],id[N],T,F,U,cnt,ans,col[N],vis[N],siz,num[N],in[N];
struct nade{int op,x,y;}q[N];char ch[5];
vector<int>E[N];
bool ed;
bool flag;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int y,int x){fa[find(x)]=find(y);}
void add(int x,int y){E[x].pb(y);E[y].pb(x);in[x]=in[y]=1;}
void dfs(int u){
	vis[u]=1;siz+=num[u];
	for(int v:E[u]){
		if(vis[v]){flag&=(col[u]^col[v]);continue;}
		col[v]=col[u]^1;dfs(v);
	}
}
inline int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%*d%d",&TT);
	while(TT--){
		n=read();m=read();
		for(int i=1;i<=m;i++){
			scanf("%s",ch);
			if(ch[0]=='T')q[i].op=0;
			else if(ch[0]=='F')q[i].op=1;
			else if(ch[0]=='U')q[i].op=2;
			else if(ch[0]=='+')q[i].op=3;
			else if(ch[0]=='-')q[i].op=4;
			if(ch[0]=='+'||ch[0]=='-')q[i].x=read(),q[i].y=read();
			else q[i].x=read();
		}
		up=n+m;cnt=n;
		int T=2*up+1,F=2*up+2,U=2*up+3;
		for(int i=1;i<=U;i++)fa[i]=i,G[i]=0,E[i].clear(),vis[i]=in[i]=num[i]=0;
		for(int i=1;i<=n;i++)id[i]=i;
		for(int i=m;i>=1;i--){   
			int x=id[q[i].x],op=q[i].op;
			if(!x)continue;
			if(q[i].x==q[i].y&&(op==3||op==4)){
				if(op==3)continue;cnt++;
				merge(cnt+up,x);merge(cnt,x+up);
				id[q[i].x]=cnt;continue;
			}
			if(op==0){merge(T,x);merge(F,x+up);}
			else if(op==1){merge(F,x);merge(T,x+up);}
			else if(op==2){merge(U,x);merge(U,x+up);}
			else{
				if(!id[q[i].y])id[q[i].y]=++cnt;int y=id[q[i].y];
				if(op==3)merge(y,x),merge(y+up,x+up);
				else merge(y+up,x),merge(y,x+up);
			}if(q[i].x!=q[i].y)id[q[i].x]=0;
		}for(int i=1;i<=n;i++)
			if(id[i])merge(id[i],find(i)),merge(id[i]+up,find(i+up));
		add(find(U),find(U));ans=0;
		for(int i=1;i<=n;i++)add(find(i),find(i+up)),num[find(i)]++;
		for(int i=1;i<=U;i++)
			if(!vis[i]&&in[i]){siz=0;flag=true;dfs(i);if(!flag)ans+=siz;}
		printf("%d\n",ans);
	}
}
