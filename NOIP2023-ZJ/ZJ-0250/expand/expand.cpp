#include<bits/stdc++.h>
#define N (2005)
using namespace std;
int xx,yy,n,m,kx,ky,cc,q;
int x[N],y[N],lx[N],ly[N];
bool f[N][N];
int c(int x,int y)
{
	if(x==y) return 2;
	return (x>y?1:0);	
}
bool check()
{
	if(1ll*(lx[1]-ly[1])*(lx[n]-ly[m])<=0) return 0;
	memset(f,0,sizeof f);
	bool fl=c(lx[1],ly[1]);
	f[1][1]=1;
	for(int i=1;i<=n;++i)
	  for(int j=1;j<=m;++j) 
	    if(fl==c(lx[i],ly[j]))
	      f[i][j]|=(f[i][j-1]|f[i-1][j]);
	return f[n][m];
} 
signed main(void)
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>cc>>n>>m>>q;
	for(int i=1;i<=n;++i) cin>>x[i],lx[i]=x[i];
	for(int i=1;i<=m;++i) cin>>y[i],ly[i]=y[i];
	cout<<check();
	for(;q--;)
	  {
	  	for(int i=1;i<=n;++i)lx[i]=x[i];
	  	for(int i=1;i<=m;++i)ly[i]=y[i];
	  	cin>>kx>>ky;
	  	for(;kx--;) cin>>xx>>yy,lx[xx]=yy;
	  	for(;ky--;) cin>>xx>>yy,ly[xx]=yy;
	  	cout<<check();
	  }
	return 0;
}
/*
考虑fi-gi的平方大于零 
则fi-gi大于零或小于零
而全部要满足这个性质，则x与y相同的下标对应值的差都大于零或小于零 

*/
