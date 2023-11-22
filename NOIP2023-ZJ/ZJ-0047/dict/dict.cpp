#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const int N = 3e3 + 10;
int n, m, id[N], rk[N];
char str[N][N], tx[N];
int b[N][31], cc[N], mx[N], mn[N];
inline bool judge(int x, int y) {
	if (cc[x] == 1 && cc[y] == 1) return mx[x] < mx[y];
	if (mn[x] < mx[y]) return 1;
	return 0;
} 
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> tx;
		for (int j = 1; j <= m; j++) str[i][j] = tx[j - 1], ++b[i][str[i][j] - 'a' + 1];
		mn[i] = 30;
		for (int j = 1; j <= 26; j++) {
			if (b[i][j]) mn[i] = min(mn[i], j), mx[i] = max(mx[i], j); 
		}
	}
	for (int i = 1; i <= n; i++) {
		bool fl = 1;
		for (int j = 1; j <= n; j++)
			if (i != j && fl && !judge(i, j)) fl = 0;
		cout << fl;
	}
}
//g++ dict.cpp -o dict -fsanitize=undefined,address -D_GLIBCXX_DEBUG -g -std=c++14 -O2 -Wall