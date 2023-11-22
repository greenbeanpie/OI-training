#include<bits/stdc++.h>
#define F(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
using namespace std;
const int N=5e5+5;
int C,n,m,q,a[N],b[N],kx,ky,x,y,aa[N],bb[N],nn,mm,c[N],d[N];
inline void work()
{
	if (a[1]==b[1]){cout<<0;return;}
	if (a[1]<b[1])
	{
		nn=m;mm=n;
		F(i,1,nn)aa[i]=b[i];
		F(i,1,mm)bb[i]=a[i];
	}else
	{
		nn=n;mm=m;
		F(i,1,nn)aa[i]=a[i];
		F(i,1,mm)bb[i]=b[i];
	}
	if (aa[nn]<=bb[mm]){cout<<0;return;}
	int mn1=1e9,mn2=1e9;
	F(i,1,nn)mn1=min(mn1,aa[i]);
	F(i,1,mm)mn2=min(mn2,bb[i]);
	cout<<(mn1>mn2);
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>n>>m>>q;
	F(i,1,n)cin>>c[i];
	F(i,1,m)cin>>d[i];
	F(i,1,n)a[i]=c[i];
	F(i,1,m)b[i]=d[i];
	work();while (q--)
	{
		F(i,1,n)a[i]=c[i];
		F(i,1,m)b[i]=d[i];
		cin>>kx>>ky;
		while (kx--){cin>>x>>y;a[x]=y;}
		while (ky--){cin>>x>>y;b[x]=y;}
		work();
	}
	return 0;
}
