#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,kx,ky,c,q;
int xx[4],yy[4];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	if(c==1)
	{
		scanf("%d%d",&x,&y);
		printf("%d",int(x!=y));
		for(int i=1,v,u;i<=q;i++)
		{
			scanf("%d%d",&kx,&ky);
			for(int j=1;j<=kx;j++) scanf("%d%d",&u,&v),x=v;
			for(int j=1;j<=ky;j++) scanf("%d%d",&u,&v),y=v;
			printf("%d",int(x!=y));
		}
	}
	else
	{
		scanf("%d%d%d%d",&xx[1],&xx[2],&yy[1],&yy[2]);
		printf("%d",int((xx[1]>yy[1]&&xx[2]>yy[2]) || (xx[1]<yy[1]&&xx[2]<yy[2])));
		for(int i=1,v,u;i<=q;i++)
		{
			scanf("%d%d",&kx,&ky);
			for(int j=1;j<=kx;j++) scanf("%d%d",&u,&v),xx[u]=v;
			for(int j=1;j<=ky;j++) scanf("%d%d",&u,&v),yy[u]=v;
			printf("%d",int((xx[1]>yy[1]&&xx[2]>yy[2]) || (xx[1]<yy[1]&&xx[2]<yy[2])));
		}
	}
	
}