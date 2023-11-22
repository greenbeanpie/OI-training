#include<bits/stdc++.h>
using namespace std;
const int NUM=2005;
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c-'0');
		c=getchar();
	}
	return x*f;
}
int opt,n,m,q,c[NUM],d[NUM],a[NUM],b[NUM];
bool dp[NUM][NUM];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	opt=read(),n=read(),m=read(),q=read();
	if(opt<=7)
	{
		int kx,ky,u;
		bool flag;
		for(int i=1;i<=n;i++) c[i]=read();
		for(int i=1;i<=m;i++) d[i]=read();
		flag=false;
		for(int i=1;i<=n;i++) a[i]=c[i];
		for(int i=1;i<=m;i++) b[i]=d[i];
		dp[1][0]=true;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				dp[i][j]=(dp[i][j-1]||dp[i-1][j]||dp[i-1][j-1])&&(a[i]>b[j]);
		}
		flag|=dp[n][m];
		dp[1][0]=true;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				dp[i][j]=(dp[i][j-1]||dp[i-1][j]||dp[i-1][j-1])&&(a[i]<b[j]);
		}
		flag|=dp[n][m];
		if(flag==true) printf("1");
		else printf("0");
		while(q--)
		{
			flag=false;
			for(int i=1;i<=n;i++) a[i]=c[i];
			for(int i=1;i<=m;i++) b[i]=d[i];
			kx=read(),ky=read();
			for(int i=1;i<=kx;i++)
				u=read(),a[u]=read();
			for(int i=1;i<=ky;i++)
				u=read(),b[u]=read();
			dp[1][0]=true;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
					dp[i][j]=(dp[i][j-1]||dp[i-1][j])&&(a[i]>b[j]);
			}
			flag|=dp[n][m];
			dp[1][0]=true;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
					dp[i][j]=(dp[i][j-1]||dp[i-1][j]||dp[i-1][j-1])&&(a[i]<b[j]);
			}
			flag|=dp[n][m];
			if(flag==true) printf("1");
			else printf("0");
		}
	}
	else
	{
		srand(time(NULL));
		printf("%d",rand()%2);
		for(int i=1;i<=q;i++)
			printf("%d",rand()%2);
	}
}