#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2005;
int c,n,m,q,xy[N],yy[N],x[N],y[N],xl[N],ff;
void solve1(){
	int x1,y1,a,b;
	scanf("%d%d",&a,&b);
	if(a==b)printf("0");
	else printf("1");
	for(int i=1;i<=q;i++){
		x1=a;y1=b;
		int kx,ky,v,p;scanf("%d%d",&kx,&ky);
		for(int j=1;j<=kx;j++){
			scanf("%d%d",&p,&v);
			x1=v;
		}
		for(int j=1;j<=ky;j++){
			scanf("%d%d",&p,&v);
			y1=v;
		}
		if(x1==y1)printf("0");
		else printf("1");
	}
	return ;
}
void check(){
	int l=0,r=0;
	//big
	int fff=1;
	for(int i=1;i<=n;i++){
		r=xl[i];
		if(l!=r)l++;
		for(int j=l;j<=r;j++)if(x[i]<=y[j]){
			fff=0;break;
		}
		if(fff==0)break;
		l=r;
	}
	if(fff==1){
		ff=1;return;
	}
	fff=1;
	for(int i=1;i<=n;i++){
		r=xl[i];
		if(l!=r)l++;
		for(int j=l;j<=r;j++)if(x[i]>=y[j]){
			fff=0;break;
		}
		if(fff==0)break;
		l=r;
	}
	if(fff==1){
		ff=1;return;
	}
	return;
}
void dfs(int a,int b){
	if(ff==1)return;
	if(a==n&&b==m){
		check();
		return;
	}
	if(a==n)return;
	a++;
	for(int i=b;i<=m;i++){
		xl[a]=i;
		dfs(a,i);
		xl[a]=0;
	}
	return;
}
void solve2(){
	for(int i=1;i<=n;i++){
		scanf("%d",&xy[i]);
		x[i]=xy[i];
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&yy[i]);
		y[i]=yy[i];
	}
	ff=0;
	dfs(0,1);
	printf("%d",ff);
	for(int i=1;i<=q;i++){
		for(int j=1;j<=n;j++)x[j]=xy[j];
		for(int j=1;j<=m;j++)y[j]=yy[j];
		int kx,ky,v,p;scanf("%d%d",&kx,&ky);
		for(int j=1;j<=kx;j++){
			scanf("%d%d",&p,&v);
			x[p]=v;
		}
		for(int j=1;j<=ky;j++){
			scanf("%d%d",&p,&v);
			y[p]=v;
		}
		ff=0;
		dfs(0,1);
		printf("%d",ff);
	}
	return;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	if(c==1)solve1();
	if(c>1&&c<=4)solve2();
	return 0;
}