#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
int a1[100005];
int b1[100005];
int a[100005];
int b[100005];
vector<int> mp;
int read()
{
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))
	{
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
int main ()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();n=read();m=read();q=read();
	for(int i=1;i<=n;i++)
	{
		a1[i]=read();
	}
	for(int i=1;i<=m;i++)
	{
		b1[i]=read();
	}
	for(int t=0;t<=q;t++)
	{
		for(int i=1;i<=n;i++)
		{
			a[i]=a1[i];
		}
		for(int i=1;i<=m;i++)
		{
			b[i]=b1[i];
		}
		if(t!=0)
		{
			int l1=read(),l2=read();
			for(int i=1;i<=l1;i++)
			{
				int x=read(),y=read();
				a[x]=y;
			}
			for(int i=1;i<=l2;i++)
			{
				int x=read(),y=read();
				b[x]=y;
			}
		}
		if((a[1]-b[1])*(a[n]-b[m])<=0)
		{
			printf("0");
			continue;
		}
	}
}