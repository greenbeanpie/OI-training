#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10000;
int c,t;
ll ans,n,m,k,d;
struct node{
	ll x,y,v;
}ch[N];
void dfs(ll now,ll da,ll val){
	if(now>n){
		ans=max(ans,val);
		return;
	}
	dfs(now+1,0,val);
	if(da==k)return;
	val-=d;
	for(int i=1;i<=m;i++){
		if(ch[i].x>now)break;
		if(ch[i].x==now&&ch[i].y<=(da+1))val+=ch[i].v;
	}
	dfs(now+1,da+1,val);
}
bool cmp(node a,node b){
	return a.x<b.x;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ans=-1e18;
		scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		for(int i=1;i<=m;i++)scanf("%lld%lld%lld",&ch[i].x,&ch[i].y,&ch[i].v);
		sort(ch+1,ch+1+m,cmp);
		dfs(1,0,0);
		printf("%lld\n",ans);
	}
	return 0;
}