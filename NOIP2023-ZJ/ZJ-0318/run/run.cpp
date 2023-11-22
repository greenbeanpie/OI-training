#include<bits/stdc++.h>
using namespace std;
struct node{
	long long y,z;
}p;
long long c,T,n,m,k,d,x,y,z,dp[1005][1005];
vector<node>v[1005];
long long get(long long day,long long lian){
	long long ans=0;
	for(long long i=0;i<v[day].size();i++){
		y=v[day][i].y,z=v[day][i].z;
		if(lian>=y) ans+=z;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>m>>k>>d;
		for(long long i=0;i<=n+1;i++){
			v[i].clear();
		}
		memset(dp,-0x7f,sizeof(dp));
		for(long long i=1;i<=m;i++){
			cin>>x>>p.y>>p.z; 
			v[x].push_back(p);
		}
		dp[0][0]=0;
		for(long long i=1;i<=n;i++){
			for(long long j=0;j<=k;j++){
				dp[i][0]=max(dp[i][0],dp[i-1][j]);
			}//don't run
			for(long long j=1;j<=k;j++){
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+get(i,j)-d);
			}
		}
		long long maxx=0;
		for(long long i=0;i<=k;i++){
			maxx=max(maxx,dp[n][i]);
		}
		cout<<maxx<<"\n";
	}
	
	return 0;
}//10:33 36pts 11:10 choc kaipai 3min found mistake 11:30 big
/*
ohhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
*/
