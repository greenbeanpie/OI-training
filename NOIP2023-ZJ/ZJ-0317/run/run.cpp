#include<bits/stdc++.h>
#define N 1010
#define int long long
using namespace std;
int n,m,t,c,k,d,f[N][N][2],x[N],y[N],v[N];
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
inline int count(int day,int tot)
{
	int sum=0ll;
	for (int i=1;i<=m;i++)
	  if (day==x[i]&&tot>=y[i])
	  {
	  	sum+=v[i];
	  }
	return sum;
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read(); t=read();
	while (t--)
	{
		n=read(); m=read(); k=read(); d=read();
		for (int i=1;i<=m;i++)
		{
			x[i]=0ll; y[i]=0ll; v[i]=0ll;
		}
		for (int i=1;i<=m;i++) 
		{
			x[i]=read(); y[i]=read(); v[i]=read();
		}
		for (int i=1;i<=n;i++)
		  for (int j=0;j<=n;j++) 
		  {
		  	f[i][j][0]=0ll; f[i][j][1]=0ll;
		  }
		f[1][0][0]=0ll; f[1][1][1]=0ll-d+count(1,1);
		for (int i=2;i<=n;i++)
		{
			f[i][0][0]=f[i-1][0][0];
			for (int j=1;j<=min(k,i-1);j++) 
			  f[i][0][0]=max(f[i][0][0],f[i-1][j][1]);
		    for (int j=1;j<=min(k,i);j++)
		  	{
		  		//if (j<i) f[i][0][0]=max(f[i][0][0],f[i-1][j][1]);
		  		if (j==1) f[i][j][1]=f[i-1][0][0]-d+count(i,1);
				  else f[i][j][1]=max(f[i][j][1],f[i-1][j-1][1]-d+count(i,j));
		  	}
		}
		int ans=f[n][0][0];
		for (int i=1;i<=k;i++)
		{
			ans=max(ans,f[n][i][1]);
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
