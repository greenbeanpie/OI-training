/*
ST:11:00
ED:
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <queue>
#define fi first
#define se second
#define mp(x, y) make_pair(x, y) 
#define lfor(i, x, y) for(int i = (x); i <= (y); ++ i)
#define rfor(i, x, y) for(int i = (x); i >= (y); -- i)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int, int> pr;
const int N = 5e5 + 5;
pr chg[2][N];
int a[2][N], raw[2][N], k[2], n[2];
bool ans[N];

map<int, int> mp;
vector< pr > s[N]; 

bool work() {
	int ch = a[1][1] > a[0][1], rh = ch ^ 1;
	if (!((a[1][1] > a[0][1]) ^ (a[1][n[1]] < a[0][n[0]]))) return false;
	mp.clear();
	lfor(i, 1, n[ch]) mp[a[ch][i]] = 1;
	lfor(i, 1, n[rh]) if (mp.count(a[rh][i]) != 0) return false;
	lfor(i, 1, n[ch]) s[i].clear(); 
	lfor(i, 1, n[ch]) {
		int l = 1, cnt = 0;
		lfor(j, 1, n[rh]) {
			if (a[ch][i] > a[rh][j] && !cnt) l = j, cnt = 1; 
			else if (a[ch][i] < a[rh][j] && cnt) s[i].emplace_back(mp(l, j - 1)), cnt = 0;
		}
		if (cnt && a[ch][i] > a[rh][n[rh]]) s[i].emplace_back(mp(l, n[rh]));
	}
	int p = s[1][0].se + 1;
	lfor(i, 2, n[ch]) {
		bool fg = false;
		rfor(j, s[i].size() - 1, 0) {
			pr x = s[i][j];
			if (x.fi <= p) {p = x.se + 1, fg = 1; break;}
		}
		if (!fg) return fg;
	}
	if (p >= n[rh]) return true;
	else return false;
}

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	int C, q; scanf("%d %d %d %d", &C, &n[0], &n[1], &q);
	lfor(opt, 0, 1) lfor(i, 1, n[opt]) scanf("%d", &a[opt][i]), raw[opt][i] = a[opt][i]; 
	if (C == 1) ans[0] = (a[0][1] != a[1][1]); 
	else ans[0] = work();
	lfor(T, 1, q) {
		scanf("%d %d", &k[0], &k[1]);
		lfor(opt, 0, 1) lfor(j, 1, k[opt]) scanf("%d %d", &chg[opt][j].fi, &chg[opt][j].se), a[opt][chg[opt][j].fi] = chg[opt][j].se;
		if (C != 1) ans[T] = work();
		else ans[T] = (a[0][1] != a[1][1]); 
		lfor(opt, 0, 1) lfor(j, 1, k[opt]) a[opt][chg[opt][j].fi] = raw[opt][chg[opt][j].fi];
	}
	lfor(i, 0, q) printf("%d", ans[i]); puts("");
	return 0;
}

