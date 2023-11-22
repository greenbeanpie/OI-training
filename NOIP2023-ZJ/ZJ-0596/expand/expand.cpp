#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

int c, n, m, q;

int seq1[N], seq2[N], bseq1[N], bseq2[N];
int ans[N], id;
int min2 = 2147483647, max1 = -1, bmax = -1, bmin = 2147483647;

int read();
void write(int);

/* I am too lazy to extract the same codes with functions, so the code is a bit looooong and hard to debug QAQ */

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	c = read();
	n = read();
	m = read();
	q = read();
	for (int i = 1; i <= n; i++) {
		seq1[i] = read();
		bseq1[i] = seq1[i];
		max1 = max(max1, seq1[i]);
	}
	for (int i = 1; i <= m; i++) {
		seq2[i] = read();
		bseq2[i] = seq2[i];
		min2 = min(min2, seq2[i]);
	}
	bmax = max1;
	bmin = min2;
	if (c == 1) {
		if (seq1[1] != seq2[1]) {
			ans[id++] = 1;
		} else {
			ans[id++] = 0;
		}
		int kx, ky;
		int p, v;
		for (int i = 1; i <= q; i++) {
			seq1[1] = bseq1[1];
			seq2[1] = bseq2[1];
			kx = read();
			ky = read();
			while (kx--) {
				p = read();
				v = read();
				seq1[p] = v;
			}
			while (ky--) {
				p = read();
				v = read();
				seq2[p] = v;
			}
			if (seq1[1] != seq2[1]) {
				ans[id++] = 1;
			} else {
				ans[id++] = 0;
			}
		}
		for (int i = 0; i <= q; i++) {
			write(ans[i]);
		}
	} else if (c == 2) {
		if (n == 1) {
			seq1[2] = seq1[1];
		}
		if (m == 1) {
			seq2[2] = seq2[1];
		}
		if (seq1[1] != seq2[1] &&
			seq1[2] != seq2[2] &&
			(seq1[1] - seq2[1]) * (seq1[2] - seq2[2]) > 0) {
			ans[id++] = 1;
		} else {
			ans[id++] = 0;
		}
		int kx, ky;
		int p, v;
		for (int i = 1; i <= q; i++) {
			seq1[1] = bseq1[1];
			seq1[2] = bseq1[2];
			seq2[1] = bseq2[1];
			seq2[2] = bseq2[2];
			kx = read();
			ky = read();
			while (kx--) {
				p = read();
				v = read();
				seq1[p] = v;
			}
			while (ky--) {
				p = read();
				v = read();
				seq2[p] = v;
			}
			if (seq1[1] != seq2[1] &&
				seq1[2] != seq2[2] &&
				(seq1[1] - seq2[1]) * (seq1[2] - seq2[2]) > 0) {
				ans[id++] = 1;
			} else {
				ans[id++] = 0;
			}
		}
		for (int i = 0; i <= q; i++) {
			write(ans[i]);
		}
	} else if (c >= 8 && c <= 14) {
		if (max1 < seq2[m] && seq1[1] < min2) {
			ans[id++] = 1;
		} else {
			ans[id++] = 0;
		}
		int kx, ky;
		int p, v;
		int mv = seq2[m], nv = seq1[1];
		for (int i = 1; i <= q; i++) {
//			cout << mv << " " << nv << endl;
//			fake
			bool flag = 0;
			max1 = bmax;
			min2 = bmin;
			mv = bseq2[m];
			nv = bseq1[1];
			kx = read();
			ky = read();
			while (kx--) {
				p = read();
				v = read();
				max1 = max(max1, v);
				if (p == 1) {
					flag = 1;
					nv = v;
				}
//				seq1[p] = v;
			}
			while (ky--) {
				p = read();
				v = read();
//				seq2[p] = v;
				min2 = min(min2, v);
				if (p == m) {
					flag = 1;
					mv = v;
				}
			}
			if (max1 < mv && nv < min2 || flag) {
				ans[id++] = 1;
			} else {
				ans[id++] = 0;
			}
		}
		for (int i = 0; i <= q; i++) {
			write(ans[i]);
		}
	}
	return 0;
}

int read() {
	int res, f = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0') {
		if (ch == '-') {
			f = -1;
		}
		ch = getchar();
	}
	res = ch - '0';
	ch = getchar();
	while (ch <= '9' && ch >= '0') {
		res = res * 10 + ch - '0';
		ch = getchar();
	}
	return res * f;
}

void write(int x) {
	if (x < 0) {
		x = -x;
		putchar('-');
	}
	if (x > 9) {
		write(x / 10);
	}
	putchar(x % 10 + '0');
}