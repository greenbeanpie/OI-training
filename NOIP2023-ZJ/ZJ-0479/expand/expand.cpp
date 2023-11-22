#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,q;
int x[N],y[N],kx,ky;
bool check(){
	return (x[1]>y[1]&&x[n]>y[m])||(x[1]<y[1]&&x[n]<y[m]);
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	for(int i=1;i<=m;i++) scanf("%d",&y[i]);
	printf("%d",check());
	while(q--){
		scanf("%d%d",&kx,&ky);
		int s1,s2;
		for(int i=1;i<=kx;i++){
			scanf("%d%d",&s1,&s2);
			x[s1]=s2;
		}
		for(int i=1;i<=ky;i++){
			scanf("%d%d",&s1,&s2);
			x[s1]=s2;
		}
		printf("%d",check());
	}
	printf("\n");
	return 0;
}
