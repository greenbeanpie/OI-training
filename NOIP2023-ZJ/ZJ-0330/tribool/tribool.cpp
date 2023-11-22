#include <bits/stdc++.h>
#define F(i, l, r) for(int i = l; i < r ; ++ i)
#define Fe(i, l, r) for(int i = l; i <= r; ++ i)
#define reopen(A) { freopen(#A".in", "r", stdin); freopen(#A".out", "w", stdout); }
using namespace std;

constexpr int N = 100005;

int c, T, n, m, ans;

char st[N];

struct op{
	int u, v;
	char tp;
} p[N];

void check(){
	static char tmp[100005];
	Fe(i, 1, n) tmp[i] = st[i];
	Fe(i, 1, m){
		if(p[i].tp == '+'){
			tmp[p[i].v] = tmp[p[i].u];
		} else if(p[i].tp == '-') {
			if(tmp[p[i].u] == 'T') tmp[p[i].v] = 'F';
			else if(tmp[p[i].u] == 'F') tmp[p[i].v] = 'T';
			else if(tmp[p[i].u] == 'U') tmp[p[i].v] = 'U';
		} else {
			tmp[p[i].v] = p[i].tp;
		}
	}
	bool fl = 1;
	Fe(i, 1, n){
		if(tmp[i] != st[i]){
			fl = 0;
			break;
		}
	}
	
	if(fl){
		int cnt = 0;
		Fe(i, 1, n) {
			if(st[i] == 'U') ++ cnt;
		}
		ans = min(ans, cnt);
	}
	return ;
}

void dfs(int x){
	if(x > n){
		check();
		return ;
	}
	
	st[x] = 'T';	
	dfs(x + 1);
	st[x] = 'F';
	dfs(x + 1);
	st[x] = 'U';
	dfs(x + 1);
}

inline void solve(){
	cin >> n >> m;
	Fe(i, 1, m){
		char op;
		cin >> op;
		p[i].tp = op;
		if(op == 'T' || op == 'F' || op == 'U') {
			cin >> p[i].v;
			p[i].u = -1;
		} else {
			cin >> p[i].v >> p[i].u;
		}
	}
//	
	if(c == 1 || c == 2){
		ans = 0x3f3f3f3f;
		dfs(1);
		cout << ans << endl;
	} else if(c == 3 || c == 4){
		Fe(i, 1, n) st[i] = 'E';
		Fe(i, 1, m){
			st[p[i].v] = p[i].tp;
		}
		int cnt = 0;
		Fe(i, 1, n) {
			if(st[i] == 'U') ++ cnt;
		}
		cout << cnt << endl;
	} else if(c == 5 || c == 6){
		Fe(i, 1, n) st[i] = 'E';
		Fe(i, 1, m){
			if(p[i].tp == 'U') {
				st[p[i].v] = 'U';
				continue;
			}
			if(st[p[i].u] == 'U') {
				st[p[i].v] = 'U';
			} else {
				st[p[i].v] = 'E';
			}
		}
		int cnt = 0;
		Fe(i, 1, n){
			if(st[i] == 'U') ++ cnt;
		}
		cout << cnt << endl;
	}
}

signed main(){
	reopen(tribool);
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> c >> T;
	while(T--){
		solve();
	}	
	return 0;
}