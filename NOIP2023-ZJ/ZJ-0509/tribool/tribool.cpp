/*
ST:9:11
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
#define lfor(i, x, y) for(int i = (x); i <= (y); ++ i)
#define rfor(i, x, y) for(int i = (x); i >= (y); -- i)
using namespace std;

typedef long long ll;
typedef double db;
const int N = 2e5 + 5;
struct Ask {
	int opt, x, y;
} a[N];
int fa[N], sz[N], C;
int val[N];
bool mark[N];
bool ret[N];
int n, m, ans;
int mmm;

int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	fa[y] = x; sz[x] += sz[y]; sz[y] = 0;
}

void work() {
	ans = 0; mmm = 0;
	scanf("%d %d", &n, &m);
	lfor(i, 1, (n << 1)) fa[i] = i, sz[i] = 1, mark[i] = 0, val[i] = 0, ret[i] = 0;
	lfor(i, 1, m) {
		char opt[5]; scanf("%s %d", opt, &a[i].x);
		if (opt[0] == '-') scanf("%d", &a[i].y), a[i].opt = 1;
		else if (opt[0] == '+') scanf("%d", &a[i].y), a[i].opt = 2;
		else {
			mmm = 1;
			if (opt[0] == 'T') a[i].opt = 3;
			else if (opt[0] == 'F') a[i].opt = 4;
			else a[i].opt = 5;
		} 
	}
}

void work1() {
	lfor(i, 1, m) {
		int opt = a[i].opt, x = a[i].x, y;
		if (opt == 1) y = a[i].y, merge(x, y + n), merge(y, x + n);
		else if (opt == 2) y = a[i].y, merge(x, y), merge(x + n, y + n);
		else {
			if (opt == 3) val[x] = 1;
			else if (opt == 4) val[x] = 2;
			else val[x] = 3, val[x + n] = 3;
		} 
	}
	lfor(i, 1, (n << 1)) {
		int f = find(i); if (mark[f]) continue;
		if (val[i] == 3) ans += sz[f];
		else if (f == find(i + n)) ans += sz[f];
		mark[f] = 1;
	}
	printf("%d\n", (ans >> 1)); 
}

void work2() {
	rfor(i, m, 1) {
		int opt = a[i].opt, x = a[i].x, y;
		if (ret[a[i].x]) continue;
		ret[a[i].x] = 1;
		if (opt == 1) y = a[i].y, merge(x, y + n), merge(y, x + n);
		else if (opt == 2) y = a[i].y, merge(x, y), merge(x + n, y + n);
		else {
			if (opt == 3) val[x] = 1;
			else if (opt == 4) val[x] = 2;
			else merge(x, 0), merge(x + n, 0);
		} 
	}
	//lfor(i, 1, (n << 1))  cout << "i:" << i << " fa:" << fa[i] << " sz:" << sz[i] << endl;
	lfor(i, 0, (n << 1)) {
		int f = find(i); if (mark[f]) continue;
		//cout << "i:" << i << " f:" << f << endl;
		//, cout << "1" << endl;
		if (f == find(i + n)) merge(f, 0), merge(i + n, 0);//, cout << "2" << endl;
	}
	ans = sz[find(0)];
	printf("%d\n", (ans >> 1)); 
}

void work3() {
	ans = 0;
	lfor(i, 1, m) {
		if (a[i].opt == 5) ++ ans;
	}
	cout << ans << endl;
}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int T; scanf("%d %d", &C, &T);
	while (T --) {
		work();
		if (C == 3 || C == 4) work3();
		else if (C == 7 || C == 8 || C == 1 || !mmm) work1();
		else work2();
	}
	return 0;
}

