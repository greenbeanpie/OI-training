#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int a[100005],b[100005],c[100005];
int n,k;
bool check(int v)
{
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		int l=0,r=n;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if(a[i]+b[i]*c[mid]>=v)
				r=mid-1;
			else
				l=mid;
		}
		cnt+=l;
	}
	return cnt<k;
}
signed main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i)
		cin>>b[i];
	for(int i=1;i<=n;++i)
		cin>>c[i];
	sort(c+1,c+1+n);
	cin>>k;
	int l=0,r=2e18;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	cout<<l;
}
