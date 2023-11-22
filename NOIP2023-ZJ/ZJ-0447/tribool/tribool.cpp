#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=1e5+5,M=1e5+5;
int task,T,n,m;
char c[10];
int a[N];
vector<int>e[N*2];
int col[N*2],tot;
void dfs(int x,int fa){
	for(auto y:e[x]){
		if(y==fa){
			continue;
		}
		if(col[y])continue;
		col[y]=col[x];
		dfs(y,x);
	}
}
int scc[N],cnt,fl[N];
vector<int>E[N];
void dfs2(int x,int fa){
	for(auto y:E[x]){
		if(y==fa){
			continue;
		}
		if(scc[y])continue;
		scc[y]=scc[x];
		dfs2(y,x);
	}
}
vector<int>tr[N];
void modify(int x){
	if(a[x]!=-1&&a[x]!=200001&&a[x]!=200002){
		int y=(a[x]+1)/2;
		if(a[y]==-1)a[x]=-1;
		else{
			(a[y]&1)?(a[x]=a[y]+1):(a[x]=a[y]-1);
		}
	}
	for(auto y:tr[x]){
		modify(y);
	}
}
void init(){
	for(int i=1;i<=n;i++){
		a[i]=i*2-1;
		fl[i]=scc[i]=0;
		E[i].clear();
		tr[i].clear();
	}
	for(int i=1;i<=n*2;i++){
		e[i].clear();
		col[i]=0;
	}
	tot=cnt=0;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&task,&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		for(int i=1,x,y;i<=m;i++){
			scanf("%s",c);
			if(c[0]=='T'||c[0]=='F'||c[0]=='U'){
				scanf("%d",&x);
				if(c[0]=='T'){
					a[x]=200001;
				}else if(c[0]=='F'){
					a[x]=200002;
				}else{
					a[x]=-1;
				}
			}else{
				scanf("%d%d",&x,&y);
				if(c[0]=='+'){
					a[x]=a[y];
				}else{
					if(a[y]==-1){
						a[x]=-1;
						continue;
					}
					(a[y]&1)?(a[x]=a[y]+1):(a[x]=a[y]-1);
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]!=-1&&a[i]!=200001&&a[i]!=200002){
				tr[(a[i]+1)/2].pb(i);
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==-1||a[i]>=200001){
				modify(i);
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==-1||a[i]>=200001)continue;
			int p=(a[i]+1)/2;
			if(a[i]%2==0){
				e[i*2].pb(p*2-1);
				e[i*2-1].pb(p*2);
				e[p*2-1].pb(i*2);
				e[p*2].pb(i*2-1);
			}else{
				e[i*2].pb(p*2);
				e[i*2-1].pb(p*2-1);
				e[p*2].pb(i*2);
				e[p*2-1].pb(i*2-1);
			}
			if(p!=i){
				E[p].pb(i);
				E[i].pb(p);
			}
		}
		for(int i=1;i<=2*n;i++){
			if(!col[i]){
				col[i]=++tot;
				dfs(i,0);
			}
		}
		for(int i=1;i<=n;i++){
			if(!scc[i]){
				scc[i]=++cnt;
				dfs2(i,0);
			}
		}
		for(int i=1;i<=n;i++){
			if(col[i*2-1]==col[i*2]){
				fl[scc[i]]=-1;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==-1){
				fl[scc[i]]=-1;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(fl[scc[i]]==-1){
				ans+=1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}