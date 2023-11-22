/*
START:8:30
END: 9:00
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
#define lfor(i, x, y) for(int i = (x); i <= (y); ++ i)
#define rfor(i, x, y) for(int i = (x); i >= (y); -- i) 
using namespace std;

typedef long long ll;
typedef double db;
const int N = 3005;
const int CH = 30;
char a[N][N];
int tot[N][CH], mx[N], mn[N];
int ans[N];

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	int n, m; scanf("%d %d", &n, &m); lfor(i, 1, n) mn[i] = CH;
	lfor(i, 1, n) scanf("%s", a[i]);
	if (n == 1) {puts("1"); return 0;}
	lfor(i, 1, n) lfor(j, 0, m - 1) {
		int t = a[i][j] - 'a';
		++ tot[i][t], 
		mx[i] = max(mx[i], t), 
		mn[i] = min(mn[i], t);
	}
	lfor(i, 1, n) lfor(j, 1, n) 
		if (mx[j] < mn[i]) {ans[i] = 1; break;}
		else if (mx[j] == mn[i] && tot[j][mx[j]] != tot[i][mn[i]]) {ans[i] = 1; break;}
	lfor(i, 1, n) printf("%d", !ans[i]); puts("");
	return 0;
}
