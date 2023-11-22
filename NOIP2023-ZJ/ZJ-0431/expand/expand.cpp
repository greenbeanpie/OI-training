#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],b[N];
signed main(void)
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	srand(time(0));
	register int c,n,m,q;
	cin>>c>>n>>m>>q;
	register int maxb=0,mina=0x3f3f3f3f,maxa=0;
	for(register int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mina=min(mina,a[i]);
		maxa=max(maxa,a[i]);
	}
	for(register int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		maxb=max(maxb,b[i]);
	}
	if(b[1]>a[1])
	{
		if(maxb<=mina) printf("0");
		else printf("1");
	}
	else
	{
		printf("%d",rand()^1);
	}
	while(q--)
	{
		register int kx,ky;
		scanf("%d%d",&kx,&ky);
		for(register int i=1;i<=kx;i++)
		{
			register int pos,val;
			scanf("%d%d",&pos,&val);
			a[pos]=val;
		}
		for(register int i=1;i<=ky;i++)
		{
			register int pos,val;
			scanf("%d%d",&pos,&val);
			b[pos]=val;
		}
		if(b[m]<=maxa) printf("0");
		else printf("%d",rand()^1);
	}
	return 0;
}