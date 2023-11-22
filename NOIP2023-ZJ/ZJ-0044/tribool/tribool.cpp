#include<bits/stdc++.h>
using namespace std; using ll = long long;
#define For(i, j, k) for ( int i = (j) ; i <= (k) ; i++ )
#define Fol(i, j, k) for ( int i = (j) ; i >= (k) ; i-- )
constexpr int inf = numeric_limits < int >::max() / 2;
int n, m, x, y, cnt, id[100009], t[200009], d[200009], val[200009], tot, mn, ans;
vector < pair < int, bool > > g[200009]; queue < int > q;
bool used[200009], vis[200009]; char op;
inline void solve()
{
	cin >> n >> m, cnt = n, ans = 0;
	For(i, 1, n) id[i] = i, g[i].clear();
	while ( q.size() ) q.pop();
	For(i, 1, m)
	{
		cin >> op >> x, g[++cnt].clear();
		if ( op == 'U' ) val[cnt] = 0, q.push(cnt);
		if ( op == 'F' ) val[cnt] = -1, q.push(cnt);
		if ( op == 'T' ) val[cnt] = 1, q.push(cnt);
		if ( op == '+' ) cin >> y, g[id[y]].emplace_back(cnt, true);
		if ( op == '-' ) cin >> y, g[id[y]].emplace_back(cnt, false);
		id[x] = cnt;
	}
	For(i, 1, n) g[id[i]].emplace_back(i, true);
	For(i, 1, cnt) used[i] = false;
	for ( int u ; q.size() ; )
	{
		u = q.front(), q.pop(), used[u] = true;
		for ( auto e : g[u] ) val[e.first] = e.second ? val[u] : -val[u], q.push(e.first);
	}
	For(i, 1, n) if ( used[i] ) ans += !val[i];
	For(i, 1, cnt) d[i] = 0, vis[i] = false;
	For(i, 1, cnt) if ( !used[i] ) for ( auto e : g[i] ) t[e.first] = i, d[i]++;
	while ( q.size() ) q.pop();
	For(i, 1, cnt) if ( !d[i] ) q.push(i);
	for ( int u ; q.size() ; )
	{
		u = q.front(), q.pop(), vis[u] = true;
		if ( !--d[t[u]] ) q.push(t[u]);
	}
	For(i, 1, cnt) if ( !vis[i] )
	{
		mn = inf, vis[i] = true;
		for ( int j = t[i] ; j != i ; j = t[j] ) vis[j] = true;
		For(j, -1, 1)
		{
			while ( q.size() ) q.pop();
			val[i] = j, q.push(i), tot = 0;
			for ( int u ; q.size() ; )
			{
				u = q.front(), q.pop();
				if ( u <= n ) tot += !val[u];
				for ( auto e : g[u] )
					if ( e.first != i ) val[e.first] = e.second ? val[u] : -val[u], q.push(e.first);
					else if ( val[e.first] != ( e.second ? val[u] : -val[u] ) ) { tot = inf; break; }
			}
			mn = min(mn, tot);
		}
		ans += mn;
	}
	cout << ans << '\n';
}
int main()
{
	freopen("tribool.in", "r", stdin), freopen("tribool.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	int _, t; cin >> _ >> t; For(tt, 1, t) solve(); return 0;
}
/*
clear && g++ tribool.cpp -o tribool -Wno-unused-result -std=c++14 -O2 -fsanitize=address,undefined -g && /usr/bin/time -f "%Us %MKB" ./tribool < tribool1.in > tribool.out && diff tribool.out tribool1.ans -Z
*/