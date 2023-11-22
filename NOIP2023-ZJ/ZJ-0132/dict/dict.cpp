#include <bits/stdc++.h>
using namespace std;
//bool be;
const int N = 3005;

int n, m, mi, se;
string s[N], t[N], tmp;

//bool en;
int main() {
//	printf("%lf\n", abs(&en - &be) / 1024.0 / 1024);
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		cin >> s[i], t[i] = s[i], sort(t[i].begin(), t[i].end(), greater<char>());
		if (!mi || t[mi] > t[i]) se = mi, mi = i;
		else if (!se || t[se] > t[i]) se = i;
	}
	for (int i = 1; i <= n; ++i) {
		tmp = s[i], sort(tmp.begin(), tmp.end());
		if (mi == i) { putchar(!se || t[se] > tmp ? '1' : '0'); continue; }
		putchar(t[mi] > tmp ? '1' : '0');
	}
	return 0;
}
