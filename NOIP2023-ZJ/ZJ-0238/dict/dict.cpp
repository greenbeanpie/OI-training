#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
ull dic[] = {998244353ull, 3221225477ull, 2997924581ull, 314159265ull};
mt19937 rnd(time(0));
string a[3005];
string b[3005], c[3005];
int ans[3005];
ull hb[3005][3005], hc[3005][3005];
int n, m;
inline bool check(int i, int j) {
	int l = 0, r = m + 1;
	while(l + 1 < r) {
		int mid = (l + r) >> 1;
		if(hb[i][mid] == hc[j][mid]) l = mid;
		else r = mid;
	}
	//cout << i << " " << j << " " << l << endl;
	if(l == m) return 1;
	return b[i][l + 1] > c[j][l + 1];
}
int cnt[32];
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		b[i] = " " + a[i];
		for(int j = 1; j <= m; j++) cnt[b[i][j] - 'a']++;
		for(int k = 0, j = 0; k < 26; k++) {
			while(cnt[k]) cnt[k]--, b[i][++j] = k + 'a';
		}
		c[i] = b[i];
		reverse(c[i].begin() + 1, c[i].end());
	}
	const ull base = dic[rnd() & 3];
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) hb[i][j] = hb[i][j - 1] * base + b[i][j];
		for(int j = 1; j <= m; j++) hc[i][j] = hc[i][j - 1] * base + c[i][j];
	}
//	for(int i = 1; i <= n; i++) cout << b[i] << endl;
//	cout << endl;
//	for(int i = 1; i <= n; i++) cout << c[i] << endl;
//	cout << endl;
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= m; j++) cout << hb[i][j] << " ";
//		cout << endl;
//		for(int j = 1; j <= m; j++) cout << hc[i][j] << " ";
//		cout << endl;
//	}

	for(int i = 1; i <= n; i++) {
		ans[i] = 1;
		for(int j = 1; j <= n; j++) {
			if(i == j) continue;
			if(check(i, j)) {
				ans[i] = 0;
				break;
			}
		}
	}
	for(int i = 1; i <= n; i++) cout << ans[i];
	cout << endl;
	return 0;
}
