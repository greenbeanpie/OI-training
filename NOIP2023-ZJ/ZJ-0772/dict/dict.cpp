#include <bits/stdc++.h>
using namespace std;
int n, m, a[3010][3010];
string w;
void work1() {
	int k = 1, x = a[1][1];
	for (int i = 2; i <= n; ++i) {
		if (a[i][1] < x) {
			x = a[i][1];
			k = i;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (k == i) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
}
void work2() {
	for (int i = 1; i <= n; ++i) {
		int s = a[i][1] * 10 + a[i][2];
		if (a[i][1] > a[i][2]) {
			s = a[i][2] * 10 + a[i][1];
		}
		bool flag = 1;
		for (int j = 1; j <= n; ++j) {
			if (!flag) {
				break;
			}
			int s1 = a[j][1] * 10 + a[j][2], s2 = a[j][2] * 10 + a[j][1];
			if (j != i) {
				if (s1 < s) {
					if (s2 < s) {
						flag = 0;
					}
				}
			}
		}
		if (flag) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
}
signed main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios :: sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		string w;
		cin >> w;
		for (int j = 1; j <= m; ++j) {
			a[i][j] = w[j - 1] - 'a' + 1;
		}
	}
	if (m == 1) {
		work1();
		return 0;
	}
	if (m == 2) {
		work2();
		return 0;
	}
//	work3();
	return 0;
}


// grade : 70
