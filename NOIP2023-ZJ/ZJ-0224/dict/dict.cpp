#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e3 + 10;

int n, m, ans[maxn];
char s[maxn][maxn];

bool comp(int x, int y) {
	if (x == 0) return 1;
	for (int i = m; i >= 1; i --)
		if (s[x][i] < s[y][i]) return 0;
		else if (s[x][i] > s[y][i]) return 1;
	return 0;
}

void solve(int id, int l, int r) {
	if (l == r) {
		for (int i = 1; i <= m; i ++)
			if (s[l][i] < s[id][m - i + 1]) ans[l] = 1;
			else if (s[l][i] > s[id][m - i + 1]) break;
		return ;
	}
	
	int L = id, R = id, mi = (l + r) >> 1;
	
	for (int i = l; i <= mi; i ++) if (comp(L, i)) L = i;
	for (int i = mi + 1; i <= r; i ++) if (comp(R, i)) R = i;
	
	solve(L, mi + 1, r), solve(R, l, mi);
}

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++)
		scanf("%s", s[i] + 1),
		sort(s[i] + 1, s[i] + m + 1);
	
	solve(0, 1, n);
	for (int i = 1; i <= n; i ++) printf("%d", ans[i]);
}

// 求求了不要挂分...
// 90(or 100) pts 
