#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,k,d;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int x,y,v;
		int ans=0;
		cin>>n>>m>>k>>d;
		while(m--){
			cin>>x>>y>>v;
			ans=max(ans,v-d*y);
		}
		cout<<ans;
	}
	return 0;
}
