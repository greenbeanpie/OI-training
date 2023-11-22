#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=0x3f3f3f3f3f3f3f3f;
struct AAA{
	int x,y,v;
	bool operator<(const AAA& aa)const{return (x<aa.x);}
}a[100005];
int dp[1005][1005],mx[1005];
bool cmp(const AAA& aa,const AAA& bb){return (aa.y<bb.y);}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int c,T;
	cin >> c >> T;
	while(T--){
		memset(dp,-0x3f,sizeof(dp));
		int n,m,k,d;
		cin >> n >> m >> k >> d;
		for(int i=0;i<m;++i) cin >> a[i].x >> a[i].y >> a[i].v;
		sort(a,a+m);
		dp[0][0]=0;
		int pos=0;
		for(int i=1;i<=n;++i){
			for(int j=0;j<=k && j<=i;++j){
				if(j>0) dp[i][j]=dp[i-1][j-1]-d;	
				else{
					dp[i][j]=-INF;
					dp[i][j]=max(dp[i][j],mx[i-1]);
				}
			}
			vector<AAA> vec;
			while(pos<m && a[pos].x==i){
				vec.push_back(a[pos]);
				++pos;		
			}
			sort(vec.begin(),vec.end(),cmp);
			int idx=0,sum=0;
			for(int j=0;j<=k && j<=i;++j){
				while(idx<(int)vec.size() && vec[idx].y<=j){
					sum+=vec[idx].v;
					++idx;
				}
				if(j>0) dp[i][j]=max(dp[i][j],dp[i-1][j-1]-d+sum);
				else dp[i][j]=max(dp[i][j],mx[i-1]+sum);
			}
			mx[i]=-INF;
			for(int j=0;j<=k;++j) mx[i]=max(mx[i],dp[i][j]);
		}
		int ans=-INF;
		for(int i=0;i<=k;++i) ans=max(ans,dp[n][i]);
		cout << ans << '\n';
	}
	return 0;
}