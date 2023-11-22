#include <bits/stdc++.h>
#define F(i, a, b) for (int i = a; i <= (b); i++)
#define D(i, a, b) for (int i = a; i >= (b); i--)
using namespace std;

const int N = 3005;
int n, m, mx[N], mn[N];
string s[N];

signed main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	F(i, 1, n) {
		cin >> s[i];
		mn[i] = 1e9;
		for (auto c : s[i]) {
			mn[i] = min(mn[i], c - 'a');
			mx[i] = max(mx[i], c - 'a');
		}
	}
	F(i, 1, n) {
		bool flag = true;
		F(j, 1, n) {
			if (i == j) continue;
			if (mn[i] >= mx[j]) {
				flag = false;
				break;
			}
		}
		cout << flag;
	}
	return 0;
}