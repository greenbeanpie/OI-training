#include<bits/stdc++.h>
#define int long long
#define fr(s) freopen(s".in","r",stdin)
#define fw(s) freopen(s".out","w",stdout)
using namespace std;
const int N=5e5+10,M=5e5+10;
int c,t,ans;
int n,m,k,d;
struct point {
	int x,y,v;
}a[M];
int vis[N],sum[N];
void dfs(int pos,int tot,int lst){
	if(lst>k)return ;
	if(pos>n){
		for(int i=1;i<=m;i++){
			if(sum[a[i].x]-sum[a[i].x-a[i].y]==a[i].y){
				tot+=a[i].v;
			}
		}
		ans=max(ans,tot);
		return ;
	}
	sum[pos]=sum[pos-1]+1;
	vis[pos]=1;
	dfs(pos+1,tot-d,lst+1);
	sum[pos]=sum[pos-1];
	vis[pos]=0;
	dfs(pos+1,tot,0);
}
signed main(){
	fr("run");
	fw("run");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==1||c==2){
		while(t--){
			ans=0;
			cin>>n>>m>>k>>d;
			for(int i=0;i<=n;i++){
				vis[i]=sum[i]=0;
			}
			for(int i=1;i<=m;i++){
				cin>>a[i].x>>a[i].y>>a[i].v;
			}
			dfs(1,0,0);
			cout<<ans<<"\n";
		}
	}
	else {
		while(t--){
			ans=0;
			cin>>n>>m>>k>>d;
			for(int i=1;i<=m;i++){
				cin>>a[i].x>>a[i].y>>a[i].v;
				if(a[i].y-a[i].x+1<=k&&a[i].v>d){
					ans=ans+a[i].v-d;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
