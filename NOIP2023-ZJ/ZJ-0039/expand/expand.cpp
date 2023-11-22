#include<bits/stdc++.h>
using namespace std;

constexpr int maxn=500010;

int x[maxn],y[maxn],px[maxn],vx[maxn],py[maxn],vy[maxn];

bool bWork(int *x,int *y,int n,int m)
{
	int *xmn,*xmx,*ymn,*ymx;
	tie(xmn,xmx)=minmax_element(x+1,x+n+1);
	tie(ymn,ymx)=minmax_element(y+1,y+m+1);
	if(*xmx>=*ymx||*xmn>=*ymn) return false;
	int i=1,j=1,vx=x[1],vy=y[1];
	while(x+i<xmn&&y+j<ymx)
	{
		int oi=i,oj=j;
		while(x+i<xmn&&x[i+1]<vy) vx=min(vx,x[++i]);
		while(y+j<ymx&&y[j+1]>vx) vy=max(vy,y[++j]);
		if(i==oi&&j==oj) return false;
	}
	i=n,j=m,vx=x[n],vy=y[m];
	while(x+i>xmn&&y+j>ymx)
	{
		int oi=i,oj=j;
		while(x+i>xmn&&x[i-1]<vy) vx=min(vx,x[--i]);
		while(y+j>ymx&&y[j-1]>vx) vy=max(vy,y[--j]);
		if(i==oi&&j==oj) return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int C,n,m,q,i;
	cin>>C>>n>>m>>q;
	for(i=1;i<=n;i++) cin>>x[i];
	for(i=1;i<=m;i++) cin>>y[i];
	auto solve=[&]
	{
		if(x[1]<y[1]&&x[n]<y[m]) cout<<bWork(x,y,n,m);
		else if(x[1]>y[1]&&x[n]>y[m]) cout<<bWork(y,x,m,n);
		else cout<<0;
	};
	solve();
	while(q--)
	{
		int kx,ky;
		cin>>kx>>ky;
		for(i=1;i<=kx;i++)
		{
			cin>>px[i]>>vx[i];
			swap(x[px[i]],vx[i]);
		}
		for(i=1;i<=ky;i++)
		{
			cin>>py[i]>>vy[i];
			swap(y[py[i]],vy[i]);
		}
		solve();
		for(i=1;i<=kx;i++) swap(x[px[i]],vx[i]);
		for(i=1;i<=ky;i++) swap(y[py[i]],vy[i]);
	}
	cout<<'\n';
	return 0;
}
