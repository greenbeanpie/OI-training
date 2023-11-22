#include <bits/stdc++.h>
using namespace std;
#define LO(A, x) (lower_bound(A.begin(), A.end(), x) - A.begin())
#define UP(A, x) (upper_bound(A.begin(), A.end(), x) - A.begin())
constexpr int MAXN = 100005;
int _, T, n, m, K, D; int64_t Ans;
struct Seg{int l, r, v; bool operator < (const Seg &x) const {return r < x.r;}} A[MAXN];
struct SegTree{
	SegTree *ls, *rs; int64_t val, tag;
	SegTree(int l, int r): ls(nullptr), rs(nullptr), val(0), tag(0){
		if(r - l > 1){
			int mid = (l + r) >> 1;
			ls = new SegTree(l, mid);
			rs = new SegTree(mid, r);
		}
	}
	~SegTree(){
		if(ls != nullptr) delete ls;
		if(rs != nullptr) delete rs;
	}
	void push_down(){ls->tag += tag, rs->tag += tag, tag = 0;}
	void push_up(){val = max(ls->val + ls->tag, rs->val + rs->tag);}
	void add(int l_, int r_, int64_t v, int l, int r){
		if(l_ >= r || r_ <= l) return;
		if(l_ <= l && r_ >= r){tag += v; return;}
		int mid = (l + r) >> 1; push_down();
		ls->add(l_, r_, v, l, mid);
		rs->add(l_, r_, v, mid, r);
		push_up();
	}
	void update(int id, int64_t v, int l, int r){
		if(r - l == 1){val = max(val, v); return;}
		int mid = (l + r) >> 1; push_down();
		if(id < mid) ls->update(id, v, l, mid);
		else         rs->update(id, v, mid, r);
		push_up();
	}
	int64_t get(int l_, int r_, int l, int r){
		if(l_ >= r || r_ <= l) return 0;
		if(l_ <= l && r_ >= r) return val + tag;
		int mid = (l + r) >> 1; push_down(); int64_t res = max(
			ls->get(l_, r_, l, mid),
			rs->get(l_, r_, mid, r)
		); push_up(); return res;
	}
};
int main(){
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	for(cin >> _ >> T; T--;){
		cin >> n >> m >> K >> D, Ans = 0; vector<int> V;
		for(int i = 1; i <= m; i++){
			int len; cin >> A[i].r >> len >> A[i].v;
			V.push_back(A[i].l = ++A[i].r - len);
			V.push_back(A[i].r);
		}
		sort(V.begin(), V.end()), V.erase(unique(V.begin(), V.end()), V.end());
		sort(A + 1, A + m + 1), n = V.size(); SegTree T(0, n);
		for(int i = 0; i < n; i++) T.add(i, i + 1, (int64_t)V[i] * D, 0, n);
		for(int i = 0, j = 1; i < n; i++){
			for(; j <= m && A[j].r <= V[i]; j++) T.add(0, UP(V, A[j].l), A[j].v, 0, n);
			int64_t x = T.get(LO(V, V[i] - K), i, 0, n) - (int64_t)V[i] * D;
			if(Ans = max(Ans, x), i + 1 < n) T.update(i + 1, Ans, 0, n);
		}
		cout << Ans << '\n';
	}
	// cerr << (double)clock() / CLOCKS_PER_SEC << endl;
	return 0;
}