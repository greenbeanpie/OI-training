#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,kx,ky,w,v,x[500005],y[500005],t[500005],px[500005],py[500005],maxx1,maxx2,minn1,minn2,kmax1,kmax2,kmin1,kmin2;
void work()
{
	if((px[1]-py[1])*(px[n]-py[m])<=0)cout<<0;
	else
	{	
		if(px[1]<py[1])
		{
			int h;
			if(m>n)h=m;
				else h=n;
			for(int i=1;i<=h;i++)
			{
				t[i]=px[i];
				px[i]=py[i];
				py[i]=t[i];
			}
		}
		maxx1=0;minn1=1e9+5;kmax1=1;kmin1=1;
		for(int i=1;i<=n;i++)
		{
			if(px[i]>maxx1)
			{
				maxx1=px[i];
				kmax1=i;
			}
			if(px[i]>minn1)
			{
				minn1=px[i];
				kmin1=i;
			}
		}
		maxx2=0;minn2=1e9+5;kmax2=1;kmin2=1;
		for(int i=1;i<=m;i++)
		{
			if(py[i]>maxx2)
			{
				maxx2=py[i];
				kmax2=i;
			}
			if(py[i]>minn2)
			{
				minn2=py[i];
				kmin2=i;
			}
		}
		if(maxx2>maxx1)cout<<0;
			else
			{
				int k1=1,k2=1;
				for(int i=2;i<kmax1;i++)
				{
					if(px[i]>px[k1])k1=i;
					if(px[i]<px[k2])k2=i;
				}
				int tx1=px[k1],tx2=px[k2];
				k1=1+kmax1;k2=kmax1;
				for(int i=kmax1+1;i<=n;i++)
				{
					if(px[i]>px[k1])k1=i;
					if(px[i]<px[k2])k2=i;
				}
				int ti1=px[k1],ti2=px[k2];
				
				k1=1;k2=1;
				for(int i=2;i<kmax2;i++)
				{
					if(py[i]>py[k1])k1=i;
					if(py[i]<py[k2])k2=i;
				}
				int ty1=py[k1],ty2=py[k2];
				k1=1+kmax2;k2=kmax2;
				for(int i=kmax2+1;i<=m;i++)
				{
					if(py[i]>py[k1])k1=i;
					if(py[i]<py[k2])k2=i;
				}
				int tj1=py[k1],tj2=py[k2];
				if(tx2<ty2||ti2<tj2)cout<<0;
					else cout<<1;
			}
	}
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=m;i++)cin>>y[i];
	for(int i=1;i<=n;i++)px[i]=x[i];
	for(int i=1;i<=m;i++)py[i]=y[i];
	work();
	for(int zth=1;zth<=q;zth++)
	{
		cin>>kx>>ky;
		for(int i=1;i<=n;i++)px[i]=x[i];
		for(int i=1;i<=m;i++)py[i]=y[i];
		for(int i=1;i<=kx;i++)
		{
			cin>>w>>v;
			px[w]=v;
		}
		for(int i=1;i<=ky;i++)
		{
			cin>>w>>v;
			py[w]=v;
		}
		work();
	}
	fclose(stdin);fclose(stdout);
	return 0;
}