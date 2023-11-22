#include<bits/stdc++.h>
#define N 500010
using namespace std;
int c,n,m,q,a[N],b[N],a1[N],b1[N],k1,k2,p,v;
inline int read()
{
	int aa=0,op=1;
	char ch=getchar();
	while (!isdigit(ch))
	{
		if (ch=='-') op=-1;
		ch=getchar();
	}
	while (isdigit(ch))
	{
		aa=aa*10+(int)(ch-'0');
		ch=getchar();
	}
	return aa*op;
}
inline void solve1()
{
	if (a[1]!=b[1]) printf("1");
	  else printf("0");
	while (q--)
	{
		k1=read(); k2=read();
		for (int i=1;i<=n;i++) a1[i]=a[i];
		for (int i=1;i<=m;i++) b1[i]=b[i];
		for (int i=1;i<=k1;i++)
		{
			p=read(); v=read();
			a1[p]=v;
		}
		for (int i=1;i<=k2;i++)
		{
			p=read(); v=read();
			b1[p]=v;
		}
		if (a1[1]!=b1[1]) printf("1");
	  	  else printf("0");
	}
	return;
}
inline void solve2()
{
	if (n==1&&m==2) 
	{
		if (a[1]<b[1]&&a[1]<b[2]||a[1]>b[1]&&a[1]>b[2]) printf("1");
		  else printf("0");
		while (q--)
		{
			k1=read(); k2=read();
			for (int i=1;i<=n;i++) a1[i]=a[i];
			for (int i=1;i<=m;i++) b1[i]=b[i];
			for (int i=1;i<=k1;i++)
			{
				p=read(); v=read(); a1[p]=v;
			}
			for (int i=1;i<=k2;i++)
			{
				p=read(); v=read(); b1[p]=v;
			}
			if (a1[1]<b1[1]&&a1[1]<b1[2]||a1[1]>b1[1]&&a1[1]>b1[2]) printf("1");
		  	  else printf("0");
		}
	}
	if (n==2&&m==1)
	{
		if (b[1]<a[1]&&b[1]<a[2]||b[1]>a[1]&&b[1]>a[2]) printf("1");
		  else printf("0");
		while (q--)
		{
			k1=read(); k2=read();
			for (int i=1;i<=n;i++) a1[i]=a[i];
			for (int i=1;i<=m;i++) b1[i]=b[i];
			for (int i=1;i<=k1;i++)
			{
				p=read(); v=read(); a1[p]=v;
			}
			for (int i=1;i<=k2;i++)
			{
				p=read(); v=read(); b1[p]=v;
			}
			if (b1[1]<a1[1]&&b1[1]<a1[2]||b1[1]>a1[1]&&b1[1]>a1[2]) printf("1");
		  	  else printf("0");
		}
	}
	if (n==2&&m==2)
	{
		if (a[2]>b[2]&&a[1]>b[1]) printf("1");
		if (a[2]<b[2]&&a[1]<b[1]) printf("1");
		if (a[1]>=b[1]&&a[2]<=b[2]) printf("0");
		if (a[1]<=b[1]&&a[2]>=b[2]) printf("0");
		while (q--)
		{
			k1=read(); k2=read();
			for (int i=1;i<=n;i++) a1[i]=a[i];
			for (int i=1;i<=m;i++) b1[i]=b[i];
			for (int i=1;i<=k1;i++)
			{
				p=read(); v=read(); a1[p]=v;
			}
			for (int i=1;i<=k2;i++)
			{
				p=read(); v=read(); b1[p]=v;
			}
			if (a1[2]>b1[2]&&a1[1]>b1[1]) printf("1");
			if (a1[2]<b1[2]&&a1[1]<b1[1]) printf("1");
			if (a1[1]>=b1[1]&&a1[2]<=b1[2]) printf("0");
			if (a1[1]<=b1[1]&&a1[2]>=b1[2]) printf("0");
		}
	}
	return;
}
signed main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(); n=read(); m=read(); q=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++) b[i]=read();
	if (c==1) solve1();
	  else if (c==2) solve2();
			else while (q--) printf("0");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
