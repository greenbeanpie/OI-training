#include <bits/stdc++.h>
using namespace std; const int N = 3005;
int n, m, pos, pos2, cnt[500];
string str1[N], str2[N], minn, semn, s;
int main() {
	freopen("dict.in", "r", stdin); freopen("dict.out", "w", stdout);
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> s; memset(cnt, 0, sizeof cnt);
		for (int j = 0; j < m; ++j) ++cnt[s[j]];
		for (int j = 'a'; j <= 'z'; ++j)
			for (int k = 1; k <= cnt[j]; ++k) str2[i] += char(j);
		for (int j = 'z'; j >= 'a'; --j) 
			for (int k = 1; k <= cnt[j]; ++k) str1[i] += char(j);
	}
	if (n == 1) { cout << "1\n"; return 0; }
	for (int i = 1; i <= n; ++i) 
		if (!pos) minn = str1[i], pos = i; 
		else if (str1[i] < minn) pos = i, minn = str1[i];
	for (int i = 1; i <= n; ++i) 
		if (i != pos && !pos2) pos2 = i, semn = str1[i];
		else if (i != pos) semn = min(semn, str1[i]);
	for (int i = 1; i <= n; ++i) {
		if (i == pos) { 
			if (str2[i] < semn) cout << 1; else cout << 0;
		} else {
			if (str2[i] < minn) cout << 1; else cout << 0;
		}
	}
	cout << '\n';
	return 0;
}