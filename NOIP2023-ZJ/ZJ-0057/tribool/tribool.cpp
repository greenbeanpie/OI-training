#include<bits/stdc++.h>
#define For(i,l,r) for(int i=l,i##end=r;i<=i##end;++i)
#define rFor(i,r,l) for(int i=r,i##end=l;i>=i##end;--i)
#define all(a) a.begin(),a.end()
using namespace std;
using ll=long long;
using pii=array<int,2>;
const int N=1e5+10,T=1e9,F=T+1,U=F+1;
int n,a[N],sz[N],d[N];
void work() {
	int m; cin>>n>>m;
	For(i,1,n) a[i]=i,sz[i]=1,d[i]=0;
	while(m--) {
		char opt; cin>>opt;
		if(opt=='T' || opt=='F' || opt=='U') {
			int x; cin>>x;
			if(opt=='T') a[x]=T;
			else if(opt=='F') a[x]=F;
			else if(opt=='U') a[x]=U;
		} else if(opt=='+') {
			int x,y; cin>>x>>y;
			a[x]=a[y];
		} else {
			int x,y; cin>>x>>y;
			if(abs(a[y])<=n) a[x]=-a[y];
			else {
				if(a[y]==T) a[x]=F;
				else if(a[y]==F) a[x]=T;
				else if(a[y]==U) a[x]=U;
			}
		}
	}
	For(i,1,n) if(abs(a[i])<=n) ++d[abs(a[i])];
	queue<int> q;
	For(i,1,n) if(!d[i]) q.push(i);
	int ans=0;
	while(q.size()) {
		int u=q.front(); q.pop();
		int v=abs(a[u]);
		if(v<=n) {
			if(!--d[v]) q.push(v);
			sz[v]+=sz[u];
		} else {
			if(a[u]==U) ans+=sz[u];
		}
	}
	For(i,1,n) if(d[i]) {
		int c=0,s=0;
		for(int x=i;d[x];d[x]=0,x=abs(a[x])) c^=a[x]<0,s+=sz[x];
		if(c) ans+=s;
	}
	cout<<ans<<"\n";
}
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	int tmp,T; cin>>tmp>>T;
	while(T--) work();
}