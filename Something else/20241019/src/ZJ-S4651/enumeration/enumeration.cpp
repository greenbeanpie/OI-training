#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100010;

int n, n3, p;
struct Tuple {
	int a, b, c;
	friend bool operator < (Tuple a, Tuple b) {
		if (a.a < b.a) return 1;
		if (a.a == b.a) {
			if (a.b < b.b) return 1;
			if (a.b == b.b) {
				if (a.c < b.c) return 1;
				return 0;
			}
			return 0;
		}
		return 0;
	}
} w[N];
int tot;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("enumeration.in", "r", stdin), freopen("enumeration.out", "w", stdout);
	cin >> n >> n3 >> p;
	n = n * n + 1;
	for (int a = 1; a <= p; a ++)
		for (int b = 0; b <= p; b ++)
			for (int c = n3 + 1; c <= p; c ++)
				if ((n % a + b) % c == n3)
					w[++ tot] = {a, b, c};
	cout << tot << '\n';
	tot = min(tot, (int)(1e5));
	sort(w + 1, w + tot + 1);
	for (int i = 1; i <= tot; i ++)
		cout << w[i].a << ' ' << w[i].b << ' ' << w[i].c << '\n';
	return 0;
}
