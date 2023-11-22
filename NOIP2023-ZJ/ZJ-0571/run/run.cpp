#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,k,d,x[1000010],y[1000100],v[1000100];
long long int ans,h;
int main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t>>n>>m>>k>>d;
	for(int i=1; i<=m; ++i) {
		cin>>x[i]>>y[i]>>v[i];
	}
	for(int i=1; i<=m; ++i) {
		if(k>=y[i]) {
			h=v[i]-y[i]*d;
		}
		ans=max(ans,ans+h);
	}
	cout<<ans;
	return 0;
}
