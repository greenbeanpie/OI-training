#include <bits/stdc++.h>
using namespace std;
int c,q,n,m,a,b,u,v;
int x[100001],y[100001];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d %d %d %d",&c,&m,&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	for(int i=1;i<=m;i++) scanf("%d",&y[i]);
	while(q--){
		scanf("%d %d",&a,&b);
		for(int i=1;i<=a;i++){
			scanf("%d %d",&u,&v);
			x[u]=v;
		}
		for(int i=1;i<=a;i++){
			scanf("%d %d",&u,&v);
			y[u]=v;
		}
		printf("%d",(x[1]-y[1])*(x[n]-y[m])>0);
	}
}