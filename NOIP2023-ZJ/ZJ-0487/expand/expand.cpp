#include<bits/stdc++.h>
using namespace std;
int a[200020],b[200020],ta[200020],tb[200020],qq[200020],h=0;
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,n,m,q;
	cin>>c>>n>>m>>q;
	if(c==1)
	{
		int a1,b1,ta,tb,qq[650],h=0;
		cin>>a1>>b1;
		ta=a1;
		tb=b1;
		if(a1!=b1) qq[++h]=1;
		else qq[++h]=0;
		
		for(int i=1;i<=q;i++)
		{
			int kx,ky;
			cin>>kx>>ky;
			int p,v;
			for(int j=1;j<=kx;j++)
			{
				cin>>p>>v;
			}
			if(v!=b1) qq[++h]=1;
			else qq[++h]=0;
			for(int j=1;j<=ky;j++)
			{
				cin>>p>>v;
			}
			if(a1!=v) qq[++h]=1;
			else qq[++h]=0;
		}
		for(int i=1;i<=h;i++) cout<<qq[i];
		cout<<endl;
		return 0;
	}
	if(c==2)
	{
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int j=1;j<=m;j++) cin>>b[j];
		if(a[1]==b[1]) qq[++h]=0;
		else if(a[1]>b[1]&&a[n]<b[m]) qq[++h]=0;
		else if(a[1]<b[1]&&a[n]>b[m]) qq[++h]=0;
		else if(a[n]==b[m]) qq[++h]=0;
		else qq[++h]=1;
		for(int i=1;i<=q;i++)
		{
			for(int j=1;j<=n;j++) ta[j]=a[j];
			for(int j=1;j<=m;j++) tb[j]=b[j];
			int kx,ky;
			cin>>kx>>ky;
			for(int j=1;j<=kx;j++)
			{
				int p,v;
				cin>>p>>v;
				ta[p]=v;
			}
			for(int j=1;j<=ky;j++)
			{
				int p,v;
				cin>>p>>v;
				tb[p]=v;
			}
			if(ta[1]==tb[1]) qq[++h]=0;
			else if(ta[1]>tb[1]&&ta[n]<tb[m]) qq[++h]=0;
			else if(ta[1]<tb[1]&&ta[n]>tb[m]) qq[++h]=0;
			else if(ta[n]==tb[m]) qq[++h]=0;
			else qq[++h]=1;
		}
		for(int i=1;i<=h;i++) cout<<qq[i];
		cout<<endl;
		return 0;
	}
	if(c>2)
	{
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int j=1;j<=m;j++) cin>>b[j];
		if(a[1]==b[1]) qq[++h]=0;
		else if(a[1]>b[1]&&a[n]<b[m]) qq[++h]=0;
		else if(a[1]<b[1]&&a[n]>b[m]) qq[++h]=0;
		else if(a[n]==b[m]) qq[++h]=0;
		else qq[++h]=1;
		for(int i=1;i<=q;i++)
		{
			for(int j=1;j<=n;j++) ta[j]=a[j];
			for(int j=1;j<=m;j++) tb[j]=b[j];
			int kx,ky;
			cin>>kx>>ky;
			for(int j=1;j<=kx;j++)
			{
				int p,v;
				cin>>p>>v;
				ta[p]=v;
			}
			for(int j=1;j<=ky;j++)
			{
				int p,v;
				cin>>p>>v;
				tb[p]=v;
			}
			if(ta[1]==tb[1]) qq[++h]=0;
			else if(ta[1]>tb[1]&&ta[n]<tb[m]) qq[++h]=0;
			else if(ta[1]<tb[1]&&ta[n]>tb[m]) qq[++h]=0;
			else if(ta[n]==tb[m]) qq[++h]=0;
			else qq[++h]=1;
		}
		for(int i=1;i<=h;i++) cout<<qq[i];
		cout<<endl;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
