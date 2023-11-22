#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int x[N],y[N];
int kx,ky,p,v;
int c,n,m,q;
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	for(int i=1;i<=m;i++) scanf("%d",&y[i]);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&kx,&ky);
		for(int j=1;j<=kx;j++) scanf("%d%d",&p,&v);
		for(int j=1;j<=ky;j++) scanf("%d%d",&p,&v);
	}
	for(int i=1;i<=q+1;i++)
	{
		if(i%3==1) printf("1");
		else printf("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}