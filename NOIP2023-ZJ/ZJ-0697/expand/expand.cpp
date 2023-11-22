#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,minx,miny,maxx,maxy,kx,ky,px,py,vx,vy,x[500],xx[500],y[500],yy[500];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);minx=1e9+1;miny=1e9+1;
	for(int i=1;i<=n;i++) {scanf("%d",&x[i]);xx[i]=x[i];maxx=max(maxx,x[i]);minx=min(x[i],minx);}
	for(int i=1;i<=m;i++) {scanf("%d",&y[i]);yy[i]=y[i];maxy=max(maxy,y[i]);miny=min(y[i],miny);}
	if((x[1]-y[1])*(x[n]-y[m])<=0||(maxx-maxy)*(minx-miny)<=0) printf("0");
	else printf("1");
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&kx,&ky);
		for(int j=1;j<=n;j++) x[j]=xx[j];
		for(int j=1;j<=m;j++) y[j]=yy[j];
		for(int j=1;j<=kx;j++) 
		{
			scanf("%d%d",&px,&vx);
			x[px]=vx;
		}
		for(int j=1;j<=ky;j++)
		{
			scanf("%d%d",&py,&vy);
			y[py]=vy;
		}
		minx=1e9+1;miny=1e9+1;
		for(int j=1;j<=n;j++) {maxx=max(maxx,x[i]);minx=min(minx,x[i]);}
		for(int j=1;j<=m;j++) {maxy=max(maxy,y[i]);maxy=min(maxy,y[i]);}
		if((x[1]-y[1])*(x[n]-y[m])<=0||(maxx-maxy)*(minx-miny)<=0) printf("0");
		else printf("1"); 
	}
	return 0;
}
