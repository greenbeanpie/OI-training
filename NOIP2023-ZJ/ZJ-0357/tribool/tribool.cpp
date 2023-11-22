#include <bits/stdc++.h>
using namespace std;
#define re register
inline int read()
{
	int k=0,pos=1;char c=getchar();
	while (!isdigit(c)&&c!='-')c=getchar();
	if (c=='-')pos=-1,c=getchar();
	while (isdigit(c))k=(k<<3)+(k<<1)+c-'0',c=getchar();
	return k*pos;
}
char c[100100];int x[100100],y[100100],a[100100],b[100100];
inline void force()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	int n=read(),m=read(),tot=1,ans=INT_MAX;
	for (re int i=1;i<=n;i++)tot*=3;
	for (re int i=1;i<=m;i++)
	{
		scanf("%c",&c[i]);
		if (c[i]=='U'||c[i]=='T'||c[i]=='F')x[i]=read();
		else x[i]=read(),y[i]=read();
	}
	for (re int v=0;v<=tot-1;v++)
	{
		int len=0,val=v;
		while (len<n)
		{
			a[++len]=val%3;
			b[len]=a[len];
			val/=3;
		}
		for (re int i=1;i<=m;i++)
			if (c[i]=='U')b[x[i]]=2;
			else if (c[i]=='T')b[x[i]]=1;
			else if (c[i]=='F')b[x[i]]=0;
			else if (c[i]=='-')b[x[i]]=(b[y[i]]==2)?b[y[i]]:1-b[y[i]];
			else if (c[i]=='+')b[x[i]]=b[y[i]];
		bool flag=1;int sum=0;
		for (re int i=1;i<=n;i++)
		{
			if (a[i]==b[i]&&a[i]==2)sum++;
			if (a[i]!=b[i])
			{
				flag=0;
				break;
			}
		}
		if (flag)ans=min(ans,sum);
	}
	printf("%d\n",ans);
}
inline void force1()
{
	memset(a,0,sizeof(a));
	int n=read(),m=read(),sum=0;
	for (re int i=1;i<=m;i++)
	{
		char cc;
		scanf("%c",&cc);
		int x=read();
		if (cc=='T')a[x]=1;
		if (cc=='F')a[x]=0;
		if (cc=='U')a[x]=2;
	}
	for (re int i=1;i<=n;i++)
		sum+=(a[i]==2);
	printf("%d\n",sum);
}
inline void force2()
{
	memset(a,0,sizeof(a));
	int n=read(),m=read(),sum=0;
	for (re int i=1;i<=m;i++)
	{
		scanf("%c",&c[i]);
		x[i]=read();
		if (c[i]=='+'||c[i]=='-')y[i]=read();
	}
	while (1)
	{
		for (re int i=1;i<=n;i++)b[i]=a[i];
		for (re int i=1;i<=m;i++)
			if (c[i]=='U')b[x[i]]=2;
			else if (c[i]=='T')b[x[i]]=1;
			else if (c[i]=='F')b[x[i]]=0;
			else if (c[i]=='-')b[x[i]]=(b[y[i]]==2)?b[y[i]]:1-b[y[i]];
			else if (c[i]=='+')b[x[i]]=b[y[i]];
		bool flag=1;
		for (re int i=1;i<=n;i++)
			if (a[i]!=b[i])
			{
				flag=0;
				break;
			}
		if (flag)break;
		for (re int i=1;i<=n;i++)a[i]=b[i];
	}
	for (re int i=1;i<=n;i++)
		if (a[i]==2)
			sum++;
	printf("%d\n",sum);
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c=read(),t=read();
	while (t--)
	{
		if (c<=2){force();continue;}
		if (c<=4){force1();continue;}
		force2();
	}
	return 0;
}