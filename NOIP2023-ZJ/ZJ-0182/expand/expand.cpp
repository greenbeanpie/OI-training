#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define il inline
#define re register
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
//#define int ll
#define pii pair<int,int>
#define mp make_pair
#define F(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define DF(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define G(i,u) for(int (i)=head[(u)];(i);(i)=nxt[(i)])
il ll read(){ll x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-48;ch=getchar();}return x*f;}
const int N=2010,NN=500010;
int c,n,m,q,nn,mm;
int x[NN],y[NN],xx[NN],yy[NN];
int ans[N];
int dp[N][N];
il void solve(int id)
{
	if(x[1]>y[1]&&x[n]>y[n])
	{
		
	}
	else if(x[1]<y[1]&&x[n]<y[n])
	{
		F(i,1,max(n,m)) swap(x[i],y[i]);
		swap(n,m);
	}
	else
	{
		ans[id]=0;
		return ;
	}
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	F(i,1,n)
	{
		F(j,1,m)
		{
			if(x[i]>y[j])
			{
				dp[i][j]=dp[i-1][j-1]|dp[i][j-1]|dp[i-1][j];
			}
		}
	}
	ans[id]=dp[n][m];
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),nn=n=read(),mm=m=read(),q=read();
	F(i,1,n) xx[i]=x[i]=read();
	F(i,1,m) yy[i]=y[i]=read();
	solve(0);
	F(i,1,q)
	{
		n=nn,m=mm;
		F(i,1,n) x[i]=xx[i];
		F(i,1,m) y[i]=yy[i];
		int kx=read(),ky=read();
		F(i,1,kx)
		{
			int pos=read(),v=read();
			x[pos]=v;
		}
		F(i,1,ky)
		{
			int pos=read(),v=read();
			y[pos]=v;
		}
		solve(i);
	}
	F(i,0,q) printf("%d",ans[i]);
	return 0;
}
