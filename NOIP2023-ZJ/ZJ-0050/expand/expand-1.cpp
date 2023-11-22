#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 500005, MAXL = __lg(MAXN) + 1;
int _, n, m, q, X[MAXN], Y[MAXN], X0[MAXN], Y0[MAXN];
int XVAL[MAXL][MAXN], XID[MAXL][MAXN];
int YVAL[MAXL][MAXN], YID[MAXL][MAXN];
int get_xval(int l, int r){
	int k = __lg(r - l + 1); return max(XVAL[k][l], XVAL[k][r - (1 << k) + 1]);
}
int get_yval(int l, int r){
	int k = __lg(r - l + 1); return min(YVAL[k][l], YVAL[k][r - (1 << k) + 1]);
}
int get_xid(int l, int r){
	int k = __lg(r - l + 1);
	if(X[XID[k][l]] < X[XID[k][r - (1 << k) + 1]]) return XID[k][l];
	else return XID[k][r - (1 << k) + 1];
}
int get_yid(int l, int r){
	int k = __lg(r - l + 1);
	if(Y[YID[k][l]] > Y[YID[k][r - (1 << k) + 1]]) return YID[k][l];
	else return YID[k][r - (1 << k) + 1];
}
int find_lx(int p, int q, int v){
	int l = p, r = q;
	while(l < r){
		int mid = (l + r + 1) >> 1;
		if(get_xval(p, mid) < v) l = mid;
		else r = mid - 1;
	}
	return l;
}
int find_ly(int p, int q, int v){
	int l = p, r = q;
	while(l < r){
		int mid = (l + r + 1) >> 1;
		if(v < get_yval(p, mid)) l = mid;
		else r = mid - 1;
	}
	return l;
}
int find_rx(int p, int q, int v){
	int l = p, r = q;
	while(l < r){
		int mid = (l + r    ) >> 1;
		if(get_xval(mid, q) < v) r = mid;
		else l = mid + 1;
	}
	return l;
}
int find_ry(int p, int q, int v){
	int l = p, r = q;
	while(l < r){
		int mid = (l + r    ) >> 1;
		if(v < get_yval(mid, q)) r = mid;
		else l = mid + 1;
	}
	return l;
}
bool solve(){
	int nn = n, mm = m;
	if(X[1] > Y[1]) swap(X, Y), swap(nn, mm);
	if(X[1] == Y[1] || X[nn] >= Y[mm]) return 0;
	for(int i = 1; i <= nn; i++) XID[0][i] = i, XVAL[0][i] = X[i];
	for(int i = 1; i <= mm; i++) YID[0][i] = i, YVAL[0][i] = Y[i];
	for(int k = 1; (1 << k) <= nn; k++)
	for(int i = 1; i + (1 << k) - 1 <= nn; i++){
		XVAL[k][i] = max(XVAL[k - 1][i], XVAL[k - 1][i + (1 << (k - 1))]);
		if(X[XID[k - 1][i]] < X[XID[k - 1][i + (1 << (k - 1))]]) XID[k][i] = XID[k - 1][i];
		else XID[k][i] = XID[k - 1][i + (1 << (k - 1))];
	}
	for(int k = 1; (1 << k) <= mm; k++)
	for(int i = 1; i + (1 << k) - 1 <= mm; i++){
		YVAL[k][i] = min(YVAL[k - 1][i], YVAL[k - 1][i + (1 << (k - 1))]);
		if(Y[YID[k - 1][i]] > Y[YID[k - 1][i + (1 << (k - 1))]]) YID[k][i] = YID[k - 1][i];
		else YID[k][i] = YID[k - 1][i + (1 << (k - 1))];
	}
	int lx =  1, ly =  1; while(true){
		int x = get_xid(lx, find_lx(lx, nn, Y[ly]));
		int y = get_yid(ly, find_ly(ly, mm, X[ x]));
		if(x > lx || y > ly) lx = x, ly = y; else break;
	}
	int rx = nn, ry = mm; while(true){
		int x = get_xid(find_rx( 1, rx, Y[ry]), rx);
		int y = get_yid(find_ry( 1, ry, X[ x]), ry);
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