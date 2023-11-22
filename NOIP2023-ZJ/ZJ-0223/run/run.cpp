#include<bits/stdc++.h>
#define ll long long
#define N 3005
using namespace std;
int c,T;
int n,m,k;
ll d;
ll x,y,v;
ll ans;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%d%d%lld",&n,&m,&k,&d);
		ans=0;
		for(int i=1;i<=m;i++){
			scanf("%lld%lld%lld",&x,&y,&v);
			ans+=max(0ll,v-y*d);
		}
		printf("%lld\n",ans);
	}
	return 0;
}