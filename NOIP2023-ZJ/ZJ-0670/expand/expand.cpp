#include<bits/stdc++.h>
using namespace std;
int x[200000],y[200000];
int c,n,m,q;

int headtailjudge()
{
	if((x[n]-y[m])*(x[1]-y[1])<=0)
	return 0;
	else
	return 1;
}


int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int kx,ky;
	int a1,a2;
	cin>>c>>n>>m>>q;
	if(c==1)
	{
		cin>>a1>>a2;
		if(a1==a2)
		cout<<0;
		else
		cout<<1;
		
		while(q)
		{
			cin>>kx>>ky;
			for(int i=1;i<=kx;i++)
			{
				cin>>a1;
				cin>>a1;
			}
			for(int j=1;j<=ky;j++)
			{
				cin>>a2;
				cin>>a2;
			}
			if(a1==a2)
			cout<<0;
			else
			cout<<1;
			
			q--;
		}
		return 0;
	}
	if(c==2)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int j=1;j<=m;j++)
		{
			cin>>y[j];
		}
		if(headtailjudge())
		cout<<1;
		else
		cout<<0;
		
		while(q)
		{
			cin>>kx>>ky;
			int x0,y0;
			for(int i=1;i<=kx;i++)
			{
				cin>>x0;
				cin>>x[x0];
			}
			for(int j=1;j<=ky;j++)
			{
				cin>>y0;
				cin>>y[y0];
			}
			if(headtailjudge())
			cout<<1;
			else
			cout<<0;
		
			q--;
		}
	return 0;
	
	}
 } 
