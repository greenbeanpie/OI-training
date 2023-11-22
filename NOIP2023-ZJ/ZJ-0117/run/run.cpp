#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll NINF = -(0x3f3f3f3f3f3f3f3f);
const int MAXM = 1e5 + 5;
struct Ev{
	int x, y, v;
	inline void read(){
		cin >> x >> y >> v;
	}
	inline bool operator < (const Ev &other) const{
		if(x != other.x)
			return x < other.x;
		return y < other.y;
	}
}es[MAXM], es2[MAXM];
struct Seg{
	int st, en, val;
	inline bool operator < (const Seg &other) const{
		return en < other.en;
	}
}ls[MAXM];
int c, t, n, m, k, d;
inline void solA(){
	ll dp[2][k + 1];
	memset(dp, 0x00, sizeof(dp));
	for(int i = 1; i <= k; ++i)
		dp[0][i] = NINF;
	int ptr = 0;
	ll ans, mx, cont;
	bool now, las;
	for(int i = 1; i <= n; ++i){
		now = i & 1; las = !now;
		mx = 0;
		cont = 0;
		for(int j = 1; j <= k; ++j){
			while(ptr < m && es[ptr].x == i && es[ptr].y == j)
				cont += es[ptr++].v;
			dp[now][j] = dp[las][j - 1] - d + cont;
			mx = max(mx, dp[las][j]);
		}
		dp[now][0] = max(dp[las][0], mx);
	}
	ans = 0;
	for(int i = 0; i <= k; ++i)
		ans = max(ans, dp[now][i]);
	cout << ans << endl;
}
inline void solB(){
	ll ans = 0;
	for(int i = 0; i < m; ++i)
		if(ll(es[i].y) * d < es[i].v)
			ans += es[i].v - ll(es[i].y) * d;
	cout << ans << endl;
}
inline void solC(){
	for(int i = 0; i < m; ++i)
		ls[i] = Seg({es[i].x - es[i].y + 1, es[i].x, es[i].v});
	ll dp[m + 10];
	memset(dp, 0x00, sizeof(dp));
	int lt, rt, mid;
	for(int i = 0; i < m; ++i){
		lt = -1;
		rt = i;
		while(lt < rt - 1){
			mid = (lt + rt) >> 1;
			if(ls[mid].en < ls[i].st)
				lt = mid;
			else
				rt = mid;
		}
		dp[i] = max(dp[i - 1], ls[i].val + dp[lt]);
	}
	cout << dp[m - 1] << endl;
}
inline void solve(){
	cin >> n >> m >> k >> d;
	for(int i = 0; i < m; ++i)
		es[i].read();
	int ptr = 0;
	for(int i = 0; i < m; ++i)
		if(es[i].y <= k)
			es2[ptr++] = es[i];
	for(int i = 0; i < ptr; ++i)
		es[i] = es2[i];
	m = ptr;
	sort(es, es + m);
	if(c <= 9){
		solA();
	}
	if(c == 17 || c == 18)
		solB();
	if(c == 19 || c == 20)
		solC();
}
int main(){
	ios::sync_with_stdio(false);
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	cin >> c >> t;
	while(t--)
		solve();
	return 0;
}