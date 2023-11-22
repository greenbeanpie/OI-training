#include<bits/stdc++.h>
#define fr(s) freopen(s".in","r",stdin)
#define fw(s) freopen(s".out","w",stdout)
using namespace std;
const int N=1e5+10,M=1e5+10,inf=1e5+10;
int c,t;
int n,m,ans;
int check(char ch){
	if(ch=='T')return 1;
	if(ch=='F')return -1;
	if(ch=='U')return 0;
	if(ch=='+')return 2;
	return 3;
}
struct input{
	int op,val,flag;
	int x,y;
}a[M];
int st[N],ed[N];
void dfs1(int cnt,int pos){
	if(cnt>=ans)return ;
	if(pos>n){
		for(int i=1;i<=n;i++){
			ed[i]=st[i];
		}
		for(int i=1;i<=m;i++){
			if(a[i].op<=1){
				ed[a[i].x]=a[i].val;
			}
			else {
				ed[a[i].x]=ed[a[i].y]*a[i].flag;
			}
		}
		for(int i=1;i<=n;i++){
			if(ed[i]!=st[i])return ;
		}
		ans=cnt;
		return ;
	}
	st[pos]=1;
	dfs1(cnt,pos+1);
	st[pos]=-1;
	dfs1(cnt,pos+1);
	st[pos]=0;
	dfs1(cnt+1,pos+1);
}
void solve1(){
	ans=inf;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		st[i]=ed[i]=0;
	}
	for(int i=1;i<=m;i++){
		char ch;
		cin>>ch;
		a[i].op=check(ch);
		if(a[i].op==1||a[i].op==-1||a[i].op==0){
			a[i].val=a[i].op;
			cin>>a[i].x;
		}
		else{
			cin>>a[i].x>>a[i].y;
			if(a[i].op==2)a[i].flag=1;
			else a[i].flag=-1;
		}
	}
	dfs1(0,1);
}
int col[N];
void solve2(){
	ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		col[i]=4;
	}
	for(int i=1;i<=m;i++){
		int op,u;
		char ch;
		cin>>ch;
		op=check(ch);
		cin>>u;
		col[u]=op;
	}
	for(int i=1;i<=n;i++){
		if(col[i]==0)ans++;
	}
}
struct result{
	int v,w;
}q[N],init;
int vis[N],f[N];
vector<int> g[N];
void dfs3(int u){
	if(q[u].w==4){
		if(vis[u]>2)return ;
		else {
			vis[u]++;
			dfs3(q[u].v);
			q[u].w=q[q[u].v].w;
		}
		return ;
	}
	return ;
}
//void dfs3(int u){
//	if(vis[u])return ;
//	vis[u]=1;
//	for(int i=0;i<g[u].size();i++){
//		int v=g[u][i];
//		dfs3(v);
//		f[u]=f[v];
//	}
//}
void solve3(){
	init.v=0;
	init.w=4;
	ans=0;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		q[i]=init;
		vis[i]=0;
	}
	for(int i=1;i<=m;i++){
		int op,u,v;
		char ch;
		cin>>ch;
		op=check(ch);
		if(op==0){
			cin>>u;
//			f[u]=0;
//			g[u].pop_back();
			q[u].w=0;
			q[u].v=0;
		}
		else {
//			g[u].pop_back();
//			g[u].push_back(v);
//			f[u]=f[v];
			cin>>u>>v;
			q[u].v=v;
//			dfs3(u);
			q[u].w=q[v].w;
		}
	}
	for(int i=1;i<=n;i++){
//		if(!vis[i]&&f[i]!=4){
//			dfs3(i);
//		}
		dfs3(i);
	}
	for(int i=1;i<=n;i++){
		ans+=(q[i].w==0);
	}
//	for(int i=1;i<=n;i++){
//		cout<<i<<" "<<q[i].v<<"/"<<q[i].w<<"\n";
//	}
}
void solve4(){
	ans=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int op,u,v;
		char ch;
		cin>>ch;
		op=check(ch);
		if(op==1||op==-1||op==0){
			cin>>u;
			ans--;
		}
		else{
			cin>>u>>v;
			if(op==3)ans++;
		}
	}
}
signed main(){
	fr("tribool");
	fw("tribool");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==1||c==2){
		while(t--){
			solve1();
			cout<<ans<<endl;
		}
	}
	else if(c==3||c==4){
		while(t--){
			solve2();
			cout<<ans<<endl;
		}
	}
	else if(c==5||c==6){
		while(t--){
			solve3();
			cout<<ans<<endl;
		}
	}
	else {
		while(t--){
			solve4();
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
*/
