#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
int c,t;
int n,m,k,d;
int x[N],y[N],v[N];
ll ans;
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m>>k>>d;
		ans=0;
		for(int i=1;i<=m;i++)
		{
			cin>>x[i]>>y[i]>>v[i];
		}
		for(int i=1;i<=m;i++)
		{
			int day=y[i];
			if(day*d<v[i]&&day<=k) ans+=(v[i]-day*d);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
