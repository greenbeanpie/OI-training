#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,a[500100],b[500500],ta[500500],tb[500500];
void read()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
}
void proc()
{
	if((ta[1]-tb[1])>0!=(ta[n]-tb[m])>0||ta[1]==tb[1]||ta[n]==tb[m])
	{
		cout<<"0";
		return;
	}
	cout<<"1";
}
int main()
{
    read();
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>a[i];
		ta[i]=a[i];
	}
	for(int j=1;j<=m;j++)
	{
		cin>>b[i];
		tb[i]=b[i];
	}
	proc();
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		while(x--)
		{
			int p,k;
			cin>>p>>k;
			ta[p]=k;
		}
		while(y--)
		{
			int p,k;
			cin>>p>>k;
			tb[p]=k;
		}
		proc();
		for(int i=1;i<=n;i++)
		{
			ta[i]=a[i];
		}
		for(int j=1;j<=m;j++)
		{
			tb[i]=b[i];
		}
	}
	cout<<endl;
	return 0;
}

