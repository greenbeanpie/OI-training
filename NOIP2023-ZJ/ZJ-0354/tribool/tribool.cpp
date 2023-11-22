#include <cstdio>
#include <algorithm>
#define Maxn 100000
#define Inf 0x3f3f3f3f
namespace FASTIO {
	char get_an_opt() {
		char ch = getchar();
		while(ch != '+' && ch != '-' && ch != 'T' && ch != 'F' && ch != 'U') ch = getchar();
		return ch;
	}
	int read() {
		int x = 0, f = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
		while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
		return x * f;
	}
	void write(int x) {
		if(x < 0) putchar('-'), write(-x);
		else if(x <= 9) putchar(x + '0');
		else write(x / 10), putchar(x % 10 + '0');
	}
}
int n, m, ans;
struct ASK {char opt; int x, y;	} ask[Maxn + 9];
void Solve() {
	n = FASTIO::read(), m = FASTIO::read();
	
}
namespace TASK1 {
	char tmp[Maxn + 9], temp[Maxn + 9];
	char Reverse(char x) {
		if(x == 'T') return 'F';
		if(x == 'F') return 'T';
		return x;
	}
	void Check(int cnt) {
		for(int i = 1; i <= n; ++ i) temp[i] = tmp[i];
		for(int i = 1; i <= m; ++ i) {
			if(ask[i].opt != '+' && ask[i].opt != '-') temp[ask[i].x] = ask[i].opt;
			else if(ask[i].opt == '+') temp[ask[i].x] = temp[ask[i].y];
			else temp[ask[i].x] = Reverse(temp[ask[i].y]);
		}
		for(int i = 1; i <= n; ++ i) if(temp[i] != tmp[i]) return;
		ans = std::min(ans, cnt);
	}
	void Dfs(int d, int cnt) {
		if(d > n) {Check(cnt); return;}
		tmp[d] = 'T', Dfs(d + 1, cnt);
		tmp[d] = 'F', Dfs(d + 1, cnt);
		tmp[d] = 'U', Dfs(d + 1, cnt + 1);
	}
	void Solve() {
		n = FASTIO::read(), m = FASTIO::read();
		for(int i = 1; i <= m; ++ i) {
			ask[i].opt = FASTIO::get_an_opt(), ask[i].x = FASTIO::read();
			if(ask[i].opt != '+' && ask[i].opt != '-') continue;
			ask[i].y = FASTIO::read();
		}
		ans = Inf;
		Dfs(1, 0);
		FASTIO::write(ans), puts("");
	}
}
int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int c = FASTIO::read(), T = FASTIO::read();
	if(c <= 2) while(T -- ) TASK1::Solve();
	else while(T --) Solve();
	return 0;
}