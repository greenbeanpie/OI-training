#include"cstdio"
#include"cstring"
int c,n,m,q;
int x[4010],y[4010];
int X[4010],Y[4010];
int f[4010][4010];
int ans[110];
int kx,ky,p,v;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-f;c=getchar();}
	while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
inline bool check(int x[],int n,int y[],int m)
{
	if(x[1]<y[1])return 0;
	for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)f[i][j]=0;
	f[1][0]=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(x[i]>y[j])if(f[i-1][j]||f[i][j-1])f[i][j]=1;
	}
	return f[n][m];
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++)x[i]=read(),X[i]=x[i];
	for(int i=1;i<=m;i++)y[i]=read(),Y[i]=y[i];
	if(x[n]>y[m])ans[0]=check(x,n,y,m);
	else ans[0]=check(y,m,x,n);
	for(int i=1;i<=q;i++)
	{
		kx=read(),ky=read();
		for(int j=1;j<=kx;j++)
		{
			p=read(),v=read();
			x[p]=v;
		}
		for(int j=1;j<=ky;j++)
		{
			p=read(),v=read();
			y[p]=v;
		}
		if(x[n]>y[m])ans[i]=check(x,n,y,m);
		else ans[i]=check(y,m,x,n);
		for(int j=1;j<=n;j++)x[j]=X[j];
		for(int j=1;j<=m;j++)y[j]=Y[j];
	}
	for(int i=0;i<=q;i++)printf("%d",ans[i]);
	return 0;
}
