#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,q,x[500003],y[500003],xma=0,xmi=1000000009,yma=0,ymi=1000000009;
string s;
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);	
	cin>>c>>n>>m>>q;
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
		xma=max(xma,x[i]);
		xmi=min(xmi,x[i]);
	}
	for(int i=0;i<m;i++)
	{
		cin>>y[i];
		yma=max(yma,y[i]);
		ymi=min(ymi,y[i]);
	}
	if(c==1)
		if(y[0]==x[0])
			s+='0';
		else
			s+='1';
	if(c>=8&&c<=14)
	{
		for(int i=0;i<n;i++)
			if(x[i]>=y[m])
				s+='0';
			else
				s+='1';
	}
	else
	{
		if(xma>=yma&&xmi<=ymi||xma<=yma&&xmi>=ymi)
			s+='0';
		else
			s+='1';
	}
	while(q--)
	{
		ll xx[500005],yy[500005],kx,ky,px[500005],vx[500005],py[500005],vy[500005];
		for(int i=0;i<n;i++)
			xx[i]=x[i];
		for(int i=0;i<m;i++)
			yy[i]=y[i];
		for(int i=0;i<kx;i++)
		{
			cin>>px[i]>>vx[i];
			xx[px[i]]=vx[i];
			xma=max(xma,x[i]);
			xmi=min(xmi,x[i]);
		}
		for(int i=0;i<ky;i++)
		{
			cin>>py[i]>>vy[i];
			yy[py[i]]=vy[i];
			yma=max(yma,y[i]);
			ymi=min(ymi,y[i]);
		}
		if(c==1)
		{
			if(yy[0]==xx[0])
				s+='0';
			else 
				s+='1';
		}
		if(c>=8&&c<=14)
		{
			for(int i=0;i<n;i++)
				if(xx[i]>=yy[m])
					s+='0';
				else
					s+='1';
		}
		else if(xma>=yma&&xmi<=ymi||xma<=yma&&xmi>=ymi)
			s+='0';
		else
			s+='1';
	}
	cout<<s;
	return 0;
}
