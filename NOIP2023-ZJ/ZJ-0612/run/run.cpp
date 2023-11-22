#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,T,n,m,k,l[100005],r[100005],b[21];
ll v[100005],d,ans=-1e18;
ll calc(){
	ll tot=0;
	for(int i=1;i<=m;i++){
		int flag=1;
		for(int j=l[i];j<=r[i];j++){
			if(!b[j]){
				flag=0;
				break;
			}
		}
		if(flag) tot+=v[i];
	}
	for(int i=1;i<=n;i++) if(b[i]) tot-=d;
	return tot;
}
void dfs(int step,int x){
	if(step==n+1){
		ans=max(ans,calc());
		return;
	}
	if(x+1<=k){
		b[step]=1;
	    dfs(step+1,x+1);
	}
	b[step]=0;
	dfs(step+1,0);
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		ans=-1e18;
		scanf("%d%d%d%lld",&n,&m,&k,&d);
		for(int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d%lld",&x,&y,&v[i]);
			l[i]=x-y+1,r[i]=x;
		}
		if(n<=18){
			dfs(1,0);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
