#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int orx[N],ory[N];
int x[N],y[N];
int xl,xr,yl,yr;
int nxl,nxr,xyl,nyr;
int c,n,m,q,chx,chy;
queue<int> xch,ych;

int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>orx[i];
		x[i]=orx[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>ory[i];
		y[i]=ory[i];
	}
	if((x[1]-y[1])*(x[n]-y[m])>0)
		cout<<1;
	else cout<<0;
	while(q--)
	{
		while(!xch.empty())
		{
			x[xch.front()]=orx[xch.front()];
			xch.pop();
		}
		while(!ych.empty())
		{
			y[ych.front()]=ory[ych.front()];
			ych.pop();
		}
		cin>>chx>>chy;
		for(int i=1,a,b;i<=chx;i++)
		{
			cin>>a>>b;
			x[a]=b;
			xch.push(a);
		}
		for(int i=1,a,b;i<=chy;i++)
		{
			cin>>a>>b;
			y[a]=b;
			ych.push(a);
		}
		
		if((x[1]-y[1])*(x[n]-y[m])>0)
			cout<<1;
		else cout<<0;
	}
	return 0;
}

