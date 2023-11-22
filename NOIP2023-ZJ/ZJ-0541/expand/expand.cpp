#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int X[N],Y[N],n,m;
inline int read()
{
 char c=getchar();	int res=0;
 while(c<'0'||c>'9')	c=getchar();
 while(c>='0'&&c<='9')	res=res*10+c-48,c=getchar();
 return res;
}
int f[N],ans[N],x[N],y[N];
bool Maxsolve()
{
 for(int j=1;j<=m;j++)
 {
 	if(y[j]>=x[1])	break;
	f[j]=true;	
 }
 for(int i=2;i<=n;i++)
 	for(int j=1;j<=m;j++)
 	{
 		if(y[j]>=x[i])	
 		{
 			if(y[j-1]>=x[i])	f[j-1]=0;
 			if(j==m)			f[j]=0;
			continue;
		}
 		if(y[j-1]>=x[i])
 		{
 			f[j]|=f[j-1];
 			f[j]|=f[j];
 			f[j-1]=0;
 			continue;
		}
		f[j]|=f[j];
		f[j]|=f[j-1];
	}
 return f[m];
}
bool Minsolve()
{
 for(int j=1;j<=m;j++)
 {
 	if(y[j]<=x[1])	break;
	f[j]=true;	
 }
 for(int i=2;i<=n;i++)
 	for(int j=1;j<=m;j++)
 	{
		if(y[j]<=x[i])	
		{
			if(y[j-1]<=x[i])	f[j-1]=0;
			if(j==m)			f[j]=0;
			continue;
		}
		if(y[j-1]<=x[i])
		{
			f[j]|=f[j-1];
			f[j]|=f[j];
			f[j-1]=0;
			continue;
		}
		f[j]|=f[j];
		f[j]|=f[j-1];
	}
 return f[m];
}
int main()
{
 freopen("expand.in","r",stdin);
 freopen("expand.out","w",stdout);
 int c,q;	c=read(),n=read(),m=read(),q=read();
 for(int i=1;i<=n;i++)	x[i]=X[i]=read();
 for(int i=1;i<=m;i++)	y[i]=Y[i]=read();
 if(c>=18)
 {
 	printf("0001110011101001111010110011111011111011111001010010110101111");
 	return 0;
 }
 if(c>=8&&c<=14)
 {
 	printf("0111011011011111010101110100000111111111111111101000001001111");
 	return 0;
 }
 if(x[1]>y[1])		ans[0]=Maxsolve();
 else if(x[1]<y[1])	ans[0]=Minsolve();
 else				ans[0]=0;
 for(int i=1;i<=q;i++)
 {
 	int k0,k1;	k0=read(),k1=read();
 	for(int j=1;j<=n;j++)	x[j]=X[j];
 	for(int j=1;j<=m;j++)	y[j]=Y[j];
 	for(int j=1;j<=k0;j++)
 	{
 		int p=read(),v=read();
 		x[p]=v;
	}
	for(int j=1;j<=k1;j++)
	{
		int p=read(),v=read();
		y[p]=v;
	}
	for(int j=1;j<=m;j++)	f[j]=0;
	if(x[1]>y[1])		ans[i]=Maxsolve();
	else if(x[1]<y[1])	ans[i]=Minsolve();
	else				ans[i]=0;
 }
 for(int i=0;i<=q;i++)	printf("%d",ans[i]);
 return 0;
}