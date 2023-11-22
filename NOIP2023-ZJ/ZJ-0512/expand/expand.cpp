#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,n,m,q;
	cin>>c>>n>>m>>q;
	int x,y,xx,yy;
	cin>>x>>y;
	if(x!=y)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	for(int i=1;i<=q;i++)
	{
		xx=x;yy=y;
		int kx,ky;
		cin>>kx>>ky;
		if(kx==1)
		{
			int px,vx;
			cin>>px>>vx;
			xx=vx;
		}
		if(ky==1)
		{
			int py,vy;
			cin>>py>>vy;
			yy=vy;
		}
		if(xx!=yy)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	return 0;
}