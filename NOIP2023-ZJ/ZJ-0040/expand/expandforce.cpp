#include<cstdio>
#include<cstring>
#define F(i,l,r) for(int i=(l),i##_end=(r);i<i##_end;++i)
using namespace std;
constexpr int N=5005;
int n,m,q,a[N],b[N];
bool f[N][N];
void solve()
{
	memset(f,0,sizeof(bool)*N*n);
	f[0][0]=a[0]!=b[0];
	F(i,0,n)F(j,0,m)if(f[i][j])
	{
		f[i][j+1]|=(long long)(a[i]-b[j])*(a[i]-b[j+1])>0;
		f[i+1][j]|=(long long)(a[i]-b[j])*(a[i+1]-b[j])>0;
		f[i+1][j+1]|=(long long)(a[i]-b[j])*(a[i+1]-b[j+1])>0;
	}
	if(f[n-1][m-1])putchar('1');
	else putchar('0');
}
int x[N],y[N];
int main()
{
	scanf("%*d%d%d%d",&n,&m,&q);
	F(i,0,n)scanf("%d",&x[i]);
	F(i,0,m)scanf("%d",&y[i]);
	memcpy(a,x,sizeof(int)*n);
	memcpy(b,y,sizeof(int)*m);
	solve();
	while(q--)
	{
		memcpy(a,x,sizeof(int)*n);
		memcpy(b,y,sizeof(int)*m);
		int kx,ky;
		scanf("%d%d",&kx,&ky);
		F(i,0,kx)
		{
			int p,v;
			scanf("%d%d",&p,&v);--p;
			a[p]=v;
		}
		F(i,0,ky)
		{
			int p,v;
			scanf("%d%d",&p,&v);--p;
			b[p]=v;
		}
		solve();
	}
	puts("");
	return 0;
}
