#include<bits/stdc++.h>
using namespace std;
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
int n,m,X[500086],Y[500086],now_x[500086],now_y[500086],ans[500086];
void sub1(int now_q){
	if((now_x[1]>now_y[1]&&now_x[2]>now_y[2])||(now_x[1]<now_y[1]&&now_x[2]<now_y[2])){
		ans[now_q]=1;
	}
	else{
		ans[now_q]=0;
	}
}
void sub2(int now_q){
	int maxx=0,miny=INT_MAX;
	for(int i=2;i<=n;i++){
		maxx=max(now_x[i],maxx);
	}
	for(int i=1;i<m;i++){
		miny=min(now_y[i],miny);
	}
	if(maxx<now_y[m]&&miny>now_x[1]){
		ans[now_q]=1;
	}
	else{
		ans[now_q]=0;
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,q;
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&X[i]);
		now_x[i]=X[i];
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&Y[i]);
		now_y[i]=Y[i];
	}
	if(8<=c&&c<=14){
		sub2(1);
		for(int i=2;i<=q+1;i++){
			int kx,ky;
			for(int j=1;j<=n;j++){
				now_x[j]=X[j];
			}
			for(int j=1;j<=m;j++){
				now_y[j]=Y[j];
			}
			scanf("%d%d",&kx,&ky);
			for(int j=1;j<=kx;j++){
				int p,v;
				scanf("%d%d",&p,&v);
				now_x[p]=v;
			}
			for(int j=1;j<=ky;j++){
				int p,v;
				scanf("%d%d",&p,&v);
				now_y[p]=v;
			}
			sub2(i);
		}
	}
	else if(c==1){
		if(now_x[1]!=now_y[1]){
			ans[1]=1;
		}
		else{
			ans[1]=0;
		}
		for(int i=2;i<=q+1;i++){
			int kx,ky;
			for(int j=1;j<=n;j++){
				now_x[j]=X[j];
			}
			for(int j=1;j<=m;j++){
				now_y[j]=Y[j];
			}
			scanf("%d%d",&kx,&ky);
			for(int j=1;j<=kx;j++){
				int p,v;
				scanf("%d%d",&p,&v);
				now_x[p]=v;
			}
			for(int j=1;j<=ky;j++){
				int p,v;
				scanf("%d%d",&p,&v);
				now_y[p]=v;
			}
			if(now_x[1]!=now_y[1]){
				ans[i]=1;
			}
			else{
				ans[i]=0;
			}
		}
	}
	else if(c==2){
		sub1(1);
		for(int i=2;i<=q+1;i++){
			int kx,ky;
			for(int j=1;j<=n;j++){
				now_x[j]=X[j];
			}
			for(int j=1;j<=m;j++){
				now_y[j]=Y[j];
			}
			scanf("%d%d",&kx,&ky);
			for(int j=1;j<=kx;j++){
				int p,v;
				scanf("%d%d",&p,&v);
				now_x[p]=v;
			}
			for(int j=1;j<=ky;j++){
				int p,v;
				scanf("%d%d",&p,&v);
				now_y[p]=v;
			}
			sub1(i);
		}
	}
	for(int i=1;i<=q+1;i++){
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}