#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int a[500005],b[500005];
int tmpa[500005],tmpb[500005];
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,n,m,q;
	scanf("%lld%lld%lld%lld",&c,&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
	if((tmpa[1]-tmpb[1])*(tmpa[n]-tmpb[m])<=0) putchar('0'); 
	else putchar('1');
	while(q--){
		int kx,ky;
		scanf("%lld%lld",&kx,&ky);
		for(int j=1;j<=n;j++) tmpa[j]=a[j],tmpb[j]=b[j];
		for(int j=1;j<=kx;j++){
			int p,c;
			scanf("%lld%lld",&p,&c);
			tmpa[p]=c;
		}
		for(int j=1;j<=ky;j++){
			int p,c;
			scanf("%lld%lld",&p,&c);
			tmpb[p]=c;
		}
		if((tmpa[1]-tmpb[1])*(tmpa[n]-tmpb[m])<=0){
			putchar('0');
			continue;
		} 
		putchar('1');
	}
}