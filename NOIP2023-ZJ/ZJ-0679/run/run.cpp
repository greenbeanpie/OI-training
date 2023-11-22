#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m,k,d;
int x[100050];
int y[100050];
int v[100050];
long long ans;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&k,&d);
		ans=0;
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&x[i],&y[i],&v[i]);
		}
		if(c==17||c==18){
			for(int i=1;i<=m;i++){
				if((long long)y[i]*d<v[i]&&y[i]<=k&&y[i]<=x[i]){
					ans+=(long long)v[i]-y[i]*d;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
