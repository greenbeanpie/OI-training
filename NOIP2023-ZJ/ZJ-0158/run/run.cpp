#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int c,t,b[N],Ans,n,m,k,d,f[N][2];
struct node {
	int x,y,z,k;
} a[N];
inline bool cmp(node a,node b) {
	return a.x<b.x;
}
inline void check(int s) {
	int res=-s*d;
	for (int i=1;i<=m;++i) {
		int flag=1;
		for (int j=a[i].x-a[i].y+1;j<=a[i].x;++j) if (!b[j]) {flag=0; break;}
		if (flag) res+=a[i].z;
	}
	Ans=max(Ans,s);
}
inline void dfs(int x,int y,int s) {
	if (x>n) return check(s);
	if (y==k) b[x]=0,dfs(x+1,0,s);
	else {
		b[x]=1; dfs(x+1,y+1,s+1);
		b[x]=0; dfs(x+1,0,s);
	}
}
signed main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>c>>t;
	if (c==1||c==2) {
		while (t--) {
			cin>>n>>m>>k>>d; Ans=-1e18;
			for (int i=1;i<=m;++i) cin>>a[i].x>>a[i].y>>a[i].z;
			dfs(1,0,0); cout<<Ans<<endl;
		}
		return 0;
	}
		while (t--) {
			cin>>n>>m>>k>>d; Ans=-1e18;
			for (int i=1;i<=m;++i) cin>>a[i].x>>a[i].y>>a[i].z,f[i][0]=f[i][1]=0;
			sort(a+1,a+m+1,cmp);
			for (int i=1;i<=m;++i) if (a[i].y<=k) {
				if (a[i].y*d<a[i].z) a[i].k=a[i].z-a[i].y*d;
			}
			for (int i=1;i<=m;++i) f[i][1]=a[i].k;
			for (int i=2;i<=m;++i) {
				if (a[i-1].x==a[i].x-a[i].y&&a[i].y+a[i-1].y>=k) f[i][1]=max(f[i][1],f[i-1][0]);
				else f[i][1]=max(f[i][1],max(f[i-1][1],f[i-1][0]));
				f[i][0]=max(f[i-1][0],f[i-1][1]);
				Ans=max(Ans,max(f[i][0],f[i][1]));
			}
			cout<<Ans<<endl;
		}
	return 0;
}
