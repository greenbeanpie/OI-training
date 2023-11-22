#include<bits/stdc++.h>
#define maxn 2005
using namespace std;
int _,n,m,q;
int kx,ky,a1[maxn],b1[maxn],a[maxn],b[maxn];
bool f[maxn][maxn];
int read(){
	int x=0;
	char ch=getchar();
	while(ch>'9' || ch<'0') ch=getchar();
	while(ch<='9' && ch>='0') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
//	scanf("%d%d%d%d",&_,&n,&m,&q);
	read();n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++) a1[i]=read();
	for(int i=1;i<=m;i++) b1[i]=read();
	int op=(a1[1]<b1[1]);
	f[1][1]=(a1[1]!=b1[1]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(i==1 && j==1) continue;
			if(!((a1[i]>b1[j])^op) || a1[i]==b1[j]) 
			{
				f[i][j]=0;
				continue;
			}
			f[i][j]=(f[i-1][j]|f[i][j-1]);
		}
	printf("%d",f[n][m]);
	while(q--)
	{
		int pos,v;
		kx=read(),ky=read();
		for(int i=1;i<=n;i++) a[i]=a1[i];
		for(int i=1;i<=m;i++) b[i]=b1[i];
		while(kx--)
		{
			pos=read(),v=read();
			a[pos]=v;
		}
		while(ky--)
		{
			pos=read(),v=read();
			b[pos]=v;
		}
		int op=(a[1]<b[1]);
		f[1][1]=(a[1]!=b[1]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(i==1 && j==1) continue;
				if(!((a[i]>b[j])^op) || a[i]==b[j]) 
				{
					f[i][j]=0;
					continue;
				}
				f[i][j]=(f[i-1][j]|f[i][j-1]);
			}
		printf("%d",f[n][m]);
	}
	return 0;
}
