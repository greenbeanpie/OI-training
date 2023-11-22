#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 1e5+5;
inline int read() {
	int x;
	scanf("%d",&x);
	return x;
}
int n, m,TY,Q;
int a[N],b[N],c[N],d[N];
namespace point1 {
	inline int solve() {
		return a[1]!=b[1];
	}
}

namespace point2 {
	inline int solve() {
		if(n==1&&m==1) return a[1]!=b[1];
		if(n==1&&m==2) {
			if(a[1]==b[1]||a[1]==b[2]) return 0;
			return !((a[1]>b[1])^(a[1]>b[2]));
		}
		if(n==2&&m==1) {
			if(b[1]==a[1]||b[1]==a[2]) return 0;
			return !((b[1]>a[1])^(b[1]>a[2]));
		}
		if(a[1]==b[1]||a[2]==b[2]) return 0;
		return !((a[1]>b[1])^(a[2]>b[2]));
	}
}

namespace point3 {
	const int M = 2e3+5;
	int f[M][M];
	inline int solve() {
		if(a[1]==b[1]) return 0;
		bool flag=a[1]<b[1];
		f[1][1]=1;
		for(int i=1; i<=n; ++i) {
			for(int j=1+(i==1); j<=m; ++j) {
				f[i][j]=0;
				if(a[i]==b[j]) continue;
				f[i][j]|=f[i][j-1]&&(flag==(a[i]<b[j]));
				f[i][j]|=f[i-1][j]&&(flag==(a[i]<b[j]));
				f[i][j]|=f[i-1][j-1]&&(flag==(a[i]<b[j]));
			}
		}
		return f[n][m];
	}
}
inline int query() {
	if(TY==1) return point1 :: solve();
	if(TY==2) return point2 :: solve();
	if(TY<=7) return point3 :: solve();
}
signed main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	TY=read(),n=read(),m=read(),Q=read();
	for(int i=1; i<=n; ++i) c[i]=a[i]=read();
	for(int j=1; j<=m; ++j) d[j]=b[j]=read();
	cout<<query();
	while(Q--) {
//		cout<<"\n--------------------------------\n";
		int cnta=read(),cntb=read();
		for(int i=1; i<=cnta; ++i) {
			int x=read(),y=read();
			a[x]=y;
		}
		for(int i=1; i<=cntb; ++i) {
			int x=read(),y=read();
			b[x]=y;
		}
		cout<<query();
		for(int i=1;i<=n;++i) a[i]=c[i];
		for(int j=1;j<=m;++j) b[j]=d[j];
	}
	return 0;
}
