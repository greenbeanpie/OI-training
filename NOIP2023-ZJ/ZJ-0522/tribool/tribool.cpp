#include<bits/stdc++.h>
using namespace std;
#define N 100005
/*
define:
1~n value of w1 ~ wn
-1~-n value of !w1 ~ !wn
n+1/-(n+2) T  n+2/-(n+1) F n+3/-(n+3) U
*/
char op;
int n,m;
int val[N<<2],rea[N<<2];
struct Edge{
	int to,pre,val;
}e[N<<2];
int last[N<<2],tot;
void add(int a,int b,int v){
	e[++tot].to=b;
	e[tot].val=v;
	e[tot].pre=last[a];
	last[a]=tot;
}
int re(int x){return x^(x>=0);}//0->1,1->0,-1->-1
int vis[N],cnt;
void dfs(int u,int val,int id){
	if(vis[u]==id) return;
	rea[u]=val;vis[u]=1;
	for(int i=last[u];i;i=e[i].pre){
		int v=e[i].to;
		dfs(v,(e[i].val?re(val):val),id);
	}
}
bool dfs1(int u,int val,int id){
	if(vis[u]==id) return val==rea[u];
//	cout<<"dfs1: "<<u<<" "<<val<<" "<<id<<endl;
	rea[u]=val,vis[u]=id;cnt+=(val==-1);
	for(int i=last[u];i;i=e[i].pre){
		int v=e[i].to;
		if(!dfs1(v,e[i].val?re(val):val,id)) return false;
	}
	return true;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) val[i]=i,rea[i]=19491001;
	memset(vis,0,sizeof vis);
	memset(last,0,sizeof last);tot=0;
	memset(e,0,sizeof e);
	for(int i=1,x,y;i<=m;i++){
		cin>>op>>x;
		if(op=='T') val[x]=n+1;
		if(op=='F') val[x]=n+2;
		if(op=='U') val[x]=n+3;
		if(op=='+'){
			cin>>y;
			val[x]=val[y];
		}
		if(op=='-'){
			cin>>y;
			val[x]=-val[y];
		}
	}
//	cout<<"input:OK"<<endl;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(val[i]==n+1||val[i]==-n-2) rea[i]=1;
		else if(val[i]==n+2||val[i]==-n-1) rea[i]=0;
		else if(val[i]==n+3||val[i]==-n-3||val[i]==-i) rea[i]=-1;
		else{
			add(abs(val[i]),i,(val[i]<0));
			continue;
		}
	}
	for(int i=1;i<=n;i++) if(rea[i]!=19491001&&!vis[i]) dfs(i,rea[i],1);
	for(int i=1;i<=n;i++) if(rea[i]==-1) ans++;
	for(int i=1;i<=n;i++){
		int res=n;
		if(!vis[i]){
			for(int j=1;j<4;j++){
				cnt=0;
				if(dfs1(i,j%3-1,j+i*3)) res=min(res,cnt);
			}
			ans+=res;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
/*
9:00 solution?
10:12 AC Huge example ex4   -finish
*/
