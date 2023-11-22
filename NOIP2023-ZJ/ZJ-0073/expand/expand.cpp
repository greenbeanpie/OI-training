#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<bitset>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<set>
#include<map>

//#define int long long
#define ls p << 1
#define rs p << 1 | 1

using namespace std;

inline int read() {
	char c = 0;
	int r = 0, f = 1;
	while(!isdigit(c)) if((c = getchar()) == '-') f = -f;
	while(isdigit(c)) r = (r << 3) + (r << 1) + (c ^ '0'), c = getchar();
	return r * f;
}
bool bg;

const int N = 5e5 + 5;
int TP;

int a[N], b[N];
int n, m, q;
vector<pair<int, int> > cgx, cgy;

namespace p1{
	const int N = 2e3 + 5;
	
	bool dp[N][N];//kexingxing dp
	
	inline void main(int *a, int *b, int n, int m) {
		memset(dp, 0, sizeof dp);
		dp[1][1] = 1;
		for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) if(dp[i][j]) {
			if(i < n && j < m && a[i + 1] < b[j + 1]) dp[i + 1][j + 1] = 1;
			if(i < n && j <= m && a[i + 1] < b[j]) dp[i + 1][j] = 1;
			if(i <= n && j < m && a[i] < b[j + 1]) dp[i][j + 1] = 1;
		}
		if(dp[n][m]) putchar('1');
		else putchar('0');
	}
}

namespace p2{
	int n, m, *a, *b;
	struct segtree{
		int ma[N << 2], mi[N << 2];
		int maid[N << 2], miid[N << 2];
		
		inline void pushup(int p) {
			ma[p] = max(ma[ls], ma[rs]);
			if(ma[ls] <= ma[rs]) maid[p] = maid[rs];
			else maid[p] = maid[ls];
			mi[p] = min(mi[ls], mi[rs]);
			if(mi[ls] >= mi[rs]) miid[p] = miid[rs];
			else miid[p] = miid[ls];
		}
		
		inline void build(int p, int l, int r, int *a) {
			if(l == r) return mi[p] = ma[p] = a[l], maid[p] = miid[p] = l, void();
			int mid = (l + r) >> 1;
			build(ls, l, mid, a), build(rs, mid + 1, r, a);
			pushup(p);
		}
		
		inline pair<int, int> queryma(int p, int l, int r, int L, int R) {
			if(L <= l && r <= R) return {ma[p], maid[p]};
			int mid = (l + r) >> 1;
			pair<int, int> res = {-1, 0};
			if(L <= mid) res = queryma(ls, l, mid, L, R);
			if(mid < R) {
				pair<int, int> pii = queryma(rs, mid + 1, r, L, R);
				res.first = max(res.first, pii.first);
				if(res.first <= pii.first) res.second = pii.second;
			}
			return res;
		}
		
		inline pair<int, int> querymi(int p, int l, int r, int L, int R) {
			if(L <= l && r <= R) return {mi[p], miid[p]};
			int mid = (l + r) >> 1;
			pair<int, int> res = {1e9 + 7, 0};
			if(L <= mid) res = querymi(ls, l, mid, L, R);
			if(mid < R) {
				pair<int, int> pii = querymi(rs, mid + 1, r, L, R);
				res.first = min(res.first, pii.first);
				if(res.first >= pii.first) res.second = pii.second;
			}
			return res;
		}
	}tra, trb;
	
	inline int qa(int ap, int y) {
		int l = y, r = m, ans = -1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(trb.querymi(1, 1, m, y, mid).first > a[ap]) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
//			cout << mid << " " << trb.querymi(1, 1, m, y, mid).first << endl;
		}
//		cout << ap << "a" << ans << endl;
		return ans;
	}//a[ap] < b[y]~b[ans]
	
	inline int qb(int bp, int y) {
		int l = y, r = n, ans = -1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(tra.queryma(1, 1, n, y, mid).first < b[bp]) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
//		cout << bp << " " << ans << endl;
		return ans;
	}
	
	struct node{
		int ap, bp;
		bool operator < (const node &b) const{
			return min(n - ap, m - bp) < min(n - b.ap, m - b.bp);
		}
	};
	
	inline void main(int *a, int *b, int n, int m) {
		p2::a = a, p2::b = b, p2::n = n, p2::m = m;
		tra.build(1, 1, n, a), trb.build(1, 1, m, b);
		
		priority_queue<node> qu;
		qu.push({1, 1});
		while(qu.size()) {
			node u = qu.top();
			qu.pop();
			int ap = u.ap, bp = u.bp;
//			cout << ap << " " << bp << endl;
			int p = qa(ap, bp + 1);
			if(p != -1) {
				pair<int, int> q = trb.queryma(1, 1, m, bp + 1, p);
				if(q.second == m) return putchar('1'), void();
				qu.push({ap, q.second});
			}
			p = qb(bp, ap + 1);
			if(p != -1) {
				pair<int, int> q = tra.querymi(1, 1, n, ap + 1, p);
				if(q.second == n) return putchar('1'), void();
				qu.push({q.second, bp});
			}
		}
		putchar('0');
		return;
	}
}

inline void solu(int *a, int *b, int n, int m) {
	if(n <= 1 && m <= 1) return putchar('1'), void();//5pts
	if(n <= 2000 && m <= 2000) return p1::main(a, b, n, m);//35pts
	if(8 <= TP && TP <= 14) return p2::main(a, b, n, m);//70pts
}//ai < bi yange

inline void solve() {
	if(a[1] == b[1] || ((a[1] < b[1]) != (a[n] < b[m]))) return putchar('0'), void();
	if(a[1] < b[1]) return solu(a, b, n, m);
	return solu(b, a, m, n);
}

bool ed;
signed main() {
//	cerr << (&ed - &bg) / 1048576 << endl;
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	
	TP = read(), n = read(), m = read(), q = read();
	for(int i = 1;i <= n;i++) a[i] = read();
	for(int i = 1;i <= m;i++) b[i] = read();
	solve();
	while(q--) {
		cgx.clear(), cgy.clear();
		int kx = read(), ky = read(), px, py;
		while(kx--) {
			px = read(), py = read();
			cgx.push_back({px, a[px]});
			a[px] = py;
		}
		while(ky--) {
			px = read(), py = read();
			cgy.push_back({px, b[px]});
			b[px] = py;
		}
		solve();
		for(auto v : cgx) a[v.first] = v.second;
		for(auto v : cgy) b[v.first] = v.second;
	}//O(qn)
	return 0;
}//made by luogu:734497 star_of_cloud
