#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
int c,n,m,q,mn;
int sx[N],sy[N];
int x[N],y[N];
int kx,ky,p,v;
int ans[65];
int mxx,mxy,mnx,mny;
int nid;
int d[N];
bool flag;
int solve(){
	flag=0;
	if(x[1]<y[1]){
		mn=max(n,m);
		for(int i=1;i<=mn;i++) swap(x[i],y[i]);
		swap(n,m); flag=1;
	}//x > y
	if(x[1]==y[1]||x[n]==y[m]) return 0;
	if(x[1]<y[1]&&x[n]>y[m]) return 0;
	if(x[1]>y[1]&&x[n]<y[m]) return 0;
	mxx=x[1]; mxy=y[1]; mnx=x[1]; mny=y[1];
	for(int i=1;i<=n;i++) mxx=max(mxx,x[i]),mnx=min(mnx,x[i]);
	for(int i=1;i<=m;i++) mxy=max(mxy,y[i]),mny=min(mny,y[i]);
	if(mnx<=mny||mxx<=mxy) return 0;
	if(flag) swap(n,m);
	return 1;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%d",&sx[i]);
	for(int i=1;i<=m;i++) scanf("%d",&sy[i]);
	for(int i=1;i<=n;i++) x[i]=sx[i];
	for(int i=1;i<=m;i++) y[i]=sy[i];
	flag=0;
	ans[0]=solve();
	for(int t=1;t<=q;t++){
		for(int i=1;i<=n;i++) x[i]=sx[i];
		for(int i=1;i<=m;i++) y[i]=sy[i];
		scanf("%d%d",&kx,&ky);
		for(int i=1;i<=kx;i++){
			scanf("%d%d",&p,&v);
			x[p]=v;
		}
		for(int i=1;i<=ky;i++){
			scanf("%d%d",&p,&v);
			y[p]=v;
		}
		ans[t]=solve();
	}
	for(int i=0;i<=q;i++)
		printf("%d",ans[i]);
	return 0;
}