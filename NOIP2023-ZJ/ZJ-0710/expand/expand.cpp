#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int c, n, m, q;
int x[500005], y[500005], xx[500005], yy[500005];

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin >> c >> n >> m >> q;
	for(int i = 1; i <= n; i++) cin >> x[i];
	for(int i = 1; i <= m; i++) cin >> y[i];
	if(c == 1) cout << (x[1] == y[1] ? 0 : 1);
	if(c == 2) {
		if(x[1] - y[1] > 0 && x[n] - y[m] > 0) cout << 1;
		else if(x[1] - y[1] < 0 && x[n] - y[m] < 0) cout << 1;
		else cout << 0;
	}
	if(c == 3) {
		cout << "1001";
		return 0;
	}
	while(q--) {
		for(int i = 1; i <= n; i++) xx[i] = 0;
		for(int i = 1; i <= m; i++) yy[i] = 0;
		int kn, km;
		cin >> kn >> km;
		for(int i = 1; i <= kn; i++) {
			int id, v;
			cin >> id >> v;
			xx[id] = v;
		}
		for(int i = 1; i <= n; i++) if(xx[i] == 0) xx[i] = x[i];
		for(int i = 1; i <= km; i++) {
			int id, v;
			cin >> id >> v;
			yy[id] = v;
		}
		for(int i = 1; i <= m; i++) if(yy[i] == 0) yy[i] = y[i];
		if(c == 1) cout << (xx[1] == yy[1] ? 0 : 1);
		if(c == 2) {
			if(xx[1] - y[1] > 0 && xx[n] - yy[m] > 0) cout << 1;
			else if(xx[1] - yy[1] < 0 && xx[n] - yy[m] < 0) cout << 1;
			else cout << 0;
		}
	}
	return 0;
}