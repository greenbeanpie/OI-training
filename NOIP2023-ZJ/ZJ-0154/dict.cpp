#include <bits/stdc++.h>
using namespace std;
string s[3005], mi[3005], mx[3005];
int a[30];
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	int i, j, k, n, m, t, flag;
	string p;
	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		cin >> s[i];
		for (j = 0; j < 26; j++) {
			a[j] = 0;
		}
		for (j = 0; j < m; j++) {
			a[s[i][j] - 'a']++;
		}
		mi[i] = mx[i] = "";
		for (j = 0; j < 26; j++) {
			for (k = 1; k <= a[j]; k++) {
				mi[i] += (char)('a' + j);
			}
		}
		for (j = 25; j >= 0; j--) {
			for (k = 1; k <= a[j]; k++) {
				mx[i] += (char)('a' + j);
			}
		}
	}
	p = mx[1];
	t = 1;
	for (i = 2; i <= n; i++) {
		for (j = 0; j < m; j++) {
			if (p[j] < mx[i][j]) {
				break;
			} else if (p[j] > mx[i][j]) {
				p = mx[i];
				t = i;
				break;
			}
		}
	}
	for (i = 1; i <= n; i++) {
		if (i == t) {
			flag = 1;
		} else {
			flag = 0;
			for (j = 0; j < m; j++) {
				if (mi[i][j] < p[j]) {
					flag = 1;
					break;
				} else if (mi[i][j] > p[j]) {
					flag = 0;
					break;
				}
			}
		}
		cout << flag;
	}
	cout << endl;
	return 0;
}
