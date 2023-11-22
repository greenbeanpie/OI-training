#include<bits/stdc++.h>
using namespace std;
#define int long long
int id,T,n,m,k,d,dd,ans,len,dp[2][100005];
struct p{
	int l,r,w;
}a[100005];
bool cmp(p x,p y){
	return x.r<y.r;
}
void B(){
	for(int i=1;i<=m;i++)
		ans+=max(0ll,a[i].w-(a[i].r-a[i].l+1)*d);
}
void solve(){
	cin>>n>>m>>k>>d,dd=ans=0,a[0].r=-1;
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y>>a[i].w;
		a[i].l=x-y+1,a[i].r=x;
	}
	sort(a+1,a+m+1,cmp);
	if(id>=17)B();
	else{
		for(int i=0;i<=k;i++)dp[0][i]=dp[1][i]=0;
		for(int i=1;i<=m;i++){
			dd^=1,len=a[i].r-a[i].l+1,dp[dd][0]=ans;
			for(int j=1;j<a[i].r-a[i-1].r&&j<=k&&j<=a[i].r;j++)dp[dd][j]=ans-j*d+(j>=len)*a[i].w;
			for(int j=a[i].r-a[i-1].r;j<=k&&j<=a[i].r;j++)
				dp[dd][j]=dp[dd^1][j-a[i].r+a[i-1].r]-(a[i].r-a[i-1].r)*d+(j>=len)*a[i].w;
			for(int j=0;j<=k;j++)ans=max(ans,dp[dd][j]);
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>id>>T;
	while(T--)solve();
}
