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
struct node
{
	int c[33],start,last;
}f[3003];
int ans[3003];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n=read(),m=read();
	for (re int i=1;i<=n;i++)
	{
		char s[3003];
		scanf("%s",s+1);
		for (re int j=1;j<=m;j++)f[i].c[s[j]-97]++;
		for (re int j=25;j>=0;j--)
			if (f[i].c[j])
			{
				f[i].last=j;
				break;
			}
		for (re int j=0;j<26;j++)
			if (f[i].c[j])
			{
				f[i].start=j;
				break;
			}
	}
	for (re int i=1;i<=n;i++)
	{
		bool flag=1;
		for (re int j=1;j<=n;j++)
		{
			if (i==j)continue;
			if (f[i].start<f[j].last||(f[i].start==f[j].last&&f[i].c[f[i].start]>f[j].c[f[j].last]))continue;
			flag=0;
			break;
		}
		ans[i]=flag;
	}
	for (re int i=1;i<=n;i++)
		printf("%d",ans[i]);
	return 0;
}