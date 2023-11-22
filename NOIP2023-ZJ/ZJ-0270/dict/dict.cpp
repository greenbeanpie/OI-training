#include<bits/stdc++.h>
using namespace std;
const int N = 3005;
bool st;
int n, m;
string s[N];
int a[N][N], b[N][N];
int cnt[N][26];
vector<int> p1[N], p2[N];
bool ed;
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	//printf("%.3lf MB\n", (&ed - &st) / 1024.0 / 1024.0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) cnt[i][s[i][j] - 'a']++;
		int now = 0;
		for (int j = 0; j <= 25; j++) {
			for (int k = now; k < now + cnt[i][j]; k++) a[i][k] = j;
			if (cnt[i][j]) p1[i].push_back(now);
			now += cnt[i][j];
		}
		now = 0;
		for (int j = 25; j >= 0; j--) {
			for (int k = now; k < now + cnt[i][j]; k++) b[i][k] = j;
			if (cnt[i][j]) p2[i].push_back(now);
			now += cnt[i][j];
		}		
	}
	for (int i = 1; i <= n; i++) {
		bool f = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			int cnt1 = p1[i].size(), cnt2 = p2[j].size();
			int now1 = 0, now2 = 0, k;
			while (now1 < cnt1 || now2 < cnt2) {
				if (now1 == cnt1) k = p2[j][now2];
				else if (now2 == cnt2) k = p1[i][now1];
				else if (p1[i][now1] < p2[j][now2]) {
					k = p1[i][now1]; now1++;
				} else {
					k = p2[j][now2]; now2++;
				}
				if (a[i][k] < b[j][k]) break;
				if (a[i][k] > b[j][k]) {
					f = 1; break;
				}
			} 
			if (f) break;
		}
		if (!f) cout << 1;
		else cout << 0;
	}
	//cout << endl << 1e3 * clock() / CLOCKS_PER_SEC << "ms";
	return 0;
}