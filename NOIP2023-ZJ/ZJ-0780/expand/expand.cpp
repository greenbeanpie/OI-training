#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,m,c,q;
int a[N],b[N],bfa[N],bfb[N];
bool chk(){
	bool mn=1,mx=1;
	for(int i=1;i<=n;++i){
		if(a[i]>b[i]) mn=0;
		if(a[i]<b[i]) mx=0;
	}
	if(mn||mx) return 1;
	return 0;
}
signed main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	
	for(int i=1; i<=n; ++i) scanf("%d",a+i),bfa[i]=a[i];
	for(int i=1; i<=m; ++i) scanf("%d",b+i),bfb[i]=b[i];
	if(chk()) printf("1");
	else printf("0");
	while(q--) {
		int ka,kb;
		scanf("%d%d",&ka,&kb);
		for(int i=1; i<=n; ++i) a[i]=bfa[i];
		for(int i=1; i<=m; ++i) b[i]=bfb[i];
		for(int i=1; i<=ka; ++i) {
			int xx,yy;
			scanf("%d%d",&xx,&yy);
			a[xx]=yy;
		}
		for(int i=1; i<=kb; ++i) {
			int xx,yy;
			scanf("%d%d",&xx,&yy);
			b[xx]=yy;
		}
	    if(chk()) printf("1");
	    else printf("0");
	}
	return 0;
}
