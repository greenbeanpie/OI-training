#include <bits/stdc++.h>

#define i64 long long
#define all(x) x.begin(), x.end()
#define seg(a, l, r) a + l, a + r + 1
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

const int N = 2e5 + 5, M = 5e5 + 5;

struct Edge
{
	int u, v, nxt;
	i64 a, b;

	Edge() {}
	Edge(int _u, int _v, i64 _a, i64 _b, int _nxt)
	{
		u = _u;
		v = _v;
		nxt = _nxt;
		a = _a;
		b = _b;
	}

} E[M << 1];

int n, m, tot, cycleTot;
int head[N], fa[N], faEdge[N];
bool vis[M << 1];
i64 sumA, sumB;
vector<pair<i64, i64>> cycle[N];

void addEdge(int u, int v, i64 a, i64 b)
{
	E[tot] = Edge(u, v, a, b, head[u]);
	head[u] = tot++;
}

void dfs(int u, int f, int last)
{
	fa[u] = f;
	faEdge[u] = (last ^ 1);

	for (int i = head[u]; ~i; i = E[i].nxt)
	{
		if (vis[i])
			continue;

		int v = E[i].v;
		if (fa[v] != 0)
		{
			cycleTot++;

			int t = u;
			while (t != v)
			{
				cycle[cycleTot].push_back(make_pair(E[faEdge[t]].a, E[faEdge[t]].b));
				t = E[faEdge[t]].v;
			}

			cycle[cycleTot].push_back(make_pair(E[i].a, E[i].b));
			vis[i] = vis[i ^ 1] = true;
		}
		else
			vis[i] = vis[i ^ 1] = true, dfs(v, u, i);
	}
}

int main()
{

	freopen("carnation.in", "r", stdin);
	freopen("carnation.out", "w", stdout);

	srand(time(NULL));

	// ios::sync_with_stdio(false);
	// cin.tie(nullptr); cout.tie(nullptr);

	memset(head, -1, sizeof(head));

	scanf("%d%d", &n, &m);
	rep(i, 1, m)
	{
		int u, v;
		i64 a, b;
		scanf("%d%d%lld%lld", &u, &v, &a, &b);

		sumA += a;
		sumB += b;

		addEdge(u, v, a, b);
		addEdge(v, u, a, b);
	}

	dfs(1, -1, -1);

	i64 ans = sumA * sumB;

	vector<int> perm;
	rep(i, 1, cycleTot) perm.push_back(i);

	rep(I, 1, 7)
	{
		random_shuffle(all(perm));

		i64 sA = sumA, sB = sumB;

		for (auto i : perm)
		{
			sort(all(cycle[i]), [&](pair<i64, i64> lhs, pair<i64, i64> rhs)
				 { return (sA - lhs.first) * (sB - lhs.second) < (sA - rhs.first) * (sB - rhs.second); });

			sA -= cycle[i][0].first;
			sB -= cycle[i][0].second;
		}

		ans = min(ans, sA * sB);
	}

	printf("%lld\n", ans);

	return 0;
}