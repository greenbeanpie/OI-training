#include <bits/stdc++.h>
using namespace std;
const int N = 3005, mod = 998244353, MOD = 1e9 + 7, P = 131;
int n, m, s1[N][N], s2[N][N], p1[N], p2[N];
char ss[N][N], s[N];
inline bool cmp(int i, int j) {
	int l = 1, r = m, ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (s2[i][mid] != s1[j][mid])
			ans = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	return ss[i][m - ans + 1] < ss[j][ans];
	return false;
}
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	p1[0] = p2[0] = 1;
	for (int i = 1; i <= m; i++)
		p1[i] = 1ll * p1[i - 1] * P % mod, p2[i] = 1ll * p2[i - 1] * P % MOD;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) 
			cin >> s[j];
		sort(s + 1, s + m + 1);
		for (int j = 1; j <= m; j++)
			ss[i][j] = s[j];
		for (int j = 1; j <= m; j++)
			s1[i][j] = (1ll * s1[i][j - 1] * P + s[j]) % MOD; 
		for (int j = 1; j <= m; j++)
			s2[i][j] = (1ll * s2[i][j - 1] * P + s[m - j + 1]) % MOD;
	}
	for (int i = 1; i <= n; i++) {
		bool flg = true;
		for (int j = 1; j <= n; j++) {
			if (i != j && cmp(j, i)) {
				flg = false;
				break;
			}
		}
		cout << flg;
	}
	return 0;
}