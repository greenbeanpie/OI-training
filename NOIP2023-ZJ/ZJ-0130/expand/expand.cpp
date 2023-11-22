#include<bits/stdc++.h>
using namespace std;
const int N=2005,M=500005;
int n,m,aa[M],bb[M],a[M],b[M],chx[M],chy[M];
bool f[N][N];
int read()
{
	int x=0,p=1;
	char ch=getchar();
	while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*p;
}
void DP()
{
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			f[i][j]=0;
	f[1][0]=1;f[0][1]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if((a[i]>b[j]&&a[1]>b[1])||(a[i]<b[j]&&a[1]<b[1]))
				f[i][j]|=(f[i-1][j]|f[i][j-1]);
	if(f[n][m])
		putchar('1');
	else
		putchar('0');
}
void print()
{
	if((a[1]>b[1]&&a[n]>b[m])||(a[1]<b[1]&&a[n]<b[m]))
		putchar('1');
	else
		putchar('0');
}
void init(int Q)
{
	print();
	while(Q--)
	{
		int kn=read(),km=read();
		for(int i=1;i<=kn;i++)
		{
			chx[i]=read();int y=read();
			a[chx[i]]=y;
		}
		for(int i=1;i<=km;i++)
		{
			chy[i]=read();int y=read();
			b[chy[i]]=y;
		}
		print();
		for(int i=1;i<=kn;i++)a[chx[i]]=aa[i];
		for(int i=1;i<=km;i++)a[chy[i]]=aa[i];
	}
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int op=read();n=read();m=read();int Q=read();
	for(int i=1;i<=n;i++)
		aa[i]=read(),a[i]=aa[i];
	for(int i=1;i<=m;i++)
		bb[i]=read(),b[i]=bb[i];
	if(op>7){init(Q);return 0;}
	DP();
	while(Q--)
	{
		int kn=read(),km=read();
		for(int i=1;i<=kn;i++)
		{
			chx[i]=read();int y=read();
			a[chx[i]]=y;
		}
		for(int i=1;i<=km;i++)
		{
			chy[i]=read();int y=read();
			b[chy[i]]=y;
		}
		DP();
		for(int i=1;i<=kn;i++)a[chx[i]]=aa[i];
		for(int i=1;i<=km;i++)a[chy[i]]=aa[i];
	}
	cout<<'\n';
	return 0;
}