#include <bits/stdc++.h>
using namespace std;

int n, m, dict[3024][26];
char str[3024];

struct Word {
	int ch[26];
};

inline bool Compare(const Word a, const Word b) {
	for (int i = 25; i >= 0; i--) {
		if (a.ch[i] > b.ch[i]) {
			return false;
		}
		if (a.ch[i] < b.ch[i]) {
			return true;
		}
	}
	return false;
}

inline Word Merge(const Word a, const Word b) {
	return Compare(a, b) ? a : b;
}

Word segtree[12024];

void build(int l, int r, int id) {
	if (l == r) {
		for (int i = 0; i < 26; i++) {
			segtree[id].ch[i] = dict[l][i];
		}
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, id << 1);
	build(mid + 1, r, id << 1 | 1);
	segtree[id] = Merge(segtree[id << 1], segtree[id << 1 | 1]);
}

Word query(int l, int r, int L, int R, int id) {
	if (L <= l && r <= R) {
		return segtree[id];
	}
	int mid = (l + r) >> 1;
	if (L <= mid && R > mid) {
		return Merge(query(l, mid, L, R, id << 1), query(mid + 1, r, L, R, id << 1 | 1));
	}
	if (L <= mid) {
		return query(l, mid, L, R, id << 1);
	}
	return query(mid + 1, r, L, R, id << 1 | 1);
}

inline Word queryExcept(int d) {
	if (d == 1) {
		return query(1, n, 2, n, 1);
	}
	if (d == n) {
		return query(1, n, 1, n - 1, 1);
	}
	return Merge(query(1, n, 1, d - 1, 1), query(1, n, d + 1, n, 1));
}

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", str);
		for (int j = 0; j < m; j++) {
			dict[i][str[j] - 'a']++;
		}
	}
	if (n == 1) {
		putchar('1');
		putchar('\n');
		return 0;
	}
	build(1, n, 1);
	for (int i = 1; i <= n; i++) {
		Word tc = queryExcept(i);
		int l = 0, r = 25;
		while (!dict[i][l]) {
			l++;
		}
		while (!tc.ch[r]) {
			r--;
		}
		if (l < r) {
			putchar('1');
			continue;
		}
		putchar('0');
	}
	putchar('\n');
	return 0;
}