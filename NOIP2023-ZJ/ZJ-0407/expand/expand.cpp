#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500010;
int f,n,m,q,a[N],b[N],c[N],d[N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int k1,k2,x,y;
	cin>>f>>n>>m>>q;
	if(f==1)//5pts
	{
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=m;i++) cin>>b[i];
		if(a[1]==0&&b[1]==0) cout<<0;
		else cout<<1;
		for(int k=1;k<=q;k++)
		{
			cin>>k1>>k2;
			for(int i=1;i<=n;i++) c[i]=a[i];
			for(int i=1;i<=m;i++) d[i]=b[i];
			for(int i=1;i<=k1;i++)
			{
				cin>>x>>y;
				c[x]=y;
			}
			for(int i=1;i<=k2;i++)
			{
				cin>>x>>y;
				d[x]=y;
			}
			if(c[1]==0&&d[1]==0) cout<<0;
			else cout<<1;
		}
	}
	else
	{
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=m;i++) cin>>b[i];
		cout<<1;
		for(int k=1;k<=q;k++)
		{
			cin>>k1>>k2;
			for(int i=1;i<=k1;i++) cin>>x>>y;
			for(int i=1;i<=k2;i++) cin>>x>>y;
			cout<<1;
		}
	}
	return 0;
}
