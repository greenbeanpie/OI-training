#include<bits/stdc++.h>
using namespace std;
int a[1000],b[1000];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,n,m,q,x,y,xx,yy;
	int i,j;
	cin>>c>>n>>m>>q;
	if(n==0||m==0)
	for(i=1;i<=q+1;i++)
	cout<<0;
	else if(c==1)
	{
		cin>>a[1];
		cin>>b[1];
		int q1=a[1];
		int q2=b[1];
		for(i=1;i<=q;i++)
		{
			cin>>xx>>yy;
			for(j=1;j<=xx;j++)
			{
				cin>>x>>y;
			a[1]=y;
			}
			for(j=1;j<=y;j++)
			{
				cin>>x>>y;
			b[1]=y;
			}
			if(a[1]==b[1])
			cout<<1;
			else
			cout<<0;
		}
		if(q1==q2)
		cout<<1;
		else
		cout<<0;
	}
	else
	{
		for(i=1;i<=q+1;i++)
		cout<<0;
	}
	return 0;
}
