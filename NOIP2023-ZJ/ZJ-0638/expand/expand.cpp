#include <bits/stdc++.h>

using namespace std;

inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while (! isdigit(ch)){
		if (ch == '-')
			f = - f;
		ch = getchar();
	}
	while (isdigit(ch)){
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}

void write(int x){
	if (x < 0){
		putchar('-');
		write(- x);
		return;
	}
	if (x >= 10)
		write(x / 10);
	putchar(x % 10 + 48);
	return;
}

inline void writesp(int x){
	write(x);
	putchar(' ');
	return;
}

inline void writeln(int x){
	write(x);
	puts("");
	return;
}

const int MAXN = 3055;

int c, n, m, q;
int ta[MAXN], a[MAXN], tb[MAXN], b[MAXN], Ans[MAXN];

inline int work(){
//		for (int i = 1; i <= n; ++ i)
//			writesp(ta[i]);
//		puts("");
//		for (int i = 1; i <= m; ++ i)
//			writesp(tb[i]);
//		puts("");
	return ((ta[1] - tb[1]) * (ta[n] - tb[m]) > 0);
}

signed main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	c = read(), n = read(), m = read(), q = read();
	int tot = 0;
	for (int i = 1; i <= n; ++ i)
		ta[i] = a[i] = read();
	for (int i = 1; i <= m; ++ i)
		tb[i] = b[i] = read();
	Ans[++ tot] = work();
	while (q --){
		for (int i = 1; i <= n; ++ i)
			ta[i] = a[i];
		for (int i = 1; i <= m; ++ i)
			tb[i] = b[i];
		int kx = read(), ky = read();
		for (int i = 1; i <= kx; ++ i){
			int px = read(), vx = read();
			ta[px] = vx;
		}
		for (int i = 1; i <= ky; ++ i){
			int py = read(), vy = read();
			tb[py] = vy;
		}
		Ans[++ tot] = work();
	}
	for (int i = 1; i <= tot; ++ i)
		write(Ans[i]);
	puts("");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
