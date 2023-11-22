//Goodbye OI, I will miss you
//龙潜月十五
//2023.11.18
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int M = 1e5 + 7;
int c, t, n, m, k;
ll ans, d;
struct challenge {
	int x, y;
	ll v;
}ch[M];

void init() {
	ans = 0;
	cin >> n >> m >> k >> d;
	for(int i = 1; i <= m; ++i)
		cin >> ch[i].x >> ch[i].y >> ch[i].v;
}

void dfs(int now, int lst, ll ene) {
	for(int i = 1; i <= m; ++i)
		if(ch[i].x == now && lst >= ch[i].y)
			ene += ch[i].v;
	if(now == n) {
		ans = max(ans, ene);
		return;
	}
	dfs(now + 1, 0, ene);
	if(lst < k)
		dfs(now + 1, lst + 1, ene - d);
	return;
}

int main() { 
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	if(c <= 2) {
		while(t--) {
			init();
			dfs(0, 0, 0);
			cout << ans << '\n';
		}
	}
	return 0;
}