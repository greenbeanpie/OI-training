#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,k,d,x[1005],y[1005],v[1005],a[1005],ans;
void dfs(long long s,long long sum){
	if(s==n+1){
		long long e=0;
		for(int i=1;i<=n;i++){
//			cout<<a[i];
			if(a[i]==1){
				e-=d;
			}
		}
//		cout<<endl;
		for(int i=1;i<=m;i++){
			long long f=1;
			for(int j=x[i];j>=x[i]-y[i]+1;j--){
				if(a[j]==0){
					f=0;
					break;
				}
			}
			if(f==1){
				e+=v[i];
			}
		}
		if(e>ans){
			ans=e;
		}
//		cout<<e<<endl;
		return;
	}
	if(sum+1<=k){
		a[s]=0;
		dfs(s+1,sum);
		a[s]=1;
		dfs(s+1,sum+1);
	}
	else{
		a[s]=0;
		dfs(s+1,0);
	}
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++){
			cin>>x[i]>>y[i]>>v[i];
		}
		ans=0;
		dfs(1,0);
		cout<<ans<<endl;
	}	
}