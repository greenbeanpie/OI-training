#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 80;

int n, a[N], sum, t;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("qigong.in", "r", stdin), freopen("qigong.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (i == 1) sum = t = a[i];
		if (t >= a[i]) t >>= 1;
		else {
			int d = a[i] - t;
			t += d;
			t >>= 1;
			sum += d;
		}
		cout << sum << ' '; 
	}
	return 0;
}
