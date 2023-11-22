#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
int x[2005],y[2005],px[2005],vx[2005],py[2005],vy[2005];
int dx[2005],dy[2005];
bool ok[2005][2005];
inline void judge()
{
	bool jj1=0,jj2=0;
	if(x[1]==y[1])
	{
		cout<<0;
		return ;
	}
	bool flg=0;
	if(x[1]<y[1]) flg=1,swap(x,y),swap(n,m);
	m++;
	y[m]=y[m-1];
	if(x[n]<y[m])
	{
		m--;
		if(flg) swap(x,y),swap(n,m);
		cout<<0;
		return ;
	}
	int cury=1;
	memset(ok,0,sizeof(ok));
	for(register int i=1;i<=n;i++)
	for(register int j=1;j<=m;j++)
	ok[i][j]=(x[i]>y[j]?1:0);
	for(register int i=1;i<=n-1;i++)
	{
		while(ok[i][cury]&&cury<=m) cury++;
		cury--;
		while(!ok[i+1][cury]&&ok[i][cury]&&cury>=i) cury--;
		if(cury==i-1)
		{
			jj1=0;
			goto A;
		}
		while(ok[i+1][cury]&&ok[i][cury]&&cury>i) cury--;
		cury++;
	}
	while(ok[n][cury]&&cury<=m) cury++;
	if(cury>=m) jj1=1;
	A:
	m--;
	if(flg) swap(x,y),swap(n,m);
	if(jj1) 
	{
		cout<<1;
		return ;
	}
	
	for(register int i=1;i<=n;i++)
	x[i]=2147483647-x[i];
	for(register int i=1;i<=m;i++)
	y[i]=2147483647-y[i];
	flg=0;
	if(x[1]<y[1]) flg=1,swap(x,y),swap(n,m);
	m++;
	y[m]=y[m-1];
	cury=1;
	memset(ok,0,sizeof(ok));
	for(register int i=1;i<=n;i++)
	for(register int j=1;j<=m;j++)
	ok[i][j]=(x[i]>y[j]?1:0);
	for(register int i=1;i<=n-1;i++)
	{
		while(ok[i][cury]&&cury<=m) cury++;
		cury--;
		while(!ok[i+1][cury]&&ok[i][cury]&&cury>=i) cury--;
		if(cury==i-1)
		{
			jj2=0;
			goto B;
		}
		while(ok[i+1][cury]&&ok[i][cury]&&cury>i) cury--;
		cury++;
	}
	while(ok[n][cury]&&cury<=m) cury++;
	if(cury>=m) jj2=1;
	B:
	m--;
	if(jj1||jj2) cout<<1;
	else cout<<0;
	if(flg) swap(x,y),swap(n,m);
	for(register int i=1;i<=n;i++)
	x[i]=2147483647-x[i];
	for(register int i=1;i<=m;i++)
	y[i]=2147483647-y[i];
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(register int i=1;i<=n;i++) cin>>x[i];
	for(register int i=1;i<=m;i++) cin>>y[i];
	judge();
	for(register int i=1;i<=q;i++)
	{
		int kx,ky;
		cin>>kx>>ky;
		for(register int j=1;j<=kx;j++)
		{
			cin>>px[j]>>vx[j];
			vx[j]-=x[px[j]];
			x[px[j]]+=vx[j];
		}
		for(register int j=1;j<=ky;j++)
		{
			cin>>py[j]>>vy[j];
			vy[j]-=y[py[j]];
			y[py[j]]+=vy[j];
		}
		judge();
		for(register int j=1;j<=kx;j++)
			x[px[j]]-=vx[j];
		for(register int j=1;j<=ky;j++)
			y[py[j]]-=vy[j];
	}
	return 0;
}
