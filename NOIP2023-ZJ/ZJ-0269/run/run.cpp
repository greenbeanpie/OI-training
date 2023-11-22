#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,ans,n,m,k,d,x[110],y[110],v[110];
bool cho[110];
void solve(){
	scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
	for(int i=1;i<=m;i++)scanf("%lld%lld%lld",&x[i],&y[i],&v[i]);
	for(int s=0;s<(1<<n);s++){
		for(int i=1;i<=n;i++)
			cho[i]=(s>>(i-1))&1;
		int len=0,mx=0,sum=0;
		for(int i=1;i<=n;i++){
			if(cho[i])len++;
			else{
				mx=max(mx,len);
				len=0;
			}
		}
		mx=max(mx,len);
		if(mx>k)continue;
		for(int i=1;i<=n;i++)
			sum-=(cho[i]==1)*d;
		for(int i=1;i<=m;i++){
			bool pd=0;
			for(int j=x[i];j>=x[i]-y[i]+1;j--)
				if(!cho[j]){
					pd=1;
					break;
				}
			if(!pd)sum+=v[i];
		}
		ans=max(ans,sum);
	}
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c<=2){
		while(t--){
			ans=-INT_MAX;
			solve();
			printf("%lld\n",ans);
		}
	}
	return 0;
}
