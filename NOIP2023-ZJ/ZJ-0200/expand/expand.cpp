#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
int x[500005],y[500005];
int kx,ky;
int px[500005],vx[500005],py[500005],vy[500005];
int tx[500005],ty[500005];

bool dfs(int u,int v,int f)
{
	if((u==n)&&(v==m))
		return true;
	if((u<n)&&(((x[u+1]-y[v])*f)<0))
		if(dfs(u+1,v,f))
			return true;
	if((v<m)&&(((x[u]-y[v+1])*f)<0))
		if(dfs(u,v+1,f))
			return true;
	if((u<n)&&(v<m)&&(((x[u+1]-y[v+1])*f)<0))
		if(dfs(u+1,v+1,f))
			return true;
	return false;
}

void chk()
{
	if(((x[1]<=y[1])&&(x[n]>=y[m]))||((x[1]>=y[1])&&(x[n]<=y[m])))
	{
		cout<<0;
		return;
	}
	if((n<=2)&&(m<=2))
	{
		cout<<1;
		return;
	}
	int xmax=0,xmin=0x3f3f3f3f;
	int ymax=0,ymin=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
		xmax=max(x[i],xmax),xmin=min(x[i],xmin);
	for(int i=1;i<=m;i++)
		ymax=max(y[i],ymax),ymin=min(y[i],ymin);
	if(x[1]<y[1])
	{
		if((ymin>xmin)&&(ymax>xmax))
			if(dfs(1,1,1))
			{
				cout<<1;
				return;
			}
		cout<<0;
		return;
	}
	if(x[1]>y[1])
	{
		if((ymin<xmin)&&(ymax<xmax))
			if(dfs(1,1,-1))
			{
				cout<<1;
				return;
			}
		cout<<0;
		return;
	}
}

int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	for(int i=1;i<=m;i++)
		cin>>y[i];
	chk();
	while(q--)
	{
		cin>>kx>>ky;
		for(int i=1;i<=kx;i++)
		{
			cin>>px[i]>>vx[i];
			tx[i]=x[px[i]];
			x[px[i]]=vx[i];
		}
		for(int i=1;i<=ky;i++)
		{
			cin>>py[i]>>vy[i];
			ty[i]=y[py[i]];
			y[py[i]]=vy[i];
		}
		chk();
		for(int i=1;i<=kx;i++)
			x[px[i]]=tx[i];
		for(int i=1;i<=ky;i++)
			y[py[i]]=ty[i];
	}
	return 0;
}