#include<bits/stdc++.h>
using namespace std;
const int N=100000;
//0 -->true
int equ[N+5];
int sym[N+5];
int c,T;
int n,m;
int fa[N+5];
int siz[N+5];
bool ban[N+5];
bool vis[N+5];
bool st;
int getroot(int x){
	return (x==fa[x]? x:fa[x]=getroot(fa[x]));
}
int head[N+5];
struct Edge{
	int to,nxt,w;
}e[N*2+5];
int tot;
inline void addE(int x,int y,int w){
	e[++tot]=(Edge){y,head[x],w};
	head[x]=tot;
}
void dfs(int x,int fa,int bol){
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(vis[y]){
			if(bol!=e[i].w&1)st=false;
			return;
		}
		if(!st)return;
		int t=e[i].w^bol;
		vis[y]=1;
		dfs(y,x,t);
		vis[y]=0;
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d %d",&c,&T);
	while(T--){
		scanf("%d%d",&n,&m);
		sym[0]=1;
		fa[n+1]=n+1;
		int ans=0;
		memset(ban,0,sizeof(ban));
		for(int i=0;i<=n;i++)equ[i]=i,sym[i]=1,fa[i]=i,siz[i]=1;
		siz[0]=0;
		siz[n+1]=0;
		fa[n+1]=n+1;
		for(int i=1;i<=m;i++){
			char op;
			int a,b;
			getchar();
			op=getchar();
			if(op=='-'||op=='+'){
				scanf("%d%d",&a,&b);
				equ[a]=equ[b];
				sym[a]=(op=='-'?-1:1);
				if(a!=b)sym[a]*=sym[b];
			}else{
				scanf("%d",&a);
				equ[a]=0;
				if(op=='F')sym[a]=-1;
				else if(op=='T') sym[a]=1;
				else sym[a]=0,equ[a]=n+1;
			}
		}
		for(int i=1;i<=n;i++){
			int x=getroot(i);
			int y=getroot(equ[i]);
			if(x==y)continue;
			fa[x]=y;
			siz[y]+=siz[x];
		}
		tot=0;
		memset(head,0,sizeof(head));
		memset(e,0,sizeof(e));
		for(int i=1;i<=n;i++){
			int x=getroot(i);
			int y=getroot(equ[i]);
			if((sym[i]==0||(i==equ[i]&&sym[i]==-1))&&ban[y]==0){
				ans+=siz[y];
				//cout<<y<<":"<<siz[y]<<endl;
				ban[y]=1;
			}
			if(ban[y]||i==equ[i])continue;
			if(equ[i]==0)continue;
			//cout<<i<<(sym[i]==-1?"=-":"=")<<equ[i]<<endl;
			addE(i,equ[i],sym[i]==-1);
		}
		for(int i=1;i<=n;i++){
			int x=getroot(i);
			//cout<<x<<":";
			memset(vis,0,sizeof(vis));
			if(ban[x])continue;
			st=true;
			vis[i]=1;
			dfs(i,0,0);
			vis[i]=0;
			if(!st){
				ans+=siz[x];
				ban[x]=1;
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}