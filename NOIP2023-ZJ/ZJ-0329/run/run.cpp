#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T,n,m,k,d,f[1010][1010],g[1010][1010];
vector<pair<int,int> >e[100010];
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		for(int i=1;i<=n;i++)e[i].clear();
		cin>>n>>m>>k>>d;
		for(int i=1,x,y,v;i<=m;i++){
			cin>>x>>y>>v;
			e[x].push_back({y,v});
		}
		for(int i=0;i<=n;i++)
		for(int j=0;j<=k;j++)g[i][j]=0;
		for(int i=1;i<=n;i++)
		for(auto j:e[i])g[i][j.first]+=j.second;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
		g[i][j]+=g[i][j-1];
		for(int i=0;i<=n;i++)
		for(int j=0;j<=k;j++)f[i][j]=-1e18;
		f[0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=k;j++){
				f[i][0]=max(f[i][0],f[i-1][j]);
				if(j>0)f[i][j]=max(f[i][j],f[i-1][j-1]-d+g[i][j]);
			}
			
		}
		int res=0;
		for(int j=0;j<=k;j++)res=max(res,f[n][j]);
		cout<<res<<'\n';
	}
}