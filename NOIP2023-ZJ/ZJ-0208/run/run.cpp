#include<bits/stdc++.h>
using namespace std;
#define int long long

struct chall{
	int d,k,v;	
}a[100005];
int n,m,k,v,c,T,ans;
bool cmp(chall x,chall y){
	return x.d<y.d;
}
void dfs(int x,int d,int l,int s){
	while(a[l].d==x){
		if(d>=a[l].k) s+=a[l].v;
		++l;
	}
	if(x==n){
		ans=max(ans,s);
		return;
	}
	dfs(x+1,0,l,s);
	if(d+1<=k) dfs(x+1,d+1,l,s-v);
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>T;
	while(T--){
		cin>>n>>m>>k>>v;
		for(int i=1;i<=m;++i){
			cin>>a[i].d>>a[i].k>>a[i].v;
		}
		sort(a+1,a+m+1,cmp);
		ans=0;
		dfs(0,0,1,0);
		cout<<ans<<endl;
	}
	return 0;
}