#include<bits/stdc++.h>
using namespace std;

const int N = 200;
int n, a[N], ans[N];
int g[N];

void dfs(int stp) {
	if(stp == n + 1) {
		int s = 0, ad = 0;
//		for(int i = 1; i <= n; i ++) cout << g[i] << ' ';
//		cout << '\n';
		for(int i = 1; i <= n; i ++) {
			if(g[i] + ad < a[i]) return;
			s += g[i];
			ans[i] = min(ans[i], s);			
			ad = (g[i] + ad) / 2;
		}
		return;
	}
	for(int i = 0; i <= a[stp]; i ++) {
		g[stp] = i;
		dfs(stp + 1);
	}
}

int main() {
	freopen("qigong.in", "r", stdin);
	freopen("qigong.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i], ans[i] = 1e9;
	if(n <= 10) {
		g[1] = a[1];
		dfs(2);
		for(int i = 1; i <= n; i ++)
			cout << ans[i] << ' ';
	} else {
		int ad = 0;
		for(int i = 1; i <= n; i ++)
			g[i] = max(0, a[i] - ad), ad = (ad + g[i]) / 2;
		int s = 0;
		for(int i = 1; i <= n; i ++)
			s += g[i], cout << s << ' ';							
	}
}
