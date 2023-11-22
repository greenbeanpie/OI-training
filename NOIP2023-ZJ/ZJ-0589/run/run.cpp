#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int c,t,n,m,k,d,ans,dp[N][5],x[N],y[N],v[N];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m>>k>>d;
		ans=0;
		for(int i=1;i<=m;i++){
			cin>>x[i]>>y[i]>>v[i];
			if(v[i]>y[i]*d)ans+=(v[i]-y[i]*d);
		}
		cout<<ans<<endl;
	}
	return 0;
}