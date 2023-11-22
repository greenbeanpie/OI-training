#include<bits/stdc++.h>
using namespace std;
const int N = 2005,INF=0x3f3f3f3f;
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return s*f;
}
int c,m,q,n;
int a[N],b[N],px[N],vx[N],wx[N],py[N],vy[N],wy[N];
bool f[N][N];
inline bool solve()
{
	if(a[1]==b[1]||a[n]==b[m]) return 0;
	if((a[1]-b[1])>0&&(a[n]-b[m])<0||a[1]-b[1]<0&&a[n]-b[m]>0) return 0;
	
	memset(f,0,sizeof(f));
	f[1][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
//			printf("%d %d %d\n",i,j,f[i][j]);
			if(f[i][j]) 
			{
				if(a[i]>b[j])
				{
					if(a[i+1]>b[j]) f[i+1][j]=1;
					if(a[i]>b[j+1]) f[i][j+1]=1;
					if(a[i+1]>b[j+1]) f[i+1][j+1]=1; 
				}
				else
				{
					if(a[i+1]<b[j]) f[i+1][j]=1;
					if(a[i]<b[j+1]) f[i][j+1]=1;
					if(a[i+1]<b[j+1]) f[i+1][j+1]=1;
				}
			}
		}
	}
	return f[n][m];
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) b[i]=read();
	cout<<solve();
	for(int i=1,kx,ky;i<=q;i++)
	{
		kx=read(),ky=read();
		for(int j=1;j<=kx;j++)
		{
			px[j]=read(),vx[j]=read();
			wx[j]=a[px[j]],a[px[j]]=vx[j];
		}
		for(int j=1;j<=ky;j++)
		{
			py[j]=read(),vy[j]=read();
			wy[j]=b[py[j]],b[py[j]]=vy[j];
		}
//		for(int j=1;j<=n;j++) printf("a%d ",a[j]);
//		putchar('\n');
//		for(int j=1;j<=m;j++) printf("b%d ",b[j]);
//		putchar('\n');
		cout<<solve();
		for(int j=1;j<=kx;j++)
			a[px[j]]=wx[j];
		for(int j=1;j<=ky;j++)
			b[py[j]]=wy[j];
	}
	return 0;
}
