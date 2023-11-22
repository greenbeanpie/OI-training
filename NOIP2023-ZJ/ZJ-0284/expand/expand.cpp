#include<bits/stdc++.h>
using namespace std;
int type,n,m,q;
int a[500005],b[500005],c[5];

int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&type,&n,&m,&q);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int j=1;j<=m;j++)
		scanf("%d",&b[j]);
	if (a[1]==b[1]) putchar('0');
	else putchar('1');
	while (q--)
	{
		int kx,ky,x,v;
		scanf("%d%d",&kx,&ky);
		for (int i=1;i<=kx;i++)
		{
			scanf("%d%d",&x,&v);
			a[x]=v;
		}
		for (int i=1;i<=ky;i++)
		{
			scanf("%d%d",&x,&v);
			b[x]=v;
		}
		if (a[1]==b[1]) putchar('0');
		else putchar('1');
	}
	return 0;
}
