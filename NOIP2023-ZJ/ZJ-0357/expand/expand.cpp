#include <bits/stdc++.h>
using namespace std;
#define re register
inline int read()
{
	int k=0,pos=1;char c=getchar();
	while (!isdigit(c)&&c!='-')c=getchar();
	if (c=='-')pos=-1,c=getchar();
	while (isdigit(c))k=(k<<3)+(k<<1)+c-'0',c=getchar();
	return k*pos;
}
int x[500100],y[500100],n,m;
inline void check()
{
	if (n==1&&m==1){printf("%d",x[1]!=y[1]);return;}
	if (n==1&&m==2)
	{
		if (x[1]==y[1]||x[1]==y[2])printf("0");
		else if (x[1]>y[1]&&x[1]>y[2]||x[1]<y[1]&&x[1]<y[2])printf("1");
		else printf("0");
		return;
	}
	if (n==2&&m==1)
	{
		if (x[1]==y[1]||x[2]==y[1])printf("0");
		else if (x[1]>y[1]&&x[2]>y[1]||x[1]<y[1]&&x[2]<y[1])printf("1");
		else printf("0");
		return;
	}
	if (n==2&&m==2)
	{
		if (x[1]==y[1]||x[2]==y[2])printf("0");
		else if (x[1]>y[1]&&x[2]>y[2]||x[1]<y[1]&&x[2]<y[2])printf("1");
		else if (x[1]>y[1]&&x[1]>y[2]&&x[2]>y[2]||x[1]<y[1]&&x[1]<y[2]&&x[2]<y[2])printf("1");
		else if (y[1]>x[1]&&y[1]>x[2]&&y[2]>x[2]||y[1]<x[1]&&y[1]<x[2]&&y[2]<x[2])printf("1");
		else printf("0");
		return;
	}
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c=read();
	n=read(),m=read();
	int q=read();
	for (re int i=1;i<=n;i++)x[i]=read();
	for (re int i=1;i<=m;i++)y[i]=read();
	check();
	while (q--)
	{
		int kx=read(),ky=read();
		for (re int i=1;i<=kx;i++)
		{
			int p=read(),v=read();
			x[p]=v;
		}
		for (re int i=1;i<=ky;i++)
		{
			int p=read(),v=read();
			y[p]=v;
		}
		check();
	}
	return 0;
}