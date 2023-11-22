#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
struct edge{
	int nxt;
	int to;
	int b;
}e[N];
int dis[N];
int head[N],cnt;
int fa[N],fae[N],ans;
void add(int u,int v,char c){
	e[--cnt].to=v;
	if(c=='T')e[cnt].b=1;
	if(c=='F')e[cnt].b=2;
	if(c=='U')e[cnt].b=3;
	if(c=='+'){
		if(e[cnt].b==1)e[cnt].b=1;
		if(e[cnt].b==2)e[cnt].b=2;
		if(e[cnt].b==3)e[cnt].b=3;
	}
	if(c=='-'){
		if(e[cnt].b==1)e[cnt].b=2;
		if(e[cnt].b==2)e[cnt].b=1;
		if(e[cnt].b==3)e[cnt].b=3;
	}
	e[cnt].nxt=head[u];
	head[u]=cnt;
	fae[cnt]=u;
	if(v!=u)fa[v]=u;
}
char ch;
int x,y,c,t,n,m;
void dfsu(int bg){
	priority_queue<int>q;
	q.push(bg);
	while(!q.empty()){
		int x=q.top();
		q.pop();
		t=e[x].to;
		if(fa[t]==fae[x])dis[t]=3;
		if(t!=fae[x]){
			for(int i=x; i; i=e[i].nxt){
				q.push(i);
			}
		}
	}
}
void dfs(int bg){
	priority_queue<int>q;
	q.push(bg);
	while(!q.empty()){
		int x=q.top();
		q.pop();
		t=e[x].to;
		if(t==fae[bg] && dis[t]!=e[x].b){
			dfsu(bg);
			return ;
		}
		if(fa[t]==fae[x])dis[t]=e[x].b;
		if(t!=fae[x]){
			for(int i=x; i; i=e[i].nxt){
				q.push(i);
			}
		}		
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin >> c >> t;
	while(t--){
		memset(e,0,sizeof(e));
		memset(dis,0,sizeof(dis));
		memset(head,0,sizeof(head));
		memset(fa,0,sizeof(fa));
		memset(fae,0,sizeof(fae));
		ans=0;
		cin >> n >> m;
		cnt=m;
		for(int i=1; i<=m; i++){
			cin >> ch;
			if(ch=='T'){
				cin >> x;
				add(x,x,'T');
			}
			if(ch=='F'){
				cin >> x;
				add(x,x,'F');
			}
			if(ch=='U'){
				cin >> x;
				add(x,x,'U');
			}
			if(ch=='+'){
				cin >> x >>y;
				add(y,x,'+');
			}
			if(ch=='-'){
				cin >> x >>y;
				add(y,x,'-');
			}
		}
		for(int i=m; i>=1; i--){
			if(!fa[fae[i]]){
				dfs(i);
			}
		}
		for(int i=1; i<=n; i++)if(dis[n]==3)ans++;
		cout << ans << "\n";
	}		
	return 0;
}