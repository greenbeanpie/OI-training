#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int c,n,m,q;
int kx,ky,id,w;
int X[maxn],Y[maxn];
int x[maxn],y[maxn];
int main(){
	srand(233);
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&y[i]);
	}
	if(x[1]<y[1] && x[n]>y[m] || x[1]>y[1] && x[n]<y[m]){
		printf("0");
	}
	else{
		printf("%d",rand()%2);
	}
	while(q--){
		for(int i=1;i<=n;i++){
			x[i]=X[i];
			y[i]=Y[i];
		}
		scanf("%d%d",&kx,&ky);
		for(int i=1;i<=kx;i++){
			scanf("%d%d",&id,&w);
			x[id]=w;
		}
		for(int i=1;i<=ky;i++){
			scanf("%d%d",&id,&w);
			y[id]=w;
		}
		if(x[1]<y[1] && x[n]>y[m]){
			printf("0");
			continue;
		}
		if(x[1]>y[1] && x[n]<y[m]){
			printf("0");
			continue;
		}
		if(x[1]==y[1] || x[n]==y[m]){
			printf("0");
			continue;
		}
		if(n==1 && m==1){
			printf("%d",x[1]!=y[1]);
			continue;
		}
		printf("%d",rand()%2);
	}
	return 0;
}
