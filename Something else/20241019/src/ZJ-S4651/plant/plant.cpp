#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int N = 1000010;

int n;
ll k;
pii a[N];
int c[N];
vector<ll> d;
map<pii, bool> mp;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("plant.in", "r", stdin), freopen("plant.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i].second;
	for (int i = 1; i <= n; i ++) cin >> a[i].first;
	for (int i = 1; i <= n; i ++) cin >> c[i];
	cin >> k;
	if (n <= 1000) {
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				d.emplace_back(a[j] + 1ll * b[j] * c[i]);
		sort(d.begin(), d.end());
		cout << d[k - 1];
	}
	else if (k <= n) {
		sort(a + 1, a + n + 1);
		sort(c + 1, c + n + 1);
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= 2; j ++)
				d.emplace_back(a[i].second + 1ll * a[i].first * c[j]),
				mp[{i, j}] = 1;
		for (int j = 1; j <= n; j ++)
			for (int i = 1; i <= 5; i ++)
				if (!mp[{i, j}])
					d.emplace_back(a[i].second + 1ll * a[i].first * c[j]);
		sort(d.begin(), d.end());
		cout << d[k - 1];
	}
}
