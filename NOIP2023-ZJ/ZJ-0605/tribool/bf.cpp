#include <bits/stdc++.h>

using namespace std;

int read() {
	int x = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar());
	for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + (c ^ 48);
	return x;
}

int readop() {
	char c = getchar();
	for (; c != '+' && c != '-' && c != 'T' && c != 'F' && c != 'U'; c = getchar());
	if (c == '+') return 4;
	if (c == '-') return 5;
	if (c == 'T') return 1;
	if (c == 'F') return 2;
	if (c == 'U') return 3;
}

const int MAXN = 1e5 + 5;
int op[MAXN][3];
int C, T, n, m, ans;
int v[MAXN], u[MAXN], ansa[MAXN];

int nt(int x) {
	if (x == 1) return 2;
	if (x == 2) return 1;
	if (x == 3) return 3;
	if (x == 0) return -1;
	if (x == -1) return 0;
}

bool check() {
	for (int i = 1; i <= n; ++i) v[i] = u[i];
	for (int i = 1; i <= m; ++i) {
		if (op[i][0] <= 3) v[op[i][1]] = op[i][0];
		else if (op[i][0] == 4) {
			v[op[i][1]] = v[op[i][2]];
		}
		else if (op[i][0] == 5) {
			v[op[i][1]] = nt(v[op[i][2]]);
		}
	}
	bool flag = true;
	for (int i = 1; i <= n; ++i)
		if (v[i] != u[i]) {
			flag = false;
			break;
		}
//	if (flag) for (int i = 1; i <= n; ++i) ansa[i] = u[i];
	return flag;
}

void dfs(int x, int num) {
	if (num >= ans) return;
	if (x > n) {
//		for (int i = 1; i <= n; ++i) cout << u[i] << ' ';
//		cout << endl;
		if (check()) ans = num;
		return;
	}
	u[x] = 1;
	dfs(x + 1, num);
	u[x] = 2;
	dfs(x + 1, num);
	u[x] = 3;
	dfs(x + 1, num + 1);
}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	
	C = read();
	T = read();
	for (; T; --T) {
		n = read();
		m = read();
		ans = n;
		for (int i = 1; i <= n; ++i) u[i] = 0;
		for (int i = 1; i <= m; ++i) {
			op[i][0] = readop();
			if (op[i][0] <= 3) op[i][1] = read();
			else {
				op[i][1] = read();
				op[i][2] = read();
			}
		}
		dfs(1, 0);
//		for (int i = 1; i <= n; ++i) cout << ansa[i] << ' ';
//		cout << endl;
		printf("%d\n", ans);
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}