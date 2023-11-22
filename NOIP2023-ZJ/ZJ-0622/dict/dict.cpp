#include<bits/stdc++.h>
using namespace std;
const int N = 3005;
int n, m;
string s[2][N], str;
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> str;
		sort(str.begin(),str.end());
		s[0][i] = str;
		sort(str.begin(), str.end(), greater<int>());
		s[1][i] = str;
	}
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		bool fl = 1;
		for (int j = 1; j <= n; ++j) {
			if (j != i) {
				if (s[0][i] > s[1][j]) {
					fl = 0;
					break;
				}
			}
		}
		cout << fl;
	}
	cout << endl;
	return 0;
}