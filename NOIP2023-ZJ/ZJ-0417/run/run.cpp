#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int x[N],y[N],v[N];
int c,t,n,m,k,d;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--){
		scanf("%d%d%d%d",&n,&m,&k,&d);
		bool yes=false;
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&x[i],&y[i],&v[i]);
			if(y[i]-x[i]+1<=k)	yes=true;
		}	
		if(!yes){
			cout<<0;
			return 0;
		}	
	}
	return 0;
}
