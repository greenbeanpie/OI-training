#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,kx,ky,x,y;
int a[2100],b[2100];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int j=1;j<=m;j++)scanf("%d",&b[j]);
	if(n==m&&m==1)
	{
		if(a[1]!=b[1])putchar('1');
		else putchar('0');
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&kx,&ky);
			for(int j=1;j<=kx;j++)scanf("%d%d",&x,&y),a[x]=y;
			for(int j=1;j<=ky;j++)scanf("%d%d",&x,&y),b[x]=y;
			putchar((a[1]!=b[1])+'0');
		}
	}
	return 0;
}
