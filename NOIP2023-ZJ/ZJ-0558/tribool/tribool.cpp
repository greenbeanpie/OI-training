#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
int testid,T,n,m,ans;
int c[MAXN<<1];//1:T,2:U,3:F
int group[MAXN<<1];
vector<int>e[MAXN];
bool vis[MAXN];
inline void dfs(int x,int anc){
	if(vis[x]) return;
	group[x]=anc;
	vis[x]=1;
	for(int i=0;i<(int)e[x].size();i++){
		if(vis[e[x][i]]) continue;
		dfs(e[x][i],anc);
	}
	return;
}
inline void reset(){
	memset(vis,0,sizeof(vis));
	for(int i=0;i<=n<<1;i++) e[i].clear();
	for(int i=0;i<=n<<1;i++) group[i]=i;
	memset(c,0,sizeof(c));
	ans=0;
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&testid,&T);
	while(T--){
		scanf("%d%d",&n,&m);
		reset();
		for(int i=0;i<m;i++){
			char opt;
			scanf("%c",&opt);
			while(opt!='-'&&opt!='+'&&opt!='U'&&opt!='T'&&opt!='F') scanf("%c",&opt);
			int x,y;
			if(opt=='T'){
				scanf("%d",&x);
				c[x]=1,c[x+n]=3;
			} 
			else if(opt=='F'){
				scanf("%d",&x);
				c[x]=3,c[x+n]=1;
			}
			else if(opt=='U'){
				scanf("%d",&x);
				c[x]=2,c[x+n]=2;
				group[x]=x+n,group[x+n]=x;
			}
			else if(opt=='+'){
				scanf("%d%d",&x,&y);
				group[x]=group[y];
				group[x+n]=group[y+n];
			}
			else{
				scanf("%d%d",&x,&y);
				group[x]=group[y+n];
				group[x+n]=group[y];
			}
		} 
		for(int i=1;i<=n<<1;i++){
			e[i].push_back(group[i]);
			e[group[i]].push_back(i);
		}
//		for(int i=1;i<=n<<1;i++) printf("%d ",group[i]);
		for(int i=1;i<=n<<1;i++) if(!vis[i]) dfs(i,i);
		for(int i=1;i<=n;i++){
			if(c[i]&&c[group[i]]!=2) c[group[i]]=c[i];
			if(group[i]==group[i+n]) c[group[i]]=2;
		}
//		for(int i=1;i<=n;i++) printf("%d ",group[i]);
		for(int i=1;i<=n;i++) if(c[group[i]]==2) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
