#include<bits/stdc++.h>
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr),std::cout.tie(nullptr);
	int c,t;
	for(std::cin>>c>>t;t--;){
		int n,m,k,d;
		long long ans=-0x7fffffffffffffff;
		std::cin>>n>>m>>k>>d;
		std::vector<std::vector<long long>>sum(n+1,std::vector<long long>(n+1));
		for(int i=0,x,y,v;i<m;++i)std::cin>>x>>y>>v,sum[x][x-y+1]+=v;
		for(int i=0;i<=n;++i)
			for(int j=n-1;j>=0;--j)sum[i][j]+=sum[i][j+1];
		std::function<void(int,int,long long)>dfs=[&](int day,int last,long long tot)->void{
			if(last<day)tot+=sum[day][last+1];
			if(day==n){ans=std::max(ans,tot);return;}
			dfs(day+1,day+1,tot);
			if(day-last+1<=k)dfs(day+1,last,tot-d);
		};
		dfs(0,0,0);
		std::cout<<ans<<'\n';
	}
	return 0;
}