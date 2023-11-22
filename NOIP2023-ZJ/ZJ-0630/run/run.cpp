#include<bits/stdc++.h>
using namespace std;
long long C,T,n,m,k,d,x[100005],y[100005],v[100005],ans=0;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++){
			cin>>x[i]>>y[i]>>v[i];
			if(k>=y[i])ans+=v[i]>y[i]? v[i]-y[i]:0;
		}cout<<ans;
	}
}