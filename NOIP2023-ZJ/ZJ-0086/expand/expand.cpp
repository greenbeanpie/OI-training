//Private Eye,dancing with the wind.The last time.
#include<bits/stdc++.h>
using namespace std;

#define MAXN 2005
int T,n,m,q,a[MAXN],b[MAXN],c[MAXN],d[MAXN];
int f[MAXN][MAXN];

inline int read()
{
	char c(getchar());
	int s(0);
	while(c<48) c=getchar();
	while(c>47) s=(s<<1)+(s<<3)+(c^48),c=getchar();
	return s;
}

inline void solve()
{
	if(a[1]==b[1]) return printf("0"),void();
	bool ty=(a[1]>b[1]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if((a[i]>b[j])==ty and a[i]!=b[j]) f[i][j]=(f[i-1][j] or f[i][j-1] or (i==1 and j==1));
			else f[i][j]=0;
	printf("%d",f[n][m]);
}

int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	T=read(),n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++) c[i]=a[i]=read();
	for(int i=1;i<=m;i++) d[i]=b[i]=read();
	solve();
	while(q--)
	{
		for(int i=1;i<=n;i++) a[i]=c[i];
		for(int i=1;i<=m;i++) b[i]=d[i];
		int s1=read(),s2=read();
		for(int i=1,t1;i<=s1;i++) t1=read(),a[t1]=read();
		for(int i=1,t1;i<=s2;i++) t1=read(),b[t1]=read();
		solve();
	}
	return 0;
}
