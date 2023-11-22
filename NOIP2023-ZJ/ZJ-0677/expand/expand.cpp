#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,n,m,q;
	cin>>c>>n>>m>>q;
	if(c==1)
	{
		int a,b;
		cin>>a>>b;
		int kx,ky;
		int px,vx,py,vy;
		for(int i=1;i<=q;i++)
		{
			cin>>kx>>ky;
			for(int i=1;i<=kx;i++)
			{
				cin>>px>>vx;
				cin>>py>>vy;
				a=vx;
				b=vy;
			}
			if(a!=b) cout<<"1";
			else cout<<"0";
		}
	}
	else if(c==2)
	{
		int a[3],b[3];
		for(int i=1;i<=2;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=2;i++)
		{
			cin>>b[i];
		}
		int kx,ky;
		int px,vx,py,vy;
		for(int i=1;i<=q;i++)
		{
			cin>>kx>>ky;
			for(int i=1;i<=kx;i++)
			{
				cin>>px>>vx;
				cin>>py>>vy;
				a[px]=vx;
				b[py]=vy;
			}
			if(a[1]>b[1]&&a[2]>b[2]||a[1]<b[1]&&a[2]<b[2])
			{
				cout<<"1";
			}
			else
			{
				cout<<"0";
			}
		}
	}
}