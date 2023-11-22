#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2005;
int _, n, m, q, X[MAXN], Y[MAXN], X0[MAXN], Y0[MAXN];
bool F[MAXN][MAXN];
bool solve(){
	int nn = n, mm = m;
	if(X[1] > Y[1]) swap(X, Y), swap(nn, mm);
	if(X[1] == Y[1] || X[nn] >= Y[mm]) return 0;
	memset(F, 0, sizeof(F)), F[1][1] = 1;
	for(int i = 1; i <= nn; i++)
	for(int j = 1; j <= mm; j++) if(X[i] < Y[j])
		F[i][j] |= F[i - 1][j] | F[i][j - 1];
	return F[nn][mm];
}
int main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.ans", "w", stdout);
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
	return 0;
}