#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int c,t;
struct pcr {
	int x,y;
	char ty;
} a[maxn];
struct aa {
	int to;
	char w;
};
int vis[maxn],flag[maxn];
int siz[maxn],sum[maxn],fa[maxn];
int p[maxn];
vector <aa> P[maxn];
int find(int x) {
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void dfs(int x) {
	for(int i=0; i<P[x].size(); i++) {
		aa now=P[x][i];
		if(vis[now.to]) continue;
		vis[now.to]=1;
		if(now.w=='-') sum[fa[now.to]]--;
		if(now.w=='+') sum[fa[now.to]]++;
		if(now.w=='T'||now.w=='F'&&!flag[fa[now.to]]) flag[fa[now.to]]=1;
		if(now.w=='U'&&!flag[fa[now.to]]) flag[fa[now.to]]=2;
		dfs(now.to);
	}
}
signed main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--) {
		int n,m,ans=0;
		bool f=0;
		scanf("%d %d",&n,&m);
		for(int i=1; i<=n; i++) P[i].clear();
		for(int i=1; i<=n; i++) vis[i]=0,flag[i]=0,sum[i]=0,fa[i]=i,siz[i]=1;
		for(int i=1; i<=m; i++) {
			cin>>a[i].ty;
			if(a[i].ty=='T'||a[i].ty=='U'||a[i].ty=='F') scanf("%d",&a[i].x);
			else {
				f=1;
				scanf("%d %d",&a[i].x,&a[i].y);
				P[a[i].y].push_back({a[i].x,a[i].ty});
				P[a[i].x].push_back({a[i].y,a[i].ty});
				fa[find(a[i].x)]=find(a[i].y);
			}
			if(a[i].ty=='U') p[a[i].x]=1;
			else p[a[i].x]=0;
		}
		if(!f) {
			for(int i=1; i<=n; i++) if(p[i]) ans++;
			printf("%d\n",ans);
			continue;
		}
		for(int i=1; i<=n; i++) {
			if(fa[i]==i) continue;
			else ++siz[fa[i]];
		}
		for(int i=1; i<=n; i++) if(!vis[i]) dfs(i);
		for(int i=1; i<=n; i++) {
			if(fa[i]==i) {
				if(flag[i]==2) ans+=siz[i];
				if(abs(sum[i])>1) ans+=siz[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}