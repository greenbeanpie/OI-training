#include<bits/stdc++.h>
using namespace std;
long long int c,t,n,m,k,d,x,y,v,ans;
vector<pair<long long int,long long int> > chall[10005];
long long int f[10005][10005],num[10005];
int main()
{
	freopen("run.in","r",stdin);freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m>>k>>d;
		ans=0;memset(f,0,sizeof(f));
		for(int i=0;i<=n;++i) chall[i].clear();
		while(d--)
		{
			cin>>x>>y>>v;++num[x];
			chall[x].push_back(make_pair(y,v));
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<=k;++j) f[i][j+1]=f[i-1][j]-d,f[i][0]=max(f[i][0],f[i-1][j]);
			for(int j=0;j<num[i];++j) 
				for(int l=chall[i][j].first;l<=k;++l) f[i][l]+=chall[i][j].second;
		}
		for(int i=0;i<=k;++i) ans=max(ans,f[n][k]);
		cout<<ans<<'\n';
	}
	return 0;
}