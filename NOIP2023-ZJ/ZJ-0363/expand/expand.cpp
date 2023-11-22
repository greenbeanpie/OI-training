#include<bits/stdc++.h>
#define int long long
#define DEBUG puts("en en shui ye mei kan de qi ni");
using namespace std;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s=(s<<3)+(s<<1)+(ch^48);
		ch=getchar();
	}
	return s*w;
}
inline void print(int x)
{
	if(x<0)x=-x,putchar('-');
	if(x>=10)print(x/10);
	putchar(x%10+'0');
}
int id,n,m,q,a[10],b[10],c[10],d[10];
signed main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	id=read();
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)b[i]=read();
	if(id==1)
	{
		if(a[1]==b[1])putchar('0');
		else putchar('1');
		while(q--)
		{
			memcpy(c,a,sizeof(c));
			memcpy(d,b,sizeof(b));
			int kx=read(),ky=read();
			for(int i=1;i<=kx;i++)
			{
				int px=read(),vx=read();
				c[px]=vx;
			}
			for(int i=1;i<=ky;i++)
			{
				int px=read(),vx=read();
				d[px]=vx;
			}
			if(c[1]==d[1])putchar('0');
			else putchar('1');
		}
		return 0;
	}
	if(id==2)
	{
		if(n==2&&m==2)
		{
			if((a[1]-b[1])*(a[2]-b[2])>0)putchar('1');
			else putchar('0');
			while(q--)
			{
				memcpy(c,a,sizeof(c));
				memcpy(d,b,sizeof(b));
				int kx=read(),ky=read();
				for(int i=1;i<=kx;i++)
				{
					int px=read(),vx=read();
					c[px]=vx;
				}
				for(int i=1;i<=ky;i++)
				{
					int px=read(),vx=read();
					d[px]=vx;
				}
//				cout<<c[1]<<' '<<c[2]<<' '<<d[1]<<' '<<d[2]<<'\n';
				if((c[1]-d[1])*(c[2]-d[2])>0)putchar('1');
				else putchar('0');
			}
			return 0;
		}
		if(n==2&&m==1)
		{
			if(a[1]==b[1]||a[2]==b[1]||(a[1]-b[1])*(a[2]-b[1])<0)putchar('0');
			else putchar('1');
			while(q--)
			{
				memcpy(c,a,sizeof(c));
				memcpy(d,b,sizeof(b));
				int kx=read(),ky=read();
				for(int i=1;i<=kx;i++)
				{
					int px=read(),vx=read();
					c[px]=vx;
				}
				for(int i=1;i<=ky;i++)
				{
					int px=read(),vx=read();
					d[px]=vx;
				}
				if(c[1]==d[1]||c[2]==d[1]||(c[1]-d[1])*(c[2]-d[1])<0)putchar('0');
				else putchar('1');
			}
		}
		if(n==1&&m==2)
		{
			if(a[1]==b[1]||a[1]==b[2]||(b[1]-a[1])*(b[2]-a[1])<0)putchar('0');
			else putchar('1');
			while(q--)
			{
				memcpy(c,a,sizeof(c));
				memcpy(d,b,sizeof(b));
				int kx=read(),ky=read();
				for(int i=1;i<=kx;i++)
				{
					int px=read(),vx=read();
					c[px]=vx;
				}
				for(int i=1;i<=ky;i++)
				{
					int px=read(),vx=read();
					d[px]=vx;
				}
				if(c[1]==d[1]||c[1]==d[2]||(c[1]-d[1])*(c[2]-d[1])<0)putchar('0');
				else putchar('1');
			}
		}
		if(n==1&&m==1)
		{
			if(a[1]==b[1])putchar('0');
			else putchar('1');
			while(q--)
			{
				memcpy(c,a,sizeof(c));
				memcpy(d,b,sizeof(b));
				int kx=read(),ky=read();
				for(int i=1;i<=kx;i++)
				{
					int px=read(),vx=read();
					c[px]=vx;
				}
				for(int i=1;i<=ky;i++)
				{
					int px=read(),vx=read();
					d[px]=vx;
				}
				if(c[1]==d[1])putchar('0');
				else putchar('1');
			}
			return 0;
		}
	}
	return 0;
}