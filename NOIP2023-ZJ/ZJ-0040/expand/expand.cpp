#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,l,r) for(int i=(l),i##_end=(r);i<i##_end;++i)
using namespace std;
constexpr int N=5e5+5;
bool solve(int *a,int *b,int n,int m)
{
	if(a[0]>=b[0])return false;
	if(a[n-1]>=b[m-1])return false;
	int amp=0,bmp=0;
	F(i,0,n)if(a[i]<a[amp])amp=i;
	F(i,0,m)if(b[i]<b[bmp])bmp=i;
	int i=0,j=0,am=a[0],bm=b[0];
	while(true)
	{
		if(i+1<n&&a[i+1]<bm)am=min(am,a[++i]);
		else if(j+1<m&&am<b[j+1])bm=max(bm,b[++j]);
		else break;
	}
	if(i<amp||j<bmp)return false;
	i=n-1,j=m-1,am=a[n-1],bm=b[m-1];
	while(true)
	{
		if(i&&a[i-1]<bm)am=min(am,a[--i]);
		else if(j&&am<b[j-1])bm=max(bm,b[--j]);
		else break;
	}
	return i<=amp&&j<=bmp;
}
int n,m,q,x[N],y[N],a[N],b[N];
int main()
{
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
#endif
#endif
	scanf("%*d%d%d%d",&n,&m,&q);
	F(i,0,n)scanf("%d",&x[i]);
	F(i,0,m)scanf("%d",&y[i]);
	if(x[0]<y[0])printf("%d",(int)solve(x,y,n,m));
	else printf("%d",(int)solve(y,x,m,n));
	while(q--)
	{
		memcpy(a,x,sizeof(int)*n);
		memcpy(b,y,sizeof(int)*m);
		int kx,ky;scanf("%d%d",&kx,&ky);
		F(i,0,kx)
		{
			int p,v;scanf("%d%d",&p,&v);--p;
			a[p]=v;
		}
		F(i,0,ky)
		{
			int p,v;scanf("%d%d",&p,&v);--p;
			b[p]=v;
		}
		if(a[0]<b[0])printf("%d",(int)solve(a,b,n,m));
		else printf("%d",(int)solve(b,a,m,n));
	}
	puts("");
	return 0;
}
