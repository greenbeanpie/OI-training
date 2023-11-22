#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5, MAXN2 = 2005;
typedef long long int ll;
int c, n, m, q, x[MAXN], y[MAXN], k, lx[MAXN], ly[MAXN];
bool dp[MAXN2][MAXN2]; // dp[i][j], xi <-> yj
//#define DEBUG
inline void solA(){
	if((x[1] == y[1] || x[n] == y[m]) || (x[1] > y[1] && x[n] < y[m]) || (x[1] < y[1] && x[n] > y[m])){
		cout << 0;
		return;
	}
	dp[0][0] = true;
	if(x[1] < y[1]){ // f < g
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j){
				dp[i][j] = false;
				if(x[i] < y[j]){
					dp[i][j] |= dp[i - 1][j - 1];
					dp[i][j] |= dp[i][j - 1];
					dp[i][j] |= dp[i - 1][j];
				}
			}
		cout << dp[n][m];
	}else{ // f > g
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j){
				dp[i][j] = false;
				if(x[i] > y[j]){
					dp[i][j] |= dp[i - 1][j - 1];
					dp[i][j] |= dp[i][j - 1];
					dp[i][j] |= dp[i - 1][j];
				}
			}
		cout << dp[n][m];
	}
}
namespace hashmp{
	const int LIM = 1e6, MEM = 1.5e7;
	int head[LIM], nxt[MEM], mem;
	ll val[MEM];
	inline void init(){
		for(int i = 0; i < LIM; ++i)
			head[i] = 0;
		mem = 0;
	}
	inline void push(ll idx){
		int key = idx % LIM;
#ifdef DEBUG
		if(mem == MEM - 1)
			cerr << "OUT" << endl;
#endif
		nxt[++mem] = head[key];
		head[key] = mem;
		val[mem] = idx;
	}
	inline bool find(int h, ll idx){
		if(!h)
			return false;
		if(val[h] == idx)
			return true;
		return find(nxt[h], idx);
	}
	inline bool find(ll idx){
		int key = idx % LIM;
		return find(head[key], idx);
	}
}
bool gmod;
bool dfs(int xi, int yi){
	if(xi == 1 && yi == 1)
		return true;
	if(hashmp::find(ll(xi) * n + yi))
		return false;
	hashmp::push(ll(xi) * n + yi);
	if((x[xi] < y[yi]) ^ gmod){
		if(dfs(xi - 1, yi))
			return true;
		if(dfs(xi, yi - 1))
			return true;
		if(dfs(xi - 1, yi - 1))
			return true;
	}
	return false;
}
inline void solB(){
	if((x[1] == y[1] || x[n] == y[m]) || (x[1] > y[1] && x[n] < y[m]) || (x[1] < y[1] && x[n] > y[m])){
		cout << 0;
		return;
	}
	if(x[1] < y[1]){
		gmod = 0;
	}else{
		gmod = 1;
	}
	hashmp::init();
	cout << dfs(n, m);
}
inline void solC(){
	if(c > 14){
		cout << 0;
		return;
	}
	int mxx = 0;
	int mny = 0;
	for(int i = 1; i <= n; ++i)
		mxx = max(mxx, x[i]);
	for(int i = 1; i <= m; ++i)
		mny = max(mny, y[i]);
	if(mxx >= y[1] && mny <= x[1]){
		cout << 0;
		return;
	}
	if(mxx > y[m] || mny <= x[n]){
		cout << 0;
		return;
	}
	cout << 1;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin >> c >> n >> m >> q;
	for(int i = 1; i <= n; ++i)
		cin >> x[i];
	for(int i = 1; i <= m; ++i)
		cin >> y[i];
	for(int i = 1; i <= n; ++i)
		lx[i] = x[i];
	for(int i = 1; i <= m; ++i)
		ly[i] = y[i];
	if(c <= 7)
		solA();
	else
//		solB();
		solC();
	while(q--){
		for(int i = 1; i <= n; ++i)
			x[i] = lx[i];
		for(int i = 1; i <= m; ++i)
			y[i] = ly[i];
		int kx, ky, p, v;
		cin >> kx >> ky;
		while(kx--){
			cin >> p >> v;
			x[p] = v;
		}
		while(ky--){
			cin >> p >> v;
			y[p] = v;
		}
		if(c <= 7)
			solA();
		else
//			solB();
			solC();
	}
	cout << endl;
	return 0;
}