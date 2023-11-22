#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=4e5+7,M=1e5+7;
struct edge {
	int nxt,to;
} e[N*2];
struct node {
	char op;
	int x,y;
} a[M];
bool vis[N];
int scc[N],head[N];
vector<int> b[N];
void init();
void bfs(int);
int cnt,dfstime;
void add(int u,int v) { // add(a,b): eventually x_a==x_b
	e[++cnt]= {head[u],v};
	head[u]=cnt;
}
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) init();
	return 0;
}
void init() {
	int n,m;
	cin>>n>>m;
	// x_i : i !x_i: i+n
	// True False:ignore U:2n+1
	int U=2*n+1;
	cnt=dfstime=0;
	memset(head,0,sizeof(int)*(U+3));
	memset(vis,0,sizeof(bool)*(U+3));
	memset(scc,0,sizeof(int)*(U+3));
	for(int i=1; i<=m; ++i) {
		cin>>a[i].op>>a[i].x;
		if(a[i].op=='+'||a[i].op=='-')
			cin>>a[i].y;
		else a[i].y=-1;
	}
	for(int i=m; i; --i) {
		int x=a[i].x;
		char op=a[i].op;
		if(vis[x]) continue;
		if(op=='+'&&a[i].x==a[i].y) continue;
		// pay attention!!!
		vis[x]=1;
		if(op=='U') {
			add(x,U);
			add(U,x);
			add(x+n,U);
			add(U,x+n);
		} else if(op=='F'||op=='T') continue;
		else {
			int y=a[i].y;
			if(op=='+') {
				add(x,y),add(y,x);
				add(x+n,y+n),add(y+n,x+n);
			} else {
				add(x,y+n),add(y+n,x);
				if(x!=y) add(x+n,y),add(y,x+n);
			}
		}
	}
	for(int i=1; i<=U; ++i)
		if(!scc[i]) {
			dfstime++;
			bfs(i);
		}
	int ans=0;
	for(int i=1; i<=dfstime; ++i) {
		if(i==scc[U]) {
			ans+=b[i].size();
			continue;
		}
		bool ok=0;
		for(auto x:b[i]) {
			int y=x>n?x-n:x+n;
			if(scc[x]==scc[y]) {
				ok=1;
				break;
			}
		}
		if(ok) ans+=b[i].size();
	}
	cout<<(ans-1)/2<<'\n'; // U and !x,x
//	for(int i=1; i<=U; ++i)
//		cout<<scc[i]<<' ';
//	cout<<'\n';
	for(int i=1; i<=dfstime; ++i)
		b[i].clear();
}
queue<int> q;
void bfs(int s) {
	q.push(s);
	scc[s]=dfstime;
	b[dfstime].emplace_back(s);
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		for(int i=head[u]; i; i=e[i].nxt) {
			int v=e[i].to;
			if(scc[v]) continue;
			scc[v]=dfstime;
			b[dfstime].emplace_back(v);
			q.push(v);
		}
	}

}
/*
1 3
3 3
- 1 2
- 2 3
+ 3 1
3 3
- 2 1
- 3 2
- 1 3
2 2
T 2
U 2
*/

/*
-1 1
2 2
T 1
F 2
*/

/*
-1 1
10 10
U 1
+ 2 1
+ 3 1
+ 4 1
+ 5 1
+ 6 1
+ 7 1
+ 8 1
+ 9 1
+ 1 10
*/