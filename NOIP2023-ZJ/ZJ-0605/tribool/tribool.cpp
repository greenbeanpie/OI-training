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

namespace A{

const int MAXN = 1e5 + 5;
int T, n, m, ans, op0;
int isdfs[MAXN];
struct spot {
	int val;
	int blng;
	int fthr;
	bool isnt;
//	vector<int> sn;
	spot() : blng(), fthr(), isnt() {}
	spot(int blng, int fthr, bool isnt) : blng(blng), fthr(fthr), isnt(isnt) {}
}v[MAXN];

int nt(int x) {
	if (x == 1) return 2;
	if (x == 2) return 1;
	if (x == 3) return 3;
	if (x == 0) return -1;
	if (x == -1) return 0;
	if (x == -2) return -2;
}

void dfs(int p, int lc) {
	isdfs[p] = lc;
	if (isdfs[v[p].fthr] == lc && op0 == -2) {
		if (v[p].isnt) {
			if (v[p].val ==	 nt(v[v[p].fthr].val)) op0 = 0;
			else op0 = 3;
		}
		else {
			if (v[p].val == v[v[p].fthr].val) op0 = 0;
			else op0 = 3;
		}
	}
	else if (v[p].fthr != 0) {
		if (v[v[p].fthr].val != -2) {
			if (v[p].isnt) op0 = nt(v[v[p].fthr].val);
			else op0 = v[v[p].fthr].val;
		}
		else {
			if (v[p].isnt) v[v[p].fthr].val = nt(v[p].val);
			else v[v[p].fthr].val = v[p].val;
			dfs(v[p].fthr, lc);
		}
	}
	if (v[p].val == 0) v[p].val = op0;
	else v[p].val = nt(op0);
}

void main() {
	T = read();
	for (; T; --T) {
		n = read();
		m = read();
		for (int i = 1; i <= n; ++i) v[i].val = -2, v[i].fthr = 0;
		for (int i = 1; i <= m; ++i) {
			int op = readop();
			if (op <= 3) {
				int px = read();
				v[px].val = op;
			}
			else if (op == 4) {
				int px = read(), py = read();
				v[px].fthr = py;
				v[px].isnt = false;
				v[px].val = v[py].val;
			}
			else if (op == 5) {
				int px = read(), py = read();
				v[px].fthr = py;
				v[px].isnt = true;
				v[px].val = nt(v[py].val);
			}
		}
//		cout << endl;
		for (int i = 1; i <= n; ++i) if (v[i].val == -2) {
			v[i].val = 0;
			op0 = -2;
			dfs(i, i);
		}
//		for (int i = 1; i <= n; ++i) cout << v[i].val << ' ';
//		cout << endl;
		ans = 0;
		for (int i = 1; i <= n; ++i) if (v[i].val == 3) ++ans;
		printf("%d\n", ans);
	}
}
}
namespace B {
const int MAXN = 1e5 + 5;
int op[MAXN][3];
int T, n, m, ans;
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

void main() {
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
}
}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	
	int C = read();
	if (C <= 2) B::main();
	else A::main();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}