#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+5;
long long point,T,n,m,k,d;
long long x,y,dp[N],ans;
struct node{long long l,r,len,v;}cl[N],now;
bool cmp(node xx,node yy){return xx.l<yy.l;}
void dfs(long long p,long long day,long long res,long long pre){
//	cout<<p<<" "<<day<<" "<<res<<" "<<pre<<endl;
	if(day>k)return;
	if(p==m){
		ans=max(ans,res);
		return;
	}
	for(long long i=p+1;i<=m;i++){
		if(cl[i].l>cl[pre].r+1){
			dfs(i,cl[i].len,res+cl[i].v-cl[i].len*d,i);
			dfs(i,0,res,pre);
		}else{
			if(day+cl[i].len-(cl[pre].r-cl[i].l+1)<=k){
				dfs(i,day+cl[i].len-(cl[pre].r-cl[i].l+1),res+cl[i].v-cl[i].len*d,i);
			}
			dfs(i,day,res,pre);
		}
	}
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>point>>T;
	while(T--){
		ans=0;
		memset(cl,0,sizeof(cl));
		cin>>n>>m>>k>>d;
		for(long long i=1;i<=m;i++){
			cin>>cl[i].r>>y>>cl[i].v;
			cl[i].l=cl[i].r-y+1;
			cl[i].len=cl[i].r-cl[i].l+1;
		}
		sort(cl+1,cl+m+1,cmp);
		dfs(1,cl[1].len,cl[1].v-cl[1].len*d,1);
		dfs(1,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
