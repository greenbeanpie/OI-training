#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;

using namespace std;
int n,m,k,d;
int ans;
vector<pair<int,int> > a[N];

void dfs(int dep, int cnt, int sum){
	// cout << dep << " " << cnt << " " << sum << endl;
	if(dep == n+1){
		ans = max(ans,sum);
		return;
	}
	int tmp1 = 0,tmp2 = 0;
	for(auto i : a[dep]){
		// if(i.first <= cnt) tmp1 += i.second;
		if(i.first <= cnt+1) tmp2 += i.second;
		if(i.first > cnt+1) break;
	}
	dfs(dep+1,0,sum);
	if(cnt+1 <= k) dfs(dep+1,cnt+1,sum + tmp2 - d);
}
void solve(){
	cin >> n >> m >> k >> d;
	for(int i = 1; i <= n; i++) a[i].clear();
	for(int i = 1; i <= m; i++){
		int x,y,v;
		cin >> x >> y >> v;
		a[x].push_back({y,v});
	}
	for(int i = 1;i <= n; i++) sort(a[i].begin(),a[i].end());
	ans = -1e18;
	dfs(1,0,0);
	cout << ans << endl;
}
int c,t;
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin >> c >> t;
	while(t--) solve();

	return 0;
}