#include<bits/stdc++.h>
using namespace std;
#define N 100005
int c,t;
bool is[N],vis[N];
int cnt;
int n,m;
int idx,h[N],e[N],ne[N],color[N],edge[N],from[N],to[N];
void add(int a,int b) {
	e[++idx]=b;
	ne[idx]=h[a];
	h[a]=idx;
}
void sprea(int x) {
	for(register int i=1; i<=n; ++i) vis[i]=0;
	queue<int> q;
	q.push(x);
	vis[x]=1;
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		for(int i=h[u]; i; i=ne[i]) {
			int v=e[i];
			is[v]=is[u];
			if(!vis[v]) {
				is[v]=is[i];
				q.push(v);
				vis[v]=1;
			}
		}
	}
	return;
}
void bfs(int st) {
	queue<int> q;
	for(register int i=1; i<=n; ++i) vis[i]=0;
	q.push(st);
	vis[st]=1;
	color[st]=1;
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		for(int i=h[u]; i; i=ne[i]) {
			int v=e[i];
			
			if(!color[v]) {
				if(edge[i]==1) {
					color[v]=color[u];
					continue;
				} 
				if(edge[i]==0){
					if(color[u]==1) color[v]=2;
					if(color[u]==2) color[v]=1;
					if(color[u]==3){
						color[v]=3;
					}
				}
			} 
			else {
				if(color[u]==3) 
				{
					color[v]=3;
					continue;
				}
				if(edge[i]==1&&color[u]!=color[v]) color[v]=3;
				if(edge[i]==0&&color[u]==color[v]) color[v]=3;
			}
			if(!vis[v]) {
		//	cout<<u<<"->"<<v<<"\n";
				q.push(v);
				vis[v]=1;
			}

		}
	}
}
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==3||c==4) {
		while(t--) {
			cnt=0;
			for(register int i=1; i<=n; ++i) is[i]=0;
			cin>>n>>m;
			char v;
			int x;
			for(int i=1; i<=m; ++i) {
				cin>>v>>x;
				if(v=='U'&&!is[x]) {
					is[x]=1;
					cnt++;
				} else {
					if(is[x]) {
						is[x]=0;
						cnt--;
					}
				}
			}
			cout<<cnt<<"\n";
		}
	}
	if(c==5||c==6) {
		while(t--) {
			cnt=0;
			int count=0;
			cin>>n>>m;
			for(register int i=1; i<=n; ++i) is[i]=0;
			for(int i=1; i<=m; i++) {
				char x;
				int u,v;
				cin>>x;
				if(x=='U') {
					cin>>u;
					is[u]=1;
				} else {
					cin>>v>>u;
					if(is[u]) is[v]=1;
				}
			}
			for(register int i=1; i<=count; ++i) cnt+=(is[i]);
			cout<<cnt<<"\n";
		}
	}
	if(c==7||c==8) {
		while(t--) {
			cin>>n>>m;
			cnt=0;
			char v;
			int x;
			int y;
			for(int i=1; i<=n; i++) color[i]=0;
			for(int i=1; i<=m; i++) {
				cin>>v>>y>>x;
				add(x,y);
				if(v=='+') edge[idx]=1;
				else edge[idx]=0;
			}
			for(int i=1; i<=n; i++) {
				if(!color[i]) bfs(i);
			}
			for(int i=1;i<=n;i++)
			{
				if(color[i]==3) bfs(i);
			}
			for(int i=1; i<=n; i++) cnt+=(color[i]==3);
			cout<<cnt<<"\n";
		}
	}
	else{
		cout<<114514<<"\n";
	}
	return 0;
}
