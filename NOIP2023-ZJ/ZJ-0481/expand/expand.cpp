#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,ans=1;
int x[500010],y[500010];
int kx,ky,px,py,vx,vy;
int mx,my,nx=1e9,ny=1e9;
int xx[500010],yy[500010];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
		xx[i]=x[i];
		mx=max(mx,x[i]);
		nx=min(nx,x[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&y[i]);
		yy[i]=y[i];
		my=max(my,y[i]);
		ny=min(ny,y[i]);
	}
	if(c==1){
		printf("%d",ans);
		while(q--){
			for(int i=1;i<=n;i++){
				x[i]=xx[i];
			}
			for(int j=1;j<=m;j++){
				y[j]=yy[j];
			}
			ans=1;
			scanf("%d%d",&kx,&ky);
			for(int i=1;i<=kx;i++){
				scanf("%d%d",&px,&vx);
				x[px]=vx;
			}
			for(int i=1;i<=ky;i++){
				scanf("%d%d",&py,&vy);
				y[py]=vy;
			}
			printf("%d",ans);
		}
	}
	else if(c==2){
		if((x[1]-y[1])*(x[2]-y[2])>0){
			ans=1;
		}
		else{
			ans=0;
		}
		printf("%d",ans);
		while(q--){
			for(int i=1;i<=n;i++){
				x[i]=xx[i];
			}
			for(int j=1;j<=m;j++){
				y[j]=yy[j];
			}
			ans=1;
			scanf("%d%d",&kx,&ky);
			for(int i=1;i<=kx;i++){
				scanf("%d%d",&px,&vx);
				x[px]=vx;
			}
			for(int i=1;i<=ky;i++){
				scanf("%d%d",&py,&vy);
				y[py]=vy;
			}
			if((x[1]-y[1])*(x[2]-y[2])>0){
				ans=1;
			}
			else{
				ans=0;
			}
			printf("%d",ans);
		}
	}
	else{
		if(x[1]>y[1]&&x[n]>y[m]&&mx>my&&nx>ny){
			ans=1;
		}
		else if(x[1]<y[1]&&x[n]<y[m]&&mx<my&&nx<ny){
			ans=1;
		}
		else{
			ans=0;
		}
		printf("%d",ans);
		while(q--){
			mx=0,my=0,nx=1e9,ny=1e9;
			for(int i=1;i<=n;i++){
				x[i]=xx[i];
			}
			for(int j=1;j<=m;j++){
				y[j]=yy[j];
			}
			ans=1;
			scanf("%d%d",&kx,&ky);
			for(int i=1;i<=kx;i++){
				scanf("%d%d",&px,&vx);
				x[px]=vx;
			}
			for(int i=1;i<=ky;i++){
				scanf("%d%d",&py,&vy);
				y[py]=vy;
			}
			for(int i=1;i<=n;i++){
				mx=max(mx,x[i]);
				nx=min(nx,x[i]);
			}
			for(int i=1;i<=m;i++){
				my=max(my,y[i]);
				ny=min(ny,y[i]);
			}
			if(x[1]>y[1]&&x[n]>y[m]&&mx>my&&nx>ny){
				ans=1;
			}
			else if(x[1]<y[1]&&x[n]<y[m]&&mx<my&&nx<ny){
				ans=1;
			}
			else{
				ans=0;
			}
			printf("%d",ans);
		}
	}
	return 0;
}
