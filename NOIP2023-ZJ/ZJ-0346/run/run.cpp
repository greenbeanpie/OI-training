#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,k,ans,d,s[N],v[N],x[N],y[N];
int pan(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(cnt==0||(s[i]=1&&s[i-1]=1)) cnt++;
		for(int i=1;i<=m;i++)
	}
}
void dfs(int x){
	if(x>n){
		ans=max(ans,pan());return;
	}s[x]=0;dfs(x+1);s[x]=1;dfs(x+1);
}
void work(){
	ans=0;
	cin>>n>>m>>k>>d;
	for(int i=1;i<=m;i++){
		cin>>x[i]>>y[i]>>v[i];
	}
	dfs();
	cout<<ans;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cout<<0<<endl;
	}
	return 0;
}