#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define For(i,j,k) for(int i=j;i<=k;i++)
#define DFor(i,j,k) for(int i=j;i>=k;i--)
#define ll long long
int c,n,m,q,kx,ky;
int x[N],y[N],nx[N],ny[N];
void solve1(){
	printf("%d",x[1]!=y[1]);
	while(q--){
		scanf("%d%d",&kx,&ky);
		For(i,1,n) nx[i]=x[i];
		For(j,1,m) ny[j]=y[j];
		For(j,1,kx){
			int p,v;
			scanf("%d%d",&p,&v);
			nx[p]=v;
		}
		For(j,1,ky){
			int p,v;
			scanf("%d%d",&p,&v);
			ny[p]=v;
		}
		printf("%d",nx[1]!=ny[1]);
	}
}
void work1(){
	if((x[1]>y[1]&&x[2]>y[2])||(x[1]<y[1]&&x[2]<y[2])){
		printf("1");
	}else printf("0");
	while(q--){
		For(i,1,n) nx[i]=x[i];
		For(j,1,m) ny[j]=y[j];
		scanf("%d%d",&kx,&ky);
		For(j,1,kx){
			int p,v;
			scanf("%d%d",&p,&v);
			nx[p]=v;
		}
		For(j,1,ky){
			int p,v;
			scanf("%d%d",&p,&v);
			ny[p]=v;
		}
		if((nx[1]>ny[1]&&nx[2]>ny[2])||(nx[1]<ny[1]&&nx[2]<ny[2])){
			printf("1");
		}else printf("0");
	}
}
void work2(){
	if((x[1]>y[1]&&x[1]>y[2])||(x[1]<y[1]&&x[1]<y[2])){
		printf("1");
	}else printf("0");
	while(q--){
		For(i,1,n) nx[i]=x[i];
		For(j,1,m) ny[j]=y[j];
		scanf("%d%d",&kx,&ky);
		For(j,1,kx){
			int p,v;
			scanf("%d%d",&p,&v);
			nx[p]=v;
		}
		For(j,1,ky){
			int p,v;
			scanf("%d%d",&p,&v);
			ny[p]=v;
		}
		if((nx[1]>ny[1]&&nx[1]>ny[2])||(nx[1]<ny[1]&&nx[1]<ny[2])){
			printf("1");
		}else printf("0");
	}
}
void work3(){
	if((x[1]>y[1]&&x[2]>y[1])||(x[1]<y[1]&&x[2]<y[1])){
		printf("1");
	}else printf("0");
	while(q--){
		For(i,1,n) nx[i]=x[i];
		For(j,1,m) ny[j]=y[j];
		scanf("%d%d",&kx,&ky);
		For(j,1,kx){
			int p,v;
			scanf("%d%d",&p,&v);
			nx[p]=v;
		}
		For(j,1,ky){
			int p,v;
			scanf("%d%d",&p,&v);
			ny[p]=v;
		}
		if((nx[1]>ny[1]&&nx[2]>ny[1])||(nx[1]<ny[1]&&nx[2]<ny[1])){
			printf("1");
		}else printf("0");
	}
}
void solve2(){
	if(n==m&&n==1){
		solve1();
		return;
	}
	if(n==m&&n==2){
		work1();
		return;
	}
	if(n==1&&m==2){
		work2();
		return;
	}
	if(n==2&&m==1){
		work3();
		return;
	}
}
void solve3(){
	if((x[1]>y[1]&&x[n]>y[m])||(x[1]<y[1]&&x[n]<y[m])){
		printf("1");
	}else printf("0");
	while(q--){
		For(i,1,n) nx[i]=x[i];
		For(j,1,m) ny[j]=y[j];
		scanf("%d%d",&kx,&ky);
		For(j,1,kx){
			int p,v;
			scanf("%d%d",&p,&v);
			nx[p]=v;
		}
		For(j,1,ky){
			int p,v;
			scanf("%d%d",&p,&v);
			ny[p]=v;
		}
		if((nx[1]>ny[1]&&nx[n]>ny[m])||(nx[1]<ny[1]&&nx[n]<ny[m])){
			printf("1");
		}else printf("0");
	}
}
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	For(i,1,n) scanf("%d",&x[i]);
	For(i,1,m) scanf("%d",&y[i]);
	if(c==1){
		solve1();
		return 0;
	}
	if(c==2){
		solve2();
		return 0;
	}
	solve3();
	return 0;
}
