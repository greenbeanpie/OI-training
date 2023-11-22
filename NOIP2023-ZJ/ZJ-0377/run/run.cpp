#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int C,T,x,yy,vv,k,d,m,n,y[N],v[N],ans;
void dfs(int now,int len,int e){
	if(now>n){
		ans=max(ans,e);
		return ;
	}
	if(len+1<=k){
		if(v[now]&&len+1>=y[now]) dfs(now+1,len+1,e-d+v[now]);
		else dfs(now+1,len+1,e-d);
	}
	dfs(now+1,0,e);
}
signed main(){
	freopen("run.in","r",stdin);freopen("run.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--){
		ans=0;
		scanf("%d%d%d%d",&n,&m,&k,&d);
		memset(y,0,sizeof(y));
		memset(v,0,sizeof(v));
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&x,&yy,&vv);
			y[x]=yy;v[x]=vv;
		}
		dfs(1,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
