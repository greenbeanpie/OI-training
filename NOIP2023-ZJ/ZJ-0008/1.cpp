#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define ll long long
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define per(i, a, b) for(int i = (a); i >= (b); --i)
#define vi vector<int>
#define PB emplace_back
#define siz(a) ((int) a.size())

const int N = 3000;
int a, b, mn[N + 5], mx[N + 5];
char s[N + 5][N + 5];

signed main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> a >> b;
	rep(i, 1, a) {
		cin >> s[i] + 1;
		mn[i] = 26;
		rep(j, 1, b) mn[i] = min(mn[i], s[i][j] - 'a'), mx[i] = max(mx[i], s[i][j] - 'a');
	}
	rep(i, 1, a) {
		bool ans = 1;
		rep(j, 1, a) if(i != j) ans &= mn[i] < mx[j];
		cout << ans;
	}
	return 0;
}