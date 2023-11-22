#include <iostream>
#define int long long
//#include <bits/exc++.h>
using namespace std;
const int maxn=20;
int a[maxn],x[maxn],y[maxn],v[maxn];
int n,k,m,d,c,t,maxx=-0x3f3f3f3f;
void dfs(int step,int now){
	if (step==n+1){
		int sum=0;
		for (int i=1;i<=m;++i){
			bool flg=true;
			for (int j=x[i];j>=x[i]-y[i]+1;--j){
				if (!a[j]){flg=false;break;}
			}
			if (flg) sum+=v[i];
		}
		for (int i=1;i<=n;++i) if (a[i]) sum-=d;
		maxx=max(sum,maxx);
		return;
	}
	if (now<k){
		a[step]=1;
		dfs(step+1,now+1);
	}
	a[step]=0;
	dfs(step+1,0);
}
void work(){
	scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
	for (int i=1;i<=m;++i)
		scanf("%lld%lld%lld",&x[i],&y[i],&v[i]);
	dfs(1,0);
	return;
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while (t--){
		maxx=-0x3f3f3f3f3f3f3f3f;
		work();
		printf("%lld\n",maxx);
	}
	return 0;
}
