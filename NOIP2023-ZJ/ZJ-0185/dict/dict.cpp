#include <bits/stdc++.h>

int n, m;
std::string a[3005];

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	
	std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
	std::cin >> n >> m;
	int pmin = 0;
	a[0] = std::string(m, 'z');
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		std::sort(a[i].begin(), a[i].end(), std::greater<>());
		if (a[i] < a[pmin]) pmin = i;
	}
	for (int i = 1; i <= n; i++) {
		std::string cur(a[i]);
		std::reverse(cur.begin(), cur.end());
		if (i == pmin || cur < a[pmin]) std::cout << '1';
		else std::cout << '0';
	}
}