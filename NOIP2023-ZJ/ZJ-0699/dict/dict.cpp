#include<bits/stdc++.h>
using namespace std;
int n,m;
string a[3500];
int p[3500],q[3500];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x=128,y=0;
		cin>>a[i];
		for(int j=0;j<m;j++)
			x=min(a[i][j]-'0',x),y=max(a[i][j]-'0',y);
		p[i]=x,q[i]=y;	
	}
	for(int i=1;i<=n;i++)
	{
		bool ans=1;
		for(int j=1;j<i;j++)
			if(p[i]>=q[j])
				ans=0;
		for(int j=i+1;j<=n;j++)
			if(p[i]>=q[j])
				ans=0;
		cout<<ans;
	}
}
