#include <iostream>
//#include <bits/exc++.h>
using namespace std;
const int maxn=5e5+5;
int c,n,m,q;
int a[maxn],b[maxn],aa[maxn],bb[maxn];
void work(){
	if (a[1]==b[1]){
		putchar(48);
		return;
	}
	else if (c==1){
		putchar(49);
		return;
	}
	else if (c==2){
		if (a[1]>b[1]){
			if (a[2]<=b[2]){putchar(48);return;}
			else{putchar(49);return;}
		}
	}
	return;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]),aa[i]=a[i];
	for (int i=1;i<=m;++i) scanf("%d",&b[i]),bb[i]=b[i];
	work();
	while (q--){
		int kx,ky;scanf("%d%d",&kx,&ky);
		for (int i=1;i<=kx;++i){
			int x,y;scanf("%d%d",&x,&y);
			a[x]=y;
		}
		for (int i=1;i<=ky;++i){
			int x,y;scanf("%d%d",&x,&y);
			b[x]=y;
		}
		work();
		for (int i=1;i<=n;++i) a[i]=aa[i];
		for (int i=1;i<=m;++i) b[i]=bb[i];
	}
	return 0;
}
