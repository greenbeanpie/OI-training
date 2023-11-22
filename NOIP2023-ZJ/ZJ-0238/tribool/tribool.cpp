/*
今天竟然有输入法能用/jy
9:12 T1 passed but 0.9979s
T1 卡常？
0.9979s 能不能过？


T2:
看起来是个图论题，给互相赋值的语句看作有向边，+是0，-是1，大抵是找环上边权和为奇数且没有额外赋值语句的东西，这种环上必须全是U，还要找全是U的链？


*/

#include<bits/stdc++.h>
using namespace std;
struct Query {
	char ch;
	int x, y;
}qs[100005];
int n, m;
namespace BF {
	int a[13], b[13], ret = 0x3f3f3f3f;
	inline bool check() {
		for(int i = 1; i <= n; i++) b[i] = a[i];
		for(int i = 1; i <= m; i++) {
			char ch = qs[i].ch; int x = qs[i].x, y = qs[i].y;
			if(ch == '+') b[x] = b[y];
			else if(ch == '-') {
				if(b[y] == 3) b[x] = 3;
				else b[x] = 3 - b[y];
			} else {
				if(ch == 'T') b[x] = 1;
				else if(ch == 'F') b[x] = 2;
				else b[x] = 3;
			}
		}
		for(int i = 1; i <= n; i++) if(b[i] != a[i]) return 0;
		return 1;
	}
	void dfs(int dep, int ans) {
		if(dep > n) {
			if(check()) ret = min(ret, ans);
			return;
		}
		a[dep] = 1;
		dfs(dep + 1, ans);
		a[dep] = 2;
		dfs(dep + 1, ans);
		a[dep] = 3;
		dfs(dep + 1, ans + 1);
		a[dep] = 0;
	}
	
	void solve() {
		ret = 0x3f3f3f3f;
		dfs(1, 0);
		cout << ret << endl;
	}
}
struct monazite {
	int val, fa, from;
	// val == -2 means this val if diff from it's father 
	// val == -1 means this val if the same to it's father 
	// val == 1 2 3 means this val is sure
} a[100005];
int id;
inline void SoLvE() {
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> qs[i].ch;
		if(qs[i].ch == '+' || qs[i].ch == '-') cin >> qs[i].x >> qs[i].y;
		else cin >> qs[i].x;
	}
	if(n <= 10) BF::solve();
	else if(id == 3 || id == 4) {
		for(int i = 1; i <= n; i++) a[i] = {-1, i, 0};
		for(int i = 1; i <= m; i++) {
			char ch = qs[i].ch; int x = qs[i].x, y = qs[i].y;
			if(ch == 'T') a[x] = {1, i, 0};
			else if(ch == 'F') a[x] = {2, i, 0};
			else if(ch == 'U') a[x] = {3, i, 0};
		}
		int ret = 0;
		for(int i = 1; i <= n; i++) if(a[i].val == 3) ret++;
		cout << ret << endl;
	} else if(id == 5 || id == 6)  {
		for(int i = 1; i <= n; i++) a[i] = {-1, i, 0};
		for(int i = 1; i <= m; i++) {
			char ch = qs[i].ch; int x = qs[i].x, y = qs[i].y;
			if(ch == '+') {
				a[x] = a[y];
				a[x].from = y;
			}else {
				if(ch == 'T') a[x] = {1, i, 0};
				else if(ch == 'F') a[x] = {2, i, 0};
				else if(ch == 'U') a[x] = {3, i, 0};
			}
		}
		int ret = 0;
		for(int i = 1; i <= n; i++) if(a[i].val == 3) ret++;
		cout << ret << endl;
	} else {
		for(int i = 1; i <= n; i++) a[i] = {-1, i, 0};
		for(int i = m; i >= 1; i--) {
			char ch = qs[i].ch; int x = qs[i].x, y = qs[i].y;
			if(ch == '+') {
				if(x == a[y].fa && a[y].val == -2) {
					
				} else {
					a[x] = a[y];
					a[x].from = y;
				}
				
			} else if(ch == '-'){
				if(x == a[y].fa && a[y].val == -1) {
					a[x].val = -3;
				} else {
					a[x] = a[y];
					if(a[y].val == -1) a[x].val = -2;
					else if(a[y].val == -2) a[x].val = -1;
					else if(a[y].val == 1) a[x].val = 2;
					else if(a[y].val == 2) a[x].val = 1;
					else if(a[y].val == 3) a[x].val = 3;
				}

			} else {
				if(ch == 'T') a[x] = {1, i, 0};
				else if(ch == 'F') a[x] = {2, i, 0};
				else if(ch == 'U') a[x] = {3, i, 0};
			}
		}
	}
}
int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int _ = 1;
	cin >> id >> _;
	while(_--) SoLvE();

	return ~(0^_^0);
}
