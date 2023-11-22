#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int ID,nn,mm,q;
int xx[N],yy[N];
int x[N],y[N];
//bool solve(int nl,int nr,int ml,int mr) {
//	int mn=query(ml,mr);
//	
//}
int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&ID,&nn,&mm,&q);
	for(int i=1; i<=nn; i++) scanf("%d",&xx[i]);
	for(int j=1; j<=mm; j++) scanf("%d",&yy[j]);
	while(q--) {
		int n=nn,m=mm,kx,ky;
		for(int i=1; i<=nn; i++) x[i]=xx[i];
		for(int j=1; j<=mm; j++) y[j]=yy[j];
		scanf("%d%d",&kx,&ky);
		for(int i=1,px,vx; i<=kx; i++) {
			scanf("%d%d",&px,&vx),x[px]=vx;
		}
		for(int j=1,py,vy; j<=ky; j++) {
			scanf("%d%d",&py,&vy),y[py]=vy;
		}
		if(x[1]==y[1]) {
			cout<<0;
			continue;
		}
		if(ID<8||ID>14) {
			bool flg=(x[1]<y[1]),ans=1;
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=m; j++) {
					if(i+j==3&&n==2&&m==2) continue;
					if((x[i]<y[j])!=flg) {
						ans=0; break;
					}
				}
			}
			cout<<ans;
		} else {
			if(x[n]>y[m]) cout<<0;
			else cout<<1;
		}
	}
}
