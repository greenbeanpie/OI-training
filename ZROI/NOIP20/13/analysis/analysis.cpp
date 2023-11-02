#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[500001][2][2];
vector<int> to[500001];
int n,aa,bb;
int g[2][2];
#define inf LONG_LONG_MAX/10000 
void dfs(int x,int fa){
	f[x][0][0]=0;
	for(auto v:to[x]){
		if(v==fa)continue;
		dfs(v,x);
		g[0][0]=g[0][1]=g[1][0]=g[1][1]=inf;
		for(int a=0;a<=1;a++){
			for(int b=0;b<=1;b++){
				for(int c=0;c<=1;c++){
					for(int d=0;d<=1;d++){
						if(a==0 and c==0){
							g[1][b|d]=min(g[1][b|d],f[x][a][b]+f[v][c][d]+(b&d)*bb);
							g[0][b|d]=min(g[0][b|d],f[x][a][b]+f[v][c][d]+aa+(b&d)*bb);
						}
						if(a==0 and c==1){
							g[1][b|d]=min(g[1][b|d],f[x][a][b]+f[v][c][d]+(b&d)*bb);
							g[0][1]=min(g[0][1],f[x][a][b]+f[v][c][d]+(b|d)*bb+aa+(b&d)*bb);
						}
						if(a==1 and c==0){
							g[0][1]=min(g[0][1],f[x][a][b]+f[v][c][d]+(b|d)*bb+(b&d)*bb);
							g[1][b|d]=min(g[1][b|d],f[x][a][b]+f[v][c][d]+aa+(b&d)*bb);
						}
						if(a==1 and c==1){
							g[0][1]=min(g[0][1],f[x][a][b]+f[v][c][d]+(b|d)*bb+(b&d)*bb);
							g[1][1]=min(g[1][1],f[x][a][b]+f[v][c][d]+(b|d)*bb+aa+(b&d)*bb);
						}
					}
				}
			}
		}
		for(int a=0;a<=1;a++){
			for(int b=0;b<=1;b++)f[x][a][b]=g[a][b];
		}
	}
	return ;
}
signed main(){
#ifndef ONLINE_JUDGE
	freopen("analysis.in", "r", stdin);
	freopen("analysis.out", "w", stdout);
#endif
	cin>>n>>aa>>bb;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		to[u].push_back(v);
		to[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		f[i][0][0]=f[i][0][1]=f[i][1][0]=f[i][1][1]=inf;
	}
	dfs(1,0);
	int ans=LONG_LONG_MAX;
	for(int i=0;i<=1;i++){
		for(int j=0;j<=1;j++){
			ans=min(ans,f[1][i][j]+i*j*bb);
		}
	}
	cout<<ans<<endl;
	return 0;
}