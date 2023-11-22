#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int s=0;
	bool f=false;
	char c=getchar();
	while(!isdigit(c))
	{
		f=(c=='-');
		c=getchar();
	}
	while(isdigit(c))
	{
		s=(s<<3)+(s<<1)+c-'0';
		c=getchar();
	}
	return f?-s:s;
}
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+'0');
}
int c,n,m,q,x[2005],y[2005],nx[2005],ny[2005];
bool dp[2005][2005];
signed main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();
	n=read();
	m=read();
	q=read();
	if(c<=7)
	{
		for(int i=1;i<=n;i++)
		{
			x[i]=read();
		}
		for(int i=1;i<=m;i++)
		{
			y[i]=read();
		}
		if(x[1]==y[1])
		{
			putchar('0');
			goto flg;
		}
		for(int i=1;i<=m&&((x[1]>y[i])==(x[1]>y[1]))&&x[1]!=y[i];i++)
		{
			dp[1][i]=true;
		}
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if((x[i]==y[j])||((x[i]<y[j])!=(x[1]<y[1])))
				{
					continue;
				}
				for(int k=j;k>=1&&!dp[i][j];k--)
				{
					if((x[i]==y[k])||((x[i]<y[k])!=(x[1]<y[1])))
						break;
					dp[i][j]=dp[i-1][k];
				}
			}
		}
		if(dp[n][m])
			putchar('1');
		else
			putchar('0');
		flg:;
		while(q--)
		{
			memset(dp,false,sizeof(dp));
			int kx=read(),ky=read();
			for(int i=1;i<=n;i++)
			{
				nx[i]=x[i];
			}
			for(int i=1;i<=m;i++)
			{
				ny[i]=y[i];
			}
			for(int i=1;i<=kx;i++)
			{
				int j=read();
				nx[j]=read();
			}
			for(int i=1;i<=ky;i++)
			{
				int j=read();
				ny[j]=read();
			}
			if(nx[1]==ny[1])
			{
				putchar('0');
				continue;
			}
			for(int i=1;i<=m&&((nx[1]>ny[i])==(nx[1]>ny[1]))&&nx[1]!=ny[i];i++)
			{
				dp[1][i]=true;
			}
			for(int i=2;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if((nx[i]==ny[j])||((nx[i]<ny[j])!=(nx[1]<ny[1])))
					{
						continue;
					}
					for(int k=j;k>=1&&!dp[i][j];k--)
					{
						if((nx[i]==ny[k])||((nx[i]<ny[k])!=(nx[1]<ny[1])))
							break;
						dp[i][j]=dp[i-1][k];
					}
				}
			}
			if(dp[n][m])
				putchar('1');
			else
				putchar('0');
		}
	}
	return 0;
}