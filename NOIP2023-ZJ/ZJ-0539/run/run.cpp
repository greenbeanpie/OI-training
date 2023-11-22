#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t,n,k,d,m;
	cin>>c>>t;
	while(t--)
	{
		int ans=0;
		cin>>n>>m>>k>>d;
		for(int u,v,w,i=1;i<=m;i++)
		{
			cin>>u>>v>>w;
			ans+=w;
		}
		ans-=n*d;
		cout<<ans<<endl;
	}
	return 0;
}
