#include<stdio.h>
#include<bits/stdc++.h>
#define fir first
#define sec second
#define all(x) begin(x),end(x)
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
bool mmp1;
namespace __Clonoth__
{
template<typename type>
inline void chmin(type &x,const type &y)
{
	if(y<x)
		x=y;
}
template<typename type>
inline void chmax(type &x,const type &y)
{
	if(x<y)
		x=y;
}
char Buf[1<<23],*P1=Buf,*P2=Buf;
#define getchar() (P1==P2&&(P2=(P1=Buf)+fread(Buf,1,1<<23,stdin),P1==P2)?EOF:*P1++)
template<typename type>
inline void read(type &x)
{
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9')
		x=x*10+(ch^48),ch=getchar();
}
constexpr int Max=5e5+10;
int A[Max],B[Max],a[Max],b[Max];
int n,m,Q;
int f[Max],g[Max],c[Max],d[Max];
pii w1[Max],w2[Max],z1[Max],z2[Max];
pii p[Max*2],q[Max*2];
int solve(int *a,int *b,pii *p,pii *q,int n,int m)
{
	if(n<=2000&&m<=2000)
	{
		static bool f[2010][2010];
		memset(f,false,sizeof(f));
		f[1][1]=true;
		for(int i=0;i<=n;++i)
			for(int j=0;j<=m;++j)
			{
				if(!f[i][j])
					continue;
				if(i<n&&a[i+1]<b[j])
					f[i+1][j]=true;
				if(j<m&&a[i]<b[j+1])
					f[i][j+1]=true;
				if(i<n&&j<m&&a[i+1]<b[j+1])
					f[i+1][j+1]=true;
			}
		return f[n][m];
	}
	for(int i=1;i<=n;++i)
		c[i]=a[i];
	for(int i=2;i<=n;++i)
		chmin(c[i],c[i-1]);
	for(int i=1;i<=m;++i)
		d[i]=b[i];
	for(int i=2;i<=m;++i)
		chmax(d[i],d[i-1]);
	for(int i=1,j=1;i<=n;++i)
	{
		while(j<=m&&d[j]<=p[i].fir)
			++j;
		f[p[i].sec]=j;
	}
	for(int i=m,j=1;i;--i)
	{
		while(j<=n&&c[j]>=q[i].fir)
			++j;
		g[q[i].sec]=j;
	}
	for(int i=1;i<=n;++i)
		if(f[i]>m)
			return 0;
	for(int i=1;i<=m;++i)
		if(g[i]>n)
			return 0;
	for(int i=1;i<=m;++i)
		chmax(g[i],g[i-1]);
	for(int i=1;i<=n;++i)
		if(g[f[i]-1]>i)
			return 0;
	return 1;
}
int solve()
{
	if(a[1]==b[1])
		return 0;
	if(a[1]<b[1])
	{
		bool flag=solve(a,b,p,q,n,m);
		if(!flag)
			return false;
		for(int i=1;i<=n;++i)
			p[i].sec=n-p[i].sec+1;
		for(int i=1;i<=m;++i)
			q[i].sec=m-q[i].sec+1;
		reverse(a+1,a+n+1);
		reverse(b+1,b+m+1);
		return solve(a,b,p,q,n,m);
	}
	else
	{
		bool flag=solve(b,a,q,p,m,n);
		if(!flag)
			return false;
		for(int i=1;i<=n;++i)
			p[i].sec=n-p[i].sec+1;
		for(int i=1;i<=m;++i)
			q[i].sec=m-q[i].sec+1;
		reverse(a+1,a+n+1);
		reverse(b+1,b+m+1);
		return solve(b,a,q,p,m,n);
	}
}
signed main()
{
	int tc;
	read(tc),read(n),read(m),read(Q);
	for(int i=1;i<=n;++i)
		read(A[i]);
	for(int i=1;i<=m;++i)
		read(B[i]);
	for(int i=1;i<=n;++i)
		a[i]=A[i];
	for(int i=1;i<=m;++i)
		b[i]=B[i];
	for(int i=1;i<=n;++i)
		w1[i]=pii(a[i],i);
	for(int i=1;i<=m;++i)
		w2[i]=pii(b[i],i);
	sort(w1+1,w1+n+1);
	sort(w2+1,w2+m+1);
	for(int i=1;i<=n;++i)
		p[i]=w1[i];
	for(int i=1;i<=m;++i)
		q[i]=w2[i];
	cout<<solve();
	while(Q--)
	{
		for(int i=1;i<=n;++i)
			a[i]=A[i];
		for(int i=1;i<=m;++i)
			b[i]=B[i];
		int k1,k2,x,y;
		read(k1),read(k2);
		for(int i=1;i<=k1;++i)
			read(x),read(y),a[x]=y,z1[i]=pii(y,x);
		for(int i=1;i<=k2;++i)
			read(x),read(y),b[x]=y,z2[i]=pii(y,x);
		sort(z1+1,z1+k1+1);
		sort(z2+1,z2+k2+1);
		merge(w1+1,w1+n+1,z1+1,z1+k1+1,p+1);
		merge(w2+1,w2+m+1,z2+1,z2+k2+1,q+1);
		for(int i=1,k=0;i<=n+k1;++i)
			if(p[i].fir==a[p[i].sec])
				p[++k]=p[i];
		for(int i=1,k=0;i<=m+k2;++i)
			if(q[i].fir==b[q[i].sec])
				q[++k]=q[i];
		cout<<solve();
	}
	cout<<"\n";
	return 0;
}
}
bool mmp2;
signed main()
{
//	cerr<<(&mmp1-&mmp2)/1048576.0<<"\n";
	freopen("expand.in","r",stdin),freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	__Clonoth__::main();
	return 0;
}