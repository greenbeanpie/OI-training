#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+10;
int n, a[N], b[N], f[N];
vector<int> ls;
int bit[N];

inline void add(int pos, int x) {
	pos ++;
	for(int i = pos; i < N; i += (i & (-i)))
		bit[i] = max(bit[i], x);
}

inline int query(int pos) {
	pos ++;
	int res = 0;
	for(int i = pos; i; i -= (i & (-i)))
		res = max(res, bit[i]);
	return res;
}

inline int find(int x) {
	return lower_bound(ls.begin(), ls.end(), x) - ls.begin() + 1;
}

signed main() {
	freopen("factor.in", "r", stdin);
	freopen("factor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i] >> b[i], ls.push_back(a[i] * (n + 1) + b[i]), f[i] = 1;
	sort(ls.begin(), ls.end());
	ls.erase(unique(ls.begin(), ls.end()), ls.end());
//	for(int i : ls) cout << i << ' ';
//	cout << '\n';
	int ans = 0;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j < i; j ++)
			if(a[j] < a[i] && b[j] < b[i])
				f[i] = max(f[i], f[j] + 1); 
		ans = max(ans, f[i]);
	}
	cout << ans;
}
