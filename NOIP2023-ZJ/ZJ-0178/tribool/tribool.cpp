#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100006;
struct Edge{
	int to,nxt,w;
}e[N*2];
int head[N],Top;
void add(int u,int v,int w){
	e[++Top].to=v;
	e[Top].nxt=head[u];
	head[u]=Top;
	e[Top].w=w;
}
int curv[N],vis[N],n;
void paint(int u){
	for(int i=head[u];i;i=e[i].nxt){
		int to=e[i].to;
		if(e[i].w==1) curv[to]=curv[u];
		else{
			if(curv[u]==n+3) curv[to]=n+3;
			else curv[to]=n+n+3-curv[u];
		}
		paint(to);
	}
}
int siz,ukn;
void dfs(int u){
	++siz;
	for(int i=head[u];i;i=e[i].nxt){
		int to=e[i].to,trans=(e[i].w==1?vis[u]:-vis[u]);
		if(vis[to]==0){
			vis[to]=trans;
			dfs(to);
		}else if(vis[to]!=trans) ukn=1;
	}
}
char s[10];
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int C,T;
	cin >> C >> T;
	while(T--){
		int m;
		cin >> n >> m;
		//qing kong !!
		memset(curv,0,sizeof(curv));
		//n+1 -> T
		//n+2 -> F
		//n+3 -> U
		for(int i=1;i<=n;++i)
			curv[i]=i;
		for(int i=1;i<=m;++i){
			int x,y;
			cin >> s >> x;
			if(s[0]=='T') curv[x]=n+1;
			if(s[0]=='F') curv[x]=n+2;
			if(s[0]=='U') curv[x]=n+3;
			if(s[0]=='+'){
				cin >> y;
				curv[x]=curv[y];
			}
			if(s[0]=='-'){
				cin >> y;
				curv[x]=-curv[y];
			}
		}
		for(int i=1;i<=n;++i){
			if(curv[i]==-n-1) curv[i]=n+2;
			if(curv[i]==-n-2) curv[i]=n+1;
			if(curv[i]==-n-3) curv[i]=n+3;
		}
		Top=0;
		memset(head,0,sizeof(head));
		for(int i=1;i<=n;++i){
			if(curv[i]>n) continue;
			add(abs(curv[i]),i,curv[i]/abs(curv[i]));
		}
		for(int i=1;i<=n;++i)
			if(curv[i]>n) paint(i);
		int ans=0;
		for(int i=1;i<=n;++i)
			if(curv[i]==n+3) ans++;
		//hei bai ran
		for(int i=1;i<=n;++i){
			if(curv[i]>n) continue;
			add(i,abs(curv[i]),curv[i]/abs(curv[i]));
		}
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;++i){
			if(curv[i]>n) continue;
			if(vis[i]!=0) continue;
			vis[i]=1; siz=0; ukn=0;
			dfs(i);
			if(ukn) ans+=siz;
		}
		cout << ans << '\n';
	}
	return 0;
}
