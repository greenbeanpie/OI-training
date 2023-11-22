#include <bits/stdc++.h>
  using namespace std;
int c,n,m,q,a[500005],b[500005],x,y,u,v;
signed main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin>>c>>n>>m>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	if (n==1 && m==1)
	{
		if (a[1]==b[1]) cout<<1;
		else cout<<0;
		while (q--)
		{
			cin>>x>>y;
			for (int i=1;i<=n;i++)
			{
				cin>>u>>v;
				a[u]=v;
			}
			for (int i=1;i<=n;i++)
			{
				cin>>u>>v;
				b[u]=v;
			}
			if (a[1]==b[1]) cout<<1;
			else cout<<0;
		}
	}
	else if (c==2)
	{
		if (n==1 && m==2)
		{
			if (b[1]==a[1] && b[2]==a[1]) cout<<1;
			else cout<<0;
			while (q--)
			{
				cin>>x>>y;
				for (int i=1;i<=n;i++)
				{
					cin>>u>>v;
					a[u]=v;
				}
				for (int i=1;i<=n;i++)
				{
					cin>>u>>v;
					b[u]=v;
				}
				if (b[1]==a[1] && b[2]==a[1]) cout<<1;
				else cout<<0;
			}
		}
		if (n==2 && m==1)
		{
			if (a[1]==b[1] && a[2]==b[1]) cout<<1;
			else cout<<0;
			while (q--)
			{
				cin>>x>>y;
				for (int i=1;i<=n;i++)
				{
					cin>>u>>v;
					a[u]=v;
				}
				for (int i=1;i<=n;i++)
				{
					cin>>u>>v;
					b[u]=v;
				}
				if (a[1]==b[1] && a[2]==b[1]) cout<<1;
				else cout<<0;
			}
		}
	}
	cout<<endl;
	return 0;
}

