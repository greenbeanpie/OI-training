#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int c, T, n, m;
struct Qn {
	char op;
	int x, y;
}q[N];
int arr[N], b[N];
int nott(int x) {
	// 0,1,2 : T,F,U
	if(x == 0 || x == 1) return !x;
	else return x;
}
int ans;
void dfs(int step) {
	if(step > n) {
		for(int i = 1; i <= n; ++i) b[i] = arr[i];
		for(int i = 1; i <= m; ++i) {
			switch(q[i].op) {
				case '+' :
					b[q[i].x] = b[q[i].y];
					break;
				case '-' :
					b[q[i].x] = nott(b[q[i].y]);
					break;
				case 'T' :
					b[q[i].x] = 1; break;
				case 'F' :
					b[q[i].x] = 0; break;
				case 'U' :
					b[q[i].x] = 2; break;		
			}
		}
		int cur = 0;
		for(int i = 1; i <= n; ++i) {
			if(b[i] != arr[i]) return ;
			if(b[i] != 2) cur ++;
		}
		ans = max(ans, cur);
		return ;
	}
	for(int i = 0; i <= 2; ++i) {
		arr[step] = i;
		dfs(step + 1);
		arr[step] = 0;
	}
}
map<char, int> mp;
namespace sub34 {
	int vis[N];
	void clear() {
		for(int i = 1; i <= n; ++i) vis[i] = 0;
		return ;
	}
}
namespace sub56 {
	int stat[N], fa[N];
	vector<int> e[N];
	int vis[N];
	void init() {
		for(int i = 1; i <= n; ++i) {
			e[i].clear();
			stat[i] = 0;
			fa[i] = i;
			vis[i] = 0;
		}
		return ;
	}
	void dfs(int x) {
		vis[x] = 1;
		for(int y : e[x]) {
			stat[y] = stat[x];
			if(!vis[y]) {
				dfs(y);
			}
		}
	}
}
int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	mp['T'] = 1;
	mp['F'] = 0;
	mp['U'] = 2;
	cin >> c >> T;
	while(T --) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= m; ++i) {
			cin >> q[i].op;
			if(q[i].op == '-' || q[i].op == '+') scanf("%d%d", &q[i].x, &q[i].y);
			else scanf("%d", &q[i].x);
		}
		if(c <= 2) { // 1,2
			ans = 0;
			for(int i = 1; i <= n; ++i) arr[i] = 0;
			dfs(1);
			cout << n - ans << endl;
		}
		else if(c <= 4) { // 3,4
			sub34::clear();
			ans = n;
			for(int i = m; i >= 1; --i) {
				if(!sub34::vis[q[i].x]) {
					if(q[i].op == 'U') {
						ans --;
					}
					sub34::vis[q[i].x] = 1;
				}
			}
			cout << n - ans << endl;
		}
		else if(c <= 6) { // 5,6
			ans = 0;
			sub56::init();
			for(int i = 1; i <= m; ++i) {
				if(q[i].op == '+') {
					sub56::fa[q[i].x] = q[i].y;
					sub56::stat[q[i].x] = sub56::stat[q[i].y];
				} else {
					sub56::fa[q[i].x] = q[i].x;
					sub56::stat[q[i].x] = 1;
				}
			}
//			for(int i = 1; i <= n; ++i) vvis[i] = 0;
//			for(int i = m; i >= 1; --i) {
//				if(!vvis[q[i].x]) {
//					if(q[i].op == 'U') {
//						sub56::stat[q[i].x] = 1;
//					} else {
//						sub56::fa[q[i].x] = q[i].y;
//					}
//					vvis[q[i].x] = 1;
//				}
//			}
			for(int i = 1; i <= n; ++i) {
				sub56::e[sub56::fa[i]].push_back(i);
			}
			for(int i = 1; i <= n; ++i) {
				if(sub56::stat[i] == 1) sub56::dfs(i);
			}
			for(int i = 1; i <= n; ++i) {
				if(sub56::stat[i] == 0) ans ++;
			}
			cout << n - ans << endl;
		}
	}
	return 0;
}