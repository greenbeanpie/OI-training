#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

const int maxN = 1e5 + 10;
const int maxM = 1e5 + 10;
const int maxO = 2e5 + 10;

struct ordstr{
	char type;
	int x, y, id;
};
int c, t, n, m;
int cnt = 0, ordsiz[maxN], fa[maxO], siz[maxO];
int len = 0, va[maxO << 1], ne[maxO << 1], to[maxO << 1], fi[maxO];
vector<ordstr> ord[maxN];
bool vis[maxO], cal[maxO];
int val[maxO];

int pfind(int x, int y) {
	int l = 0, r = ordsiz[x] - 1, mid, res = -1;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (ord[x][mid].id < y) res = mid, l = mid + 1;
		else r = mid - 1;
	}
	return res;
}

int find(int x) {
	//cout << x << endl;
	return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		if (siz[x] <= siz[y]) {
			fa[x] = y;
			siz[y] += siz[x];
		}
		else {
			fa[y] = x;
			siz[x] += siz[y];
		}
	}
}

void link(int u, int v, int w) {
	to[++len] = v, va[len] = w, ne[len] = fi[u], fi[u] = len;
}

void dfs(int p, int fp) {
	if (cal[fp]) return;
	for (int i = fi[p]; i; i = ne[i]) {
		int nexw = (val[p] ^ va[i]);
		if (val[to[i]] != -1 && val[to[i]] != nexw) {
			cal[fp] = 1;
			vis[fp] = 1;
			return;
		}
	}
	for (int i = fi[p]; i; i = ne[i]) {
		int nexw = (val[p] ^ va[i]);
		if (val[to[i]] == -1) {
			val[to[i]] = nexw;
			dfs(to[i], fp);
		}
	}
}

int main(void) {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	
	scanf("%d%d", &c, &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		char type;
		int x, y;
		for (int i = 1; i <= m; i++) {
			scanf("%s", &type);
			if (type == '+' || type == '-') {
				scanf("%d%d", &x, &y);
				ord[x].push_back({type, x, y, i});
			}
			else {
				scanf("%d", &x);
				ord[x].push_back({type, x, 0, i});
			}
		}
		//cout << endl;
		cnt = m;
		for (int i = 1; i <= n; i++) {
			ordsiz[i] = ord[i].size();
			//cout << ordsiz[i] << ' ';
			if (!ordsiz[i]) {
				cnt++;
				ord[i].push_back({'+', i, i, cnt});
				ordsiz[i]++;
			}
		}
		//cout << endl;
		//for (int i = 1; i <= n; i++) cout << ordsiz[i] << ' ';
		//cout << endl;
		
		//cout << cnt << endl;
		//cout << 1 << endl;
		for (int i = 1; i <= cnt; i++) {
			fa[i] = i, siz[i] = 1;
		}
		int p, nex;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < ordsiz[i]; j++) {
				//cout << i << ' ' << j << endl;
				if (ord[i][j].type == '+') {
					nex = ord[i][j].y;
					p = pfind(nex, ord[i][j].id);
					//if (i == 100000) cout << i << ' ' << j << endl;
					//cout << 1 << endl;
					if (p == -1) {
						if (find(ord[i][j].id) != find(ord[nex][ordsiz[nex] - 1].id)) {
							merge(ord[i][j].id, ord[nex][ordsiz[nex] - 1].id);
						}
						link(ord[nex][ordsiz[nex] - 1].id, ord[i][j].id, 0);
						link(ord[i][j].id, ord[nex][ordsiz[nex] - 1].id, 0);
					}
					else {
						if (find(ord[i][j].id) != find(ord[nex][p].id)) {
							merge(ord[i][j].id, ord[nex][p].id);
						}
						link(ord[nex][p].id, ord[i][j].id, 0);
						link(ord[i][j].id, ord[nex][p].id, 0);
					}
				}
				else if (ord[i][j].type == '-') {
					nex = ord[i][j].y;
					p = pfind(nex, ord[i][j].id);
					//if (i == 100000) cout << i << ' ' << nex << endl;
					if (p == -1) {
						if (find(ord[i][j].id) != find(ord[nex][ordsiz[nex] - 1].id)) {
							merge(ord[i][j].id, ord[nex][ordsiz[nex] - 1].id);
						}
						link(ord[nex][ordsiz[nex] - 1].id, ord[i][j].id, 1);
						link(ord[i][j].id, ord[nex][ordsiz[nex] - 1].id, 1);
					}
					else {
						//if (i == 100000) cout << i << ' ' << nex << endl;
						//if (i == 100000) cout << ord[i][j].id << ' ' << ord[nex][p].id << endl;
						//if (i == 100000) cout << find(ord[i][j].id) << ' ' << find(ord[nex][p].id) << endl;
						
						//if (i == 100000) cout << i << ' ' << nex << endl;
						if (find(ord[i][j].id) != find(ord[nex][p].id)) {
							//if (i == 100000) cout << i << ' ' << nex << endl;
							merge(ord[i][j].id, ord[nex][p].id);
						}
						//if (i == 100000) cout << i << ' ' << nex << endl;
						link(ord[nex][p].id, ord[i][j].id, 1);
						link(ord[i][j].id, ord[nex][p].id, 1);
					}
				}
				//cout << i << ' ' << j << endl;
			}
		}
		/*for (int i = 1; i <= n; i++) {
			for (int j = 0; j < ordsiz[i]; j++) {
				cout << ord[i][j].id << ' ' << find(ord[i][j].id) << endl;
			}
		}*/
		//cout << 1 << endl;
		int np, fp, ans = 0;
		for (int i = 1; i <= cnt; i++) {
			vis[i] = 0, val[i] = -1, cal[i] = 0;
		}
		//for (int i = 1; i <= cnt; i++) cout << val[i] << ' ';
		//cout << endl;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < ordsiz[i]; j++) {
				//cout << i << ' ' << j << endl;
				fp = find(ord[i][j].id);
				if (vis[fp] || cal[fp]) continue;
				if (ord[i][j].type == 'T' || ord[i][j].type == 'F') {
					vis[fp] = 1;
				}
				else if (ord[i][j].type == 'U') {
					cal[fp] = 1;
					vis[fp] = 1;
				}
			}
		}
		//cout << ans << endl;
		//cout << 1 << endl;
		//for (int i = 1; i <= cnt; i++) cout << val[i] << ' ';
		//cout << endl;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < ordsiz[i]; j++) {
				np = ord[i][j].id;
				fp = find(np);
				if (vis[fp] || cal[fp]) continue;
				val[np] = 1;
				dfs(np, fp);
				vis[fp] = 1;
				/*if (val[np] == -1) {
					for (int k = fi[np]; k; k = ne[k]) {
						if (val[to[k]] != -1) {
							val[np] = (val[to[k]] ^ va[k]);
							break;
						}
					}
				}
				if (val[np] == -1) val[np] = 1;
				for (int k = fi[np]; k; k = ne[k]) {
					//cout << np << ' ' << to[k] << ' ' << val[to[k]] << endl;
					int nexw = (val[np] ^ va[k]);
					if (val[to[k]] == -1) {
						val[to[k]] = nexw;
					}
					else if (val[to[k]] != nexw) {
						cal[fp] = 1;
						vis[fp] = 1;
						break;
					}
				}*/
			}
			//for (int j = 1; j <= cnt; j++) {
			//	cout << val[j] << ' ';
			//}
			//cout << endl;
		}
		//cout << 1 << endl;
		/*cout << endl;
		for (int i = 1; i <= cnt; i++) {
			cout << i << ' ' << cal[i] << endl;
		}
		cout << endl;*/
		for (int i = 1; i <= n; i++) {
			fp = find(ord[i][ordsiz[i] - 1].id);
			ans += cal[fp];
		}
		printf("%d\n", ans);
		
		for (int i = 1; i <= n; i++) {
			ord[i].clear();
			ordsiz[i] = 0;
		}
		for (int i = 1; i <= cnt; i++) {
			fi[i] = 0;
			fa[i] = 0, vis[i] = 0, cal[i] = 0, val[i] = 0;
		}
		for (int i = 1; i <= len; i++) {
			ne[i] = 0, va[i] = 0, to[i] = 0;
		}
		len = 0;
	}
	return 0;
}