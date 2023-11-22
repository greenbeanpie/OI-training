#include<bits/stdc++.h>
using namespace std; using ll = long long;
#define For(i, j, k) for ( int i = (j) ; i <= (k) ; i++ )
#define Fol(i, j, k) for ( int i = (j) ; i >= (k) ; i-- )
int _, n, m, q, a[500009], b[500009], ka, kb, pa[500009], va[500009], pb[500009], vb[500009];
bool dp[2009][2009];
inline void solve()
{
	if ( a[1] < b[1] )
	{
		if ( a[n] >= b[m] ) { cout << '0'; return; }
		For(i, 0, n) For(j, 0, m) dp[i][j] = false;
		dp[0][1] = dp[1][0] = true;
		For(i, 1, n) For(j, 1, m) dp[i][j] = a[i] < b[j] && ( dp[i - 1][j] || dp[i][j - 1] );
		cout << ( dp[n][m] ? '1' : '0' ); return;
	}
	if ( a[1] > b[1] )
	{
		if ( a[n] <= b[m] ) { cout << '0'; return; }
		For(i, 0, n) For(j, 0, m) dp[i][j] = false;
		dp[0][1] = dp[1][0] = true;
		For(i, 1, n) For(j, 1, m) dp[i][j] = a[i] > b[j] && ( dp[i - 1][j] || dp[i][j - 1] );
		cout << ( dp[n][m] ? '1' : '0' ); return;
	}
	cout << '0';
}
int main()
{
	freopen("expand.in", "r", stdin), freopen("expand.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> _ >> n >> m >> q;
	For(i, 1, n) cin >> a[i];
	For(i, 1, m) cin >> b[i];
	solve();
	For(_, 1, q)
	{
		cin >> ka >> kb;
		For(i, 1, ka) cin >> pa[i] >> va[i], swap(a[pa[i]], va[i]);
		For(i, 1, kb) cin >> pb[i] >> vb[i], swap(b[pb[i]], vb[i]);
		solve();
		For(i, 1, ka) a[pa[i]] = va[i];
		For(i, 1, kb) b[pb[i]] = vb[i];
	}
	return cout << '\n', 0;
}
/*
clear && g++ expand.cpp -o expand -Wno-unused-result -std=c++14 -O2 -fsanitize=address,undefined -g && /usr/bin/time -f "%Us %MKB" ./expand < expand1.in > expand.out && diff expand.out expand1.ans -Z
*/