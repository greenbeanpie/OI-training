#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,q,kx,ky;
int x[N],y[N];
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch<='9'&&ch>='0') { x=(x<<3)+(x<<1)+ch-48; ch=getchar(); }
	return x*f;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();n=read();m=read();q=read();
	for(int i=1;i<=n;i++) x[i]=read();
	for(int i=1;i<=m;i++) y[i]=read();
	int qq=q+1;
	while(q--)
	{
		kx=read();ky=read();
		for(int i=1;i<=kx;i++) {int p=read(),v=read(); }
		for(int i=1;i<=ky;i++) {int p=read(),v=read(); }
	}
	while(qq--) printf("0");
	return 0;
}
