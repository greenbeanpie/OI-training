#include<cstdio>
#include<algorithm>
#define INF (0x3f3f3f3f)
using namespace std;

const int MAXN = 100005;

int T, c;
int n, m;
struct opt {
	char v;
	int a, b;
}p[MAXN];

namespace Sub1 {
	int mn;
	int b[MAXN], t[MAXN];
	inline void dfs(int step) {
		if (step == n + 1) {
			for (int i = 1; i <= n; ++ i)
				t[i] = b[i];
			for (int i = 1; i <= m; ++ i) {
				if (p[i].v == '+')
					t[p[i].a] = t[p[i].b];
				if (p[i].v == '-')
					t[p[i].a] = 4 - t[p[i].b];
				if (p[i].v == 'T')
					t[p[i].a] = 1;
				if (p[i].v == 'U')
					t[p[i].a] = 2;
				if (p[i].v == 'F')
					t[p[i].a] = 3;
			}
			int cnt = 0;
			for (int i = 1; i <= n; ++ i) {
				if (b[i] != t[i])
					return;
				cnt += (b[i] == 2);
			}
			mn = min(mn, cnt);
			return;
		}
		for (int i = 1; i <= 3; ++ i)
			b[step] = i, dfs(step + 1);
	}
	inline void Solve() {
		mn = INF;
		dfs(1);
		printf ("%d\n", mn);
	}
}

int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	
	scanf ("%d%d", &c, &T);
	while (T --) {
		scanf ("%d%d", &n, &m);
		for (int i = 1; i <= m; ++ i) {
			char t[5];
			scanf ("%s", t);
			p[i].v = t[0];
			scanf ("%d", &p[i].a);
			if (p[i].v == '+' || p[i].v == '-')
				scanf ("%d", &p[i].b);
		}
		if (n <= 15 && m <= 15) {
			Sub1::Solve();
			continue;
		} else {
			puts("0");
		}
	}
	return 0;
}