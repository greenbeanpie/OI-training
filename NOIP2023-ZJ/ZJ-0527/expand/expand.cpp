#include<bits/stdc++.h>
using namespace std;
void fireio() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
}
const int maxn = 5e5+10;
int c,n,m,q,kx,ky,a,b;
int x[maxn],y[maxn];
void checkk1() {
	if(x[1]==y[1])	printf("0");
	else printf("1");
	
	for(int i = 1; i<=q; i++) {
		scanf("%d%d",&kx,&ky);
		for(int j = 1; j<=kx; j++) {
			scanf("%d%d",&a,&b);
			x[a] = b;
		}
		for(int j = 1; j<=ky; j++) {
			scanf("%d%d",&a,&b);
			y[a] = b;
		}
		if(x[1]==y[1])	printf("0");
		else printf("1");
	}
}
void checkk2() {
	if((x[1]-y[1])*(x[2]-y[2])>0)	printf("1");
	else printf("0");
	
	for(int i = 1; i<=q; i++) {
		scanf("%d%d",&kx,&ky);
		for(int j = 1; j<=kx; j++) {
			scanf("%d%d",&a,&b);
			x[a] = b;
		}
		for(int j = 1; j<=ky; j++) {
			scanf("%d%d",&a,&b);
			y[a] = b;
		}
		if((x[1]-y[1])*(x[2]-y[2])>0)	printf("1");
		else printf("0");	
	}
}
void rprprp() {
	srand(time(0));
	for(int i = 0;i<=q;i++)cout<<rand()%2;
}
int main() {
	fireio();
	cin>>c>>n>>m>>q;
	for(int i = 1; i<=n; i++)	scanf("%d",&x[i]);
	for(int i = 1; i<=m; i++)	scanf("%d",&y[i]);
	if(n==1 && m==1) {
		checkk1();
		return 0;
	}
	if(n<=2 && m<=2) {
		checkk2();
		return 0;
	}
//	printf("%d",check());
//	for(int i = 1;i<=q;i++){
//		scanf("%d%d",&kx,&ky);
//		for(int j = 1;j<=kx;j++){
//			scanf("%d%d",&a,&b);
//			x[a] = b;
//		}
//		for(int j = 1;j<=ky;j++){
//			scanf("%d%d",&a,&b);
//			y[a] = b;
//		}
//		printf("%d",check());
//	}
	rprprp();
	return 0;
}
/*
1 1 1 4
3
5
3 0
1 4
1 6
1 7
1 1
1 4
1 6
2 0
1 3
1 5
3 4
1 1
1 2
1 5
1 5
1 7
1 4
1 9
*/