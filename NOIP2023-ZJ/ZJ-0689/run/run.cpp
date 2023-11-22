#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e5+5;
const int N=1e2+5;
inline int read() {
	int f=1,x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	return f*x;
}
int c,t,ans;
int n,m,k,d;
bool vis[N];
int x[M],y[M],v[M],f[N];
int dp[N][N];
void solve() {
	int con=0,day=0;
	for (int i=1;i<=n;i++) {
		f[i]=f[i-1];
		if (vis[i]) {
			f[i]++;day++;
			con-=d;
		}
		else day=0;
		if (day>k) return;
	}
	for (int i=1;i<=m;i++) {
		if (y[i]>k) continue;
		if (f[x[i]]-f[x[i]-y[i]]==y[i]) con+=v[i];
	}
	ans=max(ans,con);
	return;
}
void dfs(int pos) {
	if (pos==n+1) {
		solve();
		return;
	}
	vis[pos]=false;dfs(pos+1);
	vis[pos]=true;dfs(pos+1);
}
signed main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read();t=read();
	while (t--) {
		n=read();m=read();k=read();d=read();
		for (int i=1;i<=m;i++) {
			x[i]=read();
			y[i]=read();
			v[i]=read();
		}
		if (c<=4) {
			ans=0;dfs(1);
			printf("%lld\n",ans);
		} else if (c>=17 && c<=18) {
			ans=0;
			for (int i=1;i<=m;i++) {
				if (y[i]>k) continue;
				if (d*y[i]<v[i]) ans+=v[i]-d*y[i];
			}
			printf("%lld\n",ans);
		} 
//		else if (c<=4) {
//			for (int i=1;i<n;i++) {
//				for (int j=i+1;j<=n;j++) {
//					for ()
//				}
//			}
//		}
	}
	return 0;
}
