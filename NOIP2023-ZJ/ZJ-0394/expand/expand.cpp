#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,q,x[N],y[N],px,py,hx,hy,v;
bool pd()
{
	return (x[1]<y[1]&&x[n]<y[m])||(x[1]>y[1]&&x[n]>y[m]);
}
signed main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>y[i];
	}
	if(c==1)
	{
		if(x[1]==y[1])
			cout<<0;
		else
			cout<<1;
		while(q--)
		{
			cin>>px>>py;
			for(int i=1;i<=px;i++)
			{
				cin>>hx>>v;
				x[1]=v;
			}
			for(int i=1;i<=py;i++)
			{
				cin>>hy>>v;
				y[1]=v;
			}
			if(x[1]==y[1])
				cout<<0;
			else
				cout<<1;
		}
	}
	else
	{
		if(!pd())
			cout<<0;
		else
			cout<<1;
		while(q--)
		{
			cin>>px>>py;
			for(int i=1;i<=px;i++)
			{
				cin>>hx>>v;
				x[1]=v;
			}
			for(int i=1;i<=py;i++)
			{
				cin>>hy>>v;
				y[1]=v;
			}
			if(!pd())
				cout<<0;
			else
				cout<<1;
		}
	}
	
	return 0;
}