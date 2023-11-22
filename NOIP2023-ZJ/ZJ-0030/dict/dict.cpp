#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;



namespace Isaunoya {

bool mem_u;

using ll = long long;
using pii = pair <int, int>;
using db = double;

#define fi first
#define se second
#define rep(i, l, r) for(int i = l, i##end = r; i <= i##end; ++ i)
#define per(i, l, r) for(int i = l, i##end = r; i >= i##end; -- i)


template <class T>
void chmax(T &x, T y) {
	if(x < y) x = y;
}
template <class T>
void chmin(T &x, T y) {
	if(y < x) x = y;
}

const int N = 3025;

//vector <pii> a[N];
char s[N];
int buc[26], mn[N], mx[N];
int n, m;

//bool cmp(vector <pii> &A, vector <pii> &B) {
//	rep(i, 0, int(min(A.size(), B.size())))
//		if(A[i].fi != B[i].fi) return A[i].se 
//}

bool mem_v;

void solve() {
//	clock_t _st = clock();
//	cerr << (&mem_u - &mem_v) / 1048576.0 << " MB" << endl;
	scanf("%d%d", &n, &m);
	rep(i, 1, n) {
		scanf("%s", s + 1);
		mn[i] = 1e9; mx[i] = 0;
		rep(j, 1, m) {
			chmin(mn[i], (int)s[j]);
			chmax(mx[i], (int)s[j]);
		}
//		memset(buc, 0, sizeof(buc));
//		rep(j, 1, m) ++ buc[s[j] - 'a'];
//		per(j, 25, 0) if(buc[j]) a[i].eb(j, buc[j]);
	}
	rep(i, 1, n) {
		bool flg = 1;
		rep(j, 1, n) {
			if(i == j) continue;
			if(mn[i] >= mx[j]) {
				flg = 0; break;
			}
		}
		putchar(flg ? '1' : '0');
	}
	putchar(10);
//	cerr << (clock() - _st) * 1.0 / CLOCKS_PER_SEC << " s" << endl;
}

} // Isaunoya



int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	Isaunoya :: solve();
	return 0;
}