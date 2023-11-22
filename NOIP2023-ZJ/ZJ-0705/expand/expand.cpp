#include<bits/stdc++.h>

using namespace std;

const int N=5e5+10;

int c,n,m,q;
int x[N],y[N];
int mx,mn=INT_MAX;
string ans;

bool judge()
{
	int i=1,j=1;
	//cout<<mx<<endl;
	//cout<<mn<<endl;
	if(mx>=y[m]) return false;
	else if(mn<=x[n]) return false;
	
	while(i<n-1&&j<m-1)
	{
		while(i<n-1&&x[i]>x[i+1]) i++;
		while(j<m-1&&y[j]<y[j+1]) j++;
		while(i<n-1&&x[i]<x[i+1]&&x[i+1]<y[j]) i++;
		while(j<m-1&&y[j]>y[j+1]&&y[j+1]>x[i]) j++;
		//cout<<j<<endl;
		if(i!=n-1&&j!=m-1)
			if(x[i+1]<y[j]||x[i]<y[j+1]||x[i+1]<y[j+1])
				continue;
			else return false;
	}
	return true;
}

int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		if(x[i]>mx) mx=x[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>y[i];
		if(y[i]<mn) mn=y[i];
	}
	
	if(c==1)
	{
		ans+='1';
		while(q--)
		{
			int kx,ky;
			cin>>kx>>ky;
			for(int i=1;i<=kx;i++)
			{
				int px,vx;
				cin>>px>>vx;
				x[px]=vx;
			}
			for(int i=1;i<=ky;i++)
			{
				int py,vy;
				cin>>py>>vy;
				y[py]=vy;
			}
			ans+='1';
		}
	}
	else
	{
		if(judge()==true) ans+='1';
		else ans+='0';
		while(q--)
		{
			int kx,ky;
			cin>>kx>>ky;
			for(int i=1;i<=kx;i++)
			{
				int px,vx;
				cin>>px>>vx;
				x[px]=vx;
			}
			for(int i=1;i<=ky;i++)
			{
				int py,vy;
				cin>>py>>vy;
				y[py]=vy;
			}
			if(judge()==true) ans+='1';
			else ans+='0';
		}
	}
	cout<<ans<<endl;
	return 0;
}
