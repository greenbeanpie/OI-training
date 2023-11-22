#include <bits/stdc++.h>
#include <cstring>
using namespace std;
typedef long long int LL;
const int N = 5e5+5;
int c,n,m,q;
int a[N],b[N];
int ta[N],tb[N];
string ans="";
void read()
{
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ta[i]=a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		tb[i]=b[i];
	}
}
bool check_fu()
{
	int bmaxn=-INT_MAX,pos=1;
	for(int i=1;i<=m;i++)
	{
		if(bmaxn<tb[i])
		{
			bmaxn=tb[i];
			pos=i;
		}
	}
	for(int i=1;i<pos;i++)
		if(tb[i]<=ta[1]) return 0;
	for(int i=pos+1;i<=m;i++)
		if(tb[i]<=ta[n]) return 0;
	return 1;
}bool check_zheng()
{
	int bminn=INT_MAX,pos=1;
	for(int i=1;i<=m;i++)
	{
		if(bminn>tb[i])
		{
			bminn=tb[i];
			pos=i;
		}
	}
	for(int i=1;i<pos;i++)
		if(tb[i]>=ta[1]) return 0;
	for(int i=pos+1;i<=m;i++)
		if(tb[i]>=ta[n]) return 0;
	return 1;
}
void solve()
{
	if(check_zheng()||check_fu())
	{
		ans+="1";
		return;
	}
	ans+="0";
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	read();
	solve();
	while(q--)
	{
		int kx,ky,p,v;
		cin>>kx>>ky;
		for(int i=1;i<=n;i++)
		{
			ta[i]=a[i];
		}
		for(int i=1;i<=m;i++)
		{
			tb[i]=b[i];
		}
		for(int i=1;i<=kx;i++)
		{
			cin>>p>>v;
			ta[p]=v;
		}
		for(int i=1;i<=ky;i++)
		{
			cin>>p>>v;
			tb[p]=v;
		}
		debug();
		solve();
	}
	cout<<ans;
	cout<<"\n";
	return 0;
}
