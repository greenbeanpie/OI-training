#include<cstdio>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;

const int MAXN = 10005;

int C, T;
int n, m, K, d;
struct Chg {
	int x, y, v;
	inline bool operator < (const Chg &T) const {
		return y < T.y;
	}
}a[MAXN];
vector<Chg>vec[MAXN];

namespace Sub1 {
	int mx, b[MAXN];
	int ctn[MAXN], sum[105][105];
	inline void Init() {
		for (int i = 1; i <= n; ++ i) {
			sort(vec[i].begin(), vec[i].end());
			int lst = 1;
			sum[i][0] = 0;
			for (auto u : vec[i]) {
				for (int j = lst + 1; j < u.y; ++ j)
					sum[i][j] = sum[i][j - 1];
				if (lst != u.y + 1) sum[i][u.y] = sum[i][u.y - 1];
				sum[i][u.y] += u.v;
				lst = u.y + 1;
			}
		}
	}
	inline void dfs(int step, int now) {
		if (step == n + 1) {
			mx = max(mx, now);
			return;
		}
		b[step] = 0;
		dfs(step + 1, now);
		b[step] = 1; now -= d;
		ctn[step] = ctn[step - 1] + 1;
		if (ctn[step] > K) return;
		now += sum[step][ctn[step]];
		dfs(step + 1, now);
	}
	inline void Solve() {
		mx = 0;
		Init();
		dfs(1, 0);
		printf ("%lld\n", mx);
	}
}

signed main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	
	scanf ("%lld%lld", &C, &T);
	while (T --) {
		scanf ("%lld%lld%lld%lld", &n, &m, &K, &d);
		for (int i = 1; i <= n; ++ i) vec[i].clear();
		for (int i = 1; i <= m; ++ i)
			scanf ("%lld%lld%lld", &a[i].x, &a[i].y, &a[i].v), 
			vec[a[i].x].push_back(a[i]);
		if (n <= 20) {
			Sub1::Solve();
			continue;
		} else {
			puts("0");
		}
	}
	return 0;
}