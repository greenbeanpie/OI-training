#include <iostream>
#define ll long long
using namespace std;
const int N = 3e3 + 10;
int n, m; char s[N], Max[N], Min[N];
signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
		cin >> s + 1; Max[i] = 0, Min[i] = 127;
		for (int j = 1; j <= m; ++ j) Max[i] = max(Max[i], s[j]), Min[i] = min(Min[i], s[j]);
	}
	for (int i = 1; i <= n; ++ i) {
		bool flag = true;
		for (int j = 1; j <= n; ++ j) if (i != j) flag &= Min[i] < Max[j];
		cout << flag;
	}
	cout << '\n';
	return 0;
}
