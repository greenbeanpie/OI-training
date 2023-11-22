/*
Luogu uid = 344543, Misty-Hazers
NOIp rp += inf
*/

#include <bits/stdc++.h>

using i64 = long long;

signed main(){
	
	freopen ("dict.in", "r", stdin);
	freopen ("dict.out", "w", stdout);
	
	int n, m;
	std::cin >> n >> m;
	
	std::vector<std::array<int, 26>> a(n);
	std::vector<int> pre(n, -1), suf(n, -1);
	
	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < 26; j++) {
			a[i][j] = 0;
		}
		
		std::string s;
		std::cin >> s;
		
		for (auto p : s) {
			a[i][p - 'a'] ++;
		}
		
		for (int j = 0; j < 26; j++) {
			if (a[i][j] == 0) continue;
			if (pre[i] == -1) {
				pre[i] = j;
			}
			suf[i] = j;
		}
	} 
	
	for (int i = 0; i < n; i++) {
		bool flag = false;
		
		for (int j = 0; j < n; j++) {
			if (j == i) continue;
			if (pre[i] >= suf[j]) {
				flag = true;
			}
		}
		
		std::cout << ((!flag) ? "1" : "0");
	}
	
	std::cout << "\n";
	return 0;
}
