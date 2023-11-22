#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
int c, t;
int a[N], n, m;
struct node {
	int oppo;//1 -> not change  0 -> opposite
	int id;//-1 -> T  -2 -> U -3 -> F 0 -> NULL
}num[N], km[N];
vector<int> V[N];
int sum;
int mp[N];
bool vis[N];
int abs(int a) {
	return a < 0 ? -a : a;
}
void qing(int sub) {
	if (mp[sub] == 2) return ;
	mp[sub] = 2;
	++ sum;
	for (auto i : V[sub])
		qing(abs(i));
	if (num[sub].id > 0) qing(num[sub].id);
	return ;
}
void dfs(int sub, node top, node now) {
	if (mp[top.id] == 1) return ;
	if (vis[sub]) return ;
	vis[sub] = 1;
	km[sub] = now;
	node v;
	for (auto i : V[sub]) {
		v = now;
		if (i < 0) v.oppo ^= 1, i = -i;
		if (vis[abs(i)]) {
			if (km[i].id == v.id && km[i].oppo != v.oppo)
				mp[i] = 1;
			continue;
		}
		dfs (i, top, v);
	}
	return ;
}
int main() {
	freopen ("tribool.in", "r", stdin);
	freopen ("tribool.out", "w", stdout);
	scanf ("%d%d", &c, &t);
	if (c == 3 || c == 4) {
		while (t --) {
			scanf ("%d%d", &n, &m);
			for (int i = 1;i <= n; ++ i)
				a[i] = -2;
			while (m --) {
				char opt;
				scanf (" %c", &opt);
				int p;
				scanf ("%d", &p);
				if (opt == 'U')
					a[p] = -1;
				else if (opt == 'T')
					a[p] = 1;
				else if (opt == 'F')
					a[p] = 0;
			}
			int sum = 0;
			for (int i = 1;i <= n; ++ i)
				if (a[i] == -1)
					++ sum;
			printf ("%d\n", sum);
		}
		return 0;
	}
	while (t --) {
		scanf ("%d%d", &n, &m);
		memset (num, 0, sizeof(num));
		memset (mp, 0, sizeof(mp));
		memset (vis, 0, sizeof(vis));
		for (int i = 1;i <= n; ++ i)
			V[i].clear();
		while (m --) {
			char opt;
			scanf (" %c", &opt);
			int p, p1;
			scanf ("%d", &p);
			if (opt == 'U') {
				num[p].oppo = 0;
				num[p].id = -2;
			}
			else if (opt == 'T') {
				num[p].oppo = 0;
				num[p].id = -1;
			}
			else if (opt == 'F') {
				num[p].oppo = 0;
				num[p].id = -3;
			}
			else if (opt == '+') {
				scanf ("%d", &p1);
				if (num[p1].id >= 0) {
					num[p].oppo = num[p1].oppo;
					num[p].id = (num[p1].id == 0 ? p1 : num[p1].id);
				}
				else {
					num[p].oppo = 0;
					num[p].id = num[p1].id;
				}
			}
			else if (opt == '-') {
				scanf ("%d", &p1);
				if (num[p1].id >= 0) {
					num[p].oppo = (num[p1].oppo ^ 1);
					num[p].id = (num[p1].id == 0 ? p1 : num[p1].id);
				}
				else {
					num[p].oppo = 0;
					num[p].id = -(4 + num[p1].id);
				}
			}
		}
		sum = 0;
		for (int i = 1;i <= n; ++ i)
			if (num[i].id > 0)
				V[num[i].id].push_back((num[i].oppo == 1 ? -i : i));
		for (int i = 1;i <= n; ++ i) {
			if (num[i].id == -2 && num[i].oppo == 0) {
				qing(i);
				continue;
			}
			if (num[i].id == i && num[i].oppo == 1) {
				qing(i);
				continue;
			}
		}
		for (int i = 1;i <= n; ++ i) {
			if (num[i].id > 0 && !vis[i] && !mp[i] && num[i].id != i) {
				node u = num[i];
				dfs(i, u, u);
			}
		}
		for (int i = 1;i <= n; ++ i)
			if (mp[i] == 1)
				qing(i);
		printf ("%d\n", sum);
	}
	return 0;
}
