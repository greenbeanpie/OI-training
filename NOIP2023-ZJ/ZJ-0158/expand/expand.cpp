#include <bits/stdc++.h>
using namespace std;
const int N=3010;
int n,m,c,q,a[N],b[N],x[N],y[N],xx[N],yy[N],f[N][N];
inline void read(int &res) {
	char c=getchar(); res=0;
	while (!isdigit(c)) c=getchar();
	while (isdigit(c)) res=(res<<1)+(res<<3)+c-48,c=getchar();
}
inline bool check(int x,int y) {
	if (a[1]<b[1]) return x<y; else return x>y;
}
int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>q;
//	read(c),read(n),read(m),read(q);
	for (int i=1;i<=n;++i) cin>>a[i];
	for (int i=1;i<=m;++i) cin>>b[i];
	if (c==1) {
		if (a[1]==b[1]) cout<<0; else cout<<1;
		while (q--) {
			int nn,mm; cin>>nn>>mm;
			for (int i=1;i<=nn;++i) cin>>x[i]>>y[i],swap(a[x[i]],y[i]);
			for (int i=1;i<=mm;++i) cin>>xx[i]>>yy[i],swap(b[xx[i]],yy[i]);
			if (a[1]==b[1]) cout<<0; else cout<<1;
			for (int i=1;i<=nn;++i) swap(a[x[i]],y[i]);
			for (int i=1;i<=mm;++i) swap(b[xx[i]],yy[i]);
		} return 0;
	}
		f[0][0]=1;
		for (int i=1;i<=n;++i)
			for (int j=1;j<=m;++j) {
				if (check(a[i],b[j])&&a[i]!=b[j]) f[i][j]|=(f[i-1][j-1]|f[i][j-1]|f[i-1][j]);
			} cout<<f[n][m];
		while (q--) {
			int nn,mm; cin>>nn>>mm;
			for (int i=1;i<=nn;++i) cin>>x[i]>>y[i],swap(a[x[i]],y[i]);
			for (int i=1;i<=mm;++i) cin>>xx[i]>>yy[i],swap(b[xx[i]],yy[i]);
			if (a[1]>b[1]&&a[n]>b[m]||a[1]<b[1]&&a[n]<b[m]) {
				f[0][0]=1; for (int i=1;i<=n;++i) for (int j=1;j<=m;++j) f[i][j]=0;
				for (int i=1;i<=n;++i)
					for (int j=1;j<=m;++j) {
						if (check(a[i],b[j])&&a[i]!=b[j]) f[i][j]|=(f[i-1][j-1]|f[i][j-1]|f[i-1][j]);
					} cout<<f[n][m];
			} else cout<<0;
			for (int i=1;i<=nn;++i) swap(a[x[i]],y[i]);
			for (int i=1;i<=mm;++i) swap(b[xx[i]],yy[i]);
		}
	return 0;
}
