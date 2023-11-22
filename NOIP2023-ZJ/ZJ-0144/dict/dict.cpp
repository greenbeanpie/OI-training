#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int N = 3000 + 5;
char a[N][N];
int n, m;
struct node {
	vector<int> id;
	string s;
	bool operator<(const node &tmp)const {
		return s < tmp.s;
	}
}zhong[N << 1], tz[N << 1];
bool ans[N], cnt[N];
int sum, len;
int main() {
	freopen ("dict.in", "r", stdin);
	freopen ("dict.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1;i <= n; ++ i)
		scanf ("%s", a[i]);
	for (int i = 1;i <= n; ++ i)
		sort (a[i], a[i] + m);
	for (int i = 1;i <= n; ++ i) {
		zhong[i << 1].id.push_back(i);
		zhong[(i << 1) - 1].id.push_back(i);
		for (int j = 0;j < m; ++ j) {
			zhong[(i << 1) - 1].s += a[i][j];
			zhong[i << 1].s += a[i][m - j - 1];
		}
	}
	len = (n << 1);
	sort (zhong + 1, zhong + len + 1);
	int ttt = 1;
	tz[ttt] = zhong[1];
	for (int i = 2;i <= len; ++ i) {
		if (zhong[i].s != tz[ttt].s) tz[++ ttt].s = zhong[i].s;
		for (auto j : zhong[i].id)
			tz[ttt].id.push_back(j);
	}
	len = ttt;
	while (len >= 1 && sum + 1 < n) {
		for (auto j : tz[len].id) if (!cnt[j]) {
			++ sum;
			cnt[j] = 1;
		}
		-- len;
	}
	if (sum + 1 == n) {
		for (int i = 1;i <= n; ++ i) {
			if (!cnt[i]) {
				ans[i] = 1;
				break;
			}
		}
	}
	while (len >= 1 && sum < n) {
		for (auto j : tz[len].id) if (!cnt[j]) {
			++ sum;
			cnt[j] = 1;
		}
		-- len;
	}
	if (sum == n) {
		for (int i = 1;i <= len; ++ i)
			for (auto j : tz[i].id)
				if (!ans[j])
					ans[j] = 1;
	}
	for (int i = 1;i <= n; ++ i)
		printf ("%d", ans[i]);
	return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn
*/
