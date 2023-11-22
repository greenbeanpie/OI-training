// You know I'm not alone...
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;
constexpr int maxn = 3e3 + 5;
int n, m;
string a[maxn];
string mn[maxn], mx[maxn];
auto main() -> int {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		mn[i] = a[i], mx[i] = a[i];
		sort(mn[i].begin(), mn[i].end());
		sort(mx[i].begin(), mx[i].end(), 
			[](char x, char y) -> bool { return x > y; });
	}
	// cerr << clock() * 1.0 / CLOCKS_PER_SEC << "\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j && mn[i] >= mx[j]) {
				goto fail;
			}
		}
		cout << "1";
		continue;
	fail:
		cout << "0";
	}
	// cerr << clock() * 1.0 / CLOCKS_PER_SEC << "\n";
	cout << "\n";
	return 0;
}
