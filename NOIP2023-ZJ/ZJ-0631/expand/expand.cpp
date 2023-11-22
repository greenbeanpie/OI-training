#include <bits/stdc++.h>
using namespace std;
#define LL long long
int c,n,m,q;
int a[500500],b[500500];
int ta[500500],tb[500500];
int l[500500],r[500500];
LL read()
{
	LL num=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		num=num*10+c-'0';
		c=getchar();
	}
	return num*f;
}
bool doit(int num)
{
	if(num==n)
		return r[n-1]+1>=l[n];
	for(int i=l[num-1];i<=min(r[num-1]+1,m);i++)
	{
		if(a[num]>b[i])
		{
			l[num]=r[num]=i;
			while(r[num]<m&&a[num]>b[r[num]+1])r[num]++;
			if(doit(num+1))
				return 1;
			i=r[num]+1;
		}
	}
	return 0;
}
bool isok()
{
	if(a[1]<=b[1]||a[n]<=b[m])
		return 0;
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	l[1]=r[1]=1;
	while(r[1]<m&&a[1]>b[r[1]+1])r[1]++;
	l[n]=r[n]=m;
	while(l[n]>1&&a[n]>b[l[n]-1])l[n]--;
	return doit(2);
}
bool doit2(int num)
{
	if(num==n)
		return r[n-1]+1>=l[n];
	for(int i=l[num-1];i<=min(r[num-1]+1,m);i++)
	{
		if(a[num]<b[i])
		{
			l[num]=r[num]=i;
			while(r[num]<m&&a[num]<b[r[num]+1])r[num]++;
			if(doit2(num+1))
				return 1;
			i=r[num]+1;
		}
	}
	return 0;
}
bool isok2()
{
	if(a[1]>=b[1]||a[n]>=b[m])
		return 0;
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	l[1]=r[1]=1;
	while(r[1]<m&&a[1]<b[r[1]+1])r[1]++;
	l[n]=r[n]=m;
	while(l[n]>1&&a[n]<b[l[n]-1])l[n]--;
	return doit2(2);
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++)	ta[i]=a[i]=read();
	for(int i=1;i<=m;i++)	tb[i]=b[i]=read();
	if(c==1)
		printf("%d",a[1]!=b[1]);
	else
		printf("%d",isok()|isok2()); 
	while(q--)
	{
		for(int i=1;i<=n;i++)	a[i]=ta[i];
		for(int i=1;i<=m;i++)	b[i]=tb[i];
		int kx,ky;
		kx=read(),ky=read();
		for(int i=1;i<=kx;i++)
		{
			int tx,ty;
			tx=read(),ty=read();
			a[tx]=ty;
		}
		for(int i=1;i<=ky;i++)
		{
			int tx,ty;
			tx=read(),ty=read();
			b[tx]=ty;
		}
		if(c==1)
			printf("%d",a[1]!=b[1]);
		else
			printf("%d",isok()|isok2());
	}
	return 0;
}
