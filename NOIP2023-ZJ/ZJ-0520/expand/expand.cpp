#include<bits/stdc++.h>
using namespace std;

const int N=2005,M=2005;

inline int get()
{
	register char ch;
	while((ch=getchar())<'0'||ch>'9');
	register int res=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
		res=(res<<3)+(res<<1)+ch-'0';
	return res;
}

int c,n,m,q,X[N],Y[M],x[M],y[M];

inline void init()
{
	for(int i=1;i<=n;i++)
		x[i]=X[i];
	for(int i=1;i<=m;i++)
		y[i]=Y[i];
	return;
}

inline bool work(int nx,int ny,bool bo)
{
	if(bo)
	{
		if(nx==n)
		{
			for(int i=ny;i<=m;i++)
				if(x[nx]<=y[i])return 0;
			return 1;
		}
		for(int i=ny;i<=m;i++)
			if(x[nx]>y[i]){
				if(work(nx+1,i,bo))return 1;
			}
			else break;
	}
	else{
		if(nx==n)
		{
			for(int i=ny;i<=m;i++)
				if(x[nx]>=y[i])return 0;
			return 1;
		}
		for(int i=ny;i<=m;i++)
			if(x[nx]<y[i]){
				if(work(nx+1,i,bo))return 1;
			}
			else break;
	}
	return 0;
}

int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=get(),n=get(),m=get(),q=get();
	for(int i=1;i<=n;i++)
		X[i]=get();
	for(int i=1;i<=m;i++)
		Y[i]=get();
	init();
	if(work(1,1,x[1]>y[1]))putchar('1');
	else putchar('0');
	while(q--)
	{
		init();
		int kx=get(),ky=get();
		for(int i=1;i<=kx;i++)
			x[get()]=get();
		for(int i=1;i<=ky;i++)
			y[get()]=get();
		if(work(1,1,x[1]>y[1]))putchar('1');
		else putchar('0');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
