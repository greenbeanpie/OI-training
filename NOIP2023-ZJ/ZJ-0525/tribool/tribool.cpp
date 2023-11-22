#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
struct opt{
	char op;
	int x1,x2;
}ops[100005];
char start[100005],ed[100005];
bool taken[100005],must_u[100005];
bool vis[100005];
int n,m;
int ans=1e9;
inline void operate(){
	for(int i=1;i<=n;i++) ed[i]=start[i];
	for(int i=1;i<=m;i++){
		char op=ops[i].op;
		int x1=ops[i].x1,x2=ops[i].x2;
		if(op=='T' or op=='F' or op=='U') ed[x1]=op;
		else if(op=='+') ed[x1]=ed[x2];
		else if(op=='-'){
			if(ed[x2]=='T') ed[x1]='F';
			else if(ed[x2]=='F') ed[x1]='T';
			else if(ed[x2]=='U') ed[x1]='U';
		}
	}
	bool flag=1;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(start[i]!=ed[i]) flag=0;
		if(start[i]=='U') cnt++;
	}
	if(flag)ans=min(ans,cnt);
}
void dfs(int pos){
	if(pos==n+1){
		operate();
		return;
	} 
	start[pos]='T';
	dfs(pos+1);
	start[pos]='F';
	dfs(pos+1);
	start[pos]='U';
	dfs(pos+1);
}
struct edge{
	int to,nxt;
}G[200005];
int head[100005],cnt;
void add(int u,int v){
	edge tmp;
	tmp.nxt=head[u],tmp.to=v;
	G[++cnt]=tmp;
	head[u]=cnt;
}
queue<int> q;
int bfs(int s){
	q.push(s);
	vis[s]=1;
	int siz=1;
	bool col=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=G[i].nxt){
			int v=G[i].to;
			if(!vis[v]){
				vis[v]=1;
				siz++;
				if(must_u[v]) col=1;
			}
		}
	}
	if(col) return siz;
	return 0;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,T;
	cin>>c>>T;
	if(c==1 or c==2){
		while(T--){
			ans=1e9;
			cin>>n>>m;
			for(int i=1;i<=m;i++){
				cin>>ops[i].op;
				if(ops[i].op=='T' or ops[i].op=='F' or ops[i].op=='U') cin>>ops[i].x1;
				else cin>>ops[i].x1>>ops[i].x2;
			}
			dfs(1);
			cout<<ans<<endl;
		}
	}
	if(c==3 or c==4){
		while(T--){
			int ans=0;
			cin>>n>>m;
			memset(start,0,sizeof(start));
			for(int i=1;i<=m;i++){
				char op;
				int x;
				cin>>op>>x;
				start[x]=op;
			}
			for(int i=1;i<=n;i++) if(start[i]=='U') ans++;
			cout<<ans<<endl;
		}
	}
	else if(c==5 or c==6){
		while(T--){
			memset(taken,0,sizeof(taken));
			memset(must_u,0,sizeof(must_u));
			memset(vis,0,sizeof(vis));
			memset(head,0,sizeof(head));
			cnt=0;
			cin>>n>>m;
			for(int i=1;i<=m;i++){
				cin>>ops[i].op;
				if(ops[i].op=='U') cin>>ops[i].x1;
				else cin>>ops[i].x1>>ops[i].x2;
			}
			int mustgo=0;
			for(int i=m;i>=1;i--){
				if(!taken[ops[i].x1]){
					mustgo++;
					taken[ops[i].x1]=1;
					if(ops[i].op=='U') must_u[ops[i].x1]=1;
					else{
						add(ops[i].x1,ops[i].x2);
						add(ops[i].x2,ops[i].x1);
					}
				}
			}
			cout<<mustgo<<endl;
			ans=0;
			for(int i=1;i<=n;i++) if(!vis[i]){
				int tmp=bfs(i);
				ans+=tmp;
			} 
			cout<<ans<<endl;
		}
	}
}