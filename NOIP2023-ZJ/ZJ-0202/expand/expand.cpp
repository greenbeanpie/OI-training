#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ms(x,y) memset(x,y,sizeof(x))
const int M=514514;
bool f[2005][2005],g[2005][2005];
int C,n,m,q;
int a[M],b[M],aa[M],bb[M];
bool calc()
{
	ms(f,0),ms(g,0),f[0][0]=g[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(a[i]>b[j]) f[i][j]=f[i][j-1]|f[i-1][j-1]|f[i-1][j];
			if(a[i]<b[j]) g[i][j]=g[i][j-1]|g[i-1][j-1]|g[i-1][j];
		}
	return f[n][m]||g[n][m];
}
bool calc2()
{
	int tp=1;
	bool f1=true,f2=true;
	for(int i=1;i<=n;i++)
	{
		while(tp<=m&&a[i]<b[tp]) tp++;
		if(a[i]>b[tp-1]) {f1=false;break;} 
	}
	if(f1) return true;
	tp=1;
	for(int i=1;i<=m;i++)
	{
		while(tp<=n&&b[i]>a[tp]) tp++;
		if(b[i]<a[tp-1]) {f2=false;break;} 
	}
	if(f2) return true;
	return false;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&C,&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%d",&aa[i]),a[i]=aa[i];
	for(int i=1;i<=m;i++) scanf("%d",&bb[i]),b[i]=bb[i];
	if(n<=2000) cout<<calc();
	else cout<<calc2();
	for(int i=1;i<=q;i++)
	{
		for(int i=1;i<=n;i++) a[i]=aa[i];
		for(int i=1;i<=m;i++) b[i]=bb[i];
		int kx,ky;
		scanf("%d%d",&kx,&ky);
		int p,v;
		for(int i=1;i<=kx;i++) scanf("%d%d",&p,&v),a[p]=v;
		for(int i=1;i<=ky;i++) scanf("%d%d",&p,&v),b[p]=v;
		if(n<=2000) cout<<calc();
		else cout<<calc2();
	}
	return 0;
}
