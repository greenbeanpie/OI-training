#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for(int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in","r",stdin);freopen(prob".out","w",stdout);

using namespace std;

const int N = 5e5 + 10;

int n, m, c, q;
int kx, ky;
int oX[N], oY[N];
int X[N], Y[N];

namespace C1
{
inline void solve()
{
	rep (i, 1, n) cin >> oX[i], X[i] = oX[i];
	rep (i, 1, m) cin >> oY[i], Y[i] = oY[i];
	
	cout << (X[1] != Y[1] ? 1 : 0);
	
	rep (i, 1, q)
	{
		cin >> kx >> ky;
		rep (j, 1, kx) { int px, py; cin >> px >> py; X[px] = py; }
		rep (j, 1, ky) { int px, py; cin >> px >> py; Y[px] = py; }
		cout << (X[1] != Y[1] ? 1 : 0);
	}
}
}

namespace C2
{
inline void solve()
{
	rep (i, 1, n) cin >> oX[i], X[i] = oX[i];
	rep (i, 1, m) cin >> oY[i], Y[i] = oY[i];
	
	cout << ( ( X[1] != Y[1] and X[2] != Y[2] and 1ll * (X[1] - Y[1]) * (X[2] - Y[2]) > 0 ) ? 1 : 0);
	
	rep (i, 1, q)
	{
		cin >> kx >> ky;
		rep (j, 1, kx) { int px, py; cin >> px >> py; X[px] = py; }
		rep (j, 1, ky) { int px, py; cin >> px >> py; Y[px] = py; }
		cout << (( X[1] != Y[1] and X[2] != Y[2] and 1ll * (X[1] - Y[1]) * (X[2] - Y[2]) > 0 ) ? 1 : 0);
	}
}
}

int main()
{
	file("expand");
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> c >> n >> m >> q;
	
	if (c == 1) { C1::solve(); return 0; }
	if (c == 2) { C2::solve(); return 0; }
	
	rep (i, 0, q) cout << 1;
	
	return 0;
}