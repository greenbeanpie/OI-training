#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+37,M=1e5+37;
struct node {
	ll x,y,d;
	bool operator <(const node &cmp) const {
		if(x!=cmp.x) return x<cmp.x;
		return y<cmp.y;
	}
} a[M];
namespace Solve1 {
	ll f[N][N][2];
	void init() {
		int n,m,k;
		ll d;
		cin>>n>>m>>k>>d;
		for(int i=1; i<=m; ++i)
			cin>>a[i].x>>a[i].y>>a[i].d;
		sort(a+1,a+m+1);
		int cur=1;
		for(int i=0; i<=n; ++i)
			for(int j=0; j<=n; ++j)
				f[i][j][0]=f[i][j][1]=-1e18;
		f[0][0][0]=0;
		for(int i=1; i<=n; ++i) {
			ll add=0;
			// te pan j==0
			while(cur<=m&&i==a[cur].x&&a[cur].y==1) {
				add+=a[cur].d;
				cur++;
			} // pay attention! and if->while
			f[i][1][1]=max(f[i][1][1],f[i-1][0][0]-d+add);
			for(int j=2; j<=min(i,k); ++j) {
				while(cur<=m&&i==a[cur].x&&j>=a[cur].y) {
					add+=a[cur].d;
					cur++;
				}
//			cout<<i<<' '<<j<<' '<<cur<<' '<<add<<'\n';
				f[i][j][1]=max(f[i][j][1],f[i-1][j-1][1]-d+add);
			}
			for(int j=1; j<=min(i-1,k); ++j)
				f[i][0][0]=max(f[i][0][0],f[i-1][j][1]);
			f[i][0][0]=max(f[i][0][0],f[i-1][0][0]);
			while(cur<=m&&i==a[cur].x) cur++;
		}
		ll ans=0;
		for(int i=1; i<=min(n,k); ++i)
			ans=max(ans,f[n][i][1]);
		ans=max(ans,f[n][0][0]);
		cout<<ans<<'\n';
	}
}
namespace Solve2 {
	void init() {
		int n,m,k;
		ll d;
		cin>>n>>m>>k>>d;
		for(int i=1; i<=m; ++i)
			cin>>a[i].x>>a[i].y>>a[i].d;
		ll ans=0;
		for(int i=1; i<=m; ++i)
			if(a[i].y<=k&&a[i].d>=a[i].y*d)
				ans+=a[i].d-a[i].y*d;
		cout<<ans<<'\n';
	}
}
int main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	if(c<=9) while(t--) Solve1::init();
	else while(t--) Solve2::init();
	return 0;
}