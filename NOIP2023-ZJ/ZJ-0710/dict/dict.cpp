#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
char words[3005][3005];

bool cmp(char a, char b) {
	return a > b;
}

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	if(n == 1) cout << 1 << endl;
	else if(m == 1) {
		char s = 'z';
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cin >> words[i][j];
				if(words[i][j] < s) s = words[i][j];
			}
		}
		for(int i = 1; i <= n; i++) {
			if(s == words[i][1]) cout << 1;
			else cout << 0;
		}
	} else {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cin >> words[i][j];
			}
			sort(words[i] + 1, words[i] + m + 1);
		}
		for(int i = 1; i <= n; i++) {
			bool flag = true;
			for(int j = 1; j <= n; j++) {
				if(i == j) continue;
				if(!flag) break;
				for(int k = 1; k <= m; k++) {
					if(words[i][k] < words[j][m - k + 1]) break;
					if(words[i][k] > words[j][m - k + 1]) {
						flag = false; break;
					}
					if(k == m && words[i][k] == words[j][m - k + 1]) flag = false;
				}
			}
			if(flag) cout << 1;
			else cout << 0;
		}
	}
	return 0;
}