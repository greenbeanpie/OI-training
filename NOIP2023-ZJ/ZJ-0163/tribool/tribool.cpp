#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int fa[N<<1],sz[N<<1],ans,head[N<<1],cnt,Size,C,T;
struct edge{
	int v,next;
}e[N<<2];
void add_edge(int u,int v){
	e[cnt]=edge{v,head[u]};
	head[u]=cnt++;
}
bool vis[N<<1],tag,vv[N<<1];
struct Edge{
	int u,v;
};
char Not(char c){
	if(c=='T') return 'F';
	if(c=='F') return 'T';
	return 'U';
}
vector<Edge> same,rev;
void DFS(int u,char now){
	if(vis[u]) return;
	if(now=='U') ans+=sz[u];
	vis[u]=true;
	for(int i=head[u];~i;i=e[i].next){
		const int v=e[i].v;
		if(vis[v]) continue;
		DFS(v,Not(now));
	}
}
void dfs(int u,bool val){
	vis[u]=true;
	vv[u]=val;
	Size+=sz[u];
	for(int i=head[u];~i;i=e[i].next){
		const int v=e[i].v;
		if(vis[v]){
			if(vv[v]!=(!val)) tag=true;
			continue;
		}
		dfs(v,!val);
	}
}
int find(int x){return (fa[x]==x?x:fa[x]=find(fa[x]));}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin >> C >> T;
	while(T--){
		int n,m;
		cin >> n >> m;
		for(int i=0;i<n;++i){
			fa[2*i]=2*i;
			fa[2*i+1]=2*i+1;
		}
		while(m--){
			char cc;
			cin >> cc;
			if(cc=='+'){
				int i,j;
				cin >> i >> j;
				--i;
				--j;
				int x=fa[2*j],y=fa[2*j+1];
				fa[2*i]=x;
				fa[2*i+1]=y;
			}else if(cc=='-'){
				int i,j;
				cin >> i >> j;
				--i;
				--j;
				int x=fa[2*j],y=fa[2*j+1];
				fa[2*i]=y;
				fa[2*i+1]=x;
			}else{
				int i;
				cin >> i;
				--i;
				if(cc=='T'){
					fa[2*i]=2*n;
					fa[2*i+1]=2*n+1;
				}else if(cc=='F'){
					fa[2*i]=2*n+1;
					fa[2*i+1]=2*n;
				}else fa[2*i]=fa[2*i+1]=2*n+2;
			}
		}
		same.clear();
		rev.clear();
		for(int i=0;i<n;++i){
			if(fa[2*i]!=2*i) same.push_back(Edge{fa[2*i],2*i});
			if(fa[2*i+1]!=2*i+1) same.push_back(Edge{fa[2*i+1],2*i+1});
			rev.push_back(Edge{2*i,2*i+1});
		}
		for(int i=0;i<2*n+3;++i){
			fa[i]=i;
			sz[i]=1;
		}
		for(Edge e:same){
			int x=find(e.u),y=find(e.v);
			if(x==y) continue;
			if(sz[x]<sz[y]) swap(x,y);
			fa[y]=x;
			sz[x]+=sz[y];
		}
		memset(head,255,sizeof(head));
		cnt=0;
		for(Edge e:rev){
			add_edge(find(e.u),find(e.v));
			add_edge(find(e.v),find(e.u));
		}
		memset(vis,0,sizeof(vis));
		ans=0;
		const int aa=find(2*n),bb=find(2*n+1),cc=find(2*n+2);
		DFS(aa,'T');
		DFS(bb,'F');
		DFS(cc,'U');
		--ans;
		for(int i=0;i<2*n+3;++i){
			if(fa[i]==i && !vis[i] && i!=aa && i!=bb && i!=cc){
				tag=false;
				Size=0;
				dfs(i,true);
				if(tag) ans+=Size;
			}
		}
		cout << ans/2 << '\n';
	}
	return 0;
}




/*
0 1
10 10
+ 4 3
- 3 2
- 9 6
- 8 9
- 10 8
- 2 5
- 3 6
+ 5 8
+ 9 3
- 10 10
*/