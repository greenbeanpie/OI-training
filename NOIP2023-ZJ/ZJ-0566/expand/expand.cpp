#include <bits/stdc++.h>
using namespace std;
int c,n,m,t;
int x[10005],y[10005],xx[10005],yy[10005],maxx[10005],minx[10005],maxy[10005],miny[10005];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&t);
	memset(maxx,0,sizeof(maxx));
	memset(minx,127,sizeof(minx));
	memset(maxy,0,sizeof(maxy));
	memset(miny,127,sizeof(miny));
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
		maxx[i]=max(maxx[i-1],x[i]);
		minx[i]=min(minx[i-1],x[i]);
	}
	for(int i=1;i<=m;i++){	
	    scanf("%d",&y[i]);
		maxy[i]=max(maxy[i-1],y[i]);
		miny[i]=min(miny[i-1],y[i]);
	}
	for(int i=min(n,m)+1;i<=max(n,m);i++){
		maxx[i]=max(maxx[i-1],x[i]);
		minx[i]=min(minx[i-1],x[i]);
		maxy[i]=max(maxy[i-1],y[i]);
		miny[i]=min(miny[i-1],y[i]);
	}
	if((x[1]-y[1])*(x[n]-y[m])<=0)printf("0");else{
		bool bo=1;
		for(int i=2;i<=max(n,m);i++){
			if(x[1]>y[1]){
				if(maxy[i]>maxx[i]||minx[i]<miny[i]){
					bo=0;
					break;
				}
			}
			if(x[1]<y[1]){
				if(maxy[i]<maxx[i]||minx[i]>miny[i]){
					bo=0;
					break;
				}
			}
		}
		if(bo)printf("1");else printf("0");
	}
	while(t--){
		int k1,k2;
		for(int i=1;i<=n;i++)xx[i]=x[i];
		for(int i=1;i<=m;i++)yy[i]=y[i];
		scanf("%d%d",&k1,&k2);
		for(int i=1;i<=k1;i++){
			int opt,v;
			scanf("%d%d",&opt,&v);
			xx[opt]=v;
		}
		for(int i=1;i<=k2;i++){
			int opt,v;
			scanf("%d%d",&opt,&v);
			yy[opt]=v;
		}
		memset(maxx,0,sizeof(maxx));
		memset(minx,127,sizeof(minx));
		memset(maxy,0,sizeof(maxy));
		memset(miny,127,sizeof(miny));
		for(int i=1;i<=max(n,m);i++){
			maxx[i]=max(maxx[i-1],xx[i]);
			minx[i]=min(minx[i-1],xx[i]);
			maxy[i]=max(maxy[i-1],yy[i]);
			miny[i]=min(miny[i-1],yy[i]);
		}
		if((xx[1]-yy[1])*(xx[n]-yy[m])<=0)printf("0");else{
		bool bo=1;
		for(int i=2;i<=max(n,m);i++){
			if(xx[1]>yy[1]){
				if(maxy[i]>maxx[i]||minx[i]<miny[i]){
					bo=0;
					break;
				}
			}
			if(xx[1]<yy[1]){
				if(maxy[i]<maxx[i]||minx[i]>miny[i]){
					bo=0;
					break;
				}
			}
		}
		if(bo)printf("1");else printf("0");
	}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}