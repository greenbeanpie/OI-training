#include<bits/stdc++.h>
#define int long long
#define forr(i,l,r) for(int i=l;i<=r;i++)
#define ffor(i,l,r) for(int i=l;i>=r;i--)
using namespace std;
const int N=1e5+10;
int a[N],b[N];
signed main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,q,x,y,dd,ff;
	cin>>c>>n>>m>>q;
	if(c==1)
	{
		cin>>a[1]>>b[1];
		cout<<(a[1]==b[1]?0:1);
		while(q--)
		{
			cin>>x>>y;
			while(x--)
			{
				cin>>dd>>ff;
				a[1]=ff;
			}
			while(y--)
			{
				cin>>dd>>ff;
				b[1]=ff;
			}
			cout<<(a[1]==b[1]?0:1);
		}
		cout<<'\n';
		return 0;
	}
	if(c==2)
	{
		forr(i,1,n)
		{
			cin>>a[i];
		}
		forr(i,1,m)
		{
			cin>>b[i];
		}
		if(n<m)
		{
			cout<<((a[1]-b[1])*(a[1]-b[2])>0?1:0);
			while(q--)
			{
				cin>>x>>y;
				while(x--)
				{
					cin>>dd>>ff;
					a[1]=ff;
				}
				while(y--)
				{
					cin>>dd>>ff;
					b[dd]=ff;
				}
				cout<<((a[1]-b[1])*(a[1]-b[2])>0?1:0);
			}
		}
		if(m<n)
		{
			cout<<((b[1]-a[1])*(b[1]-a[2])>0?1:0);
			while(q--)
			{
				cin>>x>>y;
				while(x--)
				{
					cin>>dd>>ff;
					a[dd]=ff;
				}
				while(y--)
				{
					cin>>dd>>ff;
					b[dd]=ff;
				}
				cout<<((b[1]-a[1])*(b[1]-a[2])>0?1:0);
			}
		}
		if(m==n)
		{
			cout<<((b[1]-a[1])*(b[2]-a[2])>0?1:0);
			while(q--)
			{
				cin>>x>>y;
				while(x--)
				{
					cin>>dd>>ff;
					a[dd]=ff;
				}
				while(y--)
				{
					cin>>dd>>ff;
					b[dd]=ff;
				}
				cout<<((b[1]-a[1])*(b[2]-a[2])>0?1:0);
			}
		}
		return 0;
	}
}
