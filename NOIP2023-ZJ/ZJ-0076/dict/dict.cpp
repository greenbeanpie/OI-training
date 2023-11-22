#include <bits/stdc++.h>
using namespace std;

const int N = 3005;
struct node {
	int cnt[26];
} A[N];
char s[N], ans[N];
int n, m, mn1, mn2;

inline bool cmp2(int x, int y) {
	if (!y) return true;
	int i = 25;
	while (i > 0 && A[x].cnt[i] == A[y].cnt[i]) --i;
	return A[x].cnt[i] < A[y].cnt[i];
}
inline bool cmp1(int x, int y) {
	if (!y) return true;
	if (x == y) return true;
	int i = 0, j = 25;
	while (i < 26 && !A[x].cnt[i]) ++i;
	while (j >= 0 && !A[y].cnt[j]) --j;
	return i < j;
}

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s + 1);
		for (int j = 1; j <= m; ++j)	
			++A[i].cnt[s[j] - 'a'];
	}
	mn1 = mn2 = 0;
	for (int i = 1; i <= n; ++i) {
		if (cmp2(i, mn2)) {
			mn2 = i;
			if (cmp2(mn2, mn1)) swap(mn1, mn2);
		}
	}
	for (int i = 1; i <= n; ++i)
		if (cmp1(i, mn1) && cmp1(i, mn2)) ans[i] = '1';
		else ans[i] = '0';
	puts(ans + 1);
	return 0;
}