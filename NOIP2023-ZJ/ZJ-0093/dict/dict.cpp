#include<bits/stdc++.h>
using namespace std;

#define Reimu inline void
#define Marisa inline int

typedef long long LL;
typedef unsigned long long ULL;

typedef pair<int, int> Pii;
#define fi first
#define se second

#define ALL(v) v.begin(), v.end()

const int N = 3010;

int n, m;
int a[N], f[N], cnt[30];

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1, t; i <= n; ++i) {
		string s; cin >> s;
		++cnt[(t = *max_element(ALL(s)) & 31)];
		f[i] = (a[i] = *min_element(ALL(s)) & 31) == t;
	}
	for (int i = 26; i; --i) cnt[i] += cnt[i + 1];
	for (int i = 1; i <= n; ++i) cout << (cnt[a[i] + 1] == n - f[i]);
	cout << '\n';
	return 0;
}

