#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int c, t, n, m;

struct node {
	int a, b;
	char op;
}fuz[N];

// F 0 T 1 U 2

// 1, 2
int vis1[15], vis2[15], answer;
int change(int a) {
	if (a == 0) return 1;
	else if (a == 1) return 0;
	else return 2; 
}
int qchange(char a) {
	if (a == 'F') return 0;
	else if (a == 'T') return 1;
	else if (a == 'U') return 2;
	else return -1;
}

bool check() {
	for (int i = 1; i <= n; i++) {
		vis2[i] = vis1[i];
	}
	for (int i = 1; i <= m; i++) {
		if (fuz[i].op == '+') {
			vis2[fuz[i].a] = vis2[fuz[i].b];
		}
		else if (fuz[i].op == '-') {
			vis2[fuz[i].a] = change(vis2[fuz[i].b]);
		}
		else {
			vis2[fuz[i].a] = qchange(fuz[i].op);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (vis2[i] != vis1[i]) {
			return false;
		}
	}
	return true;
}

// 3, 4, 5, 6
int vis[N];

void dfs(int step, int gz) {
	if (gz >= answer) {
		return ;
	}
	if (step == n + 1) {
		if (check()) {
			answer = gz;
		}
		return ;
	}
	vis1[step] = 0; dfs(step + 1, gz);
	vis1[step] = 1; dfs(step + 1, gz);
	vis1[step] = 2; dfs(step + 1, gz + 1);
	return ;
}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			cin >> fuz[i].op;
			if (fuz[i].op == '+' || fuz[i].op == '-') {
				cin >> fuz[i].a >> fuz[i].b;
			}
			else cin >> fuz[i].a;
		}
		if (c == 1 || c == 2) {
			answer = 1e9 + 5;
			dfs(1, 0);
			cout << answer << endl;
			continue;
		}
		if (c == 3 || c == 4) {
			answer = 0;
			memset(vis, 0, sizeof vis);
			for (int i = 1; i <= m; i++) {
				if (fuz[i].op == 'U') vis[fuz[i].a] = 1;
				else vis[fuz[i].a] = 0;
			}
			for (int i = 1; i <= n; i++) {
				answer += vis[i];
			}
			cout << answer << endl;
			continue;
		}
		if (c == 5 || c == 6) {
			answer = 0;
			memset(vis, 0, sizeof vis);
			for (int i = 1; i <= m; i++) {
				if (fuz[i].op == 'U') {
					vis[fuz[i].a] = 1;
				}
				if (fuz[i].op == '+') {
					vis[fuz[i].a] = vis[fuz[i].b];
				}
			}
			for (int i = 1; i <= n; i++) {
				answer += vis[i];
			}
			cout << answer << endl;
			continue;
		}
	}	
	return 0;
}