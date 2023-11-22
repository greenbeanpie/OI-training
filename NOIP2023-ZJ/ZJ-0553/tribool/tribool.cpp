#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for(int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in","r",stdin);freopen(prob".out","w",stdout);

using namespace std;

const int N = 1e5 + 10;

int n, m, c;
int v[N];

inline int fix(int p) { return (p >= 0 ? 1 - p : -1); }

namespace C12
{
char opt[20]; int opr[20][2];
int res, vp[20];
inline bool chk()
{
	rep (i, 1, n) vp[i] = v[i];
	rep (i, 1, m)
	{
		if (opt[i] == '+') vp[opr[i][0]] = vp[opr[i][1]];
		if (opt[i] == '-') vp[opr[i][0]] = fix(vp[opr[i][1]]);
		if (opt[i] == 'U') vp[opr[i][0]] = -1;
		if (opt[i] == 'T') vp[opr[i][0]] = 1;
		if (opt[i] == 'F') vp[opr[i][0]] = 0;
	}
	rep (i, 1, n) if (vp[i] != v[i]) return false;
	return true;
}
inline void dfs(int i, int cnt)
{
	if (i > n) { if (chk()) res = min(res, cnt); return; }
	v[i] = 0; dfs(i + 1, cnt);
	v[i] = 1; dfs(i + 1, cnt);
	v[i] = -1; dfs(i + 1, cnt + 1);
}
inline void solve()
{
	cin >> n >> m; res = n;
	rep (i, 1, m)
	{
		cin >> opt[i];
		if (opt[i] == '+' or opt[i] == '-')
			cin >> opr[i][0] >> opr[i][1];
		else
			cin >> opr[i][0];
	}
	dfs(1, 0);
	cout << res << endl;
}
}

namespace C34
{
inline void solve()
{
	cin >> n >> m;
	fill(v, v + n + 1, -2);
	rep (i, 1, m)
	{
		char opt; int x; cin >> opt;
		if (opt == 'T')
		{
			cin >> x;
			v[x] = 1;
		}
		else if (opt == 'F')
		{
			cin >> x;
			v[x] = 0;
		}
		else if (opt == 'U')
		{
			cin >> x;
			v[x] = -1;
		}
	}
	int res = 0;
	rep (i, 1, n) if (v[i] == -1) ++res;
	cout << res << endl;
}
}

namespace C56
{
inline bool chk(int i)
{
	rep (_, 1, 100)
	{
		if (!~v[i]) return 1;
		i = v[i];
		if (v[i] == 0) break;
	}
	if (!~v[i]) return 1;
	else return 0;
}
inline void solve()
{
	cin >> n >> m;
	rep (i, 1, n) v[i] = i;
	rep (i, 1, m)
	{
		char opt; int x, y; cin >> opt;
		if (opt == 'U')
		{
			cin >> x;
			v[x] = -1;
		}
		else if (opt == '+')
		{
			cin >> x >> y; v[x] = v[y];
		}
	}
	int res = 0;
	rep (i, 1, n) if (chk(i)) ++res;
	cout << res << endl;
}
}

namespace CHT
{
char opt[20]; int opr[20][2];
int res, vp[20];
inline bool chk()
{
	rep (i, 1, n) vp[i] = v[i];
	rep (i, 1, m)
	{
		if (opt[i] == '+') vp[opr[i][0]] = vp[opr[i][1]];
		if (opt[i] == '-') vp[opr[i][0]] = fix(vp[opr[i][1]]);
		if (opt[i] == 'U') vp[opr[i][0]] = -1;
		if (opt[i] == 'T') vp[opr[i][0]] = 1;
		if (opt[i] == 'F') vp[opr[i][0]] = 0;
	}
	rep (i, 1, n) if (vp[i] != v[i]) return false;
	return true;
}
inline void dfs(int i, int cnt)
{
	if (i > n) { if (chk()) res = min(res, cnt); return; }
	if ((double)clock() / CLOCKS_PER_SEC > 0.9) { cout << res << endl; exit(0); }
	v[i] = 0; dfs(i + 1, cnt);
	v[i] = 1; dfs(i + 1, cnt);
	v[i] = -1; dfs(i + 1, cnt + 1);
}
inline void solve()
{
	cin >> n >> m; res = n;
	rep (i, 1, m)
	{
		cin >> opt[i];
		if (opt[i] == '+' or opt[i] == '-')
			cin >> opr[i][0] >> opr[i][1];
		else
			cin >> opr[i][0];
	}
	dfs(1, 0);
	cout << res << endl;
}
}

inline void solve()
{
	cin >> n >> m;
	fill (v, v + n + 1, 0);
	rep (i, 1, m)
	{
		char opt; int x, y; cin >> opt;
		if (opt == 'T')
		{
			cin >> x;
			v[x] = 1;
		}
		else if (opt == 'F')
		{
			cin >> x;
			v[x] = 0;
		}
		else if (opt == 'U')
		{
			cin >> x;
			v[x] = -1;
		}
		else if (opt == '+')
		{
			cin >> x >> y;
			v[x] = v[y];
		}
		else if (opt == '-')
		{
			cin >> x >> y;
			v[x] = fix(v[y]);
		}
	}
	rep (i, 1, n) cout << v[i] << " \n"[i == n];
}

int main()
{
	file("tribool");
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int T; cin >> c >> T;
	if (c == 1 or c == 2) { while (T--) C12::solve(); return 0; }
	if (c == 3 or c == 4) { while (T--) C34::solve(); return 0; }
	if (c == 5 or c == 6) { while (T--) C56::solve(); return 0; }
	while (T--) CHT::solve();
	
	return 0;
}