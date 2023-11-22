#include <iostream>
#include <stdio.h>
using namespace std;

const int maxN = 3010;

int n, m;
int cnt[maxN][30];
char s[maxN][maxN], ans[maxN];

int main(void) {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= m; j++) {
			cnt[i][s[i][j] - 'a']++;
		}
		/*for (int j = 0; j <= 26; j++) {
			cout << cnt[i][j] << ' ';
		}
		cout << endl;*/
	}
	
	int mnp = 1, mnp2 = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 25; j >= 0; j--) {
			if (cnt[i][j] < cnt[mnp][j]) {
				swap(mnp, mnp2);
				mnp = i;
				break;
			}
			else if (cnt[i][j] > cnt[mnp][j]) {
				break;
			}
		}
		if (mnp != i) {
			if (!mnp2) {
				mnp2 = i;
				continue;
			}
			for (int j = 25; j >= 0; j--) {
				if (cnt[i][j] < cnt[mnp2][j]) {
					mnp2 = i;
					break;
				}
				else if (cnt[i][j] > cnt[mnp2][j]) {
					break;
				}
			}
		}
	}
	//cout << mnp << ' ' << mnp2 << endl;
	
	int l, r;
	for (int i = 1; i <= n; i++) {
		if (i == mnp) {
			l = 0, r = 25;
			while (!cnt[i][l] && l <= 25) l++;
			while (!cnt[mnp2][r] && r >= 0) r--;
			if (l < r || (l == r && cnt[i][l] > cnt[i][r])) {
				ans[i] = '1';
			}
			else {
				ans[i] = '0';
			}
		}
		else {
			l = 0, r = 25;
			while (!cnt[i][l] && l <= 25) l++;
			while (!cnt[mnp][r] && r >= 0) r--;
			if (l < r || (l == r && cnt[i][l] > cnt[i][r])) {
				ans[i] = '1';
			}
			else {
				ans[i] = '0';
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		putchar(ans[i]);
	}
	putchar('\n');
	return 0;
}