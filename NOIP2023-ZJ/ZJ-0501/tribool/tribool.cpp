#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
// vector<int> gr[MAXN];//1-n U,n+1-2*n T,2*n+1-3*n F
// inline void add(int u,int v){
//     gr[u].push_back(v),gr[v].push_back(u);
// }
// int w[MAXN]; // U 1 ,T,f 0;
// int n, m;    // duoce buqing
// bool st[MAXN], vis[MAXN];
// char val[MAXN];//values after set
// struct op
// {
//     char opt;
//     int ll, rr;
// } ops[MAXN];
// inline void reader(int n, int m)
// {
//     for (int i = 0; i <= 3 * n; i++)
//         gr[i].clear();
//     memset(st, 0, sizeof(int) * (3 * n + 3));
//     memset(w, 0, sizeof(int) * (m + 3));
//     memset(vis, 0, sizeof(bool) * (3 * n + 3));
//     memset(val, 0, sizeof(char) * (3 * n + 3));

//     for (int l, r, i = 1; i <= m; i++)
//     {
//         char v;
//         cin >> v;
//         if (v == '+')
//         {
//             cin >> l >> r;
//             ops[i].opt = v, ops[i].ll = l, ops[i].rr = r;
//         }
//         else if (v == '-')
//         {
//             cin >> l >> r;
//             ops[i].opt = v, ops[i].ll = l, ops[i].rr = r;
//         }
//         else
//         {
//             cin >> l;
//             ops[i].opt = v, ops[i].ll = l;
//         }
//     }
// }
// inline void ADD(char opt, int u, int v)
// {
//     if (opt == '+')
//     {
//         add(u,v);
//         add(n+u,n+v);
//         add(n*2+u,n*2+v);
//     }
//     else if (opt == '-')
//     {
//         add(u,v);
//         add(n+u,v+2*n);
//         add(n+v,u+2*n);
//     }
//     else
//     {
//         val[u] = opt;
//         if(opt=='U')w[u] = 1;
//         else w[u] = 0;
//     }
// }
// int tmpans = MAXN;
// void dfs(int u,int ans){
//     if()
//     for (auto v:gr[u]){
//         if(val[v]&&((v-1)/n==0&&val[v%n+1]!='U'||(v-1)/n==1&&val[v%n+1]!='T'||(v-1)/n==2&&val[v%n+1]!='F'))return;
//         vis[v] = true;
//         ans+=((v-1)/n==0);
//         dfs(v,ans);
//         ans-=((v-1)/n==0);
//         vis[v] = false;
//     }
// }
// inline void work()
// {
//     cin >> n >> m;
//     reader(n, m);
//     //build a graph
//     for (int i = m; i >= 1; i--)
//     {
//         if (st[i])
//             continue;
//         st[i] = true;
//         ADD(ops[i].opt, ops[i].ll, ops[i].rr);
//     }
//     // cal ans
// }
bool st[MAXN];
int n, m; // duoce buqing
struct op {
	char opt;
	int ll, rr;
} ops[MAXN];
namespace sub2 {
	inline void reader(int n, int m) {
		memset(st, 0, sizeof(int) * (3 * n + 3));
		for (int l, r, i = 1; i <= m; i++) {
			char v;
			cin >> v;
			if (v == '+') {
				cin >> l >> r;
				ops[i].opt = v, ops[i].ll = l, ops[i].rr = r;
			} else if (v == '-') {
				cin >> l >> r;
				ops[i].opt = v, ops[i].ll = l, ops[i].rr = r;
			} else {
				cin >> l;
				ops[i].opt = v, ops[i].ll = l;
			}
		}
	}
	void work() {
		int ans = 0;
		cin >> n >> m;
		reader(n, m);
		for (int i = m; i >= 1; i--) {
			if (st[ops[i].ll])
				continue;
			st[ops[i].ll] = true;
			if (ops[i].opt == 'U')
				ans++;
		}
		cout << ans << "\n";
	}
}
namespace sub1 {
	int tp[200];
	int ans = MAXN;
	inline void check() {
		int ori[200];
		memcpy(ori, tp, sizeof(int) * (n + 5));
		for (int i = 1; i <= m; i++) {
			int opt = ops[i].opt, l = ops[i].ll, r = ops[i].rr;
			if (opt == '+') {
				if (ori[r] == 'F')
					ori[l] = 'F';
				else if (ori[r] == 'T')
					ori[l] = 'T';
				else
					ori[l] = 'U';
			} else if (opt == '-') {
				if (ori[r] == 'T')
					ori[l] = 'F';
				else if (ori[r] == 'F')
					ori[l] = 'T';
				else
					ori[l] = 'U';
			} else {
				ori[l] = opt;
			}
		}
		bool flag = true;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			flag &= (ori[i] == tp[i]);
			cnt += (tp[i] == 'U');
		}
		if (flag)
			ans = min(ans, cnt);
		//		cout<<flag<<"\n";
	}
	inline void construct(int pos) {
		if (pos == n + 1) {
			//			for(int i = 1; i<=n; i++)cout<<char(tp[i])<<" ";
			check();
			return;
		}
		tp[pos] = 'U';
		construct(pos + 1);
		tp[pos] = 'T';
		construct(pos + 1);
		tp[pos] = 'F';
		construct(pos + 1);
	}

	inline void reader(int n, int m) {
		memset(st, 0, sizeof(int) * (3 * n + 3));
		for (int l, r, i = 1; i <= m; i++) {
			char v;
			cin >> v;
			if (v == '+') {
				cin >> l >> r;
				ops[i].opt = v, ops[i].ll = l, ops[i].rr = r;
			} else if (v == '-') {
				cin >> l >> r;
				ops[i].opt = v, ops[i].ll = l, ops[i].rr = r;
			} else {
				cin >> l;
				ops[i].opt = v, ops[i].ll = l;
			}
		}
	}
	void work() {
		ans = MAXN;
		cin >> n >> m;
		reader(n, m);
		construct(1);
		cout << ans << "\n";
	}
} // namespace sub1
namespace sub3 {
	int val[MAXN];
	inline void reader(int n, int m) {
		memset(val, 0, sizeof(int) * (3 * n + 3));
		for (int l, r, i = 1; i <= m; i++) {
			char v;
			cin >> v;
			if (v == '+') {
				cin >> l >> r;
				ops[i].opt = v, ops[i].ll = l, ops[i].rr = r;
			} else if (v == '-') {
				cin >> l >> r;
				ops[i].opt = v, ops[i].ll = l, ops[i].rr = r;
			} else {
				cin >> l;
				ops[i].opt = v, ops[i].ll = l;
			}
		}
	}
	void work() {
		cin >> n >> m;
		reader(n, m);
		for (int i = 1; i <= n; i++)
			val[i] = -1;
		for (int i = m; i >=1; i--) {
			int opt = ops[i].opt, l = ops[i].ll, r = ops[i].rr;
			if (opt == '+') {
				val[l] = val[r];
			} else if (opt == '-') {
				// if (ori[r] == 'T')
				//     ori[l] = 'F';
				// else if (ori[r] == 'F')
				//     ori[l] = 'T';
				// else
				//     ori[l] = 'U';
			} else {
				if(opt=='U')
					val[l] = 1;
			}
		}
		int ans = 0;
		for(int i = 1; i<=n; i++)
			if(val[i]==1)ans++;
		cout<<ans<<"\n";
	}
} // namespace sub3

signed main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int T, c;
	cin >> c >> T;
	while (T--) {
		if (c == 1 || c == 2)
			sub1::work();
		else if (c == 3 || c == 4)
			sub2::work();
		else if(c==5||c==6)sub3::work();
	}
	return 0;
}