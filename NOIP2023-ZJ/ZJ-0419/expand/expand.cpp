#include <iostream>
using namespace std;
int c,n,m,q,xmx=-1,xmn=1000000009,ymx=-1,ymn=1000000009;
int x[500001],y[500001];
int xx[500001],yy[500001];
int ans[61];
int fr()
{
//	char ch;
//	int w=0;
//	ch=getchar();
//	if(ch>='0' and ch<='9')
//		w=w*10+(ch-'0');
//	else
//		return w;
	int w;
	cin>>w;
	return w;
}
bool check(int tp,int r)
{
	if(tp==0)
		return false;
	else if(tp==1)
	{
		bool f=true;
		for(int i=1;i<=r;++i)
		{
			if(x[i]*tp<=y[i]*tp)
			{
				f=false;
				break;
			}
		}
		if(f)
			return true;
		for(int i=1;i<=r;++i)
		{
			xmx=max(x[i],xmx);
			xmn=min(x[i],xmn);
			ymx=max(y[i],ymx);
			ymn=min(y[i],ymn);
		}
		if(xmx*tp<=ymx*tp or xmn*tp<=ymn*tp or (x[n]*tp<=y[m]*tp and r==n))
			return false;
		int xi=1;
		for(xi=1;xi<=r;++xi)
		{
			if(tp==1 and x[xi]==xmx)
				break;
			if(tp==-1 and x[xi]==xmn)
				break;
		}
		for(int i=xi+1;i<=r;++i)
			if(x[i]*tp<=y[m]*tp)
				return false;
		return check(tp,xi-1);
	}
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	if(c==1)
	{
		int a,b;
		cin>>a>>b;
		ans[0]=(int)(a!=b);
		for(int st=1;st<=q;++st)
		{
			int kx,ky,p,v;
			cin>>kx>>ky;
			for(int i=1;i<=kx;++i)
			{
				cin>>p>>v;
				a=v;
			}
			for(int i=1;i<=ky;++i)
			{
				cin>>p>>v;
				b=v;
			}
			ans[st]=(int)(a!=b);
		}
	}
	if(c==2)
	{
		int a[3],b[3],a1[3],b1[3];
		cin>>a[1]>>a[2];
		cin>>b[1]>>b[2];
		if(a[1]==b[1] or a[2]==b[2])
			ans[0]=0;
		else if(a[1]>b[1])
			ans[0]=(int)(a[2]>b[2]);
		else
			ans[0]=(int)(a[2]<b[2]);
		for(int st=1;st<=q;++st)
		{
			a1[1]=a[1];a1[2]=a[2];
			b1[1]=b[1];b1[2]=b[2];
			int kx,ky,p,v;
			cin>>kx>>ky;
			for(int i=1;i<=kx;++i)
			{
				cin>>p>>v;
				a1[p]=v;
			}
			for(int i=1;i<=ky;++i)
			{
				cin>>p>>v;
				b1[p]=v;
			}
			if(a1[1]==b1[1] or a1[2]==b1[2])
				ans[0]=0;
			else if(a1[1]>b1[1])
				ans[0]=(int)(a1[2]>b1[2]);
			else
				ans[0]=(int)(a1[2]<b1[2]);
		}
	}
	else
	{
		for(int i=1;i<=n;++i)
		{
			xx[i]=fr();
			xmx=max(xx[i],xmx);
			xmn=min(xx[i],xmn);
		}
		for(int i=1;i<=m;++i)
		{
			yy[i]=fr();
			ymx=max(yy[i],ymx);
			ymn=min(yy[i],ymn);
		}
		for(int i=1;i<=n;++i)
			x[i]=xx[i];
		for(int i=1;i<=m;++i)
			y[i]=yy[i];
		if(x[1]==y[1])
			ans[0]=0;
		else if(x[1]>y[1])
			ans[0]=check(1,n);
		else
			ans[0]=check(-1,n);
		for(int st=1;st<=q;++st)
		{
			for(int i=1;i<=n;++i)
				x[i]=xx[i];
			for(int i=1;i<=m;++i)
				y[i]=yy[i];
			int kx,ky,p,v;
			kx=fr();ky=fr();
			for(int i=1;i<=kx;++i)
			{
				p=fr();v=fr();
				x[p]=v;
				xmx=max(x[p],xmx);
				xmn=min(x[p],xmn);
			}
			for(int i=1;i<=ky;++i)
			{
				p=fr();v=fr();
				y[p]=v;
				ymx=max(y[p],ymx);
				ymn=min(y[p],ymn);
			}
			if(x[1]==y[1])
				ans[st]=0;
			else if(x[1]>y[1])
				ans[st]=check(1,n);
			else
				ans[st]=check(-1,n);
		}
	}
	for(int i=0;i<=q;++i)
		cout<<ans[i];
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
