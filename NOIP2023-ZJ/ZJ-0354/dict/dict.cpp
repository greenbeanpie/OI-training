#include <cstdio>
#define Maxn 3000
#define Maxk 26
namespace FASTIO {
	char get_a_letter() {
		char ch = getchar();
		while(ch < 'a' || ch > 'z') ch = getchar();
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
int n, m, cnt[Maxn + 9][Maxk + 9];
bool Bigger(int x, int y) {
	int px = 0, py = 25;
	while(px <= 25 && py >= 0) {
		while(cnt[x][px] == 0 && px <= 25) ++ px;
		while(cnt[y][py] == 0 && py >= 0) -- py;
		if(px > 25 || py < 0) break;
		if(px > py) return 1;
		if(px < py) return 0;
		++ px, -- py;
	}
	return 1;
}
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	n = FASTIO::read(), m = FASTIO::read();
	for(int i = 1; i <= n; ++ i) for(int j = 1; j <= m; ++ j) {char ch = FASTIO::get_a_letter(); ++ cnt[i][ch - 'a'];}
	for(int i = 1; i <= n; ++ i) {
		bool Flag = 0;
		for(int j = 1; j <= n && !Flag; ++ j) if(i != j) Flag |= Bigger(i, j);
		Flag ^= 1;
		FASTIO::write(Flag);
	}
	puts("");
	return 0;
}