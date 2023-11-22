#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int sid,T,n,m,val[N],res[N],vis[N],cnt,ans;
vector<int> G[N];
void dfs(int u){
	if(res[u]==0)++cnt;vis[u]=1;
	for(int v:G[u])if(vis[v]!=1){
		if(val[v]==u)res[v]=res[u];
		else res[v]=-res[u];
		dfs(v);
	}
}
void clear(int u){vis[u]=0;for(int v:G[u])if(vis[v]==1)clear(v);}
void init(){
	cnt=ans=0;
	for(int i=1;i<=n;i++)G[i].clear();
	memset(val,0,sizeof(val));
	memset(res,0,sizeof(res));
	memset(vis,0,sizeof(vis));
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&sid,&T);
	while(T--){
		init();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)val[i]=i;
		for(int i=1;i<=m;i++){
			char op=getchar();int x,y;
			while(op!='T'&&op!='F'&&op!='U'&&op!='+'&&op!='-')
				op=getchar();
			if(op=='T'){scanf("%d",&x);val[x]=n+1;}
			if(op=='F'){scanf("%d",&x);val[x]=-n-1;}
			if(op=='U'){scanf("%d",&x);val[x]=0;}
			if(op=='+'){scanf("%d%d",&x,&y);val[x]=val[y];}
			if(op=='-'){scanf("%d%d",&x,&y);val[x]=-val[y];}
		}
		for(int i=1;i<=n;i++){
			int j=abs(val[i]);
			if(j>0&&j<=n)G[j].push_back(i);
		}
		for(int i=1;i<=n;i++){
			if(val[i]==0){res[i]=0;cnt=0;dfs(i);ans+=cnt;}
			if(val[i]==n+1){res[i]=n+1;cnt=0;dfs(i);ans+=cnt;}
			if(val[i]==-n-1){res[i]=-n-1;cnt=0;dfs(i);ans+=cnt;}
		}
		for(int i=1;i<=n;i++)if(!vis[i]){
			int u=i,now=n;
			while(vis[u]!=2)vis[u]=2,u=abs(val[u]);
			clear(u);res[u]=0;cnt=0;dfs(u);
			if((val[u]<0&&res[u]==-res[-val[u]])||
			   (val[u]>0&&res[u]==res[val[u]]))now=min(now,cnt);
			clear(u);res[u]=n+1;cnt=0;dfs(u);
			if((val[u]<0&&res[u]==-res[-val[u]])||
			   (val[u]>0&&res[u]==res[val[u]]))now=min(now,cnt);
			clear(u);res[u]=-n-1;cnt=0;dfs(u);
			if((val[u]<0&&res[u]==-res[-val[u]])||
			   (val[u]>0&&res[u]==res[val[u]]))now=min(now,cnt);
			ans+=now;
		}
		printf("%d\n",ans);
	}
	return 0;
}