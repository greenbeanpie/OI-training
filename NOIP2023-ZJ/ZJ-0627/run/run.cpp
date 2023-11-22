#include <bits/stdc++.h>
#define int long long 
using namespace std;
int c,t;
int n,m,k,d,ans;
int a[1000];
int x[1000],y[1000],v[1000];
void dfs(int z){
	if(z==n+1){
		int len=0,sum=0;
		if(a[1]) len++,sum++;
 		for(int i=2;i<=n;i++){
			if(a[i]==1) sum++;
			if(a[i]==a[i-1]&&a[i]==1) len++;
			else if(a[i]==1) len=1;
			else len=0;
			if(len>k) return;
		}
		sum=0-sum*d;
		for(int i=1;i<=m;i++){
			bool f=0;
			for(int j=x[i];j<=y[i];j++){
				if(a[j]!=1){f=1;break;} 
			}
			if(!f) sum+=v[i];
		}
		ans=max(ans,sum);
		return ;
	}
	for(int i=0;i<=1;i++){
		a[z]=i;
		dfs(z+1);
	}
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m>>k>>d;
		ans=-1e9;
		if(c==1||c==2){
			for(int i=1;i<=m;i++){
				cin>>y[i]>>x[i]>>v[i];
				x[i]=y[i]-x[i]+1;
			}
			dfs(1);
			cout<<ans;
		}
	}
	return 0;
}