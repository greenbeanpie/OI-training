#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,k,d,a[10001],b[1001],c1[1001],v[1001],maxx=0;
void dfs(int now) {
	if(now==n+1) {
		int l=0,ans=0;
		for(int i=1; i<=n; i++){
			if(v[i]==1){
				l++;
				ans--;
				if(l>k)return;
			}
			else l=0;
		for(int j=1;j<=m;j++)if(a[j]==i&&l>=b[j])ans+=c1[j];
		}
		maxx=max(maxx,ans);
		return;
	}
	dfs(now+1);
	v[now]=1;
	dfs(now+1);
	v[now]=0;
}
int main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>t;
	while(t--) {
		cin>>n>>m>>k>>d;
		for(int i=1; i<=m; i++)cin>>a[i]>>b[i]>>c1[i];
		dfs(1);
		cout<<maxx<<endl;
	}
	return 0;
}
