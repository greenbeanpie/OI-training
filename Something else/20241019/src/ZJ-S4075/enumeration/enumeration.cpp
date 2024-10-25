#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+10;
int p, n, m;
int res[N][3];

signed main() {
	freopen("enumeration.in", "r", stdin);
	freopen("enumeration.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> p;
	n = n * n + 1;
	int ans = 0, num = 0;
	for(int a = 1; a <= p; a ++) {
		int x = n % a;
		if(n % a <= m) {
			int b = m - n % a;
			num += p - m;
			if(ans < 1e5) {
				for(int c = m + 1; c <= p; c ++) {
					res[++ ans][0] = a;
					res[ans][1] = b;
					res[ans][2] = c;
					if(ans == 1e5) break;
				}
			}
		}
		for(int i = max(m * 2 + 1, x); i <= x + p; i ++) { // i % c == m -> (b + x) % c == m
			int b = i - x;
			for(int c = m + 1; c <= i - m && c <= p; c ++)
				if((i - m) % c == 0) {
					num ++;
					if(ans < 1e5) {
						res[++ ans][0] = a;
						res[ans][1] = b;
						res[ans][2] = c;
					}
				}
		}
	}
	cout << num << '\n';
	for(int i = 1; i <= ans; i ++)
		cout << res[i][0] << ' ' << res[i][1] << ' ' << res[i][2] << '\n';
}
