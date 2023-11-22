#include <bits/stdc++.h>
using namespace std;
#define int long long
int C,T,n,m,k,d,ans,a[100010],b[100010],c[100010];
void dfs(int x,int t,int y,int z){
	if (x>n){
		ans=max(ans,z);
		return;
	}
	while (a[t]<x) t++;
	dfs(x+1,t,0,z);
	if (y==k) return;
	y++;
	z-=d;
	if (a[t]==x && y>=b[t]) z+=c[t];
	dfs(x+1,t,y,z);
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while (T--){
		cin>>n>>m>>k>>d;
		for (int i=1;i<=m;i++) cin>>a[i]>>b[i]>>c[i];
		ans=-0x3f3f3f3f3f3f3f3f;
		dfs(1,1,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
