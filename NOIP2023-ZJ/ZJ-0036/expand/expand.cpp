#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;

int n,m,q;
int a[N],b[N];
int x[N],y[N];
int *X,*Y;
int nn,mm;
int mxxp[N],mnxp[N];
int mxyp[N],mnyp[N];
int mxxs[N],mnxs[N];
int mxys[N],mnys[N];

bool solvepre(int xx,int yy) {
	if(xx==0 || yy==0) return 1;
	if(X[mnxp[xx]]<=Y[mnyp[yy]] || Y[mxyp[yy]]>=X[mxxp[xx]]) return 0;
	if(xx==1 || yy==1) return 1;
	if(X[mxxp[xx-1]]>Y[mxyp[yy]]) return solvepre(mxxp[xx-1],yy);
	else if(Y[mnyp[yy-1]]<X[mnxp[xx]]) return solvepre(xx,mnyp[yy-1]);
	else return 0;
}

bool solvesuf(int xx,int yy) {
	if(xx==nn+1 || yy==mm+1) return 1;
	if(X[mnxs[xx]]<=Y[mnys[yy]] || Y[mxys[yy]]>=X[mxxs[xx]]) return 0;
	if(xx==nn || yy==mm) return 1;
	if(X[mxxs[xx+1]]>Y[mxys[yy]]) return solvesuf(mxxs[xx+1],yy);
	else if(Y[mnys[yy+1]]<X[mnxs[xx]]) return solvesuf(xx,mnys[yy+1]);
	else return 0;
}

bool solve() {
	if(X[mnxp[nn]]<=Y[mnyp[mm]] || Y[mxyp[mm]]>=X[mxxp[nn]]) return 0;
	int px=mxxp[nn],py=mnyp[mm];
	return solvepre(px,py)&solvesuf(px,py);
}
	
bool calc() {
	if(x[n]==y[m]) return 0;
	if(x[n]>y[m]) X=x,Y=y,nn=n,mm=m;
	else X=y,Y=x,nn=m,mm=n;
	if(X[1]<=Y[1]) return 0;
	mxxp[1]=mnxp[1]=mxyp[1]=mnyp[1]=1;
	for(int i=2;i<=nn;i++) if(X[i]>X[mxxp[i-1]]) mxxp[i]=i;else mxxp[i]=mxxp[i-1];
	for(int i=2;i<=nn;i++) if(X[i]<X[mnxp[i-1]]) mnxp[i]=i;else mnxp[i]=mnxp[i-1];
	for(int i=2;i<=mm;i++) if(Y[i]>Y[mxyp[i-1]]) mxyp[i]=i;else mxyp[i]=mxyp[i-1];
	for(int i=2;i<=mm;i++) if(Y[i]<Y[mnyp[i-1]]) mnyp[i]=i;else mnyp[i]=mnyp[i-1];
	mxxs[nn+1]=mnxs[nn+1]=mxys[mm+1]=mnys[mm+1]=0;
	mxxs[nn]=mnxs[nn]=nn,mxys[mm]=mnys[mm]=mm;
	for(int i=nn-1;i>=1;i--) if(X[i]>X[mxxs[i+1]]) mxxs[i]=i;else mxxs[i]=mxxs[i+1];
	for(int i=nn-1;i>=1;i--) if(X[i]<X[mnxs[i+1]]) mnxs[i]=i;else mnxs[i]=mnxs[i+1];
	for(int i=mm-1;i>=1;i--) if(Y[i]>Y[mxys[i+1]]) mxys[i]=i;else mxys[i]=mxys[i+1];
	for(int i=mm-1;i>=1;i--) if(Y[i]<Y[mnys[i+1]]) mnys[i]=i;else mnys[i]=mnys[i+1];
	return solve();
}
	
int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%*d%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		x[i]=a[i];
	}
	for(int i=1;i<=m;i++) {
		scanf("%d",&b[i]);
		y[i]=b[i];
	}
	printf("%d",calc());
	while(q--) {
		int kx,ky;
		scanf("%d%d",&kx,&ky);
		vector<int> arrx,arry;
		arrx.clear(),arry.clear();
		while(kx--) {
			int p,v;
			scanf("%d%d",&p,&v);
			arrx.push_back(p);
			x[p]=v;
		}
		while(ky--) {
			int p,v;
			scanf("%d%d",&p,&v);
			arry.push_back(p);
			y[p]=v;
		}
		printf("%d",calc());
		for(int p:arrx) x[p]=a[p];
		for(int p:arry) y[p]=b[p];
	}
	return 0;
}
//11:16
