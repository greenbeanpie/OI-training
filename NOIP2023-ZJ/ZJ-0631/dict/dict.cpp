#include <bits/stdc++.h>
using namespace std;
#define LL long long
int n,m;
int c[3010][128];
int maxx[3010],minn[3010];
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

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	memset(minn,0x7f,sizeof(minn));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char tt=getchar();
			c[i][tt]++;
			maxx[i]=max(maxx[i],int(tt));
			minn[i]=min(minn[i],int(tt));
		}
		getchar();
	}
	for(int i=1;i<=n;i++)//能不能满足i最小 
	{
		bool flag=1;
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			if(minn[i]>=maxx[j])
			{
				flag=0;
				break;
			}
		}
		printf("%d",int(flag));
	}
	return 0;
}
