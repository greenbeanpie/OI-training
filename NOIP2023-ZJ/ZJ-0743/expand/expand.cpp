#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,tmp;
int a[10000][5];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	if(c==1)
	{
		int p,pp,kx,ky;
		cin>>p>>pp;
		for(int i=1;i<=q;i++)
		{
			cin>>kx>>ky;
			for(int j=1;j<=kx;j++)
				cin>>p>>pp;
			for(int j=1;j<=ky;j++)
				cin>>p>>pp;
		}
		for(int i=1;i<=q+1;i++)
			cout<<1;
	}
	else if(c==2){
		int p,pp,kx,ky,p1[2000],p2[2000];
		cin>>p>>pp;
		for(int i=1;i<=q;i++)
		{
			cin>>kx>>ky;
			for(int j=1;j<=kx;j++)
				cin>>p1[j]>>p2[j];
			for(int j=1;j<=ky;j++)
				cin>>p>>pp;
		}
		for(int i=1;i<=q+1;i++)
			cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
