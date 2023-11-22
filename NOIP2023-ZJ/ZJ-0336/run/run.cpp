#include<bits/stdc++.h>
using namespace std;
long long n,c,t,m,k,d;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long ans,x,y,v;
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++){
			cin>>x>>y>>v;
			if(v>y*d&&y<=k)ans+=v-y*d;
		}
		cout<<ans<<endl;
	}
}
