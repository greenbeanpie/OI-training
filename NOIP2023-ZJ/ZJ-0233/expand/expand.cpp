#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int x[N],y[N],_x[N],_y[N];
int n,m,q;
bool f[2005][2005];
int run() {
	f[0][0]=1; int i,j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			f[i][j]=0;
			if(x[i]>y[j]) {
				f[i][j]|=f[i][j-1];
				f[i][j]|=f[i-1][j-1];
				f[i][j]|=f[i-1][j];
			}
		}
	}
	if(f[n][m]) return 1;
	f[0][0]=1;
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			f[i][j]=0;
			if(x[i]<y[j]) {
				f[i][j]|=f[i][j-1];
				f[i][j]|=f[i-1][j-1];
				f[i][j]|=f[i-1][j];
			}
		}
	}
	if(f[n][m]) return 1;
	return 0;
}
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	int c,i; ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>q;
	for(i=1;i<=n;i++) cin>>x[i];
	for(i=1;i<=m;i++) cin>>y[i];
	for(i=1;i<=n;i++) _x[i]=x[i];
	for(i=1;i<=m;i++) _y[i]=y[i];
	cout<<run();
	while(q--) {
		for(i=1;i<=n;i++) x[i]=_x[i];
		for(i=1;i<=m;i++) y[i]=_y[i];
		int __,___,c,d; cin>>__>>___;
		while(__--) {
			cin>>c>>d; x[c]=d;
		}
		while(___--) {
			cin>>c>>d; y[c]=d;
		}
		cout<<run();
	}
	return 0;
}