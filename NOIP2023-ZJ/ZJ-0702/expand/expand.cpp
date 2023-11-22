#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int c,n,m,q,kx,ky;
int a[N],b[N],a1[N],b1[N];
void st1(){
	printf("%d",(a[1]!=b[1]));
	for(int i=1;i<=q;i++){
		scanf("%d%d",&kx,&ky);
		for(int i=1;i<=n;i++) a1[i]=a[i],b1[i]=b[i];
		for(int i=1,p,v;i<=kx;i++){
			scanf("%d%d",&p,&v);
			a1[p]=v;
		}
		for(int i=1,p,v;i<=ky;i++){
			scanf("%d%d",&p,&v);
			b1[p]=v;
		}
		printf("%d",(a1[1]!=b1[1]));
	}
	printf("\n");
}
int chk2(int x[],int y[]){
	if(x[2]==0) x[2]=x[1];
	if(y[2]==0) y[2]=y[1];
	if((x[1]-y[1])*(x[2]-y[2])>0) return 1;
	if((x[1]-y[1])*(x[1]-y[2])>0&&(x[1]-y[2])*(x[2]-y[2])>0) return 1;
	if((x[1]-y[1])*(x[2]-y[1])>0&&(x[2]-y[1])*(x[2]-y[2])>0) return 1;
	return 0;
}
void st2(){
	printf("%d",chk2(a,b));
	for(int i=1;i<=q;i++){
		scanf("%d%d",&kx,&ky);
		for(int i=1;i<=n;i++) a1[i]=a[i],b1[i]=b[i];
		for(int i=1,p,v;i<=kx;i++){
			scanf("%d%d",&p,&v);
			a1[p]=v;
		}
		for(int i=1,p,v;i<=ky;i++){
			scanf("%d%d",&p,&v);
			b1[p]=v;
		}
		printf("%d",chk2(a1,b1));
	}
	printf("\n");
}
void st0(){
	for(int i=0;i<=q;i++)
		printf("1");
	printf("\n");
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++)
		scanf("%d",b+i);
	if(c==1) st1();
	else if(c==2) st2();
	else st0();
	return 0;
}

