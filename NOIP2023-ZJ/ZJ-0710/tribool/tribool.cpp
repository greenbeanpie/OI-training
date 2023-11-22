#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int c, t, n, m, cnt;
int a[100005];

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin >> c >> t;
	while(t--) {
		cnt = 0;
		cin >> n >> m;
		for(int i = 1; i <= n; i++) a[i] = i;
		while(m--) {
			char op;
			cin >> op;
			if(op == 'T') {
				int x;
				cin >> x;
				a[x] = 1e5 + 1;
			} else if(op == 'F') {
				int x;
				cin >> x;
				a[x] = 1e5 + 2;
			} else if(op == 'U') {
				int x;
				cin >> x;
				a[x] = 1e5 + 3;
			} else if(op == '+') {
				int x, y;
				cin >> x >> y;
				a[x] = a[y];
			} else if(op == '-') {
				int x, y;
				cin >> x >> y;
				a[x] = -a[y];
			}
		}
		for(int k = 1; k <= n; k++) {
			for(int i = 1; i <= n; i++) {
				if(a[i] == 0 - i || a[i] == 1e5 + 3) {
					a[i] = 1e5 + 3;
					for(int j = 1; j <= n; j++) {
						if(abs(a[j]) == i) a[j] = 1e5 + 3;
					}
				}
			}
		}

		for(int i = 1; i <= n; i++) {
			if(abs(a[i]) == 1e5 + 3) cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}