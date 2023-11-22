#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3010, mod = 998244353;
const ll p = 131;
int n, m, cnt[30], a[maxn];
string s[maxn], t[maxn], k;
ll h[maxn][maxn];
// small first
bool cmp(int x, int y) {
	int l = 0, r = m, pos = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (h[x][mid] == h[y][mid]) {
			l = mid + 1, pos = mid;
		}else r = mid - 1;
	}
	if (pos == m) return 1;
	return t[x][pos] < t[y][pos];
}
bool chk(int x, int y) {
	for (int i = 0; i < m; i++) {
		if (s[x][i] < t[y][i]) return true;
		if (s[x][i] > t[y][i]) return false;
	}
	return false;
}
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> k; memset(cnt, 0, sizeof(cnt));
		for (int j = 0; j < k.size(); j++) {
			cnt[k[j]-'a']++;
		}
		s[i] = t[i] = "";
		for (int j = 0; j < 26; j++) {
			for (int p = 1; p <= cnt[j]; p++) {
				s[i] += (char)('a' + j);
			}
		}
		for (int j = 25; j >= 0; j--) {
			for (int p = 1; p <= cnt[j]; p++) {
				t[i] += (char)('a' + j);
			}
		}
	//	cout << s[i] << " " << t[i] << endl;
	}
	for (int i = 1; i <= n; i++) {
		a[i] = i;
		for (int j = 0; j < m; j++) {
			h[i][j+1] = h[i][j] * p + (t[i][j]-'a'+13); h[i][j+1] %= mod;
		}
	}
	sort(a + 1, a + n + 1, cmp);
	//cout << a[1] << " debug" << endl;
	for (int i = 1; i <= n; i++) {
		int flag = 0;
		if (a[1] != i) {
			if (chk(i, a[1])) flag = 1;
		}else if (chk(i, a[2])) flag = 1;
		printf("%d", flag);
	}
	return 0;
}