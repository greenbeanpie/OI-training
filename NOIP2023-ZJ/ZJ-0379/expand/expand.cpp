//Goodbye OI, I will miss you
//龙潜月十五
//2023.11.18
#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;
int c, n, m, q, x[N], y[N], tx[N], ty[N];

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> q;
	for(int i = 1; i <= n; ++i)
		cin >> x[i];
	for(int i = 1; i <= m; ++i)
		cin >> y[i];
	if(c == 1) {
		cout << (x[1] != y[1]);
		while(q--) {
			tx[1] = x[1], ty[1] = y[1];
			int kx, ky;
			cin >> kx >> ky;
			for(int i = 1, px, vx; i <= kx; ++i)
				cin >> px >> vx, tx[px] = vx;
			for(int i = 1, py, vy; i <= ky; ++i)
				cin >> py >> vy, ty[py] = vy;
			cout << (tx[1] != ty[1]);
		}
	}
	else if(c == 2) {
		if((long long)(x[1] - y[1]) * (x[n] - y[m]) > 0)
			cout << 1;
		else
			cout << 0;
		while(q--) {
			tx[1] = x[1], tx[n] = x[n], ty[1] = y[1], ty[m] = y[m];
			int kx, ky;
			cin >> kx >> ky;
			for(int i = 1, px, vx; i <= kx; ++i)
				cin >> px >> vx, tx[px] = vx;
			for(int i = 1, py, vy; i <= ky; ++i)
				cin >> py >> vy, ty[py] = vy;
			if((long long)(tx[1] - ty[1]) * (tx[n] - ty[m]) > 0)
				cout << 1;
			else
				cout << 0;
		}
	}
	return 0;
}