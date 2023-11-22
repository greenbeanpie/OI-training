/*
Time complexity: O(n^2)
Estimated score: 100

qiu ni le, bie jia.

written at 9:47.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 10;

int n, m, mn[N], mx[N];

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		mn[i] = 26;
		string s; cin >> s;
		for(auto ch: s) {
			mn[i] = min(mn[i], ch - 'a');
			mx[i] = max(mx[i], ch - 'a');
		}
	}
	for(int i = 1; i <= n; ++ i) {
		bool f = 1;
		for(int j = 1; j < i; ++ j) f &= (mn[i] < mx[j]);
		for(int j = i + 1; j <= n; ++ j) f &= (mn[i] < mx[j]);
		if(f) cout << 1;
		else cout << 0;
	}
	return 0;
}