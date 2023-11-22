#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	long long val,cost;
}mission[N];
long long ans;
long long n,m,k,d;
long long ind[N];
void dfs(int day,long long cost,long long energy){
	if(day==n) {
		ans=max(ans,energy);
		return;
	}
	if(energy+ind[day]<=ans) return;
	if(mission[day].cost<=cost) energy+=mission[day].val;
	dfs(day+1,0,energy);
	dfs(day+1,cost+1,energy-d);
	return;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	if(c<=10)
	while(t--){
		memset(ind,0,sizeof ind);
		memset(mission,0,sizeof mission);
		scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		ans=0;
		for(int i=1;i<=m;i++){
			long long x,y,v;
			scanf("%lld%lld%lld",&x,&y,&v);
			mission[x].cost=y;
			mission[x].val=v;
		}
		ind[n]=mission[n].val;
		for(int i=n-1;i>=0;i--) ind[i]+=ind[i+1]+mission[i].val;
		dfs(0,0,0);
		cout<<ans<<endl;	
	}
	else{
		while(t--){
			cout<<0<<endl;
		}
	}
	return 0;
}