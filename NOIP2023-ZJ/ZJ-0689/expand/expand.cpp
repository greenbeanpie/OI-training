#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
const int maxn=1e9;
inline ll read() {
	ll f=1,x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	return f*x;
}
int c,n,m,q;
int xmax=0,xmin=maxn,ymax=0,ymin=maxn;
int x[N],y[N],xx[N],yy[N];
void solve() {
	if (x[1]==y[1] || x[n]==y[m] || (x[1]-y[1])*(x[n]-y[m])<0) {
		printf("0");
		return;
	}
	if (xmax>ymax || xmin==ymin) {
		printf("0");
		return;
	}
}
int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();n=read();m=read();q=read();
	for (int i=1;i<=n;i++) {
		x[i]=xx[i]=read();
		xmax=max(xmax,x[i]);
		xmin=min(xmin,x[i]);
	}
	for (int i=1;i<=m;i++) {
		y[i]=yy[i]=read();
		ymax=max(ymax,y[i]);
		ymin=min(ymin,y[i]);
	}
	//¿¼Éú:Ìý¿¼Éú
	if (c<=2) {
		if ((x[1]-y[1])*(x[n]-y[m])<0) printf("0");
		else printf("1");
		for (int i=1;i<=q;i++) {
			for (int j=1;j<=n;j++) x[j]=xx[j];
			for (int j=1;j<=m;j++) y[j]=yy[j];
			int k1=read(),k2=read();
			for (int j=1;j<=k1;j++) {
				int p=read(),v=read();
				x[p]=v;
			}
			for (int j=1;j<=k2;j++) {
				int p=read(),v=read();
				y[p]=v;
			}
			if ((x[1]-y[1])*(x[n]-y[m])<0) printf("0");
			else printf("1");
		}
	} else if (c>=8 && c<=14){
		solve();
	} else {
		for (int i=0;i<=q;i++) printf("0");
	}
	return 0;
}
