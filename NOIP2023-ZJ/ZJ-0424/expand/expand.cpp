#include<bits/stdc++.h>
#define endl '\n'
#define fir first
#define sec second
#define ri register
#define pb push_back
#define mp make_pair
#define int long long
#define inf 2147483647
#define Swap(x,y) ((x)^=(y)^=(x)^=(y))
#define reset(x,y) memset((x),(y),sizeof((x)))
#define fastcin ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
inline int read()
{
	ri int x=0,f=0;ri char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c-'0'),c=getchar();
	return f?-x:x;
}
inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int N=5e5+10;
int c,n,m,q,a[N],b[N],A[N],B[N];
signed main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),n=read(),m=read(),q=read();
	for(ri int i=1;i<=n;++i)
		a[i]=A[i]=read();
	for(ri int i=1;i<=m;++i)
		b[i]=B[i]=read();
	
	if(n==1)
	{
		cout<<(A[1]!=B[1]);
		for(ri int x,y;q;--q)
		{
			for(ri int i=1;i<=n;++i)
				a[i]=A[i];
			for(ri int i=1;i<=m;++i)
				b[i]=B[i];
			x=read(),y=read();
			for(ri int i=1,p,v;i<=x;++i)
				p=read(),v=read(),a[p]=v;
			for(ri int i=1,p,v;i<=y;++i)
				p=read(),v=read(),b[p]=v;
			cout<<(a[1]!=b[1]);
		}
	}
	
	else if(n==2)
	{
		cout<<(A[1]>B[1]&&A[2]>B[2]||A[1]<B[1]&&A[2]<B[2]);
		for(ri int x,y;q;--q)
		{
			for(ri int i=1;i<=n;++i)
				a[i]=A[i];
			for(ri int i=1;i<=m;++i)
				b[i]=B[i];
			x=read(),y=read();
			for(ri int i=1,p,v;i<=x;++i)
				p=read(),v=read(),a[p]=v;
			for(ri int i=1,p,v;i<=y;++i)
				p=read(),v=read(),b[p]=v;
			cout<<(a[1]>b[1]&&a[2]>b[2]||a[1]<b[1]&&a[2]<b[2]);
		}
	}
	return 0;
}
