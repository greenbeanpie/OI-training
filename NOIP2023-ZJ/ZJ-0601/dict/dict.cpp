#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
#define IOS ios::sync_with_stdio(0)
using namespace std;
inline int read()
{
	char ch=getchar();
	int pos=1,num=0;
	while (!isdigit(ch))
	{
		if (ch=='-') pos=-1;
		ch=getchar();
	}
	while (isdigit(ch))
	{
		num=num*10+(int)(ch-'0');
		ch=getchar();
	}
	return pos*num;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		write(-x);
		return;
	}
	if (x>=10) write(x/10);
	putchar(x%10+'0');
}
void writesp(int x)
{
	write(x);
	putchar(' ');
}
void writeln(int x)
{
	write(x);
	putchar('\n');
}
const int N=3e3+10,base=2333,mod=998244353;
int n,m,a[N][N],b[N][N],c[N][N],val1[N][N],val2[N][N];
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(); m=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			char ch=getchar();
			while (!(ch>='a'&&ch<='z')) ch=getchar();
			a[i][j]=ch-'a'+1; b[i][j]=a[i][j]; c[i][j]=a[i][j];
		}
	for (int i=1;i<=n;i++) sort(b[i]+1,b[i]+m+1,cmp);
	for (int i=1;i<=n;i++) sort(c[i]+1,c[i]+m+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			val1[i][j]=(val1[i][j-1]*base%mod+c[i][j])%mod;
			val2[i][j]=(val2[i][j-1]*base%mod+b[i][j])%mod;
		}
	for (int i=1;i<=n;i++)
	{
		int flag=0;
		for (int j=1;j<=n;j++)
		{
			if (i==j) continue;
			int l=1,r=m,now=0;
			while (l<=r)
			{
				int mid=(l+r)>>1;
				if (val1[i][mid]!=val2[j][mid]) now=mid,r=mid-1; else l=mid+1;
			}
			if (!now||c[i][now]>b[j][now]) flag=1;
		}
		if (!flag) putchar('1'); else putchar('0');
	}
}


