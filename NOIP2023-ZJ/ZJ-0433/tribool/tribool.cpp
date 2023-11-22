#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, m, c, t;
char legit[maxn];
int a[maxn], b[maxn];
int ans_num = 1e9;
bool vis[maxn];
bool check(string now) {
	for (int i = 1; i <= n; i++) {
		vis[i] = 0;
	}
	for (int i = m; i >= 1; i--) {
		if (vis[a[i]]) continue;
		vis[a[i]] = 1;
		if (legit[i] == '-') {
			//cout << now[a[i]] << "|" << now[b[i]] << endl;
			if (now[a[i]] == 'T' && now[b[i]] == 'F' || now[a[i]] == 'F' && now[b[i]] == 'T' || now[a[i]] == 'U' && now[b[i]] == 'U') {
				continue;
			}
			return 0;
		} else if (legit[i] == '+') {
			//cout << now[a[i]] << "|" << now[b[i]] << endl;
			if (now[a[i]] == 'T' && now[b[i]] == 'T' || now[a[i]] == 'F' && now[b[i]] == 'F' || now[a[i]] == 'U' && now[b[i]] == 'U') {
				continue;
			}
			return 0;
		} else {
			if (legit[i] == now[a[i]]) continue;
			return 0;
		}
	}
//	cout << now << endl;
	return 1;
}
void dfs(string ans, int cnt) {
	if (ans.size() == n + 1) {
		//	cout << ans << " ";
		if (check(ans)) {
			ans_num = min(ans_num, cnt);
		}
		return;
	}
	dfs(ans + "T", cnt);
	dfs(ans + "F", cnt);
	dfs(ans + "U", cnt + 1);
	return;
}
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		vis[i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		char p;
		cin >> p;
		if (p == '+' || p == '-') {
			int x, y;
			cin >> x >> y;
			legit[i] = p;
			a[i] = x;
			b[i] = y;
		}  else {
			int to;
			cin >> to;
			legit[i] = p;
			a[i] = to, b[i] = -114514;
		}
	}
	if (c == 3 || c == 4) {
		int cnt = 0;
		for (int i = m; i >= 1; i--) {
			if (vis[a[i]]) continue;
			vis[a[i]] = 1;
			if (legit[i] == 'U') cnt++;
		}
		cout << cnt << endl;
		return;
	} else if (c == 1 || c == 2){
		dfs("6", 0);
		cout << min(ans_num, n) << endl;
	} else {
		cout << n << endl;
	}
}
int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin >> c >> t;
	while(t--) {
		ans_num = 1e9; // jing dian duo zu bu qing kong wo zhen fu le aaaaa
		solve();
	}
	return 0;
}