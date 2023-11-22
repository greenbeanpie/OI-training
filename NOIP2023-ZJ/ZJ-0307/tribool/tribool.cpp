#include<bits/stdc++.h>
//#define int long long
using namespace std;

const int N = 1e5 + 5;

int c, T, n, m;
struct questions {
	char op;
	int x, y;
};
vector<questions> q;

int a[N], b[15], ans;
void dfs(int x) {
	if(x == n + 1) {
		for(int i = 1; i <= n; i++) b[i] = a[i];
		for(questions u : q) {
			if(u.op == '+') b[u.x] = b[u.y];
			else if(u.op == '-') {
				if(b[u.y] == 3) b[u.x] = 3;
				else b[u.x] = 3 - b[u.y];
			}
			else {
				switch(u.op) {
					case 'T': b[u.x] = 1; break;
					case 'F': b[u.x] = 2; break;
					default : b[u.x] = 3;
				}
			}
		}
		for(int i = 1; i <= n; i++)
			if(a[i] != b[i])
				return ;
		int cnt = 0;
		for(int i = 1; i <= n; i++)
			if(a[i] == 3) cnt++;
		ans = min(ans, cnt);
		return ;
	}
	a[x] = 1; dfs(x + 1);
	a[x] = 2; dfs(x + 1);
	a[x] = 3; dfs(x + 1);
}

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();};
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	c = read(), T = read();
	while(T--) {
		n = read(), m = read();
		for(int i = 1; i <= m; i++) {
			char op; cin >> op;
			questions u;
			if(op == '+' || op == '-') {
				u.op = op;
				u.x = read(), u.y = read();
				q.push_back(u);
			}
			else {
				u.op = op;
				u.x = read(), u.y = 0;
				q.push_back(u);
			}
		}
		if(c <= 2) {
			ans = INT_MAX;
			dfs(1);
			cout << ans << endl;
			q.clear();
		}
		else if (c <= 4) {
			for(int i = 1; i <= n; i++) a[i] = 0;
			for(questions u : q) {
				switch(u.op) {
					case 'T': a[u.x] = 1; break;
					case 'F': a[u.x] = 2; break;
					default : a[u.x] = 3;
				}
			}
			ans = 0;
			for(int i = 1; i <= n; i++) if(a[i] == 3) ans++;
			cout << ans << endl;
		}
	}
	return 0;
}
