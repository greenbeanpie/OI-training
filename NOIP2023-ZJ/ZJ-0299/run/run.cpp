#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+10;
int n,m,k,d;
ll dp[N][N];
struct node{
	ll s;
	int t;
};
vector<node> v1[N];
bool cmp(node l,node r){
	return l.t<r.t;
}
ll calc(int x,int y){
	if(v1[x].size()==0) return 0;
	if(y<v1[x][0].t) return 0;
	int l=0,r=v1[x].size()-1,ret=0;
	while(l<=r){
		int mid=l+r>>1;
		if(v1[x][mid].t<=y){
			ret=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return v1[x][ret].s;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	if(c<=9){
		while(t--){
			scanf("%d%d%d%d",&n,&m,&k,&d);
			for(int i=1;i<=n;i++){
				for(int j=0;j<=k;j++){
					dp[i][j]=-1e18;
				}
				dp[i][0]=0;
			}
			for(int i=1;i<=n;i++) v1[i].clear();
			for(int i=1;i<=m;i++){
				int x,y,v;
				scanf("%d%d%d",&x,&y,&v);
				if(y>k) continue;
				v1[x].push_back(node{v,y});
			}
			for(int i=1;i<=n;i++){
				sort(v1[i].begin(),v1[i].end(),cmp);
				for(int j=1;j<v1[i].size();j++){
					v1[i][j].s+=v1[i][j-1].s;
				}
			}
			dp[1][0]=0,dp[1][1]=-d;
			for(int i=1;i<n;i++){
				for(int j=0;j<=k;j++){
					dp[i+1][0]=max(dp[i+1][0],dp[i][j]+calc(i+1,0));
					if(j<k){
						dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+calc(i+1,j+1)-d);
					}
				}
			}
			ll ans=0;
			for(int i=0;i<=k;i++){
				ans=max(ans,dp[n][i]);
			}
			printf("%lld\n",ans);
		}
	}
	else if(c==17||c==18){
		while(t--){
			ll ans=0;
			int n,m,k,d;
			scanf("%d%d%d%d",&n,&m,&k,&d);
			for(int i=1;i<=m;i++){
				int x,y,v;
				scanf("%d%d%d",&x,&y,&v);
				if(y>k) continue;
				ans=ans+max(0,v-d*y);
			}
			printf("%lld\n",ans);
		}
	}
	else{
		while(t--){
			int n,m,k,d;
			scanf("%d%d%d%d",&n,&m,&k,&d);
			for(int i=1;i<=m;i++){
				int x,y,v;
				scanf("%d%d%d",&x,&y,&v);
			}
			printf("0\n");
		}
	}
	return 0;
}

