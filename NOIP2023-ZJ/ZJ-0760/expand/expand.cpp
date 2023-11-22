#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
#define CI const int
using namespace std;
const int N=5e5+5,inf=1e9;
int C,T,n,m,q,A[N],B[N],a[N],b[N];
int read(int& v)
{
	char ch;int f=1;
	for(ch='*';!isdigit(ch) && ch!='-';ch=getchar());
	if(ch=='-')  f=-1,ch=getchar();
	for(v=0;isdigit(ch);v=v*10+ch-'0',ch=getchar());
	v*=f;
return v;
}
namespace sub1
{
	void main()
	{
		for(int i=0;i<=q;i++)
		{
			int kx,ky,pos,val;
			for(int j=1;j<=n;j++)  a[j]=A[j];
			for(int j=1;j<=m;j++)  b[j]=B[j];
			if(i==0)  goto Try;
			read(kx),read(ky);
			for(int j=1;j<=kx;j++)
			{
				read(pos),read(val);
				a[pos]=val;
			}
			for(int j=1;j<=ky;j++)
			{
				read(pos),read(val);
				b[pos]=val;
			}
			Try:;
			if(n==1 && m==1)  putchar(a[1]!=b[1]?'1':'0');
			if(n==1 && m==2)
			{
				if(a[1]<min(b[1],b[2]) || a[1]>max(b[1],b[2]))  putchar('1');
				else putchar('0');
			}
			if(n==2 && m==1)
			{
				if(b[1]<min(a[1],a[2]) || b[1]>max(a[1],a[2]))  putchar('1');
				else putchar('0');
			}
			if(n==2 && m==2)
			{
				if(a[1]<b[1] && a[2]>b[2])  putchar('0');
				else if(a[1]>b[1] && a[2]<b[2])  putchar('0');
				else if(a[1]==b[1] || a[2]==b[2])  putchar('0');
				else putchar('1');
			}
		}
	}
}
namespace sub2
{
	void main()
	{
		for(int i=0;i<=q;i++)
		{
			int kx,ky,pos,val;
			for(int j=1;j<=n;j++)  a[j]=A[j];
			for(int j=1;j<=m;j++)  b[j]=B[j];
			if(i==0)  goto Try;
			read(kx),read(ky);
			for(int j=1;j<=kx;j++)
			{
				read(pos),read(val);
				a[pos]=val;
			}
			for(int j=1;j<=ky;j++)
			{
				read(pos),read(val);
				b[pos]=val;
			}
			Try:;
			if(a[1]<b[1] && a[n]>b[m]){ putchar('0'); continue; }
			if(a[1]<b[1] && a[n]>b[m]){ putchar('0'); continue; }
			if(a[1]==b[1] || a[n]==b[m]){ putchar('0'); continue; }
			if(a[1]<b[1])
			{
				int mav=b[1],y=2;
				for(int x=2;x<=n;x++)
				{
					for(;y<=m && b[y]>a[x] || y<=x;y++)  mav=max(mav,b[y]);
					if(y<=x && mav<=a[x]){ putchar('0'); goto go1; }
				}
				for(;y<=m;y++)
					if(a[n]>=b[y]){ putchar('0'); goto go1; }
				putchar('1');go1:;
			}
			else
			{
				int miv=b[1],y=2;
				for(int x=2;x<=n;x++)
				{
					for(;y<=m && b[y]<a[x] || y<=x;y++)  miv=min(miv,b[y]);
					if(y<=x && miv>=a[x]){ putchar('0'); goto go2; }
				}
				for(;y<=m;y++)
					if(a[n]<=b[y]){ putchar('0'); goto go2; }
				putchar('1');go2:;
			}
		}
	}
}
namespace sub3
{
	void main()
	{
		for(int i=0;i<=q;i++)
		{
			int kx,ky,pos,val;
			if(i==0)  goto Try;
			read(kx),read(ky);
			for(int j=1;j<=kx;j++)
			{
				read(pos),read(val);
				A[pos]=val;
			}
			for(int j=1;j<=ky;j++)
			{
				read(pos),read(val);
				B[pos]=val;
			}
			Try:;
			if(A[n]>=B[m])  putchar('0');
			else  putchar('1');
		}
	}
}
void solve()
{
	read(C),read(n),read(m),read(q);
	for(int i=1;i<=n;i++)  read(A[i]);
	for(int i=1;i<=m;i++)  read(B[i]);
	if(C<=2){ sub1::main(); return; }
	if(C<=7){ sub2::main(); return; }
	if(8<=C && C<=14){ sub3::main(); return; }
}
signed main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	read(T);
	while(T--)  solve();
return 0;
}