#include <bits/stdc++.h>
using namespace std;

int c,n,m,q,kx,ky,p,v;
int x[10],y[10];
void pd()
{
	if(c==1) cout<<"1";
	else if(c==2)
	{
		if((x[1]-y[1]) * (x[n]-y[m]) > 0) cout<<"1";
		else cout<<"0";
	}
}

int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	for(int i=1;i<=m;i++)
		cin>>y[i];
	if(c==1) cout<<"1";
	else if(c==2)
	{
		if((x[1]-y[1]) * (x[n]-y[m]) > 0) cout<<"1";
		else cout<<"0";
	}
	for(int i=1;i<=q;i++)
	{
		cin>>kx>>ky;
		for(int j=1;j<=kx;j++)
		{
			cin>>p>>v;
			x[p]=v;
		}
		for(int j=1;j<=ky;j++)
		{
			cin>>p>>v;
			y[p]=v;
		}
		pd();
	}
	cout<<endl;
	return 0;
}