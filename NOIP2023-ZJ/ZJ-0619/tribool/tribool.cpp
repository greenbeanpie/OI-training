#include <bits/stdc++.h>
#define N 114514
using namespace std;
struct nd{
	int to,va;
};
int n,m,co[N],rd[N],ans,ks[N];
bool vis[N];
vector<nd> g[N];
void ad(int u,int v,int w){
	g[u].push_back((nd){v,w});
}
char ot;
int uu,vv;
void dfs(int x,int f){
	int ls,lla;
	if(f!=0){
		if(g[f][x].va==0)lla=-co[f];
		else lla=co[f];
	}
//	if(co[x]==-lla||co[x]==-x||co[x]==x)return ;
//	cout<<co[x]<<"\n";
	for(int i=0;i<g[x].size();++i){
		ls=g[x][i].to;
		if(ls==f||co[v]!=(-2*N))continue;
		dfs(ls,x);
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		ans=0;
		for(int i=1;i<=n;++i)co[i]=-2*N;
		for(int i=1;i<=n;++i)ks[i]=-2*N;
		for(int i=1;i<=m;++i){
			cin>>ot;
			if(ot=='+'){
				cin>>uu>>vv;
				ad(vv,uu,1);
				if(ks[uu]==(-2*N))ks[uu]=vv;
				co[uu]=vv;
				dfs(uu,0);
			}
			if(ot=='-'){
				cin>>uu>>vv;
				ad(vv,uu,0);
			//	cout<<<
				if(ks[uu]==(-2*N))ks[uu]=-vv;
				co[uu]=-vv;
				dfs(vv,0);
			}
			if(ot=='T'){
				cin>>uu;
				if(co[uu]==(-2*N))ks[uu]=N;
				co[uu]=N;
				dfs(uu,0);
			}
			if(ot=='F'){
				cin>>uu;
				if(co[uu]==(-2*N))ks[uu]=-N;
				co[uu]=-N;
				dfs(uu,0);
			}
			if(ot=='U'){
				cin>>uu;
				if(co[uu]==(-2*N))ks[uu]=0;
				co[uu]=0;
				dfs(uu,0);
			}
		}
		if(c==3||c==4){
			for(int i=1;i<=n;++i){
				if(co[i]==0)ans++;
			}
			for(int i=1;i<=n;++i)g[i].clear();
			printf("%d\n",ans);
			continue;
		}
		if(c==5||c==6){
			for(int i=1;i<=n;++i){
				if(ks[i]==0&&co[i]!=0){
				co[co[i]]=0;
				dfs(co[i],0);
			}
			}
			for(int i=1;i<=n;++i){
				if(ks[i]!=0&&co[i]==0){
					co[ks[i]]=0;
					dfs(ks[i],0);
				}
			}
			for(int i=1;i<=n;++i){
				if(co[i]==0)ans++;
			}
			for(int i=1;i<=n;++i)g[i].clear();
			cout<<ans<<endl;
			continue;
		}
		else {
			for(int i=1;i<=n;++i){
			if(ks[i]==N&&co[i]!=N){
				co[co[i]]=N;
				dfs(co[i],0);
			}
			if(ks[i]==-N&&co[i]!=-N){
				co[co[i]]=-N;
				dfs(co[i],0);
			}
			if(ks[i]==0&&co[i]!=0){
				co[co[i]]=0;
				dfs(co[i],0);
			}
		}
			for(int i=1;i<=n;++i){
				if(ks[i]!=0&&co[i]==0){
					co[ks[i]]=0;
					dfs(ks[i],0);
				}
				if(ks[i]!=N&&co[i]==N){
					co[ks[i]]=N;
					dfs(ks[i],0);
				}
				if(ks[i]!=-N&&co[i]==-N){
					co[ks[i]]=-N;
					dfs(ks[i],0);
				}
			}
			for(int i=1;i<=n;++i){
				if(co[i]!=N&&co[i]!=-N&&co[i]!=0){
					co[i]=N;
				//	cout<<co[1]<<"\n";
					dfs(i,0);
					if(co[i]!=N){
						co[i]=0;
						dfs(i,0);
					}
				}
			}
			for(int i=1;i<=n;++i){
			//	cout<<co[i]<<" ";
				if(co[i]==0)ans++;
			}
			for(int i=1;i<=n;++i)g[i].clear();
			cout<<ans<<"\n";
		}
	/*	*/
		//if(c==)
	}
	return 0;
}