#include <bits/stdc++.h>
using namespace std;

int n, m;
string s[3005];
int a[3005][30];
long long minn[3005], maxn[3005];

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> s[i];
			for (int j = 0; j < s[i].length(); j++) {
				a[i][s[i][j] - 'a' + 1]++;
			}
			for (int j = 1; j <= 26; j++) {
				for (int k = 1; k <= a[i][j]; k++) {
					minn[i] = 1ll * minn[i] * 26 + 1ll * j;
				}
			}
			for (int j = 26; j >= 1; j--) {
				for (int k = 1; k <= a[i][j]; k++) {
					maxn[i] = maxn[i] * 26 * 1ll + j * 1ll;
				}
			}
		}
		if (n == 1) {
			printf("1\n");
			return 0;
		}
		bool flag = 1;
		for (int i = 1; i <= n; i++) {
			flag = 1;
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (minn[i] >= maxn[j]) {
					printf("0");
					flag = 0;
					break;
				}
			}
		if (flag == 1) {
			printf("1");
		}
	}
	printf("\n");
	return 0;
}