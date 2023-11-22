#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int c, t, n, m, ans = 0, ii, jj;
char v, x[N];

int main () {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin >> c >> t;
	
	if (c == 3 || c == 4) {
		while (t --) {
			cin >> n >> m; ans = 0;
			memset(x, 'T', sizeof(x));
			for (int i = 1; i <= m; i++) { 
				cin >> v >> ii; 
				x[ii] = v; 
			}
			for (int i = 1; i <= n; i++) {
				if (x[i] == 'U') ans ++;
			} cout << ans << endl;
		} return 0;
	} return 0;
}