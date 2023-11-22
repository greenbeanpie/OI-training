#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define LL long long
#define pii pair<int,int>
using namespace std;
const int N=1e5+10;
LL c,t,n,m,k,d,ans,ex[N],ey[N],ev[N],dp[10005][1005];
struct num{
	LL x,y,v;
}e[N];
void dfs(LL days,LL g,LL lian){
	if(days>n){
		ans=max(ans,g);
		return ;
	}
	if(lian<k){
		LL data=0;
		lian++;
		for(int i=1;i<=m;i++){
			if(ex[i]!=days)continue;
			if(lian>=ey[i])data+=ev[i];
		}
		dfs(days+1,g+data-d,lian);
	}
	dfs(days+1,g,0);
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	if(c<=2){
		LL x,y,v;
	while(t--){
		memset(ex,0,sizeof ex);
		memset(ey,0,sizeof ey);
		memset(ev,0,sizeof ev);
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++){
			cin>>ex[i]>>ey[i]>>ev[i];
		}
		dfs(1,0,0);
		cout<<ans<<endl;
	}
	} 
	else{
		LL x,y,v;
		while(t--){
			cin>>n>>m>>k>>d;
			for(int i=1;i<=m;i++){
				e[i].x=e[i].y=e[i].v=0;
			}
			for(int i=1;i<=m;i++){
				cin>>x>>y>>v;
				e[i].x=x;
				e[i].y=y;
				e[i].v=v;
			}
			for(int i=1;i<=n;i++){
			for(int j=0;j<=i&&j<=k;j++){
				if(j==0){
					for(int u=0;u<=i;u++){
						dp[i][j]=max(dp[i][j],dp[i-1][u]);
					}
					ans=max(ans,dp[i][j]);
				}
				else{
						LL data=0;
						for(int k=1;k<=m;k++){
							if(i-1!=e[k].x)continue;
							if(j-1>=e[k].y)data+=e[k].v;
							}
						dp[i][j]=max(dp[i][j],dp[i-1][j-1]+data-d);
//					dp[i][j]=max(dp[i][j],dp[i-1][0]);
						ans=max(ans,dp[i][j]);
				}
				
			}
		}
		cout<<ans<<endl;
		} 
	}
	return 0;
}

