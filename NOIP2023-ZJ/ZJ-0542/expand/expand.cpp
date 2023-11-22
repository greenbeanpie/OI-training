#include<bits/stdc++.h>

using namespace std;
const int maxn=5e5+100;
int c,n,m,q,n1,m1,p,v;
int x[maxn],y[maxn];
int x_1[maxn],y_1[maxn];
int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1; i<=n; i++) {
		scanf("%d",&x[i]);
	}
	for(int i=1; i<=m; i++) {
		scanf("%d",&y[i]);
	}
	if((x[1]-y[1])*(x[n]-y[n])<=0) printf("0");
	else printf("1");
	for(int i=1; i<=q; i++) {
		for(int j=1; j<=n; j++) {
			x_1[i]=x[i];
		}
		for(int j=1; j<=m; j++) {
			y_1[i]=y[i];
		}
		scanf("%d%d",&n1,&m1);
		for(int j=1; j<=n1; j++) {
			scanf("%d%d",&p,&v);
			x_1[p]=v;
		}
		for(int j=1; j<=m1; j++) {
			scanf("%d%d",&p,&v);
			y_1[p]=v;
		}
		if((x_1[1]-y_1[1])*(x_1[n]-y_1[n])<=0) printf("0");
		else printf("1");
	}
	return 0;
}
