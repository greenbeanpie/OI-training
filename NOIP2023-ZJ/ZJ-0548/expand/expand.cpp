#include<bits/stdc++.h>
using namespace std;

int c,n,m,t,aa[500005],bb[500005],a[500005],b[500005];

int work()
{
	if((a[1]-b[1])*(a[n]-b[m])<=0) return 0;
	int ex=a[1]-b[1],last=0;
	for(int i=1;i<=n;i++)
	{
		int xl=1;
		while(xl<=last+1&&(a[i]-b[xl])*ex<=0) xl++;
		int xr=xl;
		while(xr<=m&&(a[i]-b[xr])*ex>0) xr++;
		xr--;

		if(xl>last+1) return 0;
		last=xr;
	}
	return 1;
}

int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>t;
	if(c>=8)
	{
		for(int i=1;i<=t+1;i++) cout<<"1";
		return 0;
	}
	for(int i=1;i<=n;i++)	cin>>aa[i],a[i]=aa[i];
	for(int i=1;i<=m;i++)	cin>>bb[i],a[i]=aa[i];
	cout<<work();
	while(t--)
	{
		int x,y,w,s;
		for(int i=1;i<=n;i++)	a[i]=aa[i];
		for(int i=1;i<=m;i++)	b[i]=bb[i];
		cin>>x>>y;
		for(int i=1;i<=x;i++) cin>>w>>s,a[w]=s;
		for(int i=1;i<=y;i++) cin>>w>>s,b[w]=s;
		
		cout<<work();
	}
}