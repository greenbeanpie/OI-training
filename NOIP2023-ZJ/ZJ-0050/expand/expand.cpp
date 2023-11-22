#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 500005, MAXL = __lg(MAXN) + 1;
int _, n, m, q, X[MAXN], Y[MAXN], X0[MAXN], Y0[MAXN];
bool solve(){
	int nn = n, mm = m;
	if(X[1] > Y[1]) swap(X, Y), swap(nn, mm);
	if(X[1] == Y[1] || X[nn] >= Y[mm]) return 0;
	int lx =  1, ly =  1; for(int p =  1, q =  1; true;){
		int x = lx, y = ly;
		for(; p <= nn && X[p] < Y[ly]; p++) if(X[p] <= X[x]) x = p;
		for(; q <= mm && Y[q] > X[ x]; q++) if(Y[q] >= Y[y]) y = q;
		if(x > lx || y > ly) lx = x, ly = y; else break;
	}
	int rx = nn, ry = mm; for(int p = nn, q = mm; true;){
		int x = rx, y = ry;
		for(; p       && X[p] < Y[ry]; p--) if(X[p] <= X[x]) x = p;
		for(; q       && Y[q] > X[ x]; q--) if(Y[q] >= Y[y]) y = q;
		if(x < rx || y < ry) rx = x, ry = y; else break;
	}
	return lx >= rx && ly >= ry;
}
int main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> _ >> n >> m >> q;
	for(int i = 1; i <= n; i++) cin >> X[i], X0[i] = X[i];
	for(int i = 1; i <= m; i++) cin >> Y[i], Y0[i] = Y[i];
	for(cout << solve(); q--; cout << solve()){
		for(int i = 1; i <= n; i++) X[i] = X0[i];
		for(int i = 1; i <= m; i++) Y[i] = Y0[i];
		int p, q; cin >> p >> q;
		while(p--){int i, v; cin >> i >> v, X[i] = v;}
		while(q--){int i, v; cin >> i >> v, Y[i] = v;}
	}
	cout << '\n';
	// cerr << (double)clock() / CLOCKS_PER_SEC << endl;
	return 0;
}