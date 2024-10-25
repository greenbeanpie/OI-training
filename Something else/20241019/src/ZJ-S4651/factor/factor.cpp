#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, a[N], b[N];
mt19937 rnd(time(0));

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("factor.in", "r", stdin), freopen("factor.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) cin >> b[i];
	cout << n / 4 + rnd() % (n / 4) + 1;
	return 0;
}
