#include <bits/stdc++.h>

using namespace std;

int read() {
	int x=0, f=0; char c=getchar();
	while (!isdigit(c)) f|=c=='-', c=getchar();
	while (isdigit(c)) x=(x<<3)+(x<<1)+(c^48), c=getchar();
	return f ? -x : x;
}

const int N=2e3+10;
int C, n, m, q, a[N], b[N], aa[N], bb[N];
bool f[N][N];

int check() {
	if (a[1]==b[1]) return 0;
	bool qwq=0, flag=1;
	if (a[1]<b[1]) {
		qwq=1;
		for (int i=1; i<=n; i++) a[i]=-a[i];
		for (int i=1; i<=m; i++) b[i]=-b[i];
	}
	for (int j=1; j<=m; j++) {
		if (a[1]<b[j]) flag=0;
		f[1][j]=flag;
	}
	flag=1;
	for (int i=1; i<=n; i++) {
		if (a[i]<b[1]) flag=0;
		f[i][1]=flag;
	}
	for (int i=2; i<=n; i++)
		for (int j=2; j<=m; j++)
			f[i][j]=(a[i]>b[j]) && (f[i][j-1]||f[i-1][j]||f[i-1][j-1]);
	return f[n][m];
}

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	C=read(), n=read(), m=read(), q=read();
	for (int i=1; i<=n; i++) a[i]=aa[i]=read();
	for (int i=1; i<=m; i++) b[i]=bb[i]=read();
	printf("%d", check());
	while (q--) {
		int kx=read(), ky=read();
		for (int i=1; i<=n; i++) a[i]=aa[i];
		for (int i=1; i<=m; i++) b[i]=bb[i];
		for (int i=1; i<=kx; i++) {
			int px=read(), vx=read();
			a[px]=vx;
		}
		for (int i=1; i<=ky; i++) {
			int py=read(), vy=read();
			b[py]=vy;
		}
		printf("%d", check());
	}
	return 0;
}