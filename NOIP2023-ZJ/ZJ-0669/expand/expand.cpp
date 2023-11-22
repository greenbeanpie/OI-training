#include<bits/stdc++.h>
using namespace std;
long long n,m,q,c;
bool check;
int k1,k2;
int x[100001],y[100001];
int kx[100001],ky[100001];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)
	cin>>x[i];
	for(int i=1;i<=m;i++)
	cin>>y[i];
	for(int i=1;i<=n;i++)
	kx[i]=x[i];
	for(int i=1;i<=m;i++)
	ky[i]=y[i];
	if(kx[1]==ky[1])
	cout<<0;
	if(kx[n]==ky[m])
	cout<<0;
	if(n==1&&m==1)
	{
		cout<<1;
	}
	if(n==2&&m==1)
	{
		if(kx[1]>ky[1]&&kx[2]>ky[1])
		cout<<1;
		else if(kx[1]<ky[1]&&kx[2]<ky[1])
		cout<<1;
		else
		cout<<0;
	}
	if(m==2&&n==1)
	{
		if(ky[1]>kx[1]&&ky[2]>kx[1])
		cout<<1;
		else if(ky[1]<kx[1]&&ky[2]<kx[1])
		cout<<1;
		else
		cout<<0;
	}
	while(q--)
	{
		if(n==1&&m==1)
		{
			cout<<1;
			continue;
		}
		if(n==2&&m==1)
	{
		if(kx[1]>ky[1]&&kx[2]>ky[1])
		cout<<1;
		else if(kx[1]<ky[1]&&kx[2]<ky[1])
		cout<<1;
		else
		cout<<0;
		continue;
	}
	if(m==2&&n==1)
	{
		if(ky[1]>kx[1]&&ky[2]>kx[1])
		cout<<1;
		else if(ky[1]<kx[1]&&ky[2]<kx[1])
		cout<<1;
		else
		cout<<0;
	}
		for(int i=1;i<=n;i++)
		kx[i]=x[i];
		for(int i=1;i<=m;i++)
		ky[i]=y[i];
		cin>>k1>>k2;
		for(int i=1;i<=k1;i++)
		{
			int p,v;
			cin>>p>>v;
			kx[p]=v;
		}
		for(int i=1;i<=k2;i++)
		{
			int p,v;
			cin>>p>>v;
			ky[p]=v;
		}
		if(kx[1]==ky[1])
		cout<<0;
		if(kx[n]==ky[m])
		cout<<0;
	}
}
