#include<bits/stdc++.h>
using namespace std;
long long c,n,m,q,x[500005],y[500005],yb[500005];
long long x_i=1000000005,y_i=1000000005,x_id,y_id;
bool flag;
long long xx[500005],yy[500005];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		if(x[i]<x_i)
		{
			x_i=x[i];
			x_id=i;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>y[i];
		if(y[i]<y_i)
		{
			y_i=y[i];
			y_id=i;
		}
	}
//	cout<<x_id<<endl;
//	if(c>=8&&c<=14)
//	{
//		if(y_i<=x_i)
//		{
//			cout<<0;
//			return 0;
//		}
//		long long j=1;
//		for(int i=1;i<=m;i++)
//		{
//			while(y[i]>x[j]&&j<=x_id)j++;
////			cout<<j<<'\n';
//			if(j>x_id)
//			{
//				
//				cout<<1;
//			}
//		}
//		return 0;
//	}
	if(y[1]<x[1])
	{
		swap(x,y);
		swap(n,m);
		swap(x_i,y_i);
		swap(x_id,y_id);
		flag=1;
	}
	if(y[1]==x[1]||y[m]<=x[n]||y_i<=x_i)
	{
		cout<<0;
	}
	else
	{
		long long lb=m+1,rb=0,j=1;
		for(int i=1;i<=m;i++)
		{
//			cout<<i<<' '<<j<<'\n';
			while(y[i]>x[j]&&j<=x_id)j++;
//			cout<<i<<' '<<j<<'\n';
			if(j>x_id)
			{
				lb=i;
				break;
			}
		}
		j=n;
		for(int i=m;i>=lb;i--)
		{
//			cout<<j<<' '<<x_i<<' '<<n<<'\n';
			while(y[i]>x[j]&&j>=x_id)j--;
//			cout<<j<<'\n';
			if(j<x_id)
			{
				rb=i;
				break;
			}
			
		}
//		cout<<lb<<' '<<rb<<'\n';
		if(lb<=rb)
			cout<<1;
		else
			cout<<0;
	}
	
	
	long long xx_i=1000000005,xx_id,yy_i=1000000005,yy_id;
	while(q--)
	{
		long long kx,ky;
		bool flagg=0;
		cin>>kx>>ky;
		for(int i=1;i<=n;i++)
			xx[i]=x[i];
		for(int i=1;i<=m;i++)
			yy[i]=y[i];
		if(flag)
		{
			swap(kx,ky);
			for(int i=1;i<=ky;i++)
			{
				long long p,v;
				cin>>p>>v;
				yy[p]=v;
			}
			for(int i=1;i<=kx;i++)
			{
				long long p,v;
				cin>>p>>v;
				xx[p]=v;
			}
		}
		else
		{
			for(int i=1;i<=kx;i++)
			{
				long long p,v;
				cin>>p>>v;
				xx[p]=v;
			}
			for(int i=1;i<=ky;i++)
			{
				long long p,v;
				cin>>p>>v;
				yy[p]=v;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(xx[i]<xx_i)
			{
				xx_i=xx[i];
				xx_id=i;
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(yy[i]<yy_i)
			{
				yy_i=yy[i];
				yy_id=i;
			}
		}
		if(yy[1]<xx[1])
		{
			swap(xx,yy);
//			swap(n,m);
			swap(xx_i,yy_i);
			swap(xx_id,yy_id);
			flagg=1;
		}
		if(yy[1]==xx[1]||yy[m]<=xx[n]||yy_i<=xx_i)
		{
			cout<<0;
		}
		else
		{
			long long lb=m+1,rb=0,j=1;
			for(int i=1;i<=m;i++)
			{
//				cout<<i<<' '<<j<<'\n';
				while(yy[i]>xx[j]&&j<=xx_id)j++;
//				cout<<i<<' '<<j<<'\n';
				if(j>xx_id)
				{
					lb=i;
					break;
				}
			}
			j=n;
			for(int i=m;i>=lb;i--)
			{
//				cout<<j<<' '<<x_i<<' '<<n<<'\n';
				while(yy[i]>xx[j]&&j>=xx_id)j--;
//				cout<<j<<'\n';
				if(j<xx_id)
				{
					rb=i;
					break;
				}
				
			}
//			cout<<lb<<' '<<rb<<'\n';
			if(lb<=rb)
				cout<<1;
			else
				cout<<0;
		}
	}
	return 0;
}

