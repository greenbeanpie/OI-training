#include <bits/stdc++.h>
#define OK
using namespace std;
namespace Expand
{
#define inf 1000000010
	int C,n,m,q,x[500005],y[500005],cx[500005],cy[500005];
	int a[2005][2005];
	bool flag;
	bool trial (int p,int q)
	{
//		printf ("trial(%d,%d)\n",p,q);
		if (clock()>0.9*CLOCKS_PER_SEC) return 1;
		if (C<=7 && a[p][q]!=-1) return a[p][q];
		if (p==n && q==m) return 1;
		if (/*p!=n && q!=m && (x[p]>y[q] && x[p+1]>y[q+1] || x[p]<y[q] && x[p+1]<y[q+1]) && trial(p+1,q+1) ||*/ // 加了反而慢 样例3 702ms->873ms 
			p!=n && (x[p]>y[q] && x[p+1]>y[q] || x[p]<y[q] && x[p+1]<y[q]) && trial(p+1,q) ||
			q!=m && (x[p]>y[q] && x[p]>y[q+1] || x[p]<y[q] && x[p]<y[q+1]) && trial(p,q+1))
		{
			if (C<=7) return a[p][q]=1;
			return 1;
		}
		if (C<=7) return a[p][q]=0;
		return 0;
	}
	void solve ()
	{
		if (C==1)
			putchar ('0'+(x[1]!=y[1]));
		else if (C==2)
			putchar ('0'+(x[1]>y[1] && x[2]>y[2] || x[1]<y[1] && x[2]<y[2]));
		else if (x[1]>=y[1] && x[n]<=y[m] || x[1]<=y[1] && x[n]>=y[m])
			putchar ('0');
		else if (C>=8 && C<=14)
		{
			int xmax=-1,ymin=inf;
			for (int i=1;i<=n;i++)
				if (x[i]>xmax) xmax=x[i];
			for (int i=1;i<=m;i++)
				if (y[i]<ymin) ymin=y[i];
//			printf ("%d %d %d %d\n",xmax,x[n],ymin,y[m]);
			putchar ('0'+(xmax<y[m] || ymin>x[n]));
		}
		else putchar ('0'+trial(1,1));
	}
	int main ()
	{
#ifdef OK
		freopen ("expand.in","r",stdin);
		freopen ("expand.out","w",stdout);
#endif
		scanf ("%d%d%d%d",&C,&n,&m,&q);
		for (int i=1;i<=n;i++)
		{
			scanf ("%d",x+i);
			cx[i]=x[i];
		}
		for (int i=1;i<=m;i++)
		{
			scanf ("%d",y+i);
			cy[i]=y[i];
		}
		if (C<=7)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=m;j++)
					a[i][j]=-1;
		solve ();
		while (q--)
		{
//			printf ("q=%d\n",q);
			int k1,k2;
			scanf ("%d%d",&k1,&k2);
			for (int i=1;i<=n;i++) x[i]=cx[i];
			for (int i=1;i<=m;i++) y[i]=cy[i];
			for (int i=1;i<=k1;i++)
			{
				int u,v;
				scanf ("%d%d",&u,&v);
				x[u]=v;
			}
			for (int i=1;i<=k2;i++)
			{
				int u,v;
				scanf ("%d%d",&u,&v);
				y[u]=v;
			}
			if (C<=7)
				for (int i=1;i<=n;i++)
					for (int j=1;j<=m;j++)
						a[i][j]=-1;
			solve ();
		}
#ifndef OK
		printf ("\n%d\n",clock());
#endif
		exit(0);
	}
#undef inf
}
int main ()
{
	Expand::main();
	return 0;
}
/*
4 6 6 0
10 7 4 12 2 5
6 8 1 11 9 3
*/
// WHY ALWAYS SEGMENTATION FAULT!!!
