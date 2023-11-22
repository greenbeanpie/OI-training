//Goodbye OI, I will miss you
//龙潜月十五
//2023.11.18
#include<bits/stdc++.h>
using namespace std;

const int N = 3e3 + 7;
int n, m;
char s[N][N];

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j)
			cin >>s[i][j];
		sort(s[i] + 1, s[i] + m + 1);
	}
	for(int i = 1; i <= n; ++i) {
		bool flag = true, G = false;
		for(int j = 1; j <= n; ++j)
			if(i != j && !G) {
				bool f = false;
				for(int k = 1; k <= m; ++k) {
					if(s[i][k] > s[j][m - k + 1]) {
						G = true;
						break;
					}
					else if(s[i][k] < s[j][m - k + 1]) {
						f = true;
						break;
					}
				}
				if(!f) {
					flag = false;
					break;
				}
			}
		cout << (int)flag;
	}
	return 0;
}