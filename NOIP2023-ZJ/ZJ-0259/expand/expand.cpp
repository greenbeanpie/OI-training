#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int C;
int n,m;
int q;
int px,py,vx,vy,kx,ky;
int x[11450],xx[11450];
int y[11450],yy[11450];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&C,&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		xx[i]=x[i];
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&y[i]);
		yy[i]=y[i];
	}
	if(C==1)
	{
		if(x[1]!=y[1])cout<<1;
		else cout<<0;
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&kx,&ky);
			for(int i=1;i<=n;i++)
			{
				x[i]=xx[i];
			}
			for(int i=1;i<=m;i++)
			{
				y[i]=yy[i];
			}
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
			if(x[1]!=y[1])cout<<1;
			else cout<<0;
		}
	}
	else
	if(C==2)
	{
		if((x[1]<y[1]&&x[2]<y[2])||(x[1]>y[1]&&x[2]>y[2]))cout<<1;
		else cout<<0;
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&kx,&ky);
			for(int i=1;i<=n;i++)
			{
				x[i]=xx[i];
			}
			for(int i=1;i<=m;i++)
			{
				y[i]=yy[i];
			}
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
			if((x[1]<y[1]&&x[2]<y[2])||(x[1]>y[1]&&x[2]>y[2]))cout<<1;
			else cout<<0;
		}
	}
	else
	{
		for(int i=1;i<=q+1;i++)
		{
			cout<<1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}