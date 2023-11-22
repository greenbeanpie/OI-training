#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=5e5+5;
int c,n,m,q,x[N],y[N],dx[N],dy[N];
int cnt[N];
namespace sub1
{
	inline void S1()
	{
		printf("1");
	}
}
namespace sub2
{
	inline void S2()
	{
		for(int i=1;i<=n;i++) cnt[i]=min(i,m);
		int I=0;
		if(dx[1]>dy[1]) I=1;
		else if(dx[1]==dy[1])
		{
			printf("0");
			return;
		}
		for(int i=2;i<=n;i++)
		{
			int TT=0;
			if(dx[i]>dy[cnt[i]]) TT=1;
			else if(dx[i]==dy[cnt[i]]) TT=-1;
			while(TT!=I)
			{
				if(cnt[i]==m)
				{
					printf("0");
					return;
				}
				cnt[i]++;
				if(dx[i]>dy[cnt[i]]) TT=1;
				else if(dx[i]==dy[cnt[i]]) TT=-1;
				else TT=0;
			}
			while(cnt[i-1]<cnt[i]-1)
			{
				cnt[i-1]++;
				int TTT=0;
				if(dx[i-1]>dy[cnt[i-1]]) TTT=1;
				else if(dx[i-1]==dy[cnt[i-1]]) TTT=-1;
				if(TTT!=I)
				{
					printf("0");
					return;
				}
			}
		}
		printf("1");
	}
}
inline void mem()
{
	for(int i=1;i<=n;i++) dx[i]=x[i];
	for(int j=1;j<=m;j++) dy[j]=y[j];
}
inline void init()
{
	c=read(),n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++) x[i]=read();
	for(int i=1;i<=m;i++) y[i]=read();
}
inline void work()
{
	mem();
	if(n==m&&n==1) sub1::S1();
	else sub2::S2();
	while(q--)
	{
		mem();
		int kx=read(),ky=read();
		for(int i=1;i<=kx;i++)
		{
			int px=read(),vx=read();
			dx[px]=vx;
		}
		for(int i=1;i<=ky;i++)
		{
			int py=read(),vy=read();
			dy[py]=vy;
		}
		if(n==m&&n==1) sub1::S1();
		else sub2::S2();
	}
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	init();
	work();
	return 0;
}
