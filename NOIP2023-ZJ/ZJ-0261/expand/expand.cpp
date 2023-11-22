#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,Max,Min,kx,ky,p,v;
int x[500039],y[500039],w[500039];
int xs[500039],ys[500039];
void init(){
	for(int i=1;i<=n;i++)xs[i]=x[i];
	for(int i=1;i<=m;i++)ys[i]=y[i];
}
void check(){
	if(c<=2){
		if(c==1)printf("%c","10"[xs[1]==ys[1]]);
		if(c==2){
			if(xs[1]>ys[1]){
				if(xs[2]>ys[2]){
					printf("1");
				}else if(xs[2]<ys[2]){
					printf("0");
				}else printf("0");
			}else if(xs[1]<ys[1]){
				if(xs[2]>ys[2]){
					printf("0");
				}else if(xs[2]<ys[2]){
					printf("1");
				}else printf("0");
			}else printf("0");
		}
	}else{
		int Max1=0,Max2=0,Min1=1000000001,Min2=1000000001;
		for(int i=1;i<=n;i++)Max1=max(Max1,xs[i]);
		for(int i=1;i<=n;i++)Max2=max(Max2,ys[i]);
		for(int i=1;i<=n;i++)Min1=min(Min1,xs[i]);
		for(int i=1;i<=n;i++)Min2=min(Min2,ys[i]);
		if((xs[1]>ys[1])&&(xs[n]>ys[m])){
			if(Max1>Max2&&Min1<Min2)printf("1");
			else printf("0");
		}
		else if((xs[1]<ys[1])&&(xs[n]<ys[m])){
			if(Max1<Max2&&Min1>Min2)printf("1");
			else printf("0");
		}else printf("0");
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++){scanf("%d",&x[i]);}
	for(int i=1;i<=m;i++){scanf("%d",&y[i]);}
	init();check();while(q--){init();
		scanf("%d%d",&kx,&ky);
		for(int i=1;i<=kx;i++){
			scanf("%d%d",&p,&v);
			xs[p]=v;
		}
		for(int i=1;i<=ky;i++){
			scanf("%d%d",&p,&v);
			ys[p]=v;
		}
		check();
	}
}