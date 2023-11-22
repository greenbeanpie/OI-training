#include<bits/stdc++.h>
#define int long long
#define PII pair<pair<int, int>, int>
#define x first
#define y second
using namespace std;
int c;
int n, m, k, d, sum, ans;
PII s[100009];
void dfs(int pos, int r, int sum, int len){
	if(len > k) return ;
	if(pos == m + 1){
		ans = max(ans, sum);
		return ;
	}
	if(len == 0){
		dfs(pos + 1, s[pos].x.y, sum + s[pos].y, s[pos].x.y - s[pos].x.x + 1);
	}
	else{
		if(s[pos].x.x > r + 1){
			dfs(pos + 1, s[pos].x.y, sum + s[pos].y, s[pos].x.y - s[pos].x.x + 1);
		}else{
			dfs(pos + 1, s[pos].x.y, sum + s[pos].y, len + s[pos].x.y - r);
		}
	}
	dfs(pos + 1, r, sum, 0);
}
void solve(){
	cin >> n >> m >> k >> d;
	if(c == 17 || c == 18){
		int sum = 0;
		for(int i = 1; i <= m; i ++ ){
			cin >> s[i].x.x >> s[i].x.y >> s[i].y;
			int len = s[i].x.y;
			if(len <= k && len * d < s[i].y){
				sum += s[i].y - len * d;
			}
		}
		cout << sum << '\n';
		return ;
	}
	for(int i = 1; i <= m; i ++ ){
		cin >> s[i].x.y >> s[i].x.x >> s[i].y;
		s[i].y = s[i].y - s[i].x.y * d;
		if(s[i].y < 0 || s[i].x.y > k) i --, m --; 
		s[i].x.y = s[i].x.x - s[i].x.y + 1;
	}
	dfs(1, 0, 0, 0);
	cout << ans << '\n';
}
signed main(){
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c;
	int T;
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}