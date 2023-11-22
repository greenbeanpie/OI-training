#include<bits/stdc++.h>
#define N 500005
#define lson rt<<1
#define rson rt<<1|1
#define mid (l+r>>1)
int c,n,m,q,kx,ky;
int numx[N],numy[N];//original numbers
int fx[N],fy[N];//to modify
int px[N],py[N];
template <class type>
type max(type a,type b){return a>b?a:b;}
template <class type>
type min(type a,type b){return a<b?a:b;}
int read()
{
	char ch=getchar();
	int x=0;
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+(ch&15),ch=getchar();
	return x;
}
bool get_greater()
{
//	if(c==1)
//		return fx[1]!=fy[1];
	int ticx=1,ticy=1;
	return fx[1]>fy[1];
}
bool get_less()
{
//	if(c==1)
//		return fx[1]!=fy[1];
	int ticx=1,ticy=1;
	return fx[1]<fy[1];
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();
	n=read(),m=read();
	q=read();
	for(int i=1;i<=n;++i)
		numx[i]=fx[i]=read();
	for(int i=1;i<=m;++i)
		numy[i]=fy[i]=read();
	if(get_greater()||get_less())
		putchar('1');
	else
		putchar('0');
	for(int i=1;i<=q;++i)
	{
		kx=read(),ky=read();
		for(int i=1;i<=kx;++i)
		{
			px[i]=read();
			fx[px[i]]=read();
		}
		for(int i=1;i<=ky;++i)
		{
			py[i]=read();
			fy[py[i]]=read();
		}
		if(get_greater()||get_less())
			putchar('1');
		else
			putchar('0');
		for(int i=1;i<=kx;++i)
			fx[px[i]]=numx[px[i]];
		for(int i=1;i<=ky;++i)
			fy[px[i]]=numy[py[i]];
	}
	return 0;
}
