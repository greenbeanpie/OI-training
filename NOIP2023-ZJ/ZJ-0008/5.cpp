#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define ll long long
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define per(i, a, b) for(int i = (a); i >= (b); --i)
#define vi vector<int>
#define PB emplace_back
#define siz(a) ((int) a.size())

const int N = 5e5;
int TT, a, b, T, c[N + 5], d[N + 5], s[N + 5], t[N + 5], qu[N + 5];

int F(int x, int y) {
	if(s[x] == t[y]) return 2;
	return s[x] > t[y];
}
bool solve() {
	if(F(1, 1) == 2 || F(a, b) == 2 || F(1, 1) != F(a, b)) return 0;
	int c = a, d = b;
	if(!F(1, 1)) swap(s, t), swap(c, d);
	int j = 1, r = 1;
	qu[1] = 1;
	rep(i, 1, c) {
		if(t[qu[r]] >= s[i]) {
			while(r && t[qu[r]] >= s[i]) --r;
			if(!r) return 0;
			j = qu[r];
		}
		else {
			for(; j < d && t[j + 1] < s[i]; ) {
				++j;
				while(r && t[qu[r]] >= t[j]) --r;
				qu[++r] = j;
			}
		}
	}
	return j == d;
}

signed main() {
	freopen("expand5.in", "r", stdin);
	freopen(".out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> TT >> a >> b >> T;
	rep(i, 1, a) cin >> c[i];
	rep(i, 1, b) cin >> d[i];
	rep(i, 1, a) s[i] = c[i];
	rep(i, 1, b) t[i] = d[i];
	cout << solve();
	int x, y, z, w;
	while(T--) {
		cerr << T << endl;
		rep(i, 1, a) s[i] = c[i];
		rep(i, 1, b) t[i] = d[i];
		cin >> x >> y;
		rep(i, 1, x) {
			cin >> z >> w;
			s[z] = w;
		}
		rep(i, 1, y) {
			cin >> z >> w;
			t[z] = w;
		}
		cout << solve();
	}
	return 0;
}