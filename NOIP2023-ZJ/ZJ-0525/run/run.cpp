#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
struct node{
	int w,v;
	bool operator <(const node &rhs)const{return w<rhs.w;}
};
vector<node> task[1005];
int cur[1005];
int dp[1005][1005];
int dp2[100005][105];
node tasks[100005];
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c<=9){
		while(t--){
			memset(dp,0,sizeof(dp));
			memset(cur,0,sizeof(cur));
			int n,m,k,d;
			cin>>n>>m>>k>>d;
			for(int i=1;i<=n;i++) task[i].clear();
			for(int i=1;i<=m;i++){
				int x,y,v;
				cin>>x>>y>>v;
				node tmp;
				tmp.w=y,tmp.v=v;
				task[x].push_back(tmp);
			}
			for(int i=1;i<=n;i++) if(task[i].size()>0)sort(task[i].begin(),task[i].end());
			for(int i=1;i<=n;i++)
				for(int j=1;j<task[i].size();j++) task[i][j].v+=task[i][j-1].v;
			for(int i=1;i<=n;i++){
				for(int j=0;j<=min(i-1,k);j++) dp[i][0]=max(dp[i][0],dp[i-1][j]);
				for(int j=1;j<=min(i,k);j++){
					dp[i][j]=dp[i-1][j-1]-d;
					if(task[i].size()==0) continue;
					while(task[i][cur[i]].w<=j and cur[i]<task[i].size())cur[i]++;
					if(cur[i]>0) dp[i][j]+=task[i][cur[i]-1].v;
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++)
				for(int j=0;j<=n;j++) ans=max(ans,dp[i][j]);
			cout<<ans<<endl;
		}
	}
}