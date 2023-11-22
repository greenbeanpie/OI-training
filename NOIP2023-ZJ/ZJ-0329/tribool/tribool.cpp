#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,C,T,a[100010],b[100010],res;
vector<pair<char,pair<int,int> > >Q;
vector<int>e[100010];
inline int trans(int x){
	return x==2?2:1-x;
}
inline bool check(){
	for(int i=1;i<=n;i++)b[i]=a[i];
	for(auto i:Q){
		if(i.first=='+')b[i.second.first]=b[i.second.second];
		if(i.first=='-')b[i.second.first]=trans(b[i.second.second]);
		if(i.first=='T')b[i.second.first]=0;
		if(i.first=='F')b[i.second.first]=1;
		if(i.first=='U')b[i.second.first]=2;
	}
	for(int i=1;i<=n;i++)if(a[i]!=b[i])return 0;
	return 1;
}
inline void dfs(int x){
	if(x==n+1){
		int t=0;
		if(check()){
			for(int i=1;i<=n;i++)t+=a[i]==2;
			res=min(res,t);
		}
		return;
	}
	a[x]=0;dfs(x+1);
	a[x]=1;dfs(x+1);
	a[x]=2;dfs(x+1);
}
inline void Dfs(int u){
	b[u]=1;
	for(int v:e[u]){
		if(b[v])continue;
		if(a[u]==2)a[v]=a[u];
		Dfs(v);
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	for(int i=1;i<=N;i++)a[i]=b[i]=-1;
	cin>>C>>T;
	if(C<=2){
		char opt;
		int x,y;
		while(T--){
			Q.clear();res=1e9;
			for(int i=1;i<=n;i++)a[i]=b[i]=-1;
			cin>>n>>m;
			for(int i=1;i<=m;i++){
				cin>>opt;
				if(opt=='+'||opt=='-'){
					cin>>x>>y;
					Q.push_back({opt,{x,y}});
				}
				else{
					cin>>x;
					Q.push_back({opt,{x,0}});
				}
			}
			dfs(1);
			cout<<res<<'\n';
		}
		return 0;
	}
	if(C<=4){
		while(T--){
			for(int i=1;i<=n;i++)a[i]=-1;res=0;
			cin>>n>>m;
			char opt;int x;
			for(int i=1;i<=m;i++){
				cin>>opt>>x;
				if(opt=='T')a[x]=0;
		        if(opt=='F')a[x]=1;
		        if(opt=='U')a[x]=2;
			}
			for(int i=1;i<=n;i++)res+=a[i]==2;
			cout<<res<<'\n';
		}
		return 0;
	}
	if(C<=6){
		while(T--){
			for(int i=1;i<=n;i++)e[i].clear();
			for(int i=1;i<=n;i++)a[i]=b[i]=0;res=0;
			cin>>n>>m;
			char opt;int x,y;
			for(int i=1;i<=m;i++){
				cin>>opt;
				if(opt=='U')cin>>x,a[x]=2,e[x].clear(),Q.push_back({opt,{x,0}});
				else{
					cin>>x>>y;
					a[x]=a[y];
					e[y].push_back(x);
					Q.push_back({opt,{x,y}});
				}
			}
			for(int i=1;i<=n;i++)if(!b[i])Dfs(i);
			for(auto i:Q){
				opt=i.first;
				x=i.second.first;
				y=i.second.second;
				if(opt=='U')a[x]=2;
				else a[x]=a[y];
			}
			for(int i=1;i<=n;i++)res+=a[i]==2;
			cout<<res<<'\n';
		}
		return 0;
	}
}