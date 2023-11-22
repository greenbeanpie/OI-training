#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int c, t, n, m;
int f[maxn], ans[maxn], cnt[maxn], answer;
bool vis[maxn];
struct node{
	char op;
	int x, y;
}a[maxn];
void dfs(int now) {
	if (now == n + 1) {
		bool flag = 1;
		for (int i = 1; i <= n; i++) cnt[i] = ans[i];
		for (int i = 1; i <= m; i++) {
			if (a[i].op == 'T') cnt[a[i].x] = 0;
			if (a[i].op == 'F') cnt[a[i].x] = 1;
			if (a[i].op == 'U') cnt[a[i].x] = 2;
			if (a[i].op == '+') cnt[a[i].x] = cnt[a[i].y];
			if (a[i].op == '-') {
				if (cnt[a[i].y] == 2) cnt[a[i].x] = 2;
				else if (cnt[a[i].y] == 1) cnt[a[i].x] = 0;
				else if (cnt[a[i].y] == 0) cnt[a[i].x] = 1;
//				if (a[i].y == a[i].x) cout << cnt[a[i].y] << " " << cnt[a[i].x] << '\n';
			}
		}
		for (int i = 1; i <= n; i++) {
			if (cnt[i] != ans[i]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			int tmp = 0;
			for (int i = 1; i <= n; i++) {
				if (ans[i] == 2) tmp++;
			}
//			if (tmp == 3) {
//				for (int i = 1; i <= n; i++) cout << ans[i] << " ";
//				cout << '\n';
//				for (int i = 1; i <= n; i++) cout << cnt[i] << " ";
//				cout << '\n';
//			} 
			answer = min(answer, tmp);
		}
		return;
	}
	ans[now] = 0;
	dfs(now + 1);
	ans[now] = 1;
	dfs(now + 1);
	ans[now] = 2;
	dfs(now + 1);
}
void Subtask1() {
	int res = 0;
	memset(ans, 0, sizeof ans);
	for (int i = 1; i <= m; i++) {
		if (a[i].op == 'T') ans[a[i].x] = 1;
		if (a[i].op == 'F') ans[a[i].x] = 2;
		if (a[i].op == 'U') ans[a[i].x] = 3;
	}
	for (int i = 1; i <= n; i++) {
		if (ans[i] == 3) res++; 
	}
	cout << res << '\n';
	return;
}
void Subtask2() {
	int res = 0;
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= m; i++) {
		if (a[i].op == 'U') vis[a[i].x] = 1;
		else {
			if (vis[a[i].y]) vis[a[i].x] = 1;
			else vis[a[i].x] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (vis[i]) res++;
	}
	bool f = 1;
	while (f) {
		f = 0;
		int last = res;
		res = 0;
		for (int i = 1; i <= m; i++) {
			if (a[i].op == 'U') vis[a[i].x] = 1;
			else {
				if (vis[a[i].y]) vis[a[i].x] = 1;
				else vis[a[i].x] = 0;
			}
		}
		for (int i = 1; i <= m; i++) {
			if (vis[i]) res++;
		}
		if (res > last) f = 1;
	}
	cout << res << '\n';
	return;
}
//void Subtask3() {
//	memset(ans, 0, sizeof ans);
//	for (int i = 1; i <= m; i++) {
//		if (a[i].op == '+') {
//			if (ans[a[i].x] == 0 && ans[a[i].y] == 0) {
//				ans[a[i].x] = 1, ans[a[i].y] = 1;
//			}else if (ans[a[i].x] == 0) 
//		}else {
//			
//		}
//	}
//}
int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
//	char op;
	cin >> c >> t;
	while (t--) {
		cin >> n >> m;
//		for (int i = 1; i <= 2 * n; i++) f[i] = i;
		for (int i = 1; i <= m; i++) {
			cin >> a[i].op >> a[i].x;
			if (a[i].op == '+') {
				cin >> a[i].y;
			}
			if (a[i].op == '-') {
				cin >> a[i].y;
			}
		}
		if (c == 1 || c == 2) {
			answer = 1e9;
			dfs(1);
			cout << answer << '\n';
			continue;
		}
		if (c == 3 || c == 4) {
			Subtask1();
			continue;
		} 
		if (c == 5 || c == 6) {
			Subtask2();
			continue;
		} 
//		if (c == 7 || c == 8) {
//			Subtask3();
//			continue;
//		} 
	}
	return 0;
}
/*
1 1
10 10
- 7 3
- 5 3
+ 3 7
- 1 6
+ 4 6
- 8 4
- 6 8
+ 2 2
- 9 9
- 10 10
*/