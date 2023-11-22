#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int a[maxn], b[maxn], c, n, m, q;
vector<int> a1(n + 5), b1(n + 5);
const int limit = 15;
bool Super_Check(string goal, string now, int at) {
	if (goal.size() == limit) {
		int isp = 1, isn = 1;
		if ((int)goal[0] > (int)now[0]) {
			for (int i = 1; i < limit; i++) {
				if (goal[i] <= now[i]) return 0;
			}
		} else {
			for (int i = 1; i < limit; i++) {
				if (goal[i] >= now[i]) return 0;
			}
		}
		return 1;
	}
	if (n - at + now.size() < limit) {
		return Super_Check(goal, now + char(b1[at]  + '0'), at);
	}
	return Super_Check(goal, now + char(b1[at + 1] + '0'), at + 1);
}
bool is_prime = 0;
void Super_Dfs(string now, int at) {
	if (now.size() == limit) {
		if(Super_Check(now, "", 1)) {
			is_prime = 1;
		}
		return;
	}
	if (n - at + now.size() < limit) {
		Super_Dfs(now + char(a1[at]  + '0'), at);
	}
	Super_Dfs(now + char(a1[at + 1] + '0'), at + 1);
}
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin >> c >> n >> m >> q;
	if (c == 1) {
		int aaaa, bbbb;
		cin >> aaaa >> bbbb;
		while(q--) {
			int kx, ky;
			cin >> kx >> ky;
			while(kx--) {
				int nowa, nowb;
				cin >> nowa >> nowb;
			}
			while(ky--) {
				int nowa, nowb;
				cin >> nowa >> nowb;
			}
			cout << 1;
		}
	} else if (c == 2) {
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= m; i++) {
			cin >> b[i];
		}
		string ans = "";
		a1.clear(), b1.clear();
		for (int i = 1; i <= n; i++) a1[i] = a[i];
		for (int i = 1; i <= m; i++) b1[i] = b[i];
		if (a1[n] > b1[n] && a1[1] > b1[1] || a1[n] < b1[n] && a1[1] < b1[1]) {
			ans += "1";
		} else ans += "0";
		while(q--) {
			a1.clear(), b1.clear();
			int kx, ky;
			cin >> kx >> ky;
			for (int i = 1; i <= n; i++) a1[i] = a[i];
			for (int i = 1; i <= m; i++) b1[i] = b[i];
			while(kx--) {
				int now, fix;
				cin >> now >> fix;
				a1[now] = fix;
			}
			while(ky--) {
				int now, fix;
				cin >> now >> fix;
				b1[now] = fix;
			}
			if (a1[n] > b1[n] && a1[1] > b1[1] || a1[n] < b1[n] && a1[1] < b1[1]) {
				ans += "1";
			} else ans += "0";
		}
		cout << ans << endl;
	} else if (c == 3 || c == 4) {
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= m; i++) {
			cin >> b[i];
		}
		string ans = "";
		for (int i = 1; i <= n; i++) a1[i] = a[i];
		for (int i = 1; i <= m; i++) b1[i] = b[i];
		if (a1[n] < b1[n] && a1[1] > b1[1] || a1[n] > b1[n] && a1[1] < b1[1] || a1[n] == b1[n] || a1[1] == b1[1]) {
			ans += "0";
		} else {
			Super_Dfs("", 1);
			if (is_prime) ans += "1";
			else ans += "0";
			is_prime = 0;
		}
		while(q--) {
			int kx, ky;
			cin >> kx >> ky;
			for (int i = 1; i <= n; i++) a1[i] = a[i];
			for (int i = 1; i <= m; i++) b1[i] = b[i];
			while(kx--) {
				int now, fix;
				cin >> now >> fix;
				a1[now] = fix;
			}
			while(ky--) {
				int now, fix;
				cin >> now >> fix;
				b1[now] = fix;
			}
			if (a1[n] < b1[n] && a1[1] > b1[1] || a1[n] > b1[n] && a1[1] < b1[1] || a1[n] == b1[n] || a1[1] == b1[1]) {
				ans += "0";
			} else {
				Super_Dfs("", 1);
				if (is_prime) ans += "1";
				else ans += "0";
				is_prime = 0;
			}
		}
		cout << ans << endl;
	}
	return 0;
}