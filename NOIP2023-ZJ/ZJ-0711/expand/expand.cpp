#include<bits/stdc++.h>
using namespace std;
int n,m,c,q;
int a[2010],b[2010];
void check(){
	if(a[1]==b[1]||a[n]==b[m]){
		printf("0");
		return;
	}
	if(n==1&&m==1){
		if(a[1]==b[1]) printf("0");
		else{
			printf("1");
		}
		return;
	}
	printf("1");
	return;
}
int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&q);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	for(int i=1; i<=m; i++) {
		scanf("%d",&b[i]);
	}
	check();
	while(q--) {
		int kx,ky,p;
		scanf("%d%d",&kx,&ky);
		for(int i=1; i<=kx; i++) {
			scanf("%d",&p);
			scanf("%d",&a[p]);
		}
		for(int i=1; i<=ky; i++) {
			scanf("%d",&p);
			scanf("%d",&b[p]);
		}
		check();
	}
	return 0;
}

