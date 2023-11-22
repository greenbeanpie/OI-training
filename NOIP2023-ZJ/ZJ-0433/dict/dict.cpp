#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e3 + 5;
int n, m;
string s[maxn], s1[maxn], s2[maxn];
string min_s2_1;
int min_s2_1_at;
bool check(string a, string b) {
	for (int i = 0; i < m; i++) {
		if (a[i] < b[i]) {
			return 0;
		}
	}
	return 1;
}
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s1[i] = s[i];
		s2[i] = s[i];
	}
	if (n == 1) {
		cout << 1;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		sort(s1[i].begin(), s1[i].end());
		sort(s2[i].begin(), s2[i].end(), greater<int>());
	}
	min_s2_1 = s2[1], min_s2_1_at = 1;
	for (int i = 2; i <= n; i++) {
		bool isp = 1;
		for (int j = 0; j < m; j++) {
			if (s2[i][j] < min_s2_1[j]) {
				isp = 0;
				break;
			}
		}
		if (isp == 0) {
			min_s2_1 = s2[i];
			min_s2_1_at = i;
		}
	}
	string ans = "";
	for (int i = 1; i <= n; i++) {
		bool isp = 1;
		if (i != min_s2_1_at) {
			if (check(s1[i], min_s2_1)) {//cout << s1[i] << endl << s2[j] << endl;
				isp = 0;
			}
		} else {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (check(s1[i], s2[j])) {
					isp = 0;
					break;
				}
			}
		}
		if (isp) ans += '1';
		else ans += '0';
	}
//	cout << 3000ll * 3000 * log2(3000) << endl;
	cout << ans << endl;
	return 0;
}