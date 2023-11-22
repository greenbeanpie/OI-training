#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[3005][3005];
int cnt[3005][27];
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) cin >> s[i][j];
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) cnt[i][s[i][j] - 'a'] ++;
	}
	for(int i = 1; i <= n; ++i) {
		int flg = 0;
		for(int j = 1; j <= n; ++j) {
			if(j != i) {
				int st = 25, ed = 0, cnti = 0, cntj = 0;
				for(int k = 0; k <= 25; ++k) {
					if(cnt[i][k]) {
						st = min(st, k);
						cnti ++;
					}
				}
				for(int k = 25; k >= 0; --k) {
					if(cnt[j][k]) {
						ed = max(ed, k);
						cntj ++;
					}
				}
				if(st > ed) {
					flg = 1;
					break;
				}
				if(st == ed) {
					if(cnti > 0) {
						flg = 1;
						break;
					}
					if(cnt[i][st] <= cnt[j][ed]) {
						flg = 1;
						break;
					}
				}
			}
		}
		if(flg) cout << "0";
		else cout << "1";
	}
	return 0;
}