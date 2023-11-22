#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define int long long
#define CI const int
using namespace std;
const int N=1e5+5,inf=1e18;
int C,T,n,m,d,lim;
struct chall
{
	int x,y,v;
	bool operator<(const chall& a)const{ return x<a.x; }
	chall(CI&x,CI& y,CI& v):x(x),y(y),v(v){}
	chall(){}
}p[N];
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
	const int M=1e3+5;
	int val[M][M],rec[M];
	void main()
	{
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=n+1;j++)  val[i][j]=0;
		for(int i=1;i<=m;i++)
		{
			int x=p[i].x,y=p[i].y,v=p[i].v;
			int le=x-y+1,ri=x;
			if(le<1 || ri>n)  continue;
			val[le][ri]+=v;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				val[i][j]+=val[i][j-1];
		for(int j=1;j<=n;j++)
			for(int i=n;i>=1;i--)
				val[i][j]+=val[i+1][j];
		int ans=-inf;
		for(int i=1;i<=n;i++)  rec[i]=-inf;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=min(i,lim);j++)
			{
				int st=i-j+1,ed=i,tmp=0;
				for(int k=0;k<i-j;k++)
					tmp=max(tmp,rec[k]+val[st][ed]);
				if(i==j)  tmp=val[st][ed];
				tmp-=j*d;
				ans=max(ans,tmp);
				rec[i]=max(rec[i],tmp);
			}
		ans=max(ans,0ll);
		printf("%lld\n",ans);
	}
}
void solve()
{
	read(n),read(m),read(lim),read(d);
	for(int i=1;i<=m;i++)  read(p[i].x),read(p[i].y),read(p[i].v);
	sort(p+1,p+1+m);
	/*if(C<=7)*/{ sub1::main(); return; }
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	read(C),read(T);
	while(T--)  solve();
return 0;
}