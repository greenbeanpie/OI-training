#include<iostream>
#include<algorithm>
char str[3003];
int n, m, mx[3003], mn[3003];
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> str; mn[i] = 'z' + 1;
		for (int j = 0; j < m; j++) {
			mx[i] = std::max(mx[i], (int)str[j]);
			mn[i] = std::min(mn[i], (int)str[j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		int flag = 1;
		for (int j = 1; j <= n; j++) {
			if (j == i) continue;
			flag &= (mn[i] < mx[j]);
		}
		std::cout << flag;
	}
	std::cout << std::endl;
}
