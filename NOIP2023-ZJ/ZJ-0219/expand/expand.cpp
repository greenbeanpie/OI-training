#include<bits/stdc++.h>
using namespace std;
#define For(i, l ,r) for(int i=(l);i<=(r);++i)
#define RFor(i, r ,l) for(int i=(r);i>=(l);--i)
#define O(x) cerr<<#x<<":"<<x<<endl
int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')t=-t;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*t;
}
const int N=100005;
int n,m,q;
namespace Sub_1
{
	void Main()
	{
		int a,b;
		a=read();b=read();
		putchar('1'-(a==b));
		For(i, 1 ,q)
		{
			int kx=read(),ky=read();
			For(j, 1, kx) read(),a=read();
			For(j, 1, kx) read(),b=read();
			putchar('1'-(a==b));
		}
		putchar('\n');
		return;
	}
}namespace Sub_2
{
	int a[2],b[2];
	bool check(){return (a[0]>b[0]&&a[1]>b[1])||(a[0]<b[0]&&a[1]<b[1]);}
	void Main()
	{
		a[0]=read();a[1]=read();b[0]=read();b[1]=read();
		putchar('0'+check());
		For(i, 1 ,q)
		{
			int kx=read(),ky=read();
			For(j, 1, kx) {int x=read()-1;a[x]=read();}
			For(j, 1, kx) {int x=read()-1;b[x]=read();}
			putchar('0'+check());
		}
		putchar('\n');
		return;
	}
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);	
	int c=read();n=read(),m=read(),q=read();
	if(c==1){Sub_1::Main();return 0;}
	return 0;
}
