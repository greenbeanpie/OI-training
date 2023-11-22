#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,x[101],y[101],k1[61],k2[61],px[61][101],vx[61][101],py[61][101],vy[61][101];
int aa,bb,cc,dd;
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	if(c <= 2)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x[i]);
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&y[i]);
		}
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&k1[i],&k2[i]);
			for(int j=1;j<=k1[i];j++)
			{
				scanf("%d%d",&px[i][j],&vx[i][j]);
			}
			for(int j=1;j<=k2[i];j++)
			{
				scanf("%d%d",&py[i][j],&vy[i][j]);
			}
		}
		if(((x[1] - y[1] > 0) && (x[n] - y[m] > 0)) || ((x[1] - y[1] < 0) && (x[n] - y[m] < 0)))
		  printf("1");
		else
		  printf("0");
		for(int i=1;i<=q;i++)
		{
			aa = x[1];
			bb = x[2];
			cc = y[1];
			dd = y[2];
			for(int j=1;j<=k1[i];j++)
			{
				x[px[i][j]] = vx[i][j];
			}
			for(int j=1;j<=k2[i];j++)
			{
				y[py[i][j]] = vy[i][j];
			}
		    if(((x[1] - y[1] > 0) && (x[n] - y[m] > 0)) || ((x[1] - y[1] < 0) && (x[n] - y[m] < 0)))
		      printf("1");
		    else
		      printf("0");
		    x[1] = aa;
		    x[2] = bb;
		    y[1] = cc;
		    y[2] = dd;
		}
	}
	else
	{
		for(int i=0;i<=q;i++)
		  printf("0");
	}
	fclose(stdin);
	fclose(stdin);
	return 0;
}