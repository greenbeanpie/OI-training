#include<bits/stdc++.h>
using namespace std;
int x,y,maxx,maxy,c,n,m,q,id,minx=1e9,miny=1e9;
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d %d %d %d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x>maxx) maxx=x;
		if(x<minx) minx=x;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&y);
		if(maxy<y) maxy=y;
		if(miny>y) miny=y;
	}
	if(maxx<maxy&&miny>minx) printf("1");
	else printf("0");
	for(int i=1;i<=q;i++)
	{
		int kx,ky,qmaxx=maxx,qmaxy=maxy,qminx=minx,qminy=miny;
		scanf("%d %d",&kx,&ky);
		for(int j=1;j<=kx;j++)
		{
			scanf("%d %d",&id,&x);
			if(x>qmaxx) qmaxx=x;
			if(x<qminx) qminx=x;
		}
		for(int j=1;j<=ky;j++)
		{
			scanf("%d %d",&id,&y);
			if(y>qmaxy) qmaxy=y;
			if(y<qminy) qminy=y;
		}
		if(qmaxx<qmaxy&&qminx<qminy) printf("1");
		else printf("0");
	}
	return 0;
}