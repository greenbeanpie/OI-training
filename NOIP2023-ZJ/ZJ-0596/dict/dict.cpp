#include <bits/stdc++.h>

using namespace std;

const int N = 3010;
const int T = 30;

int n, m;

struct STR {
//	char s0[N], s1[N];
	string s0, s1, s2;
	int al[T];
	int cur;
} S[N];

string ans;
// char soo[N][N];

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	if (n == 1) {
		putchar('1');
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> S[i].s0;
		for (int j = 0; j < m; j++) {
			S[i].al[S[i].s0[j] - 'a']++;
		}
		for (int p = 25; p >= 0; p--) {
			for (int j = 1; j <= S[i].al[p]; j++) {
//				S[i].s1[S[i].cur++] = p + 'a';
//				soo[i][S[i].cur++] = p + 'a';
				S[i].s1 += p + 'a';
			}
		}
		for (int j = 0; j < m; j++) {
			S[i].s2 += S[i].s1[m - j - 1];
		}
//		cout << S[i].s1 << " " << S[i].s2 << endl;
	}
	
	for (int i = 1; i <= n; i++) {
		bool flag = 0;
		for (int j = 1; j <= n; j++) {
			if (j == i) {
				continue;
			}
			if (S[i].s2 >= S[j].s1) {
				ans += '0';
				flag = 1;
				break;
			}
		}
		if (!flag) {
			ans += '1';
		}
	}
	cout << ans;
	return 0;
}