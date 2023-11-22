// Think twice, code once.
#include <set>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define eputchar(c) putc(c, stderr)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eputs(str) fputs(str, stderr), putc('\n', stderr)
using namespace std;

int type, T, n, m, k, d;

namespace BruteForce {
	vector<pair<int, int>> vec[100005];
	struct SegmentTree {
#define ls(x) (x * 2)
#define rs(x) (x * 2 + 1)

		long long mx[400005], lzy[400005];
		int l[400005], r[400005];

		void build(int ll, int rr, int now = 1) {
			l[now] = ll, r[now] = rr;
			mx[now] = lzy[now] = 0;
			if (ll == rr) return ;
			int mid = (ll + rr) / 2;
			build(ll, mid, ls(now)), build(mid + 1, rr, rs(now));
			return ;
		}
		void down(int now) {
			mx[ls(now)] += lzy[now], mx[rs(now)] += lzy[now];
			lzy[ls(now)] += lzy[now], lzy[rs(now)] += lzy[now];
			lzy[now] = 0;
			return ;
		}
		void update(int ll, int rr, long long val, int now = 1) {
			if (ll <= l[now] && r[now] <= rr) {mx[now] += val; lzy[now] += val; return ;}
			if (lzy[now]) down(now);
			int mid = (l[now] + r[now]) / 2;
			if (ll <= mid) update(ll, rr, val, ls(now));
			if (mid < rr) update(ll, rr, val, rs(now));
			mx[now] = max(mx[ls(now)], mx[rs(now)]);
			return ;
		}
		long long query(int ll, int rr, int now = 1) {
			if (ll <= l[now] && r[now] <= rr) return mx[now];
			if (lzy[now]) down(now);
			int mid = (l[now] + r[now]) / 2;
			long long res = ~0x3f3f3f3f3f3f3f3f;
			if (ll <= mid) res = max(res, query(ll, rr, ls(now)));
			if (mid < rr) res = max(res, query(ll, rr, rs(now)));
			return res;
		}

#undef ls
#undef rs
	} tr;

	void main() {
		while (T--) {
			cin >> n >> m >> k >> d;
			for (int i = 1; i <= n; i++) vector<pair<int, int>>().swap(vec[i]);
			while (m--) {
				int x, y, v;
				cin >> x >> y >> v;
				vec[x].emplace_back(y, v);
			}
			tr.build(1, n + 1);
			for (int i = 1; i <= n; i++) {
				int s = n + 1 - i;
				long long dp0 = tr.query(s + 1, min(s + 1 + k, n + 1));
				tr.update(s, s, dp0);
				tr.update(s + 1, s + k, -d);
				for (auto j : vec[i])
					if (j.first <= min(i, k))
						tr.update(s + j.first, min(s + k, n + 1), j.second);
			}
			cout << tr.query(1, 1 + k) << '\n';
		}
		return ;
	}
}

namespace SpecialB {
	int l[100005], r[100005];
	long long v[100005], sum[100005], dp[100005];

	void main() {
		while (T--) {
			cin >> n >> m >> k >> d;
			int _m = m;
			m = 0;
			long long ans = 0;
			for (int i = 1; i <= _m; i++) {
				int x, y, _v;
				cin >> x >> y >> _v;
				m++;
				l[m] = x - y + 1, r[m] = x;
				v[m] = _v - (long long)y * d;
				if (v[m] <= 0) m--;
				else ans += v[m];
			}
			// cout << ans << '\n';
			// continue;
			for (int i = 1; i <= m; i++) sum[i] = sum[i - 1] + v[i];
			multiset<long long> s;
			dp[0] = 0;
			r[0] = -1;
			for (int i = 1, lst = 1; i <= m; i++) {
				if (r[i - 1] + 1 != l[i]) {
					dp[i] = dp[i - 1] + v[i];
					multiset<long long>().swap(s);
					lst = i;
				} else if (r[i] - l[lst] + 1 > k) {
					// eputs("?");
					while (r[i] - r[lst] > k)
						s.erase(s.find(dp[lst - 1] - sum[lst])), lst++;
					dp[i] = *prev(s.end()) + sum[i];
				} else dp[i] = dp[i - 1] + v[i];
				dp[i] = max(dp[i - 1], dp[i]);
				s.insert(dp[i - 1] - sum[i]);
			}
			cout << dp[m] << '\n';
		}
		return ;
	}
}

int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> type >> T;
	if (type <= 14) BruteForce::main();
	else if (type == 17 || type == 18) SpecialB::main();
	return 0;
}