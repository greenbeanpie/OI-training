#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 10;
int c,n,m,q;
int x[maxn],y[maxn];
int read() {
	char c = getchar();
	int sum = 0;
	while(c > '9' || c < '0') c = getchar();
	while(c <= '9' && c >= '0') sum = sum * 10 + c - '0',c = getchar();
	return sum;
}
int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c = read(),n = read(),m = read(),q = read();
	for(int i=1;i<=n;i++) x[i] = read();
	for(int i=1;i<=m;i++) y[i] = read();
	switch(c) {
		case 1:
			if(x[1]!=y[1]) cout << 1;
			else cout << 0;
			for(int i=1;i<=q;i++) {
				int pp=read(),ppp=read();
				for(int j=1;j<=pp;j++) {
					int xi = read(),vi = read();
					x[xi] = vi;
				}
				for(int j=1;j<=ppp;j++) {
					int yi = read(),vi = read();
					y[yi] = vi;
				}
				if((x[1] - y[1])*(x[n] - y[n])>0) cout << 1;
				else cout << 0;
			}
			break;
		default:
			if((x[1] - y[1])*(x[n] - y[n])>0) cout << 1;
			else cout << 0;
			for(int i=1;i<=q;i++) {
				int pp=read(),ppp=read();
				for(int j=1;j<=pp;j++) {
					int xi = read(),vi = read();
					x[xi] = vi;
				}
				for(int j=1;j<=ppp;j++) {
					int yi = read(),vi = read();
					y[yi] = vi;
				}
				if((x[1] - y[1])*(x[n] - y[n])>0) cout << 1;
				else cout << 0;
			}
			break;
	}
}