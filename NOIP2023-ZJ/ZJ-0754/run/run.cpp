#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t;
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);	
	cin>>c>>t;
	while(t--)
	{
		ll sum,n,m,k,d,x[100005],y[100005],v[100005];
		cin>>n>>m>>k>>d;
		for(int i=0;i<m;i++)
		{
			cin>>x[i]>>y[i]>>v[i];
			sum+=v[i];
		}
		cout<<sum-k*d<<'\n';
	}
	return 0;
}
