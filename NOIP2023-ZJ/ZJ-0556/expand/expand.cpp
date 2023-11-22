#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+7;
bool f[N][N]; // a[1~i],b[1~j]
int a[N],b[N];
int ra[N],rb[N];
void init1() {
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1; i<=n; ++i)
		cin>>a[i],ra[i]=a[i];
	for(int i=1; i<=m; ++i)
		cin>>b[i],rb[i]=b[i];
	int op;
	if(a[n]>b[m]) op=1;
	else if(a[n]<b[m]) op=-1;
	else op=0;
	f[0][0]=1;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j) {
			if((a[i]-b[j])*op>0)
				f[i][j]=f[i-1][j]|f[i][j-1]|f[i-1][j-1];
		}
	cout<<f[n][m];
	int k1,k2;
	int p,del;
	while(q--) {
		cin>>k1>>k2;
		while(k1--) {
			cin>>p>>del;
			a[p]=del;
		}
		while(k2--) {
			cin>>p>>del;
			b[p]=del;
		}
//		for(int i=1; i<=n; ++i)
//			cout<<a[i]<<' ';
//		cout<<'\n';
//		for(int j=1; j<=m; ++j)
//			cout<<b[j]<<' ';
//		cout<<'\n';
		if(a[n]>b[m]) op=1;
		else if(a[n]<b[m]) op=-1;
		else op=0;
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=m; ++j) {
				f[i][j]=0;
				if((a[i]-b[j])*op>0)
					f[i][j]=f[i-1][j]|f[i][j-1]|f[i-1][j-1];
			}
		memcpy(a,ra,sizeof(int)*(n+2));
		memcpy(b,rb,sizeof(int)*(m+2));
		cout<<f[n][m];
	}
}
void init2();
int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c;
	cin>>c;
	if(c<=9) init1();
	else init2();
	return 0;
}
queue<pair<int,int>> q;
map<pair<int,int>,bool> vis;
int n,m;
bool bfs(int op) {
	if((a[1]-b[1])*op<=0) return 0;
	while(!q.empty()) q.pop();
	q.push({1,1});
	if(n==1||m==1) return 1;
	vis.clear();
	while(!q.empty()) {
		int x=q.front().first,y=q.front().second;
		q.pop();
		if(x<n&&y<m&&(a[x+1]-b[y+1])*op>0) {
			if(x+1==n&&y+1==m) return 1;
			auto xx=make_pair(x+1,y+1);
			if(!vis[xx]) {
				vis[xx]=1;
				q.push(xx);
			}
		}
		if(x<n&&y<=m&&(a[x+1]-b[y])*op>0) {
			if(x+1==n&&y==m) return 1;
			auto xx=make_pair(x+1,y);
			if(!vis[xx]) {
				vis[xx]=1;
				q.push(xx);
			}
		}
		if(x<=n&&y<m&&(a[x]-b[y+1])*op>0) {
			if(x==n&&y+1==m) return 1;
			auto xx=make_pair(x,y+1);
			if(!vis[xx]) {
				vis[xx]=1;
				q.push(xx);
			}
		}
	}
	return 0;
}
void init2() {
	int q;
	cin>>n>>m>>q;
	for(int i=1; i<=n; ++i)
		cin>>a[i],ra[i]=a[i];
	for(int i=1; i<=m; ++i)
		cin>>b[i],rb[i]=b[i];
//	for(int i=1; i<=n; ++i,cout<<'\n')
//		for(int j=1; j<=m; ++j)
//			if(a[i]>b[j]) cout<<1<<' ';
//			else cout<<0<<' ';
	int op;
	if(a[n]>b[m]) op=1;
	else if(a[n]<b[m]) op=-1;
	else op=0;
	cout<<bfs(op);
	int k1,k2;
	int p,del;
	while(q--) {
		cin>>k1>>k2;
		while(k1--) {
			cin>>p>>del;
			a[p]=del;
		}
		while(k2--) {
			cin>>p>>del;
			b[p]=del;
		}
		if(a[n]>b[m]) op=1;
		else if(a[n]<b[m]) op=-1;
		else op=0;
		cout<<bfs(op);
		memcpy(a,ra,sizeof(int)*(n+2));
		memcpy(b,rb,sizeof(int)*(m+2));
	}
}