#include<bits/stdc++.h>
typedef long long ll;
#define int ll
constexpr int maxn = 2e5 + 10;
constexpr int mod = 1e9 + 7;
using namespace std;

inline void FileIO(string name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

int c, T;
int n, m, k, d;
struct p{
	int l, r, w;
	bool operator < (const p &RHS) const {
		if(l == RHS.l && r == RHS.r) return w > RHS.w;
		if(l == RHS.l) return r < RHS.r;
		return l < RHS.l;
	}
};
vector <p> e;

namespace Subtask1 {
	
	int f[maxn][2], x[maxn], y[maxn], w[maxn];
		
	inline void Main() {
		
		memset(f, 0, sizeof f);
				
		cin >> n >> m >> k >> d;
		for(int i = 1; i <= m; ++i) {
			cin >> y[i] >> x[i] >> w[i];			
			x[i] = y[i] - x[i] + 1;
			f[i][0] = max(f[i - 1][0], f[i - 1][1]);
			if(y[i] - x[i] + 1 > k) continue;
			if(d * (y[i] - x[i] + 1) >= w[i]) continue;
			if((i != 1) && (y[i - 1] + 1 == x[i]) && (y[i] - x[i - 1] + 1) > k)  continue;				
			f[i][1] = max(f[i - 1][1], f[i - 1][0]) + w[i] - (y[i] - x[i] + 1) * d;
		}
		
		cout << max(f[m][1], f[m][0]) << '\n';
			
		return ;
	}
}

namespace Subtask2 {
	
	bitset <50> vis;
	int ans = 0;
	
	int calc() {

		int res = 0;
		for(int cnt = 0, i = 1; i <= n; ++i) {
			if(vis[i]) {
				res -= d;
				if(++cnt > k) return 0;
			}
			else cnt = 0;
		}		
		
		for(auto k : e) {
			bool flag = 1;
			for(int i = k.l - k.r + 1; i <= k.l; ++i)	{
				if(!vis[i]) {
					flag = 0;
					break;
				}
			}
			if(flag) res += k.w;
		}
		
		return res;
	}
	
	void dfs(int tot) {
		if(tot == n + 1) {
			ans = max(ans, calc());
			return ;
		}
		vis[tot] = 0; dfs(tot + 1);
		vis[tot] = 1; dfs(tot + 1);
	}
	
	inline void Main() {
		
		cin >> n >> m >> k >> d;
		for(int x, y, w, i = 1; i <= m; ++i) {
			cin >> x >> y >> w;
			if((y - x + 1) * d >= w) continue;
			e.push_back({x, y, w});
		}
		
		ans = 0;		
		dfs(1);		
		cout << ans << '\n';
		
		return ;	
	}
}

signed main() {

	FileIO("run");

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> c >> T;
	
	if(c == 17 || c == 18) {
		while(T --) Subtask1::Main();
		return 0;
	}
	if(c == 1 || c == 2) {
		while(T --) Subtask2::Main();
		return 0;
	}
	
	while(T --) {
		cin >> n >> m >> k >> d;
		int sw = 0;
		for(int x, y, w, i = 1; i <= m; ++i) {
			cin >> x >> y >> w;
			if((y - x + 1) * d >= w) continue;
			sw += w;
			e.push_back({x, y, w});
		}
		
		sort(e.begin(), e.end());
		cout << 2 * sw - m * d  << '\n';
		e.clear();
	}


	return 0;
}
