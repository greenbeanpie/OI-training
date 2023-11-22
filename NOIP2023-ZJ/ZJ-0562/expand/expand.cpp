#include <bits/stdc++.h>

const int N=5e5+5;

int c,n,m,q,aa[N],bb[N],a[N],b[N],ans[66];

bool ck()
{
	if((a[1]-b[1])*(a[n]-b[m])<=0)return 0;
	return 1;
}

int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;++i)scanf("%d",aa+i);
	for(int i=1;i<=m;++i)scanf("%d",bb+i);
	for(int i=1;i<=n;++i)a[i]=aa[i];
	for(int i=1;i<=m;++i)b[i]=bb[i];
	ans[0]=ck();
	for(int iq=1;iq<=q;++iq)
	{
		for(int i=1;i<=n;++i)a[i]=aa[i];
		for(int i=1;i<=m;++i)b[i]=bb[i];
		int kx,ky;scanf("%d%d",&kx,&ky);
		int px,vx,py,vy;
		for(int i=1;i<=kx;++i)scanf("%d%d",&px,&vx),a[px]=vx;
		for(int i=1;i<=ky;++i)scanf("%d%d",&py,&vy),b[py]=vy;
		ans[iq]=ck();
	}
	for(int i=0;i<=q;++i)printf("%d",ans[i]);
	return 0;
}