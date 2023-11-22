#include<iostream>
#include<algorithm>
int c, n, m, q, X[500005], Y[500005], x[500005], y[500005];
int query(int *X, int *Y, int *mxX, int *mxY, int *mnX, int *mnY, int h, int w) {
	if (X[1] >= Y[1]) return 0;
	if (h <= 1 || w <= 1) return 1;
	if (Y[mxY[w]] <= X[mxX[h]] && X[mnX[h]] >= Y[mnY[w]]) return 0;
	if (Y[mxY[w]] > X[mxX[h]] && X[mnX[h]] < Y[mnY[w]]) {
		return query(X, Y, mxX, mxY, mnX, mnY, mnX[h] - 1, mxY[w] - 1);
	}
	if (Y[mxY[w]] > X[mxX[h]]) {
		while (w && X[mnX[h]] >= Y[mnY[w]]) w--;
		if (!w) return 0;
		if (Y[mxY[w]] <= X[mxX[h]]) return 0;
		return query(X, Y, mxX, mxY, mnX, mnY, mnX[h] - 1, mxY[w] - 1);
	} else {
		while (h && Y[mxY[w]] <= X[mxX[h]]) h--;
		if (!h) return 0;
		if (X[mnX[h]] >= Y[mnY[w]]) return 0;
		return query(X, Y, mxX, mxY, mnX, mnY, mnX[h] - 1, mxY[w] - 1);
	}
}
int query(int n, int m, int *X, int *Y) {
	static int mxX[500005], mxY[500005];
	static int mnX[500005], mnY[500005];
/*	std::cerr << "query " << n << " " << m << std::endl;
	for (int i = 1; i <= n; i++) std::cerr << X[i] << " \n"[i == n];
	for (int i = 1; i <= m; i++) std::cerr << Y[i] << " \n"[i == m];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cerr << int(X[i] >= Y[j]);
		}
		std::cerr << std::endl;
	}*/
	for (int i = 1; i <= n; i++) {
		mxX[i] = mxX[i - 1];
		if (!mxX[i]) mxX[i] = i;
		if (X[i] > X[mxX[i]]) mxX[i] = i;
		mnX[i] = mnX[i - 1];
		if (!mnX[i]) mnX[i] = i;
		if (X[i] < X[mnX[i]]) mnX[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		mxY[i] = mxY[i - 1];
		if (!mxY[i]) mxY[i] = i;
		if (Y[i] > Y[mxY[i]]) mxY[i] = i;
		mnY[i] = mnY[i - 1];
		if (!mnY[i]) mnY[i] = i;
		if (Y[i] < Y[mnY[i]]) mnY[i] = i;
	}
	if (Y[mxY[m]] <= X[mxX[n]] || X[mnX[n]] >= Y[mnY[m]]) return 0;
	int ret = query(X, Y, mxX, mxY, mnX, mnY, mnX[n] - 1, mxY[m] - 1);
	std::reverse(X + 1, X + n + 1);
	std::reverse(Y + 1, Y + m + 1);
	for (int i = 1; i <= n; i++) {
		mxX[i] = mxX[i - 1];
		if (!mxX[i]) mxX[i] = i;
		if (X[i] > X[mxX[i]]) mxX[i] = i;
		mnX[i] = mnX[i - 1];
		if (!mnX[i]) mnX[i] = i;
		if (X[i] < X[mnX[i]]) mnX[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		mxY[i] = mxY[i - 1];
		if (!mxY[i]) mxY[i] = i;
		if (Y[i] > Y[mxY[i]]) mxY[i] = i;
		mnY[i] = mnY[i - 1];
		if (!mnY[i]) mnY[i] = i;
		if (Y[i] < Y[mnY[i]]) mnY[i] = i;
	}
	return ret && query(X, Y, mxX, mxY, mnX, mnY, mnX[n] - 1, mxY[m] - 1);
}
int ask() {
	if (x[1] == y[1]) return 0;
	if (x[1] < y[1]) return query(n, m, x, y);
	return query(m, n, y, x);
}
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	std::cin >> c >> n >> m >> q;
	for (int i = 1; i <= n; i++) std::cin >> X[i], x[i] = X[i];
	for (int i = 1; i <= m; i++) std::cin >> Y[i], y[i] = Y[i];
	std::cout << ask();
	while (q--) {
		for (int i = 1; i <= n; i++) x[i] = X[i];
		for (int i = 1; i <= m; i++) y[i] = Y[i];
		int kx, ky; std::cin >> kx >> ky;
		while (kx--) {
			int i, v; std::cin >> i >> v;
			x[i] = v;
		}
		while (ky--) {
			int i, v; std::cin >> i >> v;
			y[i] = v;
		}
//		std::cerr << "done \n";
//		std::cerr << ask() << std::endl;
		std::cout << ask();
	}
	std::cout << std::endl;
}
