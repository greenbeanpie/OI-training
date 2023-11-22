#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct point{
	ll day,val;
};
int C,T;
ll n,m,K,D;
ll f[5005][5005];
vector<point>g[5005];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C>>T;
	while(T--){
		memset(f,0,sizeof(f));
		if(C<=14){
			cin>>n>>m>>K>>D;
			for(int i=1;i<=n;i++){
				g[i].clear();
			}
			for(int i=1;i<=m;i++){
				ll x,y,z;
				cin>>x>>y>>z;
				g[x].push_back((point){y,z});
			}
			for(int i=1;i<=n;i++){
				//求f[i][0]
				f[i][0]=0;
				for(int j=0;j<=K&&i-j>=1;j++){
					f[i][0]=max(f[i][0],f[i-1][j]);
				}
				for(int j=1;j<=K&&i-j>=0;j++){
					f[i][j]=f[i-1][j-1]-D;
				}
				for(int j=0;j<g[i].size();j++){
					point v=g[i][j];
					for(int k=v.day;k<=K&&i-k>=0;k++)
					f[i][k]+=v.val;
				}
			}
			ll ans=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j<=K&&i-j>=0;j++){
					ans=max(ans,f[i][j]);
				}
			}
			cout<<ans<<"\n";
		}else{
			cout<<"0\n";
		}
	}
	return 0;
}
/*
1 1
3 2 2 1
2 2 4
3 2 3
*/