#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
long long n,m,d,k;
long long dp[N][N];
vector<int> e[N];
struct node{
	long long x,y,z;
}a[N];
bool cmp(node x,node y){
	return x.x<y.x;
}
void wrk(){
	for(int i=1;i<=n;i++) e[i].clear();
	cin>>n>>m>>k>>d;
	for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
//	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=m;i++) e[a[i].x].push_back(i);
	for(int i=1;i<=n;i++) 
		for(int j=0;j<=n;j++) dp[i][j]=0;
	dp[1][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++) dp[i][0]=max(dp[i][0],dp[i-1][j]);
		for(int j=1;j<=min((long long)i,k);j++){
			dp[i][j]=dp[i-1][j-1]-d;
			for(int l=0;l<e[i].size();l++)
				if(j>=a[e[i][l]].y)dp[i][j]+=a[e[i][l]].z;
		}
	}
	long long ans=0;
//	for(int i=1;i<=n;i++,printf("\n"))
//		for(int j=0;j<=n;j++) printf("%d ",dp[i][j]);printf("\n\n");
//	for(int i=1;i<=n;i++){
//		printf("%d:",i);
//		for(int j=0;j<e[i].size();j++) printf("%d ",e[i][j]);
//		printf("\n");
//	}
	for(int i=0;i<=n;i++)ans=max(ans,dp[n][i]);
	printf("%lld\n",ans);
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int C;int T;
	cin>>C>>T;
	while(T-->0)wrk();
	return 0;
}
