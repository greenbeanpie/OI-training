#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for(int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in","r",stdin);freopen(prob".out","w",stdout);

using namespace std;

const int N = 3e3 + 10;

int n, m;
string Min[N], Max[N];

inline bool chk(int x)
{
	rep (i, 1, n)
	{
		if (i == x) continue;
		if (Min[x] >= Max[i]) return false;
	}
	return true;
}

int main()
{
	file("dict");
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	rep (i, 1, n)
	{
		string s; cin >> s;
		
		string t = s;
		sort(t.begin(), t.end());
		Min[i] = t;
		reverse(t.begin(), t.end());
		Max[i] = t;
	}
	
	rep (i, 1, n)
	{
		cout << (chk(i) ? 1 : 0);
	}
	return 0;
}