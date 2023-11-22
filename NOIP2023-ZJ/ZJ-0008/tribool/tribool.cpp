#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define ll long long
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define per(i, a, b) for(int i = (a); i >= (b); --i)
#define vi vector<int>
#define PB emplace_back
#define siz(a) ((int) a.size())

const int N = 1e5;
int TT, T, a, b, s[N + 5], in[N + 5], siz[N + 5], t[N + 5];
vi st[N + 5];

int init(int n) {
	vi tmp;
	for(int v : st[n]) {
		if(in[v > a ? v - a : v]) tmp.PB(v);
	}
	assert(siz(tmp) == 1);
	return tmp[0];
}

signed main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for(cin >> TT >> T; T--; ) {
		cin >> a >> b;
		rep(i, 1, a) s[i] = i, st[i].clear(), in[i] = t[i] = 0, siz[i] = 1;
		char o;
		int x, y;
		rep(i, 1, b) {
			cin >> o >> x;
			if(o == 'T') s[x] = -1;
			else if(o == 'F') s[x] = -2;
			else if(o == 'U') s[x] = -3;
			else if(o == '+') {
				cin >> y;
				s[x] = s[y];
			}
			else {
				cin >> y;
				if(s[y] < 0) {
					if(s[y] == -1) s[x] = -2;
					else if(s[y] == -2) s[x] = -1;
					else s[x] = -3;
				}
				else {
					if(s[y] > a) s[x] = s[y] - a;
					else s[x] = s[y] + a;
				}
			}
		}
		int ans = 0;
		rep(i, 1, a) if(s[i] > 0) {
			if(s[i] <= a) st[s[i]].PB(i), ++in[s[i]];
			else st[s[i] - a].PB(i + a), ++in[s[i] - a];
		}
		queue<int> qu;
		rep(i, 1, a) if(!in[i]) qu.push(i);
		while(siz(qu)) {
			int u = qu.front();
			qu.pop();
			if(s[u] < 0) {
				ans += (s[u] == -3) * siz[u];
				continue;
			}
			int v = s[u];
			if(v > a) v -= a;
			--in[v];
			siz[v] += siz[u];
			if(!in[v]) qu.push(v);
		}
		rep(i, 1, a) if(in[i]) {
			int cnt = 0;
			bool is;
			vi tmp;
			for(int x = i; ; ) {
				tmp.PB(x);
				cnt += siz[x];
				int v = init(x), w = 0;
				if(v > a) v -= a, w = 1;
				if(v == i) {
					is = (w ^ t[x]) == t[i];
					break;
				}
				else {
					t[v] = t[x] ^ w;
					x = v;
				}
			}
			for(int x : tmp) in[x] = 0;
			if(!is) ans += cnt;
		}
		cout << ans << '\n';
	}
	return 0;
}