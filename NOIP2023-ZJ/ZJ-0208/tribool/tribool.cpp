#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int op[N],x[N],y[N];
int qwq[N],tmp[N];
int c,T,n,m,s;
bool flag[N],tag[N],vis[N];
void dfs(int d){
	if(d==n){
		for(int i=1;i<=n;++i) tmp[i]=qwq[i];
		for(int i=0;i<m;++i){
			if(op[i]==0) tmp[x[i]]=tmp[y[i]];
			if(op[i]==1) tmp[x[i]]=(tmp[y[i]]<3?tmp[y[i]]%2+1:3);
			if(op[i]>=2) tmp[x[i]]=op[i]-1;
		}
		for(int i=1;i<=n;++i) if(tmp[i]!=qwq[i]) return;
		int k=0;
		for(int i=1;i<=n;++i) k+=(qwq[i]==3?1:0);
		s=min(s,k);
		return;
	}
	qwq[d+1]=1;
	dfs(d+1);
	qwq[d+1]=2;
	dfs(d+1);
	qwq[d+1]=3;
	dfs(d+1);
}
void solve1(){
	while(T--){
		cin>>n>>m;
		char ch;
		for(int i=0;i<m;++i){
			cin>>ch;
			if(ch=='-'){
				op[i]=1;
				cin>>x[i]>>y[i];
			}else
			if(ch=='+'){
				op[i]=0;
				cin>>x[i]>>y[i];
			}else{
				cin>>x[i];
				if(ch=='U') op[i]=4;
				if(ch=='T') op[i]=2;
				if(ch=='F') op[i]=3;
			}
		}
		s=n;
		dfs(0);
		cout<<s<<endl;
	}
}
void solve2(){
	while(T--){
		cin>>n>>m;
		char ch;
		for(int i=1;i<=n;++i) y[i]=0;
		for(int i=0;i<m;++i){
			cin>>ch>>x[i];
			if(ch=='U') op[i]=3;
			if(ch=='T') op[i]=1;
			if(ch=='F') op[i]=2;
			y[x[i]]=op[i];
		}
		int s=0;
		for(int i=0;i<=n;++i)
			s+=(y[i]==3?1:0);
		cout<<s<<endl;
	}	
}
/*
void solve3(){
	while(T--){
		cin>>n>>m;
		char ch;
		for(int i=1;i<=n;++i) tag[i]=vis[i]=0;
		for(int i=1;i<=n;++i) head[i]=0;
		for(int i=0;i<m;++i){
			cin>>ch;
			if(ch=='+'){
				cin>>x[i]>>y[i];
				add(x[i],y[i]);
			}else{
				cin>>x[i];y[i]=-1;
				tag[x[i]]=true;
			}
		}
		for(int i=0;i<m;++i){
			if(y[i]==-1) continue;
			tag[x[i]]=tag[y[i]];
		}
		s=0;
		for(int i=1;i<=n;++i) s+=(flag[i]||tag[i]?1:0);
		cout<<s<<endl;
	}
}*/
/*
int fa[N];
vector<int>v[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void solve4(){
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=3*n;++i) fa[i]=i;
		for(int i=1;i<=3*n;++i) v[i].clear,v[i].push_back(i);
		char ch;int x,y;
		for(int i=1;i<=m;++i){
			cin>>ch>>x>>y;
			if(find(x)==x){
				int r=v[x].size();
				if(r>1){
					v[v[x][1]].clear();
					for(int j=1;j<r;++j){
						v[v[x][1]].push_back(v[x][j]);
						fa[v[x][j]]=v[x][1];
					}
				}
				v[x].clear();v[x].push_back(x);
			}
			if(ch=='-'){
				if(find(x+n)!=find(y)){
					fa[find(x)]
				}
			}else{
			}
		}
	}
}*/
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>T;
	if(c<=2){solve1();return 0;}
	if(c<=4){solve2();return 0;}
	//if(c<=6){solve3();return 0;}
	//if(c<=8){solve4();return 0;}
	
	return 0;
}